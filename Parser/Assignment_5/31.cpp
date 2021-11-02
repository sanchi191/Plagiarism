#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class tuple
{
	int i;
	int j;
	int k;
};


class datum
{
public:
	int pos_p;
	int num;
	int pos_q;
	// datum();
	// {

	// }
	// ~datum();

	bool operator > (const datum& a) const
	{
		if(pos_p>a.pos_p)
		{
			if(num> a.num)
			{
				return true;
			}
			else
			{
				if(pos_q > a.pos_q)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			if(num > a.num && pos_q>a.pos_q)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	
		bool operator < (const datum& a) const
	{
		if(pos_p<a.pos_p)
		{
			if(num< a.num)
			{
				return true;
			}
			else
			{
				if(pos_q < a.pos_q)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			if(num < a.num && pos_q<a.pos_q)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};


typedef std::vector<int>::iterator vec_it;

int countmerge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers,int numcount)
{
	int counterl=0;
    while (left != left_end) {
        if (*left < *right || right == right_end) {
            *numbers = *left;
            ++left;
            numcount--;
        } else {
        	counterl+=numcount;
            *numbers = *right;
            ++right;
        }

        ++numbers;
    }

    while (right != right_end) {
        *numbers = *right;
        ++right;
        ++numbers;
    }
    return counterl;
}

int countmerge_sort(std::vector<int>& numbers)
{
	int counter = 0;
    if (numbers.size() <= 1) {
        return 0;
    }

    int middle = numbers.size() / 2;
    std::vector<int> left(numbers.begin(), numbers.begin() + middle);
    std::vector<int> right(numbers.begin() + middle, numbers.end());

    counter +=countmerge_sort(left);
    counter +=countmerge_sort(right);

    counter +=countmerge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin(),middle);
    return counter;
}

int checmerge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers,std::vector<int>& inv_tt)
{
	int min_invr=inv_tt[*right];
	int index=*left;
	int invl=inv_tt[*left];
    while (left != left_end) 
    {
        if (*left < *right || right == right_end) 
        {
        	invl=inv_tt[*left];
        	if(invl<min_invr)
        	{
        	//	cout<<"s"<<*left<<endl;
        		return *left;
        	}
            *numbers = *left;
            ++left;
            return *left;
        } 
        else 
        {
            *numbers = *right;
            ++right;
            if(min_invr > inv_tt[*right])
            {
            	min_invr=inv_tt[*right];
            	index = *right;
            }

        }

        ++numbers;
    }

    while (right != right_end) 
    {
        *numbers = *right;
        ++right;
        ++numbers;
    }
    return 0;
}

int checmerge_sort(std::vector<int>& numbers,std::vector<int>& inv_tt)
{
    if (numbers.size() <= 1) {
        return 0;
    }

    std::vector<int>::size_type middle = numbers.size() / 2;
    std::vector<int> left(numbers.begin(), numbers.begin() + middle);
    std::vector<int> right(numbers.begin() + middle, numbers.end());

    int l =checmerge_sort(left,inv_tt);
    // cout<<"lt"<<l<<endl;
    int r =	checmerge_sort(right,inv_tt);
    // cout<<"rt"<<r<<endl;
    if((l+r))
    {
    	// cout<<l<<"sd"<<endl;
    	return l;
    }
    else
    {
    	int k=checmerge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin(),inv_tt);
    	return k;
    }
}
int main()
{
	int n;
	std::vector<int> p,q,r,inv_p,inv_q,s;
	std::vector<datum> v;
	cin>>n;
	p.resize(n);
	q.resize(n);
	s.resize(n);
	inv_p.resize(n);
	inv_q.resize(n);
	v.resize(n);
	r.resize(n); 

	for(int i =0; i <n;i++)
	{
		// cin>>p[i].num;
		cin>>p[i];
		p[i]--;
		inv_p[p[i]]=i;
		v[p[i]].pos_p = i;
		v[i].num = i;
		// p[i].num--;
		// p[i].pos_p = i;
		// r[i].num=i;
		r[i]=i;
	}
	for(int i =0; i <n;i++)
	{
		// cin>>q[i].num;
		// q[i].num--;
		// q[i].pos_p = i;
		cin>>q[i];
		q[i]--;
		inv_q[q[i]]=i;
		v[q[i]].pos_q = i;
		s[i]=inv_p[q[i]];
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n; i++)
	{
		r[i]=v[i].num;
	}
	int j,i;
	int temp = (countmerge_sort(p) + countmerge_sort(q) - countmerge_sort(s))/2;
	i = checmerge_sort(r,inv_p);
	// cout<<"shiti"<<i;
	j = checmerge_sort(r,inv_q);
	// cout<<"shitj"<<j;
	
	if(i+j>0)
	{
		cout<<"inconsistent\n";
		cout<<i + 1<<" "<<j+1<<endl;
	}	
	else
	{
		if(countmerge_sort(r)!=temp)
		{
			cout<<"inconsistent\n";
		}
		else
		{
			cout<<"consistent\n";
			for(int i = 0; i < n; i++ )
			{
				cout<<v[i].num+1<<" ";
			}
			cout<<endl;
		}
	}	
//Output
	
}
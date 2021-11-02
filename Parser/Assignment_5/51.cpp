#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
list<int> r;
vector<int> rnew;
vector<int> rnewinv;
int n;
int g=1;
int h=0;
int j[3];
int counter=0;
bool myfunc(int i,int j){
	int e=0;
	if(i<j)
		e++;
	if(c[i]<c[j])
		e++;
	if(d[i]<d[j])
		e++;
	if(e>=2)
		return true;
	else
		return false;
}
vector<int> merge(const vector<int>& left, const vector<int>& right)
{
    // Fill the resultant vector with sorted results from both vectors
    vector<int> result;
    unsigned left_it = 0, right_it = 0;
    int minc=n;
    int mind=n;
    while(left_it < left.size() && right_it < right.size())
    {
        // If the left value is smaller than the right it goes next
        // into the resultant vector

        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            if(c[left[left_it]]>minc)
            {
                if(h==0){
                j[0]=left[left_it];
                j[1]=right[right_it];
                h=1;
                }
                g=0;
            }
            if(d[left[left_it]]>mind)
            {
                if(h==0){

                j[0]=left[left_it];
                j[1]=right[right_it];
                for(int i=0;i<n;i++){
                if(i!=j[0] && i!=j[1]){
                    if(myfunc(j[0],j[1])&&myfunc(j[1],i)&&myfunc(i,j[0]))
                        j[2]=i;
                        }
                }
                h=1;
                }
                g=0;
            }
            left_it++;
        }
        else
        {
            counter+=left.size()-left_it;
            result.push_back(right[right_it]);
            if(c[right[right_it]]<minc){
            minc=c[right[right_it]];
            }
            if(d[right[right_it]]<mind){
            mind=d[right[right_it]];
            }
            right_it++;
        }
    }

    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        if(c[left[left_it]]>minc)
            {
                if(h==0){
                j[0]=left[left_it];
                j[1]=right[right_it];
                for(int i=0;i<n;i++){
                if(i!=j[0] && i!=j[1]){
                    if(myfunc(j[0],j[1])&&myfunc(j[1],i)&&myfunc(i,j[0]))
                        j[2]=i;
                        }
                }
                h=1;
                }
                g=0;
            }
            if(d[left[left_it]]>mind)
            {
                if(h==0){

                j[0]=left[left_it];
                j[1]=right[right_it];
                for(int i=0;i<n;i++){
                if(i!=j[0] && i!=j[1]){
                    if(myfunc(j[0],j[1])&&myfunc(j[1],i)&&myfunc(i,j[0]))
                        j[2]=i;

                        }
                }
                h=1;
                }
                g=0;
            }
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}
vector<int> merge_sort(vector<int>& vec)
{
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1)
    {
        return vec;
    }

    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    // Perform a merge sort on the two smaller vectors
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

int main()
{
	cin>>n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	d.resize(n);
	rnew.resize(n);
	rnewinv.resize(n);
	vector<int> s(n);
	vector<int> rnew(n);
	vector<int> e(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=a[i]-1;
		r.push_back(i);
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i];
		b[i]=b[i]-1;
	}
	for (int i = 0; i < n; ++i)
	{
		c[a[i]]=i;
	}
	for (int i = 0; i < n; ++i)
	{
		d[b[i]]=i;
		s[i]=c[b[i]];
	}
	r.sort(myfunc);
	int i=0;
	list<int>::iterator it=r.begin();
	for(;it!=r.end();it++){
        rnew[i]=*it;
        i++;

	}
    for (int i = 0; i < n; ++i)
	{
		rnewinv[rnew[i]]=i;
	}
    int k=rnewinv[j[0]];
	int l=rnewinv[j[1]];
	for(int y=k;y<l-1;y++){
	if(myfunc(y,y+1) && myfunc(y+1,l)&&myfunc(l,y)){

        j[0]=rnew[y];
        j[1]=rnew[y+1];
        j[2]=rnew[l];
	}
	if(!myfunc(y,y+1) && !myfunc(y+1,l) && !myfunc(l,y)){
        j[2]=rnew[y];
        j[1]=rnew[y+1];
        j[0]=rnew[l];
	}

	}
	int counterr,countera,counterb,counters;
	e=merge_sort(rnew);
	counterr=counter;
	int x=g;
	counter=0;
	e=merge_sort(a);
	countera=counter;
	counter=0;
	e=merge_sort(b);
	counterb=counter;
	counter=0;
	e=merge_sort(s);
	counters=counter;
	if(x==1 && (countera+counterb-counters)/2==counterr){
        cout<<"consistent"<<endl;
        it=r.begin();
        for(;it!=r.end();it++){
        cout<<(*it+1)<<" ";}
	}
	else{
        cout<<"inconsistent"<<endl;
        for(int i=0;i<3;i++){
        cout<<(j[i]+1)<<" ";
        }
	}
	return 0;
}






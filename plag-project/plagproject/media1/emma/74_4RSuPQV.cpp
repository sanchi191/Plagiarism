# include <iostream>
# include <algorithm>
# include <cstdio>
# include <vector>
# define INF 10000000
using namespace std;

int N;
int count;

bool mergeAndCheck(int *a, int low, int high, int* invy);
void mergeAndCount(int *a, int low, int high, int& count);

struct contestant
{
	int rank1, rank2 ,index;

	bool operator <(const contestant& rhs) const
	{
		if(index>rhs.index)
		{
			if(rank1>rhs.rank1 || rank2>rhs.rank2)
				return false;
			else
				return true;
		}
		else
		{
			if(rank1>rhs.rank1 && rank2>rhs.rank2)
				return false;
			else
				return true;
		}
	}
};

bool mergesort(int *a, int low, int high, int* invy)
{
    if (low + 1 != high)
    {
        if(mergesort(a, low, (low+high)/2, invy))
        {
        	if(mergesort(a, (low+high)/2, high, invy))
        	{
        		return mergeAndCheck(a, low, high, invy);
        	}
        }
        return false;
    }
    return true;
}
bool mergeAndCheck(int *a, int low, int high, int* invy)
{	
	int mid = (low+high)/2;
    int i = low, j = mid, k = 0;
    int *temp = new int[high - low];

    int minTillnow = INF;

    while (i < mid || j < high)
    {
        if (i == mid)
        {
            temp[k] = a[j];
            minTillnow = min(minTillnow,invy[a[j]]);
            k++;j++;
        }
        else if(j == high)
        {
        	if(invy[a[i]] > minTillnow)
        		return false;

            temp[k] = a[i];
            k++;i++;
        }
        else
        {
        	if (a[i] < a[j])
	        {	
	        	if(invy[a[i]] > minTillnow)
	        		return false;

	            temp[k] = a[i];
	            k++;i++;
	        }
	        else
	        {
	            temp[k] = a[j];
	            minTillnow = min(minTillnow,invy[a[j]]);
	            k++;j++;
	        }
        }
    }
    k = 0;
    for (i = low; i < high; i++)
    {	
        a[i] = temp[k];
        k++;
    }
    delete[] temp;

    return true;
}
bool everyInvOf_X_isInvOf_Y(int* x, int* y)
{
	int invy[N+1];
	for (int i = 1; i < N+1; ++i)
	{
		invy[y[i]] = i;
	}

	return mergesort(x, 1, N+1, invy);
}


void mergesortCount(int *a, int low, int high, int& count)
{
    if (low + 1 < high)
    {
        mergesortCount(a, low, (low+high)/2, count);
		mergesortCount(a, (low+high)/2, high, count);
       	mergeAndCount(a, low, high, count);
    }
}

void mergeAndCount(int *a, int low, int high, int& count)
{	
	int mid = (low+high)/2;
    int i = low, j = mid, k = 0;
    int *temp = new int[high - low];

    while (i < mid || j < high)
    {
        if (i == mid)
        {
            temp[k] = a[j];
            k++;j++;
        }
        else if(j == high)
        {
            temp[k] = a[i];
            k++;i++;
        }
        else
        {
        	if (a[i] < a[j])
	        {	
	            temp[k] = a[i];
	            k++;i++;
	        }
	        else
	        {
	            temp[k] = a[j];
	            count = count + mid - i;
	            k++;j++;
	        }
        }
    }
    k = 0;
    for (i = low; i < high; i++)
    {	
        a[i] = temp[k];
        k++;
    }
    delete[] temp;
}

int invCount(int*x)
{
	int count = 0;
	mergesortCount(x, 1, N+1, count);
	return count;
}

int main()
{
	scanf("%d", &N);
	int index;
	int p[N+1];
	int q[N+1];
	contestant contestants[N+1];

	for (int i = 1; i < N+1; ++i)
	{	
		contestants[i].index = i;
	}
	for (int i = 1; i < N+1; ++i)
	{
		scanf("%d", &index);
		contestants[index].rank1 = i;
		p[i] = index;
	}
	for (int i = 1; i < N+1; ++i)
	{
		scanf("%d", &index);
		contestants[index].rank2 = i;
		q[i] = index;
	}

	sort(contestants + 1, contestants+ N+1);
	int r[N+1];
	for (int i = 1; i < N+1; ++i)
	{
		r[i] = contestants[i].index;
	}

	if(everyInvOf_X_isInvOf_Y(r, p) && everyInvOf_X_isInvOf_Y(r, q))
	{	
		int invy[N+1];
		for (int i = 1; i < N+1; ++i)
		{
			invy[p[i]] = i;
		}
		int s[N+1];
		for (int i = 1; i < N+1; ++i)
		{
			s[i] = invy[q[i]];
		}

		if(invCount(r) == ((invCount(p)+invCount(q)-invCount(s))/2))
		{
			cout<<"consistent"<<endl;
			for (int i = 1; i < N+1; ++i)
			{
				cout<<r[i]<<" ";
			}
		}
		else
		{	
			int i,j;
			bool x= true;
			cout<<"inconsistent"<<endl;
			for (i = 1; i < N; ++i)
			{
				for (j = i+2; j < N+1; ++j)
				{
					if(contestants[j] < contestants[i])
					{
						x = false;
						break;
					}
				}
				if(!x)
					break;
			}
			
		cout<<contestants[i].index<<" "<<contestants[j-1].index<<" "<<contestants[j].index<<" "<<endl;
		}

	}
	else
	{	int i,j;bool x= true;
		cout<<"inconsistent"<<endl;
		for (i = 1; i < N; ++i)
		{
			for (j = i+2; j < N+1; ++j)
			{
				if(contestants[j] < contestants[i])
				{
					x = false;
					break;
				}
			}
			if(!x)
				break;
		}

		cout<<contestants[i].index<<" "<<contestants[j-1].index<<" "<<contestants[j].index<<" "<<endl;
	}

	return 0;
}
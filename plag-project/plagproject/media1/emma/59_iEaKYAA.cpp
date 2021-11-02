#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
vector<int> pinv, qinv;
bool lessthan(int i, int j)
{
	if (pinv[i-1] < pinv[j-1] && qinv[i-1] < qinv[j-1])
		return true;
	else if (i < j && pinv[i-1] < pinv[j-1])
		return true;
	else if (i < j && qinv[i-1] < qinv[j-1])
		return true;
	else
		return false;
}
void merge(vector<int> &v, int start, int mid, int end)
{
	int i, j, k;
	vector<int> w(end);
	k = 0;
	for (i=start; i<end; ++i)
	{
		w[i] = v[i];
	}
	for (i=start, j=mid, k=start; i<mid && j<end;)
	{
		if (lessthan(w[i], w[j]))
		{
			v[k] = w[i];
			++i;
			++k;
		}
		else 
		{
			v[k] = w[j];
			++j;
			++k;
		}
	}
	if (i<mid)
	{
		while (i<mid)
		{
			v[k] = w[i];
			++i;
			++k;
		}
	}
	else if (j<end)
	{
		while (j<end)
		{
			v[k] = w[j];
			++j;
			++k;
		}
	}
}
void merge_sort(vector<int> &v, int start, int end)
{
	if (start == end-1)
		return;
	int mid = start + (end - start)/2;
	merge_sort(v, start, mid);
	merge_sort(v, mid, end);
	merge(v, start, mid, end);
}
int main()
{
	int n, i, j, k, cnt = 0;
	vector<int> p, q, v, myinv;
	cin >> n;
	srand(100);
	for (i=0; i<n; ++i)
	{
		pinv.push_back(0);
		qinv.push_back(0);
		v.push_back(i+1);
		myinv.push_back(0);
	}
	for (i=0; i<n; ++i)
	{
		cin >> k;
		p.push_back(k);
		pinv[k-1] = i+1;
	}
	for (i=0; i<n; ++i)
	{
		cin >> k;
		q.push_back(k);
		qinv[k-1] = i+1;
	}
	merge_sort(v, 0, n);
	for (i=0; i<n; ++i)
	{
		myinv[v[i]-1] = i+1; 
	}
	if (n <= 10000)
	{
		for (i=1; i<=n; ++i)
		{
			for (j=1; j<=n; ++j)
			{
				if (i == j)
					continue;
				if (lessthan(i, j))
				{
					if (myinv[i-1] > myinv[j-1])
					{
						cnt++;
						for (k=myinv[j-1]; k<(myinv[i-1]-1); ++k)
						{
							if (lessthan(v[k], i))
							{
								cout << "inconsistent" << endl;
								cout << j << " " << v[k] << " " << i << endl;
								break;
							}
						}
						break;
					}
				}
			}
			if (cnt)
				break;
		}
	}
	if (cnt == 0 || n > 10000)
	{
		cout << "consistent" << endl;
		for (i=0; i<n; ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
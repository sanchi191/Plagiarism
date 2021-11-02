#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define s(n) scanf(" %d",&n)
#define sc(n) scanf("%c",&n)
#define INF 10000000

std::vector<int> p,q,p1,q1,r,s,A,r1;
int ind1=0,ind3=0,ind3;
bool compare(int i,int j)
{
	int x=0;
	if(i < j) x++;
	if(p1[i] < p1[j]) x++;
	if(q1[i] < q1[j]) x++;
	return (x>=2);
}
bool checkAndMerge(vector<int> &x,int start, int end);
bool check(vector<int>& x,int start, int end)
{
    int mid = (start + end)/2;
    if(mid-1 == start)
        return true;
    bool a1=0,b1=0,c1=0;
    a1= check(x,start,mid);
    if(a1)
        b1 = check(x,mid,end);
    else
        return 0;
    if(a1 && b1)
        c1 = checkAndMerge(x,start,end);
    return (a1&&b1&&c1);
}

bool checkAndMerge(vector<int> &X,int start,int end)
{
    int mid = (start + end)/2;
    int l = end-start, i= start,j = mid;

    int min = 1000,numR=0,k=0;
    vector<int> B(l);

    while(i<mid || j < end)
    {
        if(i < mid && j < end)
        {
            if(A[i] < A[j]){
                B[k++] = A[i];
                if(numR!= 0 && X[A[i]] > X[min]){
                    ind1 = A[i];
                    ind3 = min;
                    return false;
                }
                i++;
            }
            else {
                B[k++] = A[j];
                int idx = X[A[j]];
                if(min >= A.size())
                    min = A[j];
                else
                    min = (X[min] > idx )? A[j] : min;
                numR++;
                j++;
            }
        }
        else if( i == mid)
        {
            B[k++] = A[j++];

        }
        else if ( j == end)
        {
            if(numR!= 0 && X[A[i]] > X[min]){
                ind1 = A[i];
                ind3 = min;
                return false;
            }
            B[k++] = A[i++];
        }

    }
    rep(i,start,end)
    {
        A[i] = B[i-start];
    }
    return true;
}
int countAndMerge(vector<int> &p,int start,int end);
int count(vector<int> &x, int start, int end)
{
    int mid = (start + end)/2;
    if(mid-1 == start)
        return 0;
    int a1=0,b1=0,c1=0;
    a1= count(x,start,mid);
    b1 = count(x,mid,end);
    c1 = countAndMerge(x,start,end);
    return (a1+b1+c1);
}

int countAndMerge(vector<int> &X,int start,int end)
{
    int mid = (start + end)/2;
    int l = end-start, i= start,j = mid;
    int min = X.size() + 1,num=0,numR=0,k=0;
    vector<int> B(l);
    while(i<mid || j < end)
    {
        if(i < mid && j < end)
        {
            if(X[i] < X[j]){
            B[k++] = X[i++];
            num += numR;
            }
            else {
                B[k++] = X[j++];
                numR++;
            }
        }
        else if( i == mid)
        {
            rep(x,j,end)
            {
                B[x] = X[j++];
                numR++;
            }
        }
        else if (j == end)
        {
            rep(x,i,mid)
            {
                B[x] = X[i++];
                num += numR;
            }
        }
    }
    rep(i,start,end)
    {
        X[i] = B[i-start];
    }
    return num;
}
int search2(int n)
{
    int i1 = r1[ind1],i3 = r1[ind3];
    rep(j,i1+1,i3)
    {
        if(compare(r[j],ind3))
            return r[j];
        else{
        i1=i1+1;
        ind1 = r[i1];
        }
    }
    for(int i=0;i < n ;i++)
    {
        for(int j=i+1;j<n;j++)
        {

        }
    }
}

int main()
{

	int n,a;
	cin >>n;
	p.resize(n);
	q.resize(n);
	p1.resize(n);
	q1.resize(n);
	r.resize(n);
	s.resize(n);
	r1.resize(n);
	rep(i,0,n)
	{
		cin>>a;
		a--;
		p[i]=a;
		p1[a]=i;
		r[i]=i;
	}
	rep(i,0,n)
	{
		cin>>a;
		a--;
		q[i]=a;
		q1[a]=i;
	}
	rep(i,0,n)
	{
        s[i] = p1[q[i]];
        r1[r[i]] = i;
	}
	sort(r.begin(),r.end(),compare);
    A=r;
	if(!check(p1,0,n)){
        cout << "inconsistent\n";
        int b = search2(n);
        cout << ind1+1 << b+1 <<ind3+1;
        return 0;
    }
    A = r;
	if(!check(q1,0,n)){
        cout <<"inconsistent\n";
         int b = search2(n);
         cout <<ind1+1<< b+1 <<ind3+1;
         return 0;
    }
	A=r;
	int inv_p = count(p,0,n);
	int inv_q = count(q,0,n);
	int inv_s = count(s,0,n);
	int inv_r = count(A,0,n);
	int tot = (inv_p + inv_q - inv_s)/2;
	if(tot == inv_r)
	{
        cout << "consistent\n";
        rep(i,0,n)
        {
            cout <<r[i]+1<<" ";
        }
	}
	else{
        cout << "inconsistent";
	}
	return 0;
}

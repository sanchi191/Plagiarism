#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void mergesort(vector<int> &r,vector<int> &p,vector<int> &q,int start,int end);
void merge(vector<int> &r,vector<int> &p,vector<int> &q,int start,int mid,int end);
bool islessthan(vector<int> &pi,vector<int> &qi,int i,int j);
int main()
{
    int n;
    cin>>n;
    int temp;
    vector<int> p(n+1),q(n+1),pi(n+1),qi(n+1),r(n+1);
    for(int i=1; i<n+1; i++)//sort(r.begin(),r.end(),compareperson)
    {
        r[i]=i;
        cin>>p[i];
        pi[p[i]]=i;
    }
    for(int i=1; i<n+1; i++)
    {
        cin>>q[i];
        qi[q[i]]=i;

    }
    mergesort(r,pi,qi,1,n+1);
    bool flag=true;
    cout<<endl;
    for(int i=1;i<n+1;i++)
    {
    int temp;

    for(int j=i+1;j<n+1;j++)
    {
    if(islessthan(pi,qi,r[i],r[j]))
    {
    temp=j;
    if(temp!=i+1)
    {
    flag=false;
    break;
    }
    }
    }
    if(flag==false)
    {
    cout<<"inconsistent"<<endl;
    cout<<r[i]<<" "<<r[temp-1]<<" "<<r[temp]<<endl;
    return 0;
    }
    }

    cout<<"consistent"<<endl;
    for(int i=1;i<n+1;i++)
    {
    cout<<r[i]<<" ";
    }
    return 0;
}
void mergesort(vector<int> &r,vector<int> &pi,vector<int> &qi,int start,int end)
  {
    if(start+1==end)
    {
        return;
    }
    mergesort(r,pi,qi,start,(start+end)/2);
    mergesort(r,pi,qi,(start+end)/2,end);
    merge(r,pi,qi,start,(start+end)/2,end);
    return;
  }
void merge(vector<int> &r,vector<int> &pi,vector<int> &qi,int start,int mid,int end)
{
    vector<int> temp(end-start);
    int index=0;
    int i,j;
    for (i = start, j = mid; ((i < mid) || (j < end)); )   // Merging loop
    {
        if ((i < mid) && (j < end))   // None of the two subarrays fully seen yet
        {
            if (islessthan(pi,qi,r[i],r[j]))
            {
                temp[index]=r[j];
                j++;
            }
            else
            {
                temp[index]=r[i];
                i++;
            }
        }
        else
        {
            if (i < mid)
            {
                temp[index]=r[i];    // A[mid] … A[end-1] seen
                i++;
            }
            else
            {
                temp[index]=r[j];    // A[start] … A[mid-1] seen
                j++;
            }
        }
        index ++;
    }
    for(int a=0; a<end-start; a++)
    {
        r[start+a]=temp[a];
    }
}
// if r[i]>r[j] then it must return true
bool islessthan(vector<int> &pi,vector<int> &qi,int i,int j)
{

    if((i>j)&&(pi[i]>pi[j]))
    {
        return true;
    }
    if((i>j)&&(qi[i]>qi[j]))
    {
        return true;
    }
    if((qi[i]>qi[j])&&(pi[i]>pi[j]))
    {
        return true;
    }
    return false;
}

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
void cmerge(vector<int> &ai, vector<int> &bi, int start,int mid, int last, vector<int> &v);
bool lessth(int i, int j, vector<int> &a, vector<int> &b)
{
    int k=0;
    if(i<j)
    {
        k++;

    }
    if(a[i]<a[j])
    {
        k++;
    }
    if(b[i]<b[j])
    {
        k++;
    }
    if(k>=2)
    return true;
    else return false;
}
void consiperm(vector<int> &ai, vector<int> &bi, int start, int last, vector<int> &v)
{
    if(start==last-1)
    {
        return;
    }
    int mid = (start+last)/2;
    consiperm(ai,bi,start,mid,v);
    consiperm(ai,bi,mid,last,v);
    cmerge(ai,bi,start,mid,last,v);
    return;
}
void cmerge(vector<int> &ai, vector<int> &bi, int start,int mid, int last, vector<int> &v)
{
    vector<int> temp(ai.size());
    int i,j,index=start;
    for(i=start,j=mid;i<mid||j<last;)
    {
        if(i<mid&&j<last)
        {
            if(lessth(i,j,ai,bi)) {temp[index]=v[i];i++;}
            else {temp[index]=v[j];j++;}
        }
        else
        {
            if(i<mid){ temp[index]=v[i];i++;}
            else{temp[index]=v[j];j++;}
        }
        index++;
    }
    for(int i=start;i<last;i++)
    {
        v[i]=temp[i];
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    vector<int>v(n);
    for(int i=0; i<2*n; i++)
    {
        if(i<n)
        {
            cin>>a[i];
            v[i]=i+1;
        }
        else
        {
            cin>>b[i-n];
        }
    }


    vector<int> ai(n);
    vector<int> bi(n);
    for(int i=0; i<n;i++)
    {
        ai[a[i]-1]=i;
        bi[b[i]-1]=i;
    }
    consiperm(ai,bi,0,n,v);
    bool flag =1;
    int u,w;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!lessth(v[i]-1,v[j]-1,ai,bi))
            {
            cout<<"inconsistent"<<endl;
            flag=0;
            u=v[i];
            w=v[j];

            break;

            }

        }
        if(!flag)
            break;
    }
    if(flag)
    {
    cout<<"consistent"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
           if(lessth(v[i]-1,u-1,ai,bi)&&lessth(w-1,v[i]-1,ai,bi))
           {cout<<w<<" "<<v[i]<<" "<<u;return 0;}
           else if(lessth(v[i]-1,w-1,ai,bi)&&lessth(u-1,v[i]-1,ai,bi))
           {cout<<u<<" "<<v[i]<<" "<<w;return 0;}

        }
    }

}

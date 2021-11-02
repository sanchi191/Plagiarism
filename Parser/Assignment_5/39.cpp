#include<iostream>
#include<vector>
using namespace std;

vector<int> prank;
vector<int> qrank;

bool lessthan(int i,int j)
{
    if(i<j)
    {
        if(prank[i]<prank[j])
        {
            return 1;

        }
        else
        {
            if(qrank[i]<qrank[j])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {

        if((prank[i]<prank[j])&&(qrank[i]<qrank[j]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}
void mergeback(vector<int> &r,int start,int mid,int e)
{
    int i,j;
    vector<int> temp;
    temp.push_back(0);
    int n=r.size()-1;
    for(int i=1; i<n+1; i++)
    {
        temp.push_back(0);
    }
    int index=start;
    for(i=start,j=mid; ((i<mid)||(j<e));)
    {
        if((i<mid)&&(j<e))
        {
            if(lessthan(r[i],r[j]))
            {
                temp[index]=r[i];
                i++;
            }
            else
            {
                temp[index]=r[j];
                j++;
            }
        }
        else
        {
            if(i<mid)
            {
                temp[index]=r[i];
                i++;
            }
            else
            {
                temp[index]=r[j];
                j++;
            }
        }
        index++;
    }
    for(int k=start; k<e; k++)
    {
        r[k]=temp[k];
    }
    return;
}
void mergesort(vector<int> &r,int start,int e)
{
    if(e==start+1)
    {
        return;
    }
    int mid=(start+e)/2;
    mergesort(r,start,mid);
    mergesort(r,mid,e);
    mergeback(r,start,mid,e);
    return;
}

int main()
{
    int n;
    vector<int> p;
    vector<int> q;
    vector<int> s;
    vector<int> r;
    vector<int> rrank;
    cin>>n;
    p.push_back(0);
    q.push_back(0);
    r.push_back(0);
    prank.push_back(0);
    qrank.push_back(0);
    rrank.push_back(0);
    for(int i=1; i<n+1; i++)
    {
        prank.push_back(0);
        qrank.push_back(0);
        rrank.push_back(0);
        r.push_back(i);
    }
    for(int i=1; i<n+1; i++)
    {
        int a;
        cin>>a;
        p.push_back(a);
        prank[a]=i;
    }

    for(int i=1; i<n+1; i++)
    {
        int a;
        cin>>a;
        q.push_back(a);
        qrank[a]=i;
    }
    mergesort(r,1,n+1);
    for(int i=1; i<n+1; i++)
    {
        rrank[r[i]]=i;
    }
    bool a=1;
    int x,y,z;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(lessthan(i,j))
            {
                if(rrank[i]<rrank[j])
                {

                }
                else
                {
                    a=0;
                    x=i;
                    y=j;

                }
            }
            else
            {
                if(rrank[i]>rrank[j])
                {

                }
                else
                {
                    a=0;
                    x=i;
                    y=j;
                }
            }
            if(a==0)
            {
                break;
            }
        }
        if(a==0)
        {
            break;
        }
    }
    if(a==1)
    {
        cout<<"consistent"<<endl;
        for(int i=1; i<n+1; i++)
        {
            cout<<r[i]<<" ";
        }
    }
    else
    {
        if(lessthan(x,y))
        {

        }
        else
        {
            int temp=x;
            x=y;
            y=temp;
        }
        for(int i=1; i<n+1; i++)
        {
            if(lessthan(i,x)&&lessthan(y,i))
            {
                z=i;
                break;
            }
        }
        cout<<"inconsistent"<<endl;
        cout<<z<<" "<<x<<" "<<y;

    }
    return 0;
}

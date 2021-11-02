#include <iostream>
#include <vector>

using namespace std;

int countInv (vector<int> &v, int i, int j)
{
    vector<int> res,l,r,temp;
    temp=v;
    int c=0;
    int mid = (i+j)/2;
    if (i==j)
    {
        return 0;
    }
    else
    {
        c+=countInv(v,i,mid);
        c+=countInv(v,mid+1,j);
        int x=i,y=mid+1,z=i;
        while (true)
        {
            if (v[x]>v[y])
            {
                temp[z++]=v[y++];
                c+=mid+1-x;
            }
            else if (v[x]<=v[y])
            {
                temp[z++]=v[x++];
            }
            if (y==j+1)
            {
                while (x!=mid+1)
                {
                    temp[z++]=v[x++];
                }
                break;
            }
            else if (x==mid+1)
            {
                while (y!=j+1)
                {
                    temp[z++]=v[y++];
                }
                break;
            }
        }
        v=temp;
        return c;
    }
}

vector<int> InvOf(vector<int> p, vector<int> q, int n)
{
    vector<int> s,d;
    s.resize(n);
    d.resize(n);
    int i,j;
    for (i=0;i<n;i++)
    {
        d[p[i]-1]=i+1;
    }
    for (i=0;i<n;i++)
    {
        s[i]=d[q[i]-1];
    }
    return s;
}

int common (vector<int> p, vector<int> q, int n)
{
    vector<int> s,p1,q1;
    p1=p;
    q1=q;
    s=InvOf(p,q,n);
    return (countInv(p1,0,n-1)+countInv(q1,0,n-1)-countInv(s,0,n-1))/2;
}

void findR(vector<int> p, vector<int> s, vector<int> q, vector<int> &r, int n, int i, int j)
{
    vector<int> temp;
    temp=p;
    int mid = (i+j)/2;
    if (i==j)
    {
        return ;
    }
    else
    {
        findR(p,s,q,r,n,i,mid);
        findR(p,s,q,r,n,mid+1,j);

        int x=i,y=mid+1,z=i;
        while (true)
        {
            if (p[x]>p[y])
            {
                if (q[s[x]]<=q[s[y]])
                {
                    r[z]=p[x];
                    temp[z++]=p[x++];
                }
                else
                {
                    r[z]=p[y];
                    temp[z++]=p[y++];
                }
            }
            else if (p[x]<=p[y])
            {
                r[z]=p[x];
                temp[z++]=p[x++];
            }
            if (y==j+1)
            {
                while (x!=mid+1)
                {
                    r[z]=p[x];
                    temp[z++]=p[x++];
                }
                break;
            }
            else if (x==mid+1)
            {
                while (y!=j+1)
                {
                    r[z]=p[y];
                    temp[z++]=p[y++];
                }
                break;
            }
        }
        p=temp;
        return ;
    }
}

void checkR (vector<int> p, vector<int> q, vector<int> &r, int n)
{
    vector<int> s,p1,q1;
    s.resize(n);
    r.resize(n);
    p1=p;
    q1=q;
    int i,j;
    for (i=0;i<n;i++)
    {
        j=q[i];
        s[j]=i;
    }
    findR(p1,s,q1,r,n,0,n-1);
    p1=p;
    q1=q;
    vector<int> r1=r;
    if (countInv(r1,0,n-1)==common(p1,q1,n))
    {
        cout << "consistent";
        cout << "\n";
        for (i=0;i<n;i++)
        {
            cout << r[i] << " " ;
        }
    }
    else
    {
        cout << "inconsistent";
    }
}

int main()
{
    int n,i,t;
    vector<int> p;
    vector<int> q;
    vector<int> r;
    cin >> n;
    p.resize(n);
    q.resize(n);
    for (i=0;i<n;i++)
    {
        cin >> t;
        p[i]=t;
    }
    for (i=0;i<n;i++)
    {
        cin >> t;
        q[i]=t;
    }

    checkR(p,q,r,n);
    return 0;
}

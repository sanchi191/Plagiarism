#include<iostream>

using namespace std;

int flag=0;

class ranks
{
public:
    int a;
    int b;
    int c;
    bool operator<(const ranks& x)
    {
        if (((this->a)<x.a&&(this->b)<x.b)||((this->c)<x.c&&(this->b)<x.b)||((this->a)<x.a&&(this->c)<x.c))
        {
            return true;
        }
        return false;
    }
    void operator=(const ranks& x)
    {
        this->a=x.a;
        this->b=x.b;
        this->c=x.c;
        return ;
    }

};

int mergefind(ranks *a,int low,int high,int mid,int now);
int mergefind(int *a,int low,int high,int mid,int now);
int mergecheck(ranks *a,int *p,int low,int high,int mid,int now);
int mergesortfind(ranks *a,int low,int high)
{
    int mid,val=0;
    if (low < high)
    {
        mid=(low+high)/2;
        val += mergesortfind(a,low,mid);
        val += mergesortfind(a,mid+1,high);
        return mergefind(a,low,high,mid,val);
    }
    return 0;
}

int mergesortcheck(ranks *a,int *p,int low,int high)
{
    int mid,val=0;
    if (low < high)
    {
        mid=(low+high)/2;
        val += mergesortcheck(a,p,low,mid);
        val += mergesortcheck(a,p,mid+1,high);
        return mergecheck(a,p,low,high,mid,val);
    }
    return 0;
}

int mergecheck(ranks *a,int *p, int low, int high, int mid,int now)
{
    int i, j, k, n, *c,val=0,min1,min2;
    i = low;
    k = low;
    j = mid + 1;
    n = high - low + 10;
    c = new int[n];
    min1=n;
    min2=n;
    while (i <= mid && j <= high)
    {
        if (p[i]< p[j])
        {
            if (a[p[i]-1].a<=min1&&a[p[i]-1].b<=min2)
            {
                min1=n;
                min2=n;
            }
            else
            {
                flag=1;
            }
            c[k]= p[i];
            k++;
            i++;
        }
        else
        {
            val += mid - i +1;
            c[k]= p[j];
            k++;
            j++;
            if (a[p[j]-1].a<min1)
            {
                min1=a[p[j]-1].a;
            }
            if (a[p[j]-1].b<min2)
            {
                min2=a[p[j]-1].b;
            }
        }
    }
    while (i <= mid)
    {
        c[k]= p[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k]= p[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        p[i]= c[i];
    }
    return (val + now);
}



int mergefind(ranks *a, int low, int high, int mid,int now)
{
    int i, j, k, n,val=0;
    i = low;
    k = low;
    j = mid + 1;
    n = high - low + 10;
    ranks c[n];
    while (i <= mid && j <= high)
    {
        if (a[i]< a[j])
        {
            c[k]= a[i];
            k++;
            i++;
        }
        else
        {
            val += mid - i +1;
            c[k]= a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k]= a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k]= a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i]= c[i];
    }
    return (val + now);
}

int mergesortfind(int *a,int low,int high)
{
    int mid,val=0;
    if (low < high)
    {
        mid=(low+high)/2;
        val += mergesortfind(a,low,mid);
        val += mergesortfind(a,mid+1,high);
        return mergefind(a,low,high,mid,val);
    }
    return 0;
}


int mergefind(int *a, int low, int high, int mid,int now)
{
    int i, j, k,*c, n,val=0;
    i = low;
    k = low;
    j = mid + 1;
    n = high - low + 10;
    c = new int[n];
    while (i <= mid && j <= high)
    {
        if (a[i]< a[j])
        {
            c[k]= a[i];
            k++;
            i++;
        }
        else
        {
            val += mid - i +1;
            c[k]= a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k]= a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k]= a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i]= c[i];
    }
    return (val + now);
}


int main()
{
    int n,*p,*q,*r,*s,*ris,invr=0,invp=0,invq=0,invs=0;
    cin>>n;
    ranks a[n];
    p = new int[n];
    q = new int[n];
    r = new int[n];
    s = new int[n];
    ris = new int[n];
    for (int i=0; i<n; i++)
    {
        cin>>p[i];
        r[i]=p[i];
        a[p[i]-1].a=i+1;
        a[i].c=i+1;
    }

    for (int i=0; i<n; i++)
    {
        cin>>p[i];
        q[i]=p[i];
        a[p[i]-1].b=i+1;
    }
    for (int i=0; i<n; i++)
    {
        s[i]=a[q[i]-1].a-1;
    }
    mergesortfind(a,0,n-1);
    for (int i=0; i<n; i++)
    {
        ris[i]=a[i].c;
    }
    invr=mergesortcheck(a,ris,0,n-1);
    invp=mergesortfind(r,0,n-1);
    invq=mergesortfind(q,0,n-1);
    invs=mergesortfind(s,0,n-1);
    if (invr!=(invq+invp-invs)/2)
    {
        flag=1;
    }
    if (flag==1)
    {
    cout<<"inconsistent"<<endl;
    }
    else
    {
        cout<<"consistent"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i].c<<" ";
        }
    }
}

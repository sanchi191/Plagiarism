#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<int> invp;
vector<int> invq;
vector<int> r;
vector<int> p;
vector<int> q;
vector<int>perm;
vector<int> inverse_r;
int count_inv=0;
int flag=1;
int var1,var2,var3;
bool compare(int a,int b)
{   int count=0;
    if(invp[a-1]<invp[b-1])
        count++;
    if(a<b)
        count++;
    if(invq[a-1]<invq[b-1])
    count++;
    if(count>=2)
        return true;
    else
        return false;
}

void merge(vector<int> ,int, int , int );
void mergesort(vector<int> a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(vector<int> a, int low, int high, int mid)
{
    int i, j, k,trac1=INT_MAX,trac2=INT_MAX;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i]<a[j])
        {
            perm[k] = a[i];
            k++;
            i++;
            if(invp[a[i]-1]<trac1&&invq[a[i]-1]<trac2)
            {
            }
            else
            {
            var1=a[i];
            var2=a[j];
            flag=0;
            return;
            }

        }
        else
        {
            if(invp[a[i]-1]<invp[a[j]-1]&&invq[a[i]-1]<invq[a[j]-1])
            {
            }
            else
            {
            var1=a[i];
            var2=a[j];
            flag=0;
            return;
            }
            trac1=min(trac1,invp[a[j]-1]);
            trac2=min(trac2,invq[a[j]-1]);
            perm[k] = a[j];
            k++;
            j++;
        }

    }
    while (i <= mid)
    {
        perm[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        perm[k] = a[j];
        k++;
        j++;
    }
     for (i = low; i < k; i++)
    {
        a[i] = perm[i];
    }
}
void merge1(vector<int> a, int low, int high, int mid);
void mergesort1(vector<int> a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort1(a,low,mid);
        mergesort1(a,mid+1,high);
        merge1(a,low,high,mid);
    }
    return;
}
void merge1(vector<int> a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            perm[k] = a[i];
            k++;
            i++;
        }
        else
        {
        count_inv+=mid-i+1;
            perm[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        perm[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        perm[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = perm[i];
    }
}
int main()
{

int n ;
scanf("%d",&n);
invp.resize(n,0);
invq.resize(n,0);
p.resize(n,0);
q.resize(n,0);
r.resize(n,0);
perm.resize(n,0);
inverse_r.resize(n,0);
vector<int> invpq(n,0);

for(int i=0;i<n;i++)
{
    scanf("%d",&p[i]);
}
for(int i=0;i<n;i++)
{
    scanf("%d",&q[i]);
}
for(int i=0;i<n;i++)
{
    invp[p[i]-1]=i+1;
}
for(int i=0;i<n;i++)
{
    invq[q[i]-1]=i+1;
    r[i]=i+1;
    invpq[i]=invp[q[i]-1];
}

    sort(r.begin(),r.end(),compare);
    //for(int i=0;i<n;i++)
      //  cout<<r[i]<<"    ";
    //cout<<endl;
    for(int i=0;i<n;i++)
{
    inverse_r[r[i]-1]=i+1;
}
    vector<int>temp;
    temp=r;
    mergesort(temp,0,n-1);
    if(flag==1)
    {
        int x,y,z,t;
        temp=r;
        mergesort1(temp,0,n-1);
        t=count_inv;
        count_inv=0;
        mergesort1(p,0,n-1);
        x=count_inv;
        count_inv=0;
        mergesort1(q,0,n-1);
        y=count_inv;
        count_inv=0;
        mergesort1(invpq,0,n-1);
        z=count_inv;
        count_inv=0;//cout<<x<<"  "<<y<<"    "<<z;
        if((x+y-z)==t*2)
        {
            printf("consistent\n");
            for(int i=0;i<n;i++)
            {
                printf("%d ",r[i]);
            }
            cout<<endl;
        }
        else
        {
            printf("inconsistent\n");
        }
    }
    else
    {
            int lower=inverse_r[var1-1];
            int upper=inverse_r[var3-1];
            int maxi,mini,tempo;
            tempo=lower;
            mini=min(lower,upper);
            maxi=max(tempo,upper);
            var1=mini;
            var3=maxi;
            while(mini<maxi)
            {
                if(r[mini+1]<r[maxi])
                {
                    var1=mini;
                    var2=mini+1;
                    break;
                }
                mini++;
            }
            printf("inconsistent\n");
            printf("%d %d %d",var1,var2,var3);
    }

}

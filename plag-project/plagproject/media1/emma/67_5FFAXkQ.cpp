#include<iostream>
using namespace std;

int n,index=0,l=0,noc=0,noi=0,noa=0,nob=0;
int *p=new int[n];
int *q=new int[n];
int *r=new int[n];
int *A=new int[n];
int *B=new int[n];
int *obt=new int[n];
int *ex=new int[n];

bool check(int a,int b)
{
    int ina=0,inb=0,inc=0;
    if(a<b)
    {
        inc=1;
    }
    if(A[a]<A[b])
    {
        ina=1;
    }
    if(B[a]<B[b])
    {
        inb=1;
    }
    if(ina+inb+inc>=2)
    {
        return true;
    }
    else
        return false;
}

void newmerge(int low,int mid,int high)
{
    int h,i,j,k,b[high-low+1];
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high))
    {
        if(check(r[h],r[j]))
        {
            b[i]=r[h];
            h++;
        }
        else
        {
            b[i]=r[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=r[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            b[i]=r[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) r[k]=b[k];
}



void newmergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low)+(high-low)/2;
        newmergesort(low,mid);
        newmergesort(mid+1,high);
        newmerge(low,mid,high);
    }
    return;
}

void new_merge(int low,int mid,int high)
{
    int h,i,j,k,b[high-low+1];
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high))
    {
        if(r[h]>r[j])
        {
            if(A[r[h]]>A[r[j]]||B[r[h]]>B[r[j]])
            {
                ex[l]=r[h];
                l++;
                ex[l]=r[j];
                l++;
                index=10;
            }
            else
            {
                noc++;
            }
            b[i]=r[h];
            h++;

        }
        else
        {
            b[i]=r[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=r[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            b[i]=r[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) r[k]=b[k];
    return ;
}

void new_mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low)+(high-low)/2;
        new_mergesort(low,mid);
        new_mergesort(mid+1,high);
        new_merge(low,mid,high);
    }
    return ;
}



int main()
{

    cin>>n;
    int x=0;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
        A[p[i]]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        cin>>q[i];
        B[q[i]]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        r[i]=i+1;
    }
    newmergesort(0, n-1);
    for(int i=0; i<n; i++)
    {
        obt[i]=r[i];
    }
    new_mergesort(0,n-1);
    if(index==0)
    {
        cout<<"consistent"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<obt[i]<<" ";
        }
    }
    else
    {
        cout<<"inconsistent"<<endl;

    }

}

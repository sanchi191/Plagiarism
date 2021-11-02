#include<iostream>
using namespace std;
// function 'bool lt()' is equivalent to operator overloading of '<'
bool lt(int i,int j,int a1[],int b1[],int c1[])
{
    int p=0;
    if(a1[i]<a1[j])
    {
        p++;
    }
    if(b1[i]<b1[j])
    {
        p++;
    }
    if(c1[i]<c1[j])
    {
        p++;
    }
    if(p>=2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void mergearrays(int A[],int a1[],int b1[],int c1[],int start,int mid,int end)
{
    int i,j;
    int temp[end];
    int index=start;
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {
        if ((i < mid) && (j < end))   // None of the two subarrays fully seen yet
        {
            if (lt(A[i],A[j],a1,b1,c1))
            {
                temp[index] = A[i];
                i++;
            }
            else
            {
                temp[index] = A[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                temp[index] = A[i];    // A[mid] … A[end-1] seen
                i++;
            }
            else
            {
                temp[index] = A[j];    // A[start] … A[mid-1] seen
                j++;
            }
        }
        index ++;
    }
    for(int i=start; i<end; i++)
    {
        A[i]=temp[i];
    }
}

void mergesort(int A[],int a1[],int b1[],int c1[],int start,int end)
{
    if(end==start+1)
    {
        return;
    }
    int mid=(start+end)/2;
    mergesort(A,a1,b1,c1,start,mid);
    mergesort(A,a1,b1,c1,mid,end);
    mergearrays(A,a1,b1,c1,start,mid,end);
    return;
}


int main()
{
    int n;
    cin>>n;
    int a[n],b[n],c[n],a1[n],b1[n],c1[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a1[a[i]]=i;
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
        c[i]=i+1;
        b1[b[i]]=i;
        c1[c[i]]=i;
    }
    cout<<endl;
    mergesort(c,a1,b1,c1,0,n);
    int p=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(!(lt(c[i],c[j],a1,b1,c1)))
            {
                p++;
                cout<<"inconsistent";
                cout<<endl;
                cout<<c[i]<<" "<<c[i+1]<<" "<<c[j];
                break;
            }
        }
    }
    if(p!=1)
    {
        cout<<"consistent";
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<c[i]<<" ";
        }
    }

    return 0;
}

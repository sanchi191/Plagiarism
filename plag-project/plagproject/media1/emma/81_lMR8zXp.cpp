#include<iostream>
using namespace std;
int merged(int *A,int low,int mid, int high,int *B,int *C)
{
    int temp[high];
    int i=low,j=mid+1,index=low;
    while( i<=mid)
    {
        if(i<=mid && j<=high)
        {
            int cnt=0;
            if(B[i]<B[j])cnt++;
            if(C[i]<C[j])cnt++;
            if(cnt>=1)
            {
                temp[index]=A[i];
                index++;
                i++;
            }
            else
            {
                return -1;
            }
        }
    }
    for(index; index<high; index++)
    {
        temp[index]=A[j];
        j++;
    }
    for(int p=low; p<index; p++)
    {
        A[p]=temp[p];
    }
    return 0;
}
int msort(int* A,int low, int high,int *B,int *C)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        msort(A,low,mid,B,C);
        msort(A,mid+1,high,B,C);
        if(merged(A,low,mid,high,B,C)==0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}
int merge(int *A,int low,int mid, int high,int & invcnt)
{
    int temp[high];
    int i=low,j=mid+1,index=low;
    while( i<=mid || j<=high)
    {
        if(i<=mid && j<=high)
        {
            if(A[i]<=A[j])
            {
                temp[index]=A[i];
                index++;
                i++;
            }
            else
            {
                invcnt=invcnt+mid+1-i;
                temp[index]=A[j];
                index++;
                j++;
            }
        }
        else
        {
            if(i<=mid)
            {
                temp[index]=A[i];
                index++;
                i++;
            }
            else
            {
                temp[index]=A[j];
                index++;
                j++;
            }
        }
    }
    for(int p=low; p<index; p++)
    {
        A[p]=temp[p];
    }
    return invcnt;
}
int mergesort(int* A, int low, int high,int &ans)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(A,low,mid,ans);
        mergesort(A,mid+1,high,ans);
        merge(A,low,mid,high,ans);
    }
    return ans;
}
int main()
{
    int n,icountA,icountB,icountR,icountS;
    cin>>n;
    int A[n],B[n],C[n],S[n],R[n],inverseA[n],inverseB[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
        inverseA[A[i]-1]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        cin>>B[i];
        inverseB[B[i]-1]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        C[i]=i+1;
        R[i]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        S[i]=inverseB[A[i]-1];
    }
    int num=0;
    icountA=mergesort(A,0,n-1,num);
    num=0;
    icountB=mergesort(B,0,n-1,num);
    num=0;
    icountR=mergesort(R,0,n-1,num);
    num=0;
    icountS=mergesort(S,0,n-1,num);
    if(msort(C,0,n-1,inverseA,inverseB)==0 && ((icountA+icountB-icountS)/2 ==icountR) )
    {
        cout<<"consistent"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<C[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"inconsistent"<<endl;
    }
    return 0;
}

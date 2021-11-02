#include <iostream>
using namespace std;
int count=0;
int count2=0;
class integer
{
public:
    int value;
    integer* add;
};
void swap(integer A[],int a, int b)
{
    int tmp = A[a].add->value;
    A[a].add->value=A[b].add->value;
    A[b].add->value=tmp;
    A[a].add=&A[b];
    A[b].add=&A[a];
}
void merge(int A[],int start, int end,integer I[],int RQ[])
{
    int C[end-start];
    int mid=(start+end)/2;
    int j=mid;
    int i=start;
    int k=0;
    while(i<mid&&j<end)
    {
        if(A[i]>A[j])
        {
            count2=count2+mid-i;
            C[k]=A[j];
            for(int a=i; a<mid; a++)
            {
                if(RQ[A[i]-1]<RQ[A[j]-1])
                {
                    swap(I, A[a]-1,A[j]-1);
                    count++;
                }
            }
            k++;
            j++;
        }
        else
        {
            C[k]=A[i];
            k++;
            i++;
        }
    }
    while(i<mid)
    {
        C[k]=A[i];
        i++;
        k++;
    }
    while(j<end)
    {
        C[k]=A[j];
        j++;
        k++;
    }
    for(int i=start,t=0; i<end; i++,t++)
    {
        A[i]=C[t];
    }
}
void mergesort(int A[], int start, int end,integer I[],int RQ[])
{
    if(end==start+1)
    {
        return;
    }
    int mid = (start+end)/2;
    mergesort(A,start,mid,I,RQ);
    mergesort(A,mid, end,I,RQ);
    merge(A,start, end,I,RQ);
}
int main()
{
    int n;
    cin>>n;
    int P[n];
    int Q[n];
    int RQ[n];
    for(int i=0; i<n; i++)
    {
        cin>>P[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>Q[i];
        RQ[Q[i]-1]=i;
    }

    integer R[n];
    for(int i=0; i<n; i++)
    {
        R[i].value=i+1;
        R[i].add=&R[i];
    }
    mergesort(P,0,n,R,RQ);

    count2=0;
    int L[n];
    for(int i=0; i<n; i++)
    {
        L[i]=R[i].value;
    }
    mergesort(L,0,n,R,RQ);
    if(count==count2)
    {
        cout<<"consistent"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<R[i].value<<" ";
        }
    }
    else
    {
        cout<<"inconsistent"<<endl;
    }
}

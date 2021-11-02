#include<iostream>
using namespace std;
void merge_sort(int A[],int n,int B[],int p){
if(n==1){
A[0]=A[0];
return;}
else{
    int l,r;
    if(n%2==0)
    {
        l=n/2;
        r=n/2;
    }
    else
    {
        l=n/2+1;
        r=n/2;
    }
    int L[l],R[r];
    for(int k=0;k<l;k++)
    {
        L[k]=A[k];
    }
    for(int k=0;k<r;k++)
    {
        R[k]=A[l+k];
    }

    if((l==1)&&(r==1))
    {
        if(L[0]<R[0])
        {
            A[0]=L[0];
            A[1]=R[0];
        return;
        }
        if(L[0]>R[0])
        {
            if(B[L[0]-1]<B[R[0]-1])
            {
                A[0]=L[0];
                A[1]=R[0];

            }
            if(B[L[0]-1]>B[R[0]-1])
            {
                A[0]=R[0];
                A[1]=L[0];
            }
        return;
        }
    }
    else
    {
        merge_sort(L,l,B,p);
        merge_sort(R,r,B,p);
        int m=0;
        int e=0;
        for(m=0,e=0;((m<l)||(e<r));)
        {
            if((m<l)&&(e<r))
            {
                if(L[m]<R[e])
                {
                    A[m+e]=L[m];
                    m++;
                }
                if(L[m]>R[e])
                {
                    if(B[L[m]-1]<B[R[e]-1])
                    {
                        A[m+e]=L[m];
                        m++;
                    }
                    if(B[L[m]-1]>B[R[e]-1])
                    {
                        A[m+e]=R[e];
                        e++;
                    }
                }
            }
            else
            {
                if(m==l)
                {
                    A[m+e]=R[e];
                    e++;
                }
                if(e==r)
                {
                    A[m+e]=L[m];
                    m++;
                }
            }
        }
        return;

    }
    }
}
int main()
{
    int n;
    cin>>n;
    int P1[n],P2[n];
    int P3[n],P4[n];
    for(int k=0;k<n;k++)
    {
        int j;
        cin>>j;
        P1[k]=j;
        P3[j-1]=k;
    }
    for(int k=0;k<n;k++)
    {
        int j;
        cin>>j;
        P2[k]=j;
        P4[j-1]=k;
    }
    merge_sort(P1,n,P4,n);
    merge_sort(P2,n,P3,n);
    for(int o=0;o<n;o++)
    {
        if(P1[o]!=P2[o])
        {
            cout<<"inconsistent"<<endl;
            return 0;
        }
    }
}

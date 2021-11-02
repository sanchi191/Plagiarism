#include<iostream>
#include<vector>
using namespace std;

bool Less(int a,int b,int A1[],int B1[],int C1[])
{
    int count=0;
    if(A1[a]<A1[b])
    {
        count++;
    }
    if(B1[a]<B1[b])
    {
        count++;
    }
    if(C1[a]<C1[b])
    {
        count++;
    }
    if(count>1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Merge(int A[],int start,int mid,int end1,int A1[],int B1[],int C1[])
{
    int i=0,j=0,k=0;
    int *temp;
    temp = new int[end1];
    int index = start;
    for (int i=start,j=mid; i<mid || j<end1;)
    {
        if((i<mid) && (j<end1))
        {
            if(Less(i,j,A1,B1,C1))
            {
                temp[index]=A[i];
                i++;
            }
            else
            {
                temp[index]=A[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
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
        index++;
    }
    for(int i=start; i<end1; i++)
    {
        A[i]=temp[i];
    }
}

void Merge_Sort(int A[],int start,int end1,int A1[],int B1[],int C1[])
{
    if(end1==(start+1))
    {
        return ;
    }
    int mid=(start+end1)/2;
    Merge_Sort(A,start,mid,A1,B1,C1);
    Merge_Sort(A,mid,end1,A1,B1,C1);
    Merge(A,start,mid,end1,A1,B1,C1);
};

int main()
{
    int n;
    cin>>n;
    int *A,*B,*C,*P,*A1,*B1,*C1;
    A = new int[n];
    B = new int[n];
    C = new int[n];
    P = new int[n];
    A1 = new int[n];
    B1 = new int[n];
    C1 = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
        A[i]--;
        A1[A[i]]=i;
    }
    for(int i=0; i<n; i++)
    {
        cin>>B[i];
        B[i]--;
        B1[B[i]]=i;
        C[i]=i;
        P[i]=i;
        C1[C[i]]=i-1;
    }
    Merge_Sort(P,0,n,A1,B1,C1);
    bool p=true,q=true;
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(Less(P[i],P[j],A1,B1,C1))
            {
                ;
            }
            else
            {
                p=false;
                break;
            }
        }
        if(!p)
        {
            break;
        }
    }
    for(k=i+1; k<j-1; k++)
    {
            if(Less(P[i],P[k],A1,B1,C1) && Less(P[k],P[j],A1,B1,C1))
            {
                q=false;
                break;
            }
    }
    if (p==true)
    {
        cout<<endl<<"consistent"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<(P[i]+1)<<" ";
        }
    }
    else
    {
        cout<<"inconsistent"<<endl;
        cout<<P[i]+1<<" "<<P[k]+1<<" "<<P[j]+1;
    }
    return 0;
}

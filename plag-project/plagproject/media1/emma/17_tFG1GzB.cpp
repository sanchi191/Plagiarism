#include<iostream>
using namespace std;
int n=0;

bool islessthan(int CP[],int CQ[],int i,int j)
{
    if(i<j)
    {
        if((CP[i]<CP[j]) || (CQ[i]<CQ[j]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if((CP[i]>CP[j]) || (CQ[i]>CQ[j]))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
void mergeinverseform(int A[],int CP[],int CQ[], int start, int mid, int end)
{
    int i, j;
    int tempA[n+1];
    int index = start;
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {
        if ((i < mid) && (j < end))
        {
            if ((CP[A[j]] > CP[A[i]]) || (CQ[A[j]] > CQ[A[i]]))
            {
                tempA[index] = A[i];
                i++;
            }
            else
            {
                tempA[index] = A[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = A[i];
                i++;
            }
            else
            {
                tempA[index] = A[j];
                j++;
            }
        }
        index ++;
    }
    for (i = start; i < end; i++)
    {
        A[i] = tempA[i];
    }
    return;
}

void inverseform(int A[],int CP[],int CQ[],int start,int end)
{
    if (end == start +1)
    {
        return;
    }
    int mid = (start + end)/2;
    inverseform(A,CP,CQ,start,mid);
    inverseform(A,CP,CQ,mid,end);
    mergeinverseform(A,CP,CQ, start, mid, end);
    return;
}


void inverseform(int A[],int CP[],int CQ[],int start,int end);
void mergeinverseform(int A[],int CP[],int CQ[], int start, int mid, int end);

int main()
{
    cin>>n;
    int *P=new int [n+1];
    int *CP=new int [n+1];
    int *Q=new int [n+1];
    int *CQ=new int [n+1];
    int *R=new int [n+1];
    int *A=new int [n+1];
    for (int i = 0; i < n; i++)
    {
        cin>>P[i+1];
        CP[P[i+1]]=i+1;

    }
    for (int i = 0; i < n; i++)
    {
        cin>>Q[i+1];
        CQ[Q[i+1]]=i+1;
    }
    for (int i = 0; i < n; i++)
    {
        R[i+1]=i+1;
        A[i+1]=i+1;

    }
    inverseform(A,CP,CQ,1, n+1);
    int i;
    int c=0;
    for( i=1; i<n+1; i++)
    {
        for(int j=i+2; j<n+1; j++)
        {
            if(islessthan(CP,CQ,A[i],A[j]))
            {
                continue;
            }
            else
            {
                cout<<"inconsistent"<<endl;
                cout<<A[i]<<" "<<A[j-1]<<" "<<A[j];  // because A[i] is consistent with A[j-1] and A[j-1] is
                //consistent with A[j] but A[i] and A[j] are inconsistent.
                c=-1;
                break;
            }
        }
        if(c==-1)
        {
            break;
        }
    }
    if(i==n+1)
    {
        cout<<"consistent"<<endl;
        for (int i = 1; i < n+1; i++)
        {
            cout<<A[i]<<" ";
        }
    }
    return 0;
}

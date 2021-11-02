#include<iostream>
using namespace std;
bool lessthan(int* IA,int* IB,int i,int j)
{
    if(i<j)
    {
        if(IA[i]<IA[j]||IB[i]<IB[j])
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
        if(IA[i]>IA[j]||IB[i]>IB[j])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
void mergeSortedSubarrays(int* X,int* IA,int* IB, int start, int mid, int last)
{
    int tempX[last-start+1],i,j,index=start;
    for (i = start, j = mid; ((i < mid) || (j < last)); )   // Merging loop
    {
        if ((i < mid) && (j < last))   // None of the two subarrays fully seen yet
        {
            if (lessthan(IA,IB,X[i],X[j]))
            {
                tempX[index] = X[i];
                i++;
            }
            else
            {
                tempX[index] = X[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempX[index] = X[i];    // A[mid] … A[last-1] seen
                i++;
            }
            else
            {
                tempX[index] = X[j];    // A[start] … A[mid-1] seen
                j++;
            }
        }
        index ++;
    }
    for(int k=start; k<last; k++)
    {
        X[k]=tempX[k];
    }
}
void mergeSort(int* X,int* IA, int* IB, int start, int last)
{
    if (last == start +1)
    {
        return;    //Subarray of interest has 1 element
    }
    int mid = (start + last)/2; //Get mid-index of subarray of interest
    mergeSort(X,IA,IB, start, mid); // Sort subarray A[start] … A[mid-1]
    mergeSort(X,IA,IB, mid, last); // Sort subarray A[mid] … A[last-1]
    // Merge sorted subarrays A[start] … A[mid-1] and A[mid] … A[last-1]
    mergeSortedSubarrays(X,IA,IB, start, mid, last);
    return;
}

int main()
{
    int n;
    cin>>n;
    int A[n+1],B[n+1];
    int IA[n+1],IB[n+1];
    int X[n+1];
    for(int i=1; i<n+1; i++)
    {
        cin>>A[i];
        IA[A[i]]=i;
        X[i]=i;

    }
    for(int i=1; i<n+1; i++)
    {
        cin>>B[i];
        IB[B[i]]=i;
    }
    mergeSort(X,IA,IB,1,n+1);
    int i;
    for( i=1; i<n+1; i++)
    {
        int c=0;
        for(int j=2; i+j<n+1; j++)
        {
            if(lessthan(IA,IB,X[i],X[i+j]))
            {
                continue;
            }
            else
            {
                cout<<"inconsistent"<<endl;
                cout<<X[i]<<" "<<X[i+j-1]<<" "<<X[i+j];
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
        for(int k=1;k<n+1;k++)
        {cout<<X[k]<<" ";}
    }

}

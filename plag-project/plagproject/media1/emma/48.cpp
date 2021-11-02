#include<iostream>
using namespace std;

bool check(int i,int j,int * ai,int * bi)
{
if(i<j)
{
if(ai[i]<ai[j]||bi[i]<bi[j]){return true;}
else{return false;}
}
if(i>j)
{
if(ai[i]>ai[j]||bi[i]>bi[j]){return false;}
else{return true;}
}
}


void mergeSortedSubarrays(int * A, int start, int mid, int end,int * ai,int *bi)
{
    int i, j;
    int index = 0,x=end-start;
    int * tempA;
    tempA = new int[x];
    for (i = start, j = mid; ((i < mid) || (j < end)); )   // Merging loop
    {
        if ((i < mid) && (j < end))   // None of the two subarrays fully seen yet
        {

            if (check(A[i],A[j],ai,bi))
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
                tempA[index] = A[i];    // A[mid] … A[end-1] seen
                i++;
            }
            else
            {
                tempA[index] = A[j];    // A[start] … A[mid-1] seen
                j++;
            }
        }
        index ++;
    }
    for (i = 0; i < end-start; i++)
    {
        A[i+start] = tempA[i];
    }
    return;
}


void mergeSort(int* A, int start, int end,int * ai,int *bi)
{
    if (end == start +1)
    {
        return;    //Subarray of interest has 1 element
    }
    int mid = (start + end)/2; //Get mid-index of subarray of interest
    mergeSort(A, start, mid,ai,bi); // Sort subarray A[start] … A[mid-1]
    mergeSort(A, mid, end,ai,bi); // Sort subarray A[mid] … A[end-1]
// Merge sorted subarrays A[start] … A[mid-1] and A[mid] … A[end-1]
    mergeSortedSubarrays(A, start, mid, end,ai,bi);
    return;
}

int main()
{
    int n;
    cin>>n;

    int * a;
    a=new int[n+1];
    int * b;
    b=new int[n+1];
    int * ai;
    ai=new int[n+1];
    int * bi;
    bi=new int[n+1];
    int * A;
    A = new int[n+1];
    for(int i=1; i<n+1; i++)
    {
        cin>>a[i];
        ai[a[i]]=i;
    }
    for(int i=1; i<n+1; i++)
    {
        cin>>b[i];
        bi[b[i]]=i;
        A[i]=i;
    }

    mergeSort(A, 1, n+1,ai,bi); // Sort elements A[0] … A[n-1]

    int l=0;
    for(int i=1;i<n+1;i++)
    {

    for(int j=i+1;j<n+1;j++)
    {
    if(!check(A[i],A[j],ai,bi))
    {
    cout<<"inconsistent"<<endl;
    cout<<A[i]<<" "<<A[j-1]<<" "<<A[j];
    l=1;
    break;
    }
    }

   if(l==1){break;}
    }

    if(l!=1)
    {
    cout<<"consistent"<<endl;
    for(int i=1; i<n+1; i++)
    {
        cout<<A[i]<<" ";
    }
    }

    return 0;
}


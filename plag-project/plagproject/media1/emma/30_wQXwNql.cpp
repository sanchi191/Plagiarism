#include<iostream>
using namespace std;
int n;
void mergeSortedSubarrays(int p[], int qinv[],int start, int mid, int end);
void mergeSort(int p[],int qinv[], int start, int end)
{
    if (end == start +1)
    {
        return;    //Subarray of interest has 1 element
    }
    int mid = (start + end)/2; //Get mid-index of subarray of interest
    mergeSort(p,qinv, start, mid); // Sort subarray A[start] ... A[mid-1]
    mergeSort(p,qinv, mid, end); // Sort subarray A[mid] ... A[end-1]
// Merge sorted subarrays A[start] ... A[mid-1] and A[mid] ... A[end-1]
    mergeSortedSubarrays(p,qinv,start, mid, end);
    return;
}
void mergeSortedSubarrays(int p[], int qinv[],int start, int mid, int end)
{
    int i, j;
    int * tempA = new int [end-start],
    index = 0;
    int leftmost = n+2;
    int rightnum;
    int leftnum;
    for (i = start, j = mid; ((i < mid) || (j < end)); )   // Merging loop
    {
        if ((i < mid) && (j < end))   // None of the two subarrays fully seen yet
        {
            if (p[i]<p[j])
            {
                leftnum = p[i];
                if(qinv[leftnum]<leftmost)
                {
                    //skip
                    cout<<"true1"<<endl;
                }
                else
                {
                    cout<<qinv[leftnum]<<leftmost<<n<<endl;
                    cout<<"false1"<<endl;
                }
                tempA[index] = p[i];
                i++;
            }
            else
            {
                rightnum = p[j];
                if(qinv[rightnum]<leftmost)
                {
                    leftmost = qinv[rightnum];
                }
                tempA[index] = p[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                rightnum = p[i];
                if(qinv[rightnum]<leftmost)
                {
                    //skip

                    cout<<"true1"<<endl;
                }
                else
                {
                    cout<<"false2"<<endl;
                }
                tempA[index] = p[i];    // A[mid] ... A[end-1] seen
                i++;
            }
            else
            {
                rightnum = p[j];
                if(qinv[rightnum]<leftmost)
                {
                    leftmost = qinv[rightnum];
                }
                tempA[index] = p[j];    // A[start] ... A[mid-1] seen
                j++;
            }
        }
        index ++;
    } // end of merging loop
// Copy tempA[start] ... tempA[end-1] to A[start] ... A[end-1]
    for(int i = 0; i<end-start; i++)
    {
        p[i+start] = tempA[i];
    }
    delete []tempA;
    return;
}

int main()
{
    cin>>n;
    int * p = new int[n+1];
    int * q = new int[n+1];
    for(int i = 1; i<=n; i++)
    {
        cin>>p[i];
    }
    for(int i = 1; i<=n; i++)
    {
        cin>>q[i];
    }
    int * pinv = new int [n+1];
    int * qinv = new int [n+1];
    for(int i = 1; i<=n; i++)
    {
        pinv[p[i]] = i;
        qinv[q[i]] = i;
    }
    mergeSort(p,qinv,1,n+1);
    for(int i = 1; i<=n; i++)
    {
        cout<<p[i];
    }
}

#include <iostream>
using namespace std;
int *A,*B,*C,*rank1,*rank2,*rank3,*S;
int *temp,*temp1;
bool lessthan(int i,int j)
{
    int count=0;
    if(rank1[i]<rank1[j])
    {
        count++;
    }
    if(rank2[i]<rank2[j])
    {
        count++;
    }
    if(rank3[i]<rank3[j])
    {
        count++;
    }
    if(count>=2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (lessthan(arr[i],arr[j]))
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
    return ;
}
void mergeSort(int arr[], int temp[], int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (right + left)/2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid+1, right);
        merge(arr, temp, left, mid+1, right);
    }
    return ;
}
bool invmerge(int arr[],int Q[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int minindex=0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if(arr[j]<minindex)
        {
        return false;
        }
        if(arr[i]>arr[j])
        {
                minindex=Q[arr[j]];
                temp[k++] = arr[j++];
        }
        if (arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
        for (i=left; i <= right; i++)
        arr[i] = temp[i];
    return true;
}
bool inversionpair(int arr[],int Q[],int temp[],int left,int right)
{
    int mid;
    if (right > left)
    {
        mid = (right + left)/2;
        if(inversionpair (arr,Q, temp, left, mid)&&inversionpair(arr, Q,temp, mid+1, right)&&invmerge(arr,Q, temp, left, mid+1, right))
        {
            return true;
        }
        else
            return false;
    }
    return true;
}
int countinvmerge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (lessthan(arr[i],arr[j]))
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i=left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}
int countinv(int arr[], int temp[], int left, int right)
{
    int mid,count=0;
    if (right > left)
    {
        mid = (right + left)/2;
        count= countinv(arr, temp, left, mid);
        count+= countinv(arr, temp, mid+1, right);
        count+=countinvmerge(arr, temp, left, mid+1, right);
    }
    return count;
}
void consistent(int rankf[],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(!lessthan(rankf[i],rankf[j]))
            {
                cout<<i<<j<<endl;
            }
        }
    }
    cout<<"consistent";
    for(int i=0; i<n; i++)
    {
        cout<<rankf[i]<<" ";
    }
    return;
}
void consistent2(int rankf[],int n)
{
int tempr=countinv(rankf,temp,0,n-1);
int tempA=countinv(A,temp,0,n-1);
int tempB=countinv(B,temp,0,n-1);
int tempS=countinv(S,temp,0,n-1);
if(tempr==(tempA+tempB-tempS)/2)
{
    cout<<"consistent"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<rankf[i]<<" ";
    }
}
else
{
cout<<"inconsistent";
}
}
int main()
{
    int n;
    int *rankf;
    cin>>n;
    A=new int[n];
    B=new int[n];
    C=new int[n];
    rankf=new int[n];
    rank1=new int[n+1];
    rank2=new int[n+1];
    rank3=new int[n+1];
    S=new int[n];
    temp=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>B[i];
        C[i]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        rank1[A[i]]=i;
        rank2[B[i]]=i;
        rank3[C[i]]=i;
        rankf[i]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        S[i]=rank1[B[i]];
    }
    mergeSort(rankf,temp,0,n-1);
    consistent2(rankf,n);
    //cout<<inversionpair(B,rank1,temp,0,n-1);
    return 0;
}

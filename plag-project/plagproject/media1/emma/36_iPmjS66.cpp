#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r ,int&N)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];}
    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
}
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            N=N+j;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        N=N+j;

    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r,int &N)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m ,N);
        mergeSort(arr, m+1, r,N);
        merge(arr, l, m, r,N);
    }
}

bool compare(int P[],int Q[],int i,int j){
int c=0;
if(i<j) c++;

if(P[i-1]<P[j-1]) c++;
if(Q[i-1]<Q[j-1]) c++;
if (c>=2) return 1;
else return 0;
}

void ranks( int arr[], int arr1[], int arr2[], int l, int m, int r )
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];}
    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
}
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if ( compare(arr1,arr2,L[i],R[j]) )
        {
            arr[k] = L[i];
            i++;

        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;


    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort2(int arr[], int arr1[], int arr2[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort2(arr,arr1,arr2,l,m );
        mergeSort2(arr,arr1,arr2,m+1,r);
        ranks(arr,arr1,arr2,l,m,r);
    }
}


/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
 void inverse(int a[],int A[],int size)
 {
 int i;
    for (i=0; i < size; i++){
    A[(a[i]-1)]=i+1;
    }

 }



/* Driver program to test above functions */
int main()
{

    int i,n;
    cin>>n;
    int p[n],q[n],s[n];
      for(i=0;i<n;i++)
    {cin>>p[i];
    }
    for(i=0;i<n;i++)
    {cin>>q[i];
    }

    int a=0,b=0,c=0,d=0;
    int f[n];
    for(i=0;i<n;i++)
    {f[i]=n-i;
    }

    int P[n],Q[n];

    inverse(p,P,n);

    inverse(q,Q,n);

    for(i=0;i<n;i++)
    {s[i]=Q[p[i]-1];
    }

    mergeSort2(f,P,Q,0,n-1);
    mergeSort(s,0,n-1,a);
    mergeSort(p,0,n-1,b);
    mergeSort(q,0,n-1,c);
    mergeSort(f,0,n-1,d);
    mergeSort2(f,P,Q,0,n-1);


       if((b+c-a==2*d)){
       cout<<"consistent"<<endl;;
        printArray(f,n);
       }
      else{
      cout<<"inconsistent"<<endl;}




    return 0;
}

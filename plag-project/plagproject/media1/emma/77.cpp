#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

bool compare(int invP1[], int invP2[], int i, int j);

void mCount(int arr[], int l, int m, int r, int &inv)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inv = inv + (n1-i);
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mSCount(int arr[], int l, int r, int &inv)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mSCount(arr, l, m, inv);
        mSCount(arr, m+1, r, inv);
        mCount(arr, l, m, r, inv);
    }
}

void mfindR(int arr[], int invP1[], int invP2[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (compare(invP1, invP2, L[i], R[j]))
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

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mSfindR(int arr[], int invP1[], int invP2[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mSfindR(arr, invP1, invP2, l, m);
        mSfindR(arr, invP1, invP2, m+1, r);
        mfindR(arr, invP1, invP2, l, m, r);
    }
}

void invarr(int arr[], int invarr[], int size) {
    for(int i=0;i<size;i++) {
        invarr[arr[i]-1]=i+1;
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++) cout<<A[i]<<" ";
    printf("\n");
}

bool compare(int invP1[], int invP2[], int i, int j) {
int c=0;

if(i<j) c++;
if(invP1[i-1]<invP1[j-1]) c++;
if(invP2[i-1]<invP2[j-1]) c++;

if(c>=2) {return true;}
else {return false;}
}

int main()
{
    int invp=0; int invq=0; int invr=0; int invs=0;
    int I,J,K;
    int intsec;
    int n,i;
    cin>>n;
    int P1[n], P2[n], P3[n], R[n];
    for(i=0;i<n;i++) {
    P3[i]=i+1;
    }
    for(i=0;i<n;i++) {
    cin>>P1[i];
    }
    for(i=0;i<n;i++) {
    cin>>P2[i];
    R[i]=P2[i];
    }
    int invP1[n], invP2[n], s[n];
    invarr(P1, invP1, n);
    invarr(P2, invP2, n);
    for(i=0;i<n;i++) {
    s[i]=invP2[P1[i]-1];
    }
    mSCount(P1, 0, n-1, invp);
    mSCount(P2, 0, n-1, invq);
    mSCount(s, 0, n-1, invs);
    mSfindR(R, invP1, invP2, 0, n-1);
    mSCount(R, 0, n-1, invr);
    mSfindR(R, invP1, invP2, 0, n-1);
    intsec=(invp+invq-invs);
    if(2*invr==intsec) {
    cout<<"consistent"<<endl;
        for(i=0;i<n;i++) {
        cout<<R[i]<<" ";
        }
    }
    else {
    cout<<"inconsistent";
    }
    return 0;
}

#include<iostream>
#include<vector>

using namespace std;


int mergeSortedSubarrays(int A[],int start,int mid,int end)
{
    int i, j,count=0,factor=0;
    int tempA[end-start], index = 0;
    for (i=start,j=mid;((i<mid)||(j<end));)
    {
        if ((i<mid)&&(j<end))
        {
            if (A[j]<A[i])
            {
                tempA[index]=A[j];
                j++;
                factor++;
            }
            else
            {
                tempA[index]=A[i];
                i++;
                count=count+factor;
            }
        }
        else
        {
            if (i<mid)
            {
                tempA[index]=A[i];
                i++;
                count=count+factor;
            }
            else
            {
                tempA[index]=A[j];
                j++;
                factor++;
            }
        }
        index ++;
    }
    for(i=start;i<end;i++){A[i]=tempA[i-start];}
    return count;
}

int mergeSort(int A[],int start,int end)
{
    int count=0;
    if(end==start +1)
    {
        return count;
    }
    int mid=(start+end)/2;
    int count1=mergeSort(A,start,mid);
    int count2=mergeSort(A,mid,end);
    int count3=mergeSortedSubarrays(A,start,mid,end);
    count=count1+count2+count3;
    return count;
}


int mergeSortedSubarrays1(int A[],int start,int mid,int end,int c1[],int c2[])
{
    int i, j,count=0,factor=0;
    int tempA[end-start], index = 0;
    for (i=start,j=mid;((i<mid)||(j<end));)
    {
        if ((i<mid)&&(j<end))
        {
            if ((c1[A[i]-1]>c1[A[j]-1])&&(c2[A[i]-1]>c2[A[j]-1]))
            {
                tempA[index]=A[j];
                j++;factor++;
            }
            else
            {
                tempA[index]=A[i];
                i++;count=count+factor;
            }
        }
        else
        {
            if (i<mid)
            {
                tempA[index]=A[i];
                i++;count=count+factor;
            }
            else
            {
                tempA[index]=A[j];
                j++;factor++;
            }
        }
        index ++;
    }
    for(i=start;i<end;i++){A[i]=tempA[i-start];}
    return count;
}

int mergeSort1(int A[],int start,int end,int c1[],int c2[])
{
    int count=0;
    if(end==start +1)
    {
        return count;
    }
    int mid=(start+end)/2;
    int count1=mergeSort1(A,start,mid,c1,c2);
    int count2=mergeSort1(A,mid,end,c1,c2);
    int count3=mergeSortedSubarrays1(A,start,mid,end,c1,c2);
    count=count1+count2+count3;
    return count;
}

bool mergeSortedSubarrays2(int A[],int start,int mid,int end,int c1[],int c2[])
{
    int i, j;
    bool b=true;
    int n=sizeof(A);
    int min1=n,min2=n;
    int tempA[end-start], index = 0;
    for (i=start,j=mid;((i<mid)||(j<end));)
    {
        if ((i<mid)&&(j<end))
        {
            if ((c1[A[i]-1]>c1[A[j]-1])&&(c2[A[i]-1]>c2[A[j]-1]))
            {
                tempA[index]=A[j];
                if(min1>c1[A[j]-1]){min1=c1[A[j]-1];}
                if(min2>c2[A[j]-1]){min2=c2[A[j]-1];}
                j++;
            }
            else
            {
                tempA[index]=A[i];
                if(c1[A[i]-1]>min1){b=false;}
                if(c2[A[i]-1]>min2){b=false;}
                i++;
            }
        }
        else
        {
            if (i<mid)
            {
                tempA[index]=A[i];
                if(c1[A[i]-1]>min1){b=false;}
                if(c2[A[i]-1]>min2){b=false;}
                i++;
            }
            else
            {
                tempA[index]=A[j];
                if(min1>c1[A[j]-1]){min1=c1[A[j]-1];}
                if(min2>c2[A[j]-1]){min2=c2[A[j]-1];}
                j++;
            }
        }
        index ++;
    }
    for(i=start;i<end;i++){A[i]=tempA[i-start];}
    return b;
}

bool mergeSort2(int A[],int start,int end,int c1[],int c2[])
{
    bool b=true;
    int count=0;
    if(end==start +1)
    {
        return b;
    }
    int mid=(start+end)/2;
    bool b1=mergeSort2(A,start,mid,c1,c2);
    bool b2=mergeSort2(A,mid,end,c1,c2);
    bool b3=mergeSortedSubarrays2(A,start,mid,end,c1,c2);
    b=(b1&&b2&&b3);
    return b;
}

void inverse(int a[],int inv[],int n){
    for(int i=0;i<n;i++){
        inv[a[i]-1]=i+1;
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    int v1[n],v2[n],v3[n],v[n];
    int inv1[n],inv2[n];
    int s[n];
    for(int k=0; k<n; k++)
    {
        cin>>v1[k];
    }
    for(int k=0; k<n; k++)
    {
        cin>>v2[k];
    }
    for(int k=0; k<n; k++)
    {
        v3[k]=k+1;
    }
    inverse(v1,inv1,n);
    inverse(v2,inv2,n);
    for(int k=0;k<n;k++){
        s[k]=inv1[v2[k]];
    }
    int count_v3=mergeSort1(v3,0,n,inv1,inv2);
    for(int k=0; k<n; k++)
    {
        v3[k]=k+1;
    }
    bool b=mergeSort2(v3,0,n,inv1,inv2);
    for(int k=0;k<n;k++){
        v[k]=v1[k];
    }
    int count1=mergeSort(v,0,n);
    for(int i=0;i<n;i++){
        v[i]=v2[i];
    }
    int count2=mergeSort(v,0,n);
    int count3=mergeSort(s,0,n);
    if(b){
    int c1=(count1+count2-count3)/2;
        if(c1==count_v3){
            cout<<"consistent"<<endl;
        }
        else{
            cout<<"inconsistent"<<endl;
        }
    }
    else{cout<<"inconsistent"<<endl;}
    return 0;
}


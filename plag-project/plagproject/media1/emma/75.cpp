#include<cstdio>
#include<iostream>
using namespace std;
int *q, *p, *qinv, *pinv,*tinv, *s;
int countin=0;
bool check =true;
int maintain;
void merge(int* &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int* L=new int[n1];
    int* R=new int[n2];


    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if ((pinv[L[i]] < pinv[R[j]] && qinv[L[i]] < qinv[R[j]] ) || (pinv[L[i]] < pinv[R[j]] && tinv[L[i]] < tinv[R[j]])|| (qinv[L[i]] < qinv[R[j]] && tinv[L[i]] < tinv[R[j]]))
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


void mergeSort(int* &arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge1(int* &arr, int l, int m, int r, int &countin)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int countofr=0;

    int* L=new int[n1];
    int* R=new int[n2];


    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i]<R[i])
        {
            arr[k] = L[i];
            i++;
            countin = countin + countofr;
        }
        else
        {
            arr[k] = R[j];
            j++;
            countofr++;

        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        countin = countin + countofr;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort1(int* &arr, int l, int r, int &countin)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort1(arr, l, m,countin);
        mergeSort1(arr, m+1, r,countin);
        merge1(arr, l, m, r,countin);
    }
}
void merge2(int* &arr, int l, int m, int r,int* &temp)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int min1 = 100000009;

    int* L=new int[n1];
    int* R=new int[n2];


    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i]<R[i])
        {
            arr[k] = L[i];
            i++;
            if(temp[L[i]]<min1){check = false;maintain = i+1;}

        }
        else
        {
            arr[k] = R[j];
            j++;
            if(min1>temp[R[j]])min1 = temp[R[j]];

        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        if(temp[L[i]]<min1){check = false;maintain = i+1;

    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
}

void mergeSort2(int* &arr, int l, int r, int* &temp)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort2(arr, l, m,temp);
        mergeSort2(arr, m+1, r, temp);
        merge2(arr, l, m, r,temp);
}
}


int main()
{
int n;
scanf("%d",&n);
p = new int[n+1];
q = new int[n+1];
qinv = new int[n+1];
pinv = new int[n+1];
tinv = new int[n+1];
s =new int[n+1];
int *r = new int[n+1];
int *ztemp = new int[n+1];
for(int i = 1;i<n+1;i++)
    {scanf("%d",&p[i]);
    pinv[p[i]]=i;
    tinv[i] = i;
    }
for(int i = 1;i<n+1;i++)
    {
    scanf("%d",&q[i]);
    qinv[q[i]] = i;
    r[i]=i;
    s[i] = pinv[q[i]];
    }
mergeSort(r,1,n);

for(int i = 1;i<n+1;i++)
    {
    ztemp[i]=r[i];
    }

//counting
int countin = 0;
mergeSort1(p,1,n,countin);
int countinp=countin;

countin=0;
mergeSort1(q,1,n,countin);
int countinq = countin;

countin = 0;
mergeSort1(s,1,n,countin);
int countins=countin;

countin = 0;
mergeSort1(ztemp,1,n,countin);
int countinr=countin;

int
//checking
check = true;

for(int i = 1;i<n+1;i++)
    {
    ztemp[i]=r[i];
    }
mergeSort2(ztemp,1,n,pinv);

for(int i = 1;i<n+1;i++)
    {
    ztemp[i]=r[i];
    }
mergeSort2(ztemp,1,n,qinv);

/*if(countinr != (countinp + countinq - countins)/2){check = false;}



if(check == false) {printf("inconsistent\n");

int q ,w,e;
for(int i = 1;i<maintain;i++)
{

}
}

else {*/
printf("consistent\n");
for(int i = 1;i<n+1;i++)
    {
    printf("%d ",r[i]);
    }



}










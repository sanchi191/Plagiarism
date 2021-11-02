#include <iostream>

using namespace std;

void merge(int*,int*,int*,int*,int*,int,int,int);
bool check(int* q, int* j1i, int* j2i, int* j3i,int a, int b)
{
    if((j1i[q[a]]<j1i[q[b]]&&j2i[q[a]]<j2i[q[b]])||(j1i[q[a]]<j1i[q[b]]&&j3i[q[a]]<j3i[q[b]])||(j1i[q[a]]<j1i[q[b]]&&j3i[q[a]]<j3i[q[b]]))
    {
        return true;
    }
}
void mergesort(int* q, int *j1i, int* j2i, int*j3i, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(q,j1i,j2i,j3i,b,low,pivot);
        mergesort(q,j1i,j2i,j3i,b,pivot+1,high);
        merge(q,j1i,j2i,j3i,b,low,pivot,high);
    }
}
void merge(int* q, int* j1i, int* j2i, int* j3i, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;

    while((h<=pivot)&&(j<=high))
    {
        if(check(q,j1i,j2i,j3i,h,j))
        {
            b[i]=q[h];
            h++;
        }
        else
        {
            b[i]=q[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=q[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=q[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) q[k]=b[k];
}

int main()
{
    int total;
    cin>>total;
    int* j1;
    int* j2;
    int* j3;
    int* q;
    int* b;
    b=new int[total];
    j1=new int[total];
    j2=new int[total];
    j3=new int[total];
    q=new int[total];
    int* j1i;
    int* j2i;
    int* j3i;
    j1i=new int[total];
    j2i=new int[total];
    j3i=new int[total];
    for(int j=0;j<total;j++)
    {
    j3[j]=j;
    j3i[j]=j;
    q[j]=j;
    b[j]=j;
    }
    for(int i=0;i<total;i++)
    {
    cin>>j1[i];
    --j1[i];
    }
    for(int ii=0;ii<total;ii++)
    {
    j1i[j1[ii]]=ii;
    }
    for(int k=0;k<total;k++)
    {
    cin>>j2[k];
    --j2[k];
    }
    for(int ki=0;ki<total;ki++)
    {
    j2i[j2[ki]]=ki;
    }
    int real;
    real=total-1;


    mergesort(q,j1i,j2i,j3i,b,0,real);
    cout<<"consistent"<<endl;
    for(int i=0; i<total; i++)
        cout<<q[i]+1<<" ";
    cout<<endl;
}

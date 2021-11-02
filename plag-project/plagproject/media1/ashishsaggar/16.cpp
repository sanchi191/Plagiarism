#include <iostream>
#include <cstdio>
using namespace std;

bool myLess(int input[],int i,int j,int pinverse[],int qinverse[])
{
    int a=0,b=0,c=0;
    if(i<j){a=1;}else{a=0;}
    if(pinverse[i]<pinverse[j]){b=1;}else{b=0;}
    if(qinverse[i]<qinverse[j]){c=1;}else{c=0;}
    if(a+b+c>1){return true;}
    else{return false;}
}


void mergeArrays(int input[],int output[],int start,int mid,int end,int pinverse[],int qinverse[])
{
    int i=start,j=mid,k=start;
    for(i=start,j=mid;k<end;)
    {
        if((i<mid)&&(j<end))
        {
            if(myLess(input,i,j,pinverse,qinverse))
            {
                output[k]=input[i];
                i++;
                k++;
            }
            else
            {
                output[k]=input[j];
                j++;
                k++;
            }
        }
        else
        {
            if((i==mid)&&(j!=end))
            {
                for(;j<end;j++)
                {
                    output[k]=input[j];
                    k++;
                }
            }
            if((i!=mid)&&(j==end))
            {
                for(;i<mid;i++)
                {
                    output[k]=input[i];
                    k++;
                }
            }
        }
    }
    return;
}

void mergeSort(int input[],int output[],int start,int end,int pinverse[],int qinverse[])
{
    if(end-start==1)
    {
        return;
    }
    int mid = (start+end)/2;
    mergeSort(input,output,start,mid,pinverse,qinverse);
    mergeSort(input,output,mid,end,pinverse,qinverse);
    mergeArrays(input,output,start,mid,end,pinverse,qinverse);
    return;
}

bool checkConsistency(int input[],int n,int pinverse[],int qinverse[],int &a,int &b)
{
    int i=0,j=0;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
            {
                if(!myLess(input,i,j,pinverse,qinverse))
                {
                    a=i;
                    b=j;
                    return false;
                }
            }
    }
    return true;
}

int main()
{
    int n=0,i=0,index=0,a=0,b=0;
    bool flag=true;
    cin>>n;
    int *p = new int[n];
    int *q = new int[n];
    int *r = new int[n];
    int *output = new int [n];
    int *pinverse = new int[n];
    int *qinverse = new int[n];
    for(i=0;i<n;i++)
    {
        scanf("%i",&p[i]);
        p[i]=p[i]-1;
    }
    for(i=0;i<n;i++)
    {
        scanf("%i",&q[i]);
        q[i]=q[i]-1;
    }
    for(i=0;i<n;i++)
    {
        r[i]=i;
    }
    for(i=0;i<n;i++)
    {
        qinverse[q[i]] = i;
    }
    for(i=0;i<n;i++)
    {
        pinverse[p[i]] = i;
    }
    mergeSort(r,output,0,n,pinverse,qinverse);
    flag=checkConsistency(output,n,pinverse,qinverse,a,b);
    if(flag)
    {
        cout<<"consistent"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<output[i]+1<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"inconsistent"<<endl;
        for(i=0;i<n;i++)
        {
            if((myLess(p,a,i,pinverse,qinverse))&&(myLess(p,i,b,pinverse,qinverse)))
            {
                index=i;
                break;
            }
        }
        cout<<a+1<<" "<<index+1<<" "<<b+1<<endl;
    }
    return 0;
}

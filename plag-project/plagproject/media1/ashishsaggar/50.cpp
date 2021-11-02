#include<iostream>
#include<cstdio>
#include<vector>
#include<list>

using namespace std;
int q1,q2,q3;

void merg(int a[],int i,int m,int f,int b[],int c[],int d[])
{
    int l[m-i+1];
    int r[f-m];
    int k=i;
    int j=0;
    while(k<=m)
    {
        l[j]=a[k];
        k++;
        j++;
    }
    j=0;
    while(k<=f)
    {
        r[j]=a[k];
        k++;
        j++;
    }
    k=i;
    int s=0,t=0;
    while(k<=f)
    {
        if(s<m-i+1 && t<f-m)
        {
            if((d[l[s]]<=d[r[t]]) && (c[l[s]]<=c[r[t]]))
            {
                a[k]=l[s];
                s++;
            }
            else if((d[l[s]]<=d[r[t]]) && (b[l[s]]<=b[r[t]]))
            {
                a[k]=l[s];
                s++;
            }
            else if((c[l[s]]<=c[r[t]]) && (b[l[s]]<=b[r[t]]))
            {
                a[k]=l[s];
                s++;
            }
            else if((d[l[s]]>d[r[t]]) && (c[l[s]]>c[r[t]]))
            {
                a[k]=r[t];
                t++;
            }
            else if((d[l[s]]>d[r[t]]) && (b[l[s]]>b[r[t]]))
            {
                a[k]=r[t];
                t++;
            }
            else if((c[l[s]]>c[r[t]]) && (b[l[s]]>b[r[t]]))
            {
                a[k]=r[t];
                t++;
            }
        }
        else if(s==m-i+1 && t<f-m)
        {
            a[k]=r[t];
            t++;
        }

        else if(t==f-m && s<m-i+1)
        {
            a[k]=l[s];
            s++;
        }
        k++;
    }
}



void merge_sort(int a[],int i,int f,int b[],int c[],int d[])        //b and c and d in_p1 and in_p2 and p_3  a=r
{
    if(i<f)
    {
        int m=(i+f)/2;
        merge_sort(a,i,m,b,c,d);
        merge_sort(a,m+1,f,b,c,d);
        merg(a,i,m,f,b,c,d);
    }
}

bool iscon(int a[],int N,int in_p1[],int in_p2[],int p3[])
{
    bool r=true;
    int i=1;
    while(i<=N-2)
    {
        if((in_p1[a[i]]>in_p1[a[i+2]])&&(in_p2[a[i]]>in_p2[a[i+2]])) r=false;
        else if((in_p1[a[i]]>in_p1[a[i+2]])&&(p3[a[i]]>p3[a[i+2]])) r=false;
        else if((in_p2[a[i]]>in_p2[a[i+2]])&&(p3[a[i]]>p3[a[i+2]])) r=false;
        if (r==false) {q1=a[i];q2=a[i+1];q3=a[i+2];break;}
        i++;
    }
    return r;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    int p1[N+1],p2[N+1],p3[N+1],in_p1[N+1],in_p2[N+1],r[N+1];
    p1[0]=0;
    p2[0]=0;
    p3[0]=0;
    in_p1[0]=0;
    in_p2[0]=0;
    r[0]=0;
    i=1;
    while(i<=N)
    {
        p3[i]=i;
        r[i]=i;
        i++;
    }
    i=1;
    while(i<=N)
    {
        scanf("%d",&p1[i]);
        in_p1[p1[i]]=i;
        i++;
    }
    i=1;
    while(i<=N)
    {
        scanf("%d",&p2[i]);
        in_p2[p2[i]]=i;
        i++;
    }
    merge_sort(r,1,N,in_p1,in_p2,p3);
    if(iscon(r,N,in_p1,in_p2,p3)==true)
    {
        i=1;
        printf("consistent\n");
        while(i<=N){printf("%d ",r[i]);i++;};
    }
    else if(iscon(r,N,in_p1,in_p2,p3)==false)
    {
        printf("inconsistent\n");
        printf("%d %d %d",q1,q2,q3);
    }
}

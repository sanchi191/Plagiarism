#include <iostream>
using namespace std;

void nlognrsort(int r[],int f,int l,int pin[],int qin[])
{
    int p=(f+l)/2;
    if(f!=p)nlognrsort(r,f,p,pin,qin);
    if(p+1!=l)nlognrsort(r,p+1,l,pin,qin);
    int i=f,j=p+1,k=0;
    int *B=new int[l-f+1];
    while(i!=p+1&&j!=l+1)
    {
        if(((r[i]<r[j])&&(pin[r[i]]<pin[r[j]]||qin[r[i]]<qin[r[j]]))||((r[i]>r[j])&&(pin[r[i]]<pin[r[j]]&&qin[r[i]]<qin[r[j]])))
        {
            B[k]=r[i];
            i++;
        }
        else
        {
            B[k]=r[j];
            j++;
        }
        k++;
    }
    if(i==p+1)for(;j<=l;j++,k++)B[k]=r[j];
    else {if(j==l+1)for(;i<=p;i++,k++)B[k]=r[i];}
    for(i=f,k=0;i<=l;i++,k++)r[i]=B[k];
    delete B;
}

int count_inv(int A[],int f,int l)
{
    int p=(f+l)/2,s1=0,s2=0,s3=0;
    if(f!=p)s1=count_inv(A,f,p);
    if(p+1!=l)s2=count_inv(A,p+1,l);
    int i=f,j=p+1,k=0;
    int *B=new int[l-f+1];
    while(i!=p+1&&j!=l+1)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            i++;
        }
        else
        {
            B[k]=A[j];
            s3+=p-i+1;
            j++;
        }
        k++;
    }
    if(i==p+1)for(;j<=l;j++,k++)B[k]=A[j];
    else {if(j==l+1)for(;i<=p;i++,k++)B[k]=A[i];}
    for(i=f,k=0;i<=l;i++,k++)A[i]=B[k];
    delete B;
    return s1+s2+s3;
}

bool nlognfunc(int r[],int f,int l,int pin[],int qin[],int &u1,int &u2,int &u3)
{
    bool b1=1,b2=1;
    int p=(f+l)/2;
    if(f!=p)b1=nlognfunc(r,f,p,pin,qin,u1,u2,u3);
    if(!b1)return 0;
    if(p+1!=l)b2=nlognfunc(r,p+1,l,pin,qin,u1,u2,u3);
    if(!b2)return 0;
    int i=f,j=p+1,k=0;
    int *B=new int[l-f+1];
    while(i!=p+1&&j!=l+1)
    {
        if(r[i]>r[j])
        {
            if(pin[r[i]]>pin[r[j]]||qin[r[i]]>qin[r[j]])
            {
                //u1=r[j+1]+1;u2=r[j]+1;u3=r[i]+1;cout<<u1<<u2<<u3<<" ";
                return 0;
            }
            B[k]=r[i];
            i++;
        }
        else
        {
            B[k]=r[j];
            j++;
        }
        k++;
    }
    if(i==p+1)for(;j<=l;j++,k++)B[k]=r[j];
    else {if(j==l+1)for(;i<=p;i++,k++)B[k]=r[i];}
    for(i=f,k=0;i<=l;i++,k++)r[i]=B[k];
    delete B;
    b1=b1&&b2;
    return b1;
}

int main()
{
    int n,temp,u1=0,u2=0,u3=0;
    bool b1=1,b2=1;
    cin>>n;
    int p[n],q[n],pin[n],qin[n],r[n],s[n],t[n];
    for(int i=0;i<n;i++){cin>>temp;p[i]=temp-1;}
    for(int i=0;i<n;i++){cin>>temp;q[i]=temp-1;}
    for(int i=0;i<n;i++){pin[p[i]]=i;qin[q[i]]=i;r[i]=i;}

    nlognrsort(r,0,n-1,pin,qin);
    for(int i=0;i<n;i++)s[qin[p[i]]]=i;
    for(int i=0;i<n;i++){t[i]=r[i];}

    int c1,c2,c3,c4;
    c1=count_inv(p,0,n-1);
    c2=count_inv(q,0,n-1);
    c3=count_inv(s,0,n-1);
    c4=count_inv(t,0,n-1);
    if((c1+c2-c3)/2!=c4)b1=0;

    for(int i=0;i<n;i++){t[i]=r[i];}
    //b2=nlognfunc(t,0,n-1,pin,qin,u1,u2,u3);

    if(b1&&b2)
    {
        cout<<"consistent"<<endl;
        for(int i=0;i<n;i++)cout<<r[i]+1<<" ";
    }
    else
    {
        cout<<"inconsistent"<<endl;
    }
    return 0;
}

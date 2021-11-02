#include<iostream>
using namespace std;
////////////
void mer(int*A,int &ct,int low,int high,int mid)
{

    int c[high];
    int i=low,j=mid+1,k=low;

    while(i<=mid && j<=high)
    {

        if(A[i]<A[j])
        {
            c[k]=A[i];
            k++;
            i++;
        }
        else
        {
            ct=ct+mid+1-i;
            c[k]=A[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        c[k]=A[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        c[k]=A[j];
        k++;
        j++;
    }

    for(i=low; i<k; i++)
    {
        A[i]=c[i];
    }
    return;
}


int m(int* A,int &ct,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        m(A,ct,low,mid);
        m(A,ct,mid+1,high);
        mer(A,ct,low,high,mid);
    }
    return ct;
}

////////////
int merg(int*A,int*B,int*N,int low,int high,int mid)
{
    int c[high];
    int i=low,j=mid+1,k=low;
    int t=0;
    while(i<=mid)
    {
        if(A[i]<A[j])
        {
            t++;
        }
        if(B[i]<B[j])
        {
            t++;
        }
        if(t>=1)
        {
            c[k]=N[i];
            k++;
            i++;
        }



        else
        {

            return 1;
        }
    }
    while(i<=high)
    {
        c[k]=N[i];
        k++;
        i++;
    }



    for(i=low; i<k; i++)
    {
        N[i]=c[i];
    }
    return 0;
}


int msort(int* A,int*B,int*N,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        msort(A,B,N,low,mid);
        msort(A,B,N,mid+1,high);
        if(merg(A,B,N,low,high,mid)==1)
        {
            return 1;
        }
        else {return 0;}
    }

    return 0;
}


int main()
{
    int n,x=0;
    cin>>n;
    int A[n],B[n],N[n],Ai[n],Bi[n],s[n],r[n];
    for(int i=0; i<n; i++)
    {

        cin>>A[i];

        N[i]=i+1;r[i]=i+1;
    }

    for(int i=0; i<n; i++)
    {

        cin>>B[i];

    }
    for(int i=0; i<n; i++)
    {
        Ai[A[i]-1]=i+1;
        Bi[B[i]-1]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        s[i]=Bi[A[i]-1];
    }








        if((m(A,x,0,n-1)+m(B,x,0,n-1)-m(s,x,0,n-1))/2 == m(r,x,0,n-1) && (msort(Ai,Bi,N,0,n-1)== 0))
        {
            cout<<"consistent"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<N[i];
            }
        }

         if(msort(Ai,Bi,N,0,n-1)== 1)
    {
        cout<<"inconsistent"<<endl;
    }




    return 0;
}

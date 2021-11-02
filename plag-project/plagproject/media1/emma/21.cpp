#include<iostream>
using namespace std;
bool less_than(int A[],int B[],int C[],int i,int j)
{
    int n=0;
    if(i<j)
    {
        n++;
    }
    if(B[i]<B[j])
    {
        n++;
    }
    if(C[i]<C[j])
    {
        n++;
    }
    if(n<2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void merge_sortedarrays(int A[],int B[],int C[],int start,int mid,int stop)
{
    int*temp=new int[stop-start];
    int k=start;
    int i=start;
    int j=mid;
    while(i!=mid||j!=stop)
    {
        if(i<mid&&j<stop)
        {
            if(less_than(A,B,C,i,j))
            {
                temp[k-start]=A[i];
                i++;
            }
            else
            {
                temp[k-start]=A[j];
                j++;
            }
        }
        else if(i==mid)
        {
            temp[k-start]=A[j];
            j++;
        }
        else
        {
            temp[k-start]=A[i];
            i++;
        }
        k++;
    }
    i=start;
    while(i!=stop)
    {
        A[i]=temp[i-start];
        i++;
    }
    delete temp;
    return;
}
void merge_sort(int A[],int B[],int C[],int start,int stop)
{
    int mid;
    if(start==stop-1)
    {
        return ;
    }
    else
    {
        mid=(start+stop)/2;
    }
    merge_sort(A,B,C,start,mid);
    merge_sort(A,B,C,mid,stop);
    merge_sortedarrays(A,B,C,start,mid,stop);
    return;
}

void merge_sortedarrays_check(int A[],int C[],int start,int mid,int stop,int&min_q,bool check,int a,int b)
{
    int*temp=new int[stop-start];
    int k=start;
    int i=start;
    int j=mid;
    int m=min_q;
    while(i!=mid||j!=stop)
    {
        if(i<mid&&j<stop)
        {
            if(A[i]<A[j])
            {
                if(C[A[i]]>m)
                {
                    b=A[i];
                    a=C[m];
                    check=false;
                    return;
                }
                temp[k-start]=A[i];
                i++;
            }
            else
            {
                if(m>C[A[j]])
                {
                    m=C[A[j]];
                }
                temp[k-start]=A[j];
                j++;
            }
        }
        else if(i==mid)
        {
            if(m>C[A[j]])
            {
                m=C[A[j]];
            }
            temp[k-start]=A[j];
            j++;
        }
        else
        {
            if(C[A[i]]>m)
            {
                b=A[i];
                a=C[m];
                check=false;
                return;
            }
            temp[k-start]=A[i];
            i++;
        }
        k++;
    }
    i=start;
    while(i!=stop)
    {
        A[i]=temp[i-start];
        i++;
    }
    delete temp;
    return;
}
void merge_sort_check(int A[],int C[],int start,int stop,int&min_q,bool check,int a,int b)
{
    int mid;
    if(start==stop-1)
    {
        return ;
    }
    else
    {
        mid=(start+stop)/2;
    }
    merge_sort_check(A,C,start,mid,min_q,check,a,b);
    merge_sort_check(A,C,mid,stop,min_q,check,a,b);
    merge_sortedarrays_check(A,C,start,mid,stop,min_q,check,a,b);
    return;
}

void merge_sortedarrays_inv(int A[],int start,int mid,int stop,int&count)
{
    int*temp=new int[stop-start];
    int k=start;
    int i=start;
    int j=mid;
    while(i!=mid||j!=stop)
    {
        if(i<mid&&j<stop)
        {
            if(A[i]<A[j])
            {
                temp[k-start]=A[i];
                i++;
            }
            else
            {
                temp[k-start]=A[j];
                count=count+mid-i;
                j++;
            }
        }
        else if(i==mid)
        {
            temp[k-start]=A[j];
            j++;
        }
        else
        {
            temp[k-start]=A[i];
            i++;
        }
        k++;
    }
    i=start;
    while(i!=stop)
    {
        A[i]=temp[i-start];
        i++;
    }
    delete temp;
    return;
}
void merge_sort_inv(int A[],int start,int stop,int&count)
{
    int mid;
    if(start==stop-1)
    {
        return ;
    }
    else
    {
        mid=(start+stop)/2;
    }
    merge_sort_inv(A,start,mid,count);
    merge_sort_inv(A,mid,stop,count);
    merge_sortedarrays_inv(A,start,mid,stop,count);
}

bool consistent(int A[],int B[],int C[],int i,int j,int k)
{
    return ((less_than(A,B,C,i,j))&&(less_than(A,B,C,j,k)));
}
int main()
{
    int n;
    cin>>n;
    int*p=new int[n];
    int*q=new int[n];
    int*P=new int[n];
    int*Q=new int[n];
    int*S=new int[n];
    int*R=new int[n];
    int*U=new int[n];
    int*V=new int[n];
    int*W=new int[n];
    int*Y=new int[n];
    int*Z=new int[n];
    int*G=new int[n];
    int*K=new int[n];
    int i=0,j;
    int d,e,x,y;
    int min_q=n+1;
    int min_p=n+1;
    bool checkp=true;
    bool checkq=true;
    int rpairs=0;
    int ppairs=0;
    int qpairs=0;
    int spairs=0;
    int compairs=0;
    while(i!=n)
    {
        cin>>p[i];
        i++;
    }
    i=0;
    while(i!=n)
    {
        cin>>q[i];
        i++;
    }
    i=0;
    while(i!=n)
    {
        P[p[i]-1]=i;
        Q[q[i]-1]=i;
        R[i]=i+1;
        i++;
    }
    i=0;
    while(i!=n)
    {
        S[i]=P[q[i]-1];
        K[R[i]-1]=i;
        i++;
    }
    merge_sort(R,P,Q,0,n);
    i=0;
    while(i!=n)
    {
        W[i]=R[i];
        U[i]=p[i];
        V[i]=q[i];
        Y[i]=S[i];
        Z[i]=R[i];
        G[i]=R[i];
        i++;
    }
    merge_sort_inv(W,0,n,rpairs);
    merge_sort_inv(U,0,n,ppairs);
    merge_sort_inv(V,0,n,qpairs);
    merge_sort_inv(Y,0,n,spairs);
    compairs=(ppairs+qpairs-spairs)/2;
    merge_sort_check(G,P,0,n,min_p,checkp,x,y);
    merge_sort_check(Z,P,0,n,min_q,checkq,d,e);

    if(checkp&&checkq&&(compairs==rpairs))
    {
        i=0;
        cout<<"consistent"<<endl;
        while(i!=n)
        {
            cout<<R[i]<<" ";
            i++;
        }
        return 0;
    }
    else if(checkp==false)
    {
        int v=K[x]+1;
        while(v!=K[y]-1)
        {
            if(consistent(R,P,Q,K[x],v,K[y]))
            {
                cout<<"inconsistent"<<endl;
                cout<<x<<" "<<R[v]<<" "<<y;
                return 0;
            }
        }
    }
    else if(checkq==false)
    {
        int v=K[d]+1;
        while(v!=K[e]-1)
        {
            if(consistent(R,P,Q,K[d],v,K[e]))
            {
                cout<<"inconsistent"<<endl;
                cout<<d<<" "<<R[v]<<" "<<e;
                return 0;
            }
        }
    }
    else
    {
        cout<<"inconsistent"<<endl;
        i=0;
        while(i!=3)
        {
            cout<<R[i]<<" ";
            i++;
        }
        return 0;
    }
    cout<<ppairs;
    cout<<qpairs;
    cout<<rpairs;
    cout<<spairs;
    cout<<compairs;
    return 0;
}

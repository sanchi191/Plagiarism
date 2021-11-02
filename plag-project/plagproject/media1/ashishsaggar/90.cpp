#include<iostream>
using namespace std;
bool Merg(int C[],int A[],int B[],int Start1,int End1,int Start2,int End2);
void Merge(int C[],int A[],int B[],int Start1,int End1,int Start2,int End2);
bool mergeSort(int C[],int A[],int B[],int i,int j);
void MergeSort(int C[],int A[],int B[],int i,int j);
int p;
int main()
{
    int n,m;
    cin>>n;
    int *a,*b,*C,*A,*B,*D;
    a=new int [n];
    b=new int [n];
    C=new int [n+1];
    D=new int [n+1];
    A=new int [n+1];
    B=new int [n+1];
    for(int i=0; i<=n; i++)
    {
        C[i]=i;
    }
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for(int i=0; i<n; i++)
    {
        A[a[i]]=i+1;
        B[b[i]]=i+1;
    }
    MergeSort(C,A,B,1,n);
    for(int i=0;i<=n;i++)
    {
        D[i]=C[i];
    }
    bool x=mergeSort(C,A,B,1,n);
    if(x==false)
    {
    cout<<"Inconsistant"<<endl;
    }
    else
    {
    cout<<"Consistant"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<D[i];
    }
    }
    return 0;
}
void Merge(int C[],int A[],int B[],int Start1,int End1,int Start2,int End2)
{
    int temp[End2-Start1+1],i,j,k=0;
    for(i=Start1,j=Start2; (i<=End1||j<=End2);)
    {
        if(i<=End1&&j<=End2)
        {
            if(C[i]>C[j])
            {
                if((A[C[i]]<A[C[j]])&&(B[C[i]]<B[C[j]]))
                {
                    temp[k]=C[i];
                    //cout<<temp[k]<<"hi"<<endl;
                    k++;
                    i++;
                }
                else
                {
                    temp[k]=C[j];
                    //cout<<temp[k]<<"Hi"<<endl;
                    k++;
                    j++;
                }
            }
            else
            {
                if((A[C[i]]<A[C[j]])||(B[C[i]]<B[C[j]]))
                {
                    temp[k]=C[i];
                    //cout<<temp[k]<<"hI"<<endl;
                    k++;
                    i++;
                }
                else
                {
                    temp[k]=C[j];
                    //cout<<temp[k]<<"HI"<<endl;
                    k++;
                    j++;
                }
            }
        }
        else
        {
            if(i<=End1)
            {
                temp[k]=C[i];
                //cout<<temp[k]<<"H"<<endl;
                k++;
                i++;
            }
            else
            {
                temp[k]=C[j];
                //cout<<temp[k]<<"I"<<endl;
                k++;
                j++;
            }
        }
    }
    if(k==End2-Start1+1)
    {
        //cout<<"Hi"<<endl;
    }
    for(int i=0; i<k; i++)
    {
        C[Start1+i]=temp[i];
    }
    return;
}
bool Merg(int C[],int A[],int B[],int Start1,int End1,int Start2,int End2)
{
    int temp[End2-Start1+1],i,j,k=0,Min=99999999;
    for(i=Start1,j=Start2; (i<=End1||j<=End2);)
    {
        if(i<=End1&&j<=End2)
        {
            if(C[i]>C[j])
            {
                if(j!=Start2)
                {
                if((A[C[i]]<A[Min])&&(B[C[i]]<B[Min]))
                {
                    temp[k]=C[i];
                    k++;
                    i++;
                }
                else
                {
                    return false;
                }
                }
                else
                {
                    temp[k]=C[i];
                    k++;
                    i++;
                }
            }
            else
            {
                temp[k]=C[j];
                if(C[j]<Min)
                {
                Min=C[j];
                }
                //cout<<temp[k]<<"Hi"<<endl;
                k++;
                j++;
            }
        }
        else
        {
            if(i<=End1)
            {
                temp[k]=C[i];
                //cout<<temp[k]<<"hI"<<endl;
                k++;
                i++;
            }
            else
            {
                temp[k]=C[j];
                //cout<<temp[k]<<"hi"<<endl;
                k++;
                j++;
            }
        }
    }
    for(int i=0; i<k; i++)
    {
        C[Start1+i]=temp[i];
    }
    //cout<<"hi"<<endl;
    return true;
}
void MergeSort(int C[],int A[],int B[],int i,int j)
{
    if(i==j)
    {
        return ;
    }
    int mid=(i+j)/2;
    MergeSort(C,A,B,i,mid);
    MergeSort(C,A,B,mid+1,j);
    Merge(C,A,B,i,mid,mid+1,j);
    return;
}
bool mergeSort(int C[],int A[],int B[],int i,int j)
{
    if(i==j)
    {
        return true;
    }
    int mid=(i+j)/2;
    if((mergeSort(C,A,B,i,mid))&&(mergeSort(C,A,B,mid+1,j)))
    {
        return Merg(C,A,B,i,mid,mid+1,j);
    }
    else
    {
        return false;
    }
}

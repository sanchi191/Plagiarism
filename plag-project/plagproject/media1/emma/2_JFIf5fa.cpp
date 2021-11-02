#include<iostream>
using namespace std;
int num,val;

//less than operator
bool lessthan(int a,int b,int A1[],int B1[],int i,int j){
      if(a<b){
             if((A1[i]<A1[j])||(B1[i]<B1[j])) return 1;
             else return 0;
              }
      else{
           if((A1[i]>A1[j])||(B1[i]>B1[j])) return 1;
             else return 0;
              }

                                                 }
//less than ends

 //merge sort algorithm
void merge(int *,int, int , int ,int *,int *,int,int);
void mergesort(int *a, int low, int high,int *b,int *c,int n,int t)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid,b,c,n,t);
        mergesort(a,mid+1,high,b,c,n,t);
        merge(a,low,high,mid,b,c,n,t);
    }
    return;
}
void merge(int *a, int low, int high, int mid,int *b,int *c,int n,int t)
{
    int i, j, k, d[n],rh,pos,minpos=n;
    bool s;
    rh=0;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
       if(t==1) s=lessthan(a[i],a[j],b,c,i,j);
       if(t==0) s=a[i]<a[j];
        if (s)//checking less than
        {
            d[k] = a[i];num=num+rh;
                      if(b[a[i]]>minpos) val=val+1;
            k++;
            i++;
        }
        else
        {
            d[k] = a[j];rh=rh+1;pos=b[a[j]];
                                if(pos<minpos) minpos=pos;
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        d[k] = a[i];num=num+rh;
        k++;
        i++;
    }
    while (j <= high)
    {
        d[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = d[i];
    }
}

 //merge sort algo ends

//printing algo
void print(int A[],int n){
int i;
for(i=1;i<n+1;i++){
             cout<<A[i]<<" ";
                 }cout<<endl;
                 return;

                       }
 //printing ends

int main(){
int i,j,k=0, n;
int r ,a ,b,s;
cin>>n;
int A[n],B[n],C[n],A1[n],B1[n];
A[0]=0;B[0]=0;A1[0]=0;B1[0]=0,C[0]=0;
for(i=1;i<n+1;i++){
             cin>>A[i];
             j=A[i];//constructing inverse A
             A1[j]=i;
             C[i]=i;
                }
for(i=1;i<n+1;i++){
             cin>>B[i];
             j=B[i];
             B1[j]=i;
                }

 mergesort(C,0,n,A1,B1,n,1);//finding r here
 //copying c to new array;
 int R[n],R1[n],R2[n];R[0]=0;R1[0]=0;R2[0]=0;
 for(i=1;i<n+1;i++){
           R[i]=C[i];
           R1[i]=C[i];
           R2[i]=C[i];
                   }
 //copying ends

 //construct s array
  int S[n];S[0]=0;
 for(i=1;i<n+1;i++){
           S[i]=A1[B[i]];
                   }
 //constructed

//get no of inv pairs of r;
num=0;
mergesort(R,1,n,A1,B1,n,0);
r=num;
//cout<<"no of inv pairs  r "<<num;cout<<endl;
//inv pairs of a
num=0;
mergesort(A,1,n,A1,B1,n,0);
a=num;
//cout<<"no of inv pairs  a "<<num;cout<<endl;
//inv pairs of b
num=0;
mergesort(B,1,n,A1,B1,n,0);
b=num;
//cout<<"no of inv pairs  b "<<num;cout<<endl;
//inv pairs of s
num=0;
mergesort(S,1,n,A1,B1,n,0);
s=num;
//cout<<"no of inv pairs  s "<<num;cout<<endl;
//ends

//check one contained in other
val=0;
mergesort(R1,1,n,A1,B1,n,0);
//cout<<"r is contained in a "<<val;cout<<endl;
if(val==0) k=k+1;
val=0;
mergesort(R2,1,n,B1,A1,n,0);
//cout<<"r is contained in b "<<val;cout<<endl;
if(val==0) k=k+1;
//checking ends
//checking consistency;
if((k==2)&&(2*r==a+b-s)) {cout<<"consistent"<<endl;print(C,n);}
else cout<<"inconsistent"<<endl;
//checked
                return 0;
            }

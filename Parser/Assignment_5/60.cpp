#include<iostream>
using namespace std;

void mergesortedarrays(int* r,int start,int mid,int end,int n2,int p1[],int q1[])
{

 int i,j;int n=n2;bool c;
 int temp[n];
 int index=0;
 for(i=start,j=mid;((i<mid)||(j<end));)
  {
   if((i<mid)&&(j<end)){
      if(r[i]<r[j])
   {if((p1[i-1]<p1[j-1])||(q1[i-1]<q1[j-1]))c=true;
     else c=false;
   }
 else
   {if((p1[i-1]<p1[j-1])&&(q1[i-1]<q1[j-1]))c=true;
    else c=false;
   }
      if(c){temp[index]=r[i];i++;}
      else {temp[index]=r[j];j++;}
   }
   else{
      if(i<mid){temp[index]=r[i];i++;}
      else {temp[index]=r[j];j++;}
   }
   index++;
  }
  index=0;
  for(i=start;i<end;i++){r[i]=temp[index];index++;}
}

void mergesort(int* r,int start,int end,int p1[],int q1[])
{

 if(end == start+1){return;}
 int n1=end-start;
 int mid=(start+end)/2;
 mergesort(r,start,mid,p1,q1);
 mergesort(r,mid,end,p1,q1);
 mergesortedarrays(r,start,mid,end,n1,p1,q1);
 return;
}



int main()
{
 int n;bool cons;bool c1=true;
 int* p=new int [n];
 int* p1=new int [n];
 int* q=new int [n];
 int* q1=new int [n];
 int* r=new int [n];
 cin>>n;
 int i=0;
 while(i<n){cin>>p[i];p1[p[i]-1]=i+1;i++;}
 i=0;

 while(i<n){cin>>q[i];q1[q[i]-1]=i+1;i++;}
 i=0;
 while(i<n){r[i]=i+1;i++;}

 mergesort(r,0,n,p1,q1);

 i=0;int j=0;
 while(i<n)
 {
  j=i+2;
  while(j<n)
  {
   if(r[i]<r[j])
   {if((p1[r[i]-1]<p1[r[j]-1])||(q1[r[i]-1]<q1[r[j]-1])){c1=true;}
     else
      {
       c1=false;
       cout<<"inconsistent"<<endl;cout<<r[i]<<" "<<r[j-1]<<" "<<r[j]<<" "<<endl;return 0;}
   }
 else
   {if((p1[r[i]-1]<p1[r[j]-1])&&(q1[r[i]-1]<q1[r[j]-1]))c1=true;
    else {c1=false;cout<<"inconsistent"<<endl;cout<<r[i]<<" "<<r[j-1]<<" "<<r[j]<<" "<<endl;return 0;}
   }
  j++;
  }
  i++;
 }
 if(c1==true){cout<<"consistent"<<endl;i=0;
 while(i<n){cout<<r[i]<<" ";i++;}
 cout<<endl;}
return 0;
}




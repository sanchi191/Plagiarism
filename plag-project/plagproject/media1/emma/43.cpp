#include <iostream>
#include <vector>
using namespace std;


bool comp(int i,int j,vector<int> &br,vector<int> &cr){//returns true if i<j

  int count=0;
  if(i<j)count++;
  if(br[i]<br[j])count++;
  if(cr[i]<cr[j])count++;

  if(count>=2){
    return true;
  }
  else{
    return false;
  }

}

void merge(vector<int> &A,vector<int> &temp,int start,int mid,int end,vector<int> &br,vector<int> &cr,long long &count){

  int i=start,j=mid+1,k=start;
  while(i<=mid&&j<=end){

    if(comp(A[i],A[j],br,cr)){//A[i]<A[j]
       temp[k]=A[i];
       i++; k++;
    }
    else{
       temp[k]=A[j];
       j++; k++;
       count+=(mid-i+1);
    }

  }

  while(j<=end){
    temp[k]=A[j];
    j++; k++;
  }

  while(i<=mid){
    temp[k]=A[i];
    i++; k++;
  }

  for(int h=start;h<=end;h++){
    A[h]=temp[h];
  }
  return;

}

void msort(vector<int> &A,vector<int> &temp,int start,int end,vector<int> &br,vector<int> &cr,long long &count){//sorts A
   if(start==end){
     return;
   }

   int mid=(start+end)/2;
   msort(A,temp,start,mid,br,cr,count);
   msort(A,temp,mid+1,end,br,cr,count);
   merge(A,temp,start,mid,end,br,cr,count);
   return;
}

//-------------------------------------------------------

bool merge2(vector<int> &A,vector<int> &B,vector<int> &temp,int start,int mid,int end,vector<int> &Br,int &I,int &K){

  bool flag=true;
  int min=B.size()+5;
  int i=start,j=mid+1,k=start;
  while(i<=mid&&j<=end){

    if(A[i]<A[j]){//A[i]<A[j]
       temp[k]=A[i];

       if(Br[A[i]]>min){
         flag=false;
         I=A[i]; K=B[min];
          break;
       }
       i++; k++;
    }
    else{
       temp[k]=A[j];

       if(Br[A[j]]<min)min=Br[A[j]];
       j++; k++;
    }

  }

  while(j<=end&&flag){
    temp[k]=A[j];
    j++; k++;
  }

  while(i<=mid&&flag){
    temp[k]=A[i];
    i++; k++;
  }

  for(int h=start;h<=end&&flag;h++){
    A[h]=temp[h];
  }
  return flag;

}

//given A and B returns true if all inv of A are there in B
bool msort2(vector<int> &A,vector<int> &B,vector<int> &temp,int start,int end,vector<int> &Br,int &I,int &K){//sorts A
   if(start==end){
     return true;
   }

   int mid=(start+end)/2;
   bool flag=true;
   flag=msort2(A,B,temp,start,mid,Br,I,K);
   if(flag==false)return flag;
   flag=msort2(A,B,temp,mid+1,end,Br,I,K);
   if(flag==false)return flag;
   flag=merge2(A,B,temp,start,mid,end,Br,I,K);
   return flag;
}



void merge3(vector<int> &A,vector<int> &temp,int start,int mid,int end,long long &count){

  int i=start,j=mid+1,k=start;
  while(i<=mid&&j<=end){

    if(A[i]<A[j]){//A[i]<A[j]
       temp[k]=A[i];
       i++; k++;
    }
    else{
       temp[k]=A[j];
       j++; k++;
       count+=(mid-i+1);
    }

  }

  while(j<=end){
    temp[k]=A[j];
    j++; k++;
  }

  while(i<=mid){
    temp[k]=A[i];
    i++; k++;
  }

  for(int h=start;h<=end;h++){
    A[h]=temp[h];
  }
  return;

}

void msort3(vector<int> &A,vector<int> &temp,int start,int end,long long &count){//sorts A
   if(start==end){
     return;
   }

   int mid=(start+end)/2;
   msort3(A,temp,start,mid,count);
   msort3(A,temp,mid+1,end,count);
   merge3(A,temp,start,mid,end,count);
   return;
}

void check(vector<int> &r,vector<int> &br,vector<int> &cr,int n,int I,int K){
   bool flar=false;
   int k,i,j;

       for(int zar=1;zar<=n;zar++){
         if(r[zar]==I)i=zar;
         if(r[zar]==K)k=zar;
       }
       if(i<=n&&k<=n&&k>i+1){
         if(comp(r[k],r[i],br,cr)){
            flar=true;
         }
       }

   if(flar==true){
      for( j=i+1;j<k;j++){
          if(comp(r[i],r[j],br,cr)&&comp(r[j],r[k],br,cr)){
             break;
          }
      }
      if(j<k){

         if(i<=n&&j<=n&&k<=n){
           cout<<r[i]<<" "<<r[j]<<" "<<r[k];
         }

         return;
      }

   }




   for( i=1;i<=n;i++){
      for( k=i+2;k<=n;k++){
         if(comp(r[k],r[i],br,cr)){
            break;
         }
      }
      if(k<=n){

        for( j=i+1;j<k;j++){
          if(comp(r[i],r[j],br,cr)&&comp(r[j],r[k],br,cr)){
             break;
          }
        }
        if(j<k)break;

      }
   }

   if(i<=n&&j<=n&&k<=n){
     cout<<r[i]<<" "<<r[j]<<" "<<r[k];
   }
}


//-------------------------------------------------------

int main(){

  int n;
  cin>>n;
  vector<int> a,ar,b,br,c,cr,temp,temp2,r;
  a.resize(n+1);
  ar.resize(n+1);//ar[i] is rank of i in a
  b.resize(n+1);
  br.resize(n+1);
  c.resize(n+1);
  cr.resize(n+1);
  temp.resize(n+1);
  temp2.resize(n+1);
  r.resize(n+1);

  for(int i=1;i<=n;i++){
    a[i]=i;
    r[i]=i;
    ar[i]=i;
  }

  for(int i=1;i<=n;i++){
    cin>>b[i];
    br[b[i]]=i;
  }

  for(int i=1;i<=n;i++){
    cin>>c[i];
    cr[c[i]]=i;
  }

  long long count=0;
  msort(r,temp,1,n,br,cr,count);
  //now r is a possible solution
  for(int i=1;i<=n;i++){
    temp[i]=r[i];
  }

  bool flag=true;
  int I=n+5,K=n+5;
  flag=msort2(temp,b,temp2,1,n,br,I,K);
  if(flag==false){
    cout<<"inconsistent"<<endl;
    check(r,br,cr,n,I,K);
    //do some thing
  }
  else{
    for(int i=1;i<=n;i++){
      temp[i]=r[i];
    }
    I=n+5; K=n+5;
    flag=msort2(temp,c,temp2,1,n,cr,I,K);
    if(flag==false){
       cout<<"inconsistent"<<endl;
       check(r,br,cr,n,I,K);
       //do something
    }
    else{
      for(int i=1;i<=n;i++){
        temp[i]=r[i];
      }
      long long n1=0,n2=0,n3=0,n4=0;
      msort3(temp,temp2,1,n,n1);

      for(int i=1;i<=n;i++){
        temp[i]=b[i];
      }
      msort3(temp,temp2,1,n,n2);

      for(int i=1;i<=n;i++){
        temp[i]=c[i];
      }
      msort3(temp,temp2,1,n,n3);

      for(int i=1;i<=n;i++){
        temp[i]=br[c[i]];
      }
      msort3(temp,temp2,1,n,n4);

      if(n1==((n2+n3-n4)/2)){
         cout<<"consistent"<<endl;
         for(int z=1;z<=n;z++){
           cout<<r[z]<<" ";
         }
      }
      else{
        cout<<"inconsistent"<<endl;
        check(r,br,cr,n,n+5,n+5);
        //do some thing
      }

    }
  }


  return 0;
}



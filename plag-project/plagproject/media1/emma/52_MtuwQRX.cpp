#include<iostream>
#include<list>
using namespace std;
bool les(int i,int j, int *iq, int *ir)
{
int p=0;
if(i<j){
if(iq[i]<iq[j]){p++;}
if(ir[i]<ir[j]){p++;}
if(p>=2){return true;}
else{return false;}}

}

void mergesortsubarray(int *p,int *iq,int *ir,int *perm,int start, int mid , int end){
int i,j,index=start;
for(i=start,j=mid;(i<mid||j<end);){
if((i < mid) && (j < end)){
if(les(i,j,iq,ir)){perm[index]=p[i];i++;}
else{perm[index]=p[j];j++;}
}

else{
if(i < mid){perm[index]=p[i];i++;}
else{perm[index]=p[j];j++;}
}
index++;
}
}
void mergesort(int *p,int *iq,int *ir,int *perm,int start,int end){
if(end==start+1){return;}
int mid=(start+end)/2;
mergesort(p,iq,ir,perm,start,mid);
mergesort(p,iq,ir,perm,mid,end);
mergesortsubarray(p,iq,ir,perm,start,mid,end);
}
int main(){
int n;
cin>>n;cout<<endl;
int p[n+1],q[n+1],r[n+1],iq[n+1],ir[n+1],perm[n+1];
for(int i=1;i<n+1;i++){
p[i]=i;
cin>>q[i];
iq[q[i]]=i;
}
cout<<endl;
for(int i=1;i<n+1;i++){
cin>>r[i];
ir[r[i]]=i;
}
cout<<endl;
int start=1;
int end=n+1;
int consis=0,j;
mergesort(p,iq,ir,perm,start,end);
/*for(int i=1;i<n+1;i++){
for(j=i+1;j<n+1;j++){
if(!les(perm[i],perm[j],iq,ir)){
cout<<"inconsistent"<<"\n";
cout<<perm[i]<<" "<<perm[i+1]<<" "<<perm[j]<<endl;
consis=1;
break;
}
else{}
}
if(!les(perm[i],perm[j],iq,ir)){break;}
}*/
cout<<"inconsistent\n";
for(int i=1;i<n+1;i++){
cout<<perm[i]<<" ";
}


return 0;
}


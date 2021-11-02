#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
int A[n],B[n],C[n];
for(int i=0;i<n;i++){
cin>>A[i];
}
for(int i=0;i<n;i++){
cin>>B[i];
}
for(int i=0;i<n;i++){
C[i]=i;
}
int relation[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
relation[i][j]=0;
}
}
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
relation[A[i]-1][A[j]-1]++;
relation[A[j]-1][A[i]-1]--;
relation[B[i]-1][B[j]-1]++;
relation[B[j]-1][B[i]-1]--;
relation[C[i]][C[j]]++;
relation[C[j]][C[i]]--;
}
}
int f,con=1,place[n];
int ans1[n],ans2[n];
for(int g=0;g<n;g++){
ans1[g]=0;
ans2[g]=0;
}
for(int i=0;i<n;i++){
place[i]=1;
for(int j=0;j<n;j++){
if(relation[i][j]<0){place[i]++;}
//cout<<relation[i][j];
}
if(con==1){
if(ans1[place[i]-1]==0){
ans1[place[i]-1]=place[i];
}
else{
f=place[i];
con=2;
//cout<<1<<endl;
}
}
else if(con==2){
for(int k=0;k<i;k++){
if(place[k]==f){ans2[0]=k+1;
}
}
ans2[1]=i+1;
}
else{
if(place[i]==f){
//cout<<"1"<<endl;
ans2[2]=i+1;
break;
}
}
}
if(con==1){
cout<<"consistent"<<endl;
for(int h=0;h<n;h++){
cout<<place[h]<<" ";
}
}
else{
cout<<"inconsistent"<<endl;
cout<<ans2[0]<<" "<<ans2[1]<<" "<<ans2[2];
}
return 0;
}

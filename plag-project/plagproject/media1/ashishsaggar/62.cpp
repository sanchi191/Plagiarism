#include<iostream>
#include<vector>
using namespace std;
int* mg(int* a,int* b,int* d,int* e,int* f,int c,int l ){int s=(l+c)/2;
                                                          if(s==l)
                                                    mg(a,b,d,e,f,s,l);
                                                    mg(a,b,d,e,f,c,s+1);
                                                    //mgst
                                                    return f;
                                                    }
int main(){int c,l=0;
            cin>>c;
            int a[c+1];int b[c+1];int d[c+1];int e[c+1],f[c+1];
            a[0]=b[0]=e[0]=f[0]=d[0]=0;
            for(int i=1;i<c+1;i++){cin>>a[i];f[i]=i;}
            for(int i=1;i<c+1;i++){cin>>b[i];}
            for(int i=1;i<c+1;i++){d[a[i]]=i;e[b[i]]=i;}
            int* g=mg(a,b,d,e,f,c,l);
return 0;}

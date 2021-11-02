#include <iostream>
using namespace std;
int numi(int ini,int fin,int a[],int ai[],int n){
    if(ini<fin){
        int one,two;
        one=numi(ini,((ini+fin)/2),a,ai,n);
        two=numi(((ini+fin)/2)+1,fin,a,ai,n);
        int i, j, k;
        int *c = new int[n+1];
        i = ini;
        k = ini;
        j = ((ini+fin)/2)+1;
        int count=0;
        int total=0;
        while (i<=ini&&j<=fin){
        if(a[i]<a[j]){
        c[k]=a[i];
        total=total+count;
        k++;
        i++;
        }
        else{
        c[k]=a[j];
        count++;
        k++;
        j++;
        }
        }
        while(i<=((ini+fin)/2)){
        c[k]=a[i];
        total=total+count;
        k++;
        i++;
        }
        while(j<=fin){
        c[k]=a[j];
        count++;
        k++;
        j++;
        }
        for (i=ini;i<k;i++){
        a[i]=c[i];
        }
        return total+one+two;
    }
    else
    {return 0;}
}
bool lol(int ini,int fin,int p[],int a[],int ai[],int n){
    if(ini<fin){
    bool one,two;
        one=lol(ini,((ini+fin)/2),p,a,ai,n);
        two=lol(((ini+fin)/2)+1,fin,p,a,ai,n);
        int i,j,k,mini;
        int *c = new int[n+1];
        i = ini;
        k = ini;
        bool b=true;
        j = ((ini+fin)/2)+1;
        while (i<=ini&&j<=fin){
            if(p[i]<p[j]){
                if(j==((ini+fin)/2)+1){c[k]=p[i];k++;i++;}
                else{c[k]=p[i];b=b&&(ai[p[i]]<ai[mini]);k++;i++;}
            }
            else{
                if(j==((ini+fin)/2)+1){mini=p[((ini+fin)/2)+1];c[k]=p[j];k++;j++;}
                else{c[k]=p[j];if(p[j]<mini){mini=p[j];}
                    k++;j++;
                }
            }
        }
        while(i<=((ini+fin)/2)){
        c[k]=p[i];
        b=b&&(ai[p[i]]<ai[mini]);
        k++;
        i++;
        }
        while(j<=fin){
        c[k]=p[j];
        k++;
        j++;
        }
        for (i=ini;i<k;i++){
        p[i]=c[i];
        }
        return b&&one&&two;
    }
    else{return true;}
}
void msr(int ini,int fin,int p[],int ai[],int bi[],int ci[],int n){
    if(ini<fin){
        msr(ini,((ini+fin)/2),p,ai,bi,ci,n);
        msr(((ini+fin)/2)+1,fin,p,ai,bi,ci,n);
        int i, j, k;
        int *c = new int[n+1];
        i = ini;
        k = ini;
        j = ((ini+fin)/2)+1;
        while (i<=ini&&j<=fin){
        if((ai[p[i]]<ai[p[j]]&&bi[p[i]]<bi[p[j]])||(ci[p[i]]<ci[p[j]]&&bi[p[i]]<bi[p[j]])||(ai[p[i]]<ai[p[j]]&&ci[p[i]]<ci[p[j]])){
        c[k]=p[i];
        k++;
        i++;
        }
        else{
        c[k]=p[j];
        k++;
        j++;
        }
        }
        while(i<=((ini+fin)/2)){
        c[k]=p[i];
        k++;
        i++;
        }
        while(j<=fin){
        c[k]=p[j];
        k++;
        j++;
        }
        for (i=ini;i<k;i++){
        p[i]=c[i];
        }
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int *a = new int[n+1];
    int *b= new int[n+1];
    int *c=new int[n+1];
    int *ai = new int[n+1];
    int *bi= new int[n+1];
    int *ci=new int[n+1];
    int *p=new int[n+1];
    for(int it1=1;it1<n+1;it1++){cin>>a[it1];ai[a[it1]]=it1;}
    for(int it2=1;it2<n+1;it2++){cin>>b[it2];bi[b[it2]]=it2;}
    for(int it3=1;it3<n+1;it3++){c[it3]=it3;p[it3]=it3;ci[it3]=it3;}
    msr(1,n,p,ai,bi,ci,n);
    cout<<"consistent"<<endl;
    for(int it6=1;it6<n;it6++){cout<<p[it6]<<' ';}
        cout<<p[n];
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct input{

        int n;
        vector<int> A,B,C,D;

    bool dummyfunction(int i,int j){

        bool check1=(i<j);
        bool check2=(C[i]<C[j]);
        bool check3=(D[i]<D[j]);

        if((check1 && check2)||(check2 && check3)||(check3 && check1)){
            return true;
        }
        else{return false;}
    }

    input(){
        cin>>n;
        A.resize(n+1,0);B.resize(n+1,0);
        C.resize(n+1,0);D.resize(n+1,0);
        A[0]=-1;B[0]=-1;C[0]=-1;D[0]=-1;
        for(int i=1;i<n+1;i++){
            cin>>A[i];
        }
        for(int i=1;i<n+1;i++){
            cin>>B[i];
        }

        for(int i=1;i<n+1;i++){
            C[A[i]]=i;
            D[B[i]]=i;
        }

    }
};
input goutham;
bool checkfunction(int i,int j){
    if(goutham.dummyfunction(i,j)){return true;}
    else{return false;}
};

int main(){
    int *E=new int[(goutham.n)+1];
    for(int i=1;i<(goutham.n)+1;i++){
            E[i]=i;
        }

    sort(E+1,E+(goutham.n)+1,checkfunction);
    for(int l=1;l<=goutham.n;l++){

        for(int k=l+2;k<=goutham.n;k++){
                if(checkfunction(E[l],E[k])){continue;}
                else{cout<<"inconsistent"<<endl;
                     cout<<E[l]<<" "<<E[k-1]<<" "<<E[k];
                     return 0;
                }

        }


    }

    for(int i=1;i<(goutham.n)+1;i++){
        if(i==1){
            cout<<"consistent"<<endl;
            cout<<E[i];
        }
        else{cout<<" "<<E[i];}
    }

return 0;
};

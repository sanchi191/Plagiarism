#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class forSort{
    private :
        int n;

    public :
        vector<int> p,q,pInverse,qInverse;

        forSort(){
            p.push_back(0);
            q.push_back(0);
            pInverse.push_back(0);
            qInverse.push_back(0);
        }

        forSort(int m){
            n=m;
            pInverse.resize(n+1);
            qInverse.resize(n+1);
            p.push_back(0);
            q.push_back(0);
            pInverse[0]=0;
            qInverse[0]=0;

        }

        void getInv(){
            for (int i=1; i<=n; i++){
                pInverse[p[i]]=i;
                qInverse[q[i]]=i;
            }
        }

        bool operator() (int i, int j){
            bool result = false;
            if( (pInverse[i]<pInverse[j]) && (qInverse[i]<qInverse[j]) ) { result = true; }
            if( (pInverse[i]<pInverse[j]) && i<j ) { result = true; }
            if( (qInverse[i]<qInverse[j]) && i<j ) { result = true; }
            return result;
        }

        bool comparison(int i, int j){
            bool result=false;
            if( (pInverse[i]<pInverse[j]) && (qInverse[i]<qInverse[j]) ) { result = true; }
            if( (pInverse[i]<pInverse[j]) && i<j ) { result = true; }
            if( (qInverse[i]<qInverse[j]) && i<j ) { result = true; }
            return result;
        }

};


int main(){
    int N;
    cin>>N;
    int x;
    vector<int> r,rInverse(N+1);
    forSort myObject(N);
    bool final=true;
    int x1,x2,x3;
    r.push_back(0);
    for (int i=1; i<=N ; i++ ){
        cin>>x;
        (myObject.p).push_back(x);
    }
    for (int i=1; i<=N ; i++ ){
        cin>>x;
        (myObject.q).push_back(x);
    }
    for (int i=1; i<=N ; i++ ){
        r.push_back(i);
    }

    myObject.getInv();

    sort(r.begin()+1, r.end(), myObject);

    rInverse[0]=0;
    for (int i=1; i<=N; i++){
        rInverse[r[i]]=i;
    }

    for (int i=1; i<=N ; i++ ){
        for (int j=i+1; j<=N ; j++){
            if(
            ((myObject.pInverse[r[i]]<myObject.pInverse[r[j]]) && (myObject.qInverse[r[i]]<myObject.qInverse[r[j]])) ||
            ((myObject.pInverse[r[i]]<myObject.pInverse[r[j]]) && (r[i]<r[j])) ||
            ((r[i]<r[j]) && (myObject.qInverse[r[i]]<myObject.qInverse[r[j]]))
            ) {}
            else {final = false;
                x1=r[i];
                x2=r[j-1];
                x3=r[j];
            }

        }
    }

    if(final==false){cout<<"inconsistent"<<endl;
                        cout << x1 << " " << x2 << " " << x3 <<endl;
    }
    else{   cout<<"consistent"<<endl;
            for (int i=1; i<=N ; i++ ){
                cout<<r[i]<<" ";
            }
    }

return 0; }

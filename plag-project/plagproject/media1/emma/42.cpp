//1405000002 lab5
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> v4,v5;


//v2 inversed;v1 q;v2 of size n
void inverse1(vector<int> &p,vector<int> &q){
    for(int i=0;i<n;i++){
        q[p[i]-1] = i;
    }
    return;
}

//of p in q
bool everyInversion(vector<int>::iterator it1,vector<int>::iterator it2,vector<int> &qi,int n,int &sum){
    if(it2==(++it1)){
        return true;
    }
    it1--;
    bool bl,br;
    vector<int>::iterator temp1,temp2;

    vector<int>::iterator it4,it5,it6;
    it4 = it1;
    it6 = it2;
    vector<int>::iterator temp=it1;
    for(int i=0;i<(n/2);i++,temp++){}
    it5 = temp;
    bl = everyInversion(it4,it5,qi,(n/2),sum);
    br = everyInversion(it5,it6,qi,(n/2)+(n%2),sum);
    if(!(bl&&br)){return false;}
    //leftmost is element who is at leftmost position
    int leftmost = -1;
    bool isEvery = true;
    vector<int> vf;

    temp1 = it4;
    temp2 = it5;
    int count1 = 0;

    while((temp1!=it5)&&(temp2!=it6)){

        if((*temp1)>(*temp2)){
            vf.push_back(*temp2);
            if(leftmost==-1){leftmost=(*temp2);temp2++;continue;}
            if(qi[leftmost-1]>qi[(*temp2)-1]){
                leftmost = (*temp2);
            }
            temp2++;
            count1++;
        }
        else{
            vf.push_back(*temp1);
            if(leftmost==-1){temp1++;continue;}
            if(qi[(*temp1)-1]>=qi[leftmost-1]){
                isEvery = false;
                break;
            }
            temp1++;
            sum += count1;
        }
    }
    if(isEvery){
        if(temp1==it5){
            while(temp2!=it6){
                vf.push_back(*temp2);
                temp2++;
                count1++;
            }
        }
        else{
            while(temp1!=it5){
                vf.push_back(*temp1);
                if(leftmost==-1){temp1++;continue;}
                if(qi[(*temp1)-1]>=qi[leftmost-1]){
                    isEvery = false;
                    break;
                }
                temp1++;
                sum += count1;
            }
        }
    }
    int i = 0;
    while(it1!=it6){
        (*it1) = vf[i];
        it1++;i++;
    }
    if(isEvery==false){return false;}else{return true;}
}

//v4 p inverted;v5 q inverted
bool compaire1(int i,int j){
    if(i>j){
        if((v4[i-1]<v4[j-1])&&(v5[i-1]<v5[j-1])){return true;}else{false;}
    }
    else{
        if((v4[i-1]<v4[j-1])||(v5[i-1]<v5[j-1])){return true;}else{false;}
    }

}

void printSolution(bool isConsitent,vector<int> &v3){
    if(isConsitent){
        cout<<"consistent"<<endl;
        for(int i=0;i<n;i++){
            cout<<v3[i]<<" ";
        }
        cout<<endl;
    }
    return;
}


int main(){
    cin>>n;
    vector<int> v1(n),v2(n),v3(n);
    v4.resize(n);v5.resize(n);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v1[i] = temp;
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v2[i] = temp;
    }
    inverse1(v1,v4);
    inverse1(v2,v5);
    for(int i=0;i<n;i++){v3[i]=i+1;}
    sort(v3.begin(),v3.end(),compaire1);

    printSolution(true,v3);
    return 0;
}

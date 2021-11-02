#include<iostream>
#include<list>
#include<vector>
using namespace std;
//class pint{
//public:
//    int x;//index;
//    list<pint>::iterator it;
//};
list<int>l1,l2,l3;
int n;
vector<int>l1inv;
vector<int>l2inv;
vector<int>l3inv;
//void merge_sort(list<int>l);
//void merge(list<int>l1 ,list<int>l2);
bool lessthan(int &lhs,int &rhs){
         if((lhs<rhs)&&((l1inv[lhs]<l1inv[rhs])||(l2inv[lhs]<l2inv[rhs]))){
               return true;
         }
         if((lhs>rhs)&&(l1inv[lhs]<l1inv[rhs])&&(l2inv[lhs]<l2inv[rhs])){
               return true;
         }
         return false;
}
int main(){
     int temp,thirdlist;
     cin>>n;
     l1inv.resize(n+1,0);
     l2inv.resize(n+1),0;
     for(int i=0;i<n;i++){
     thirdlist=i+1;
     //thirdlist.index=i;
        cin>>temp;
        //temp.index=i;
        l1.push_back(temp);
        //l1.back().it = (l1.end());
        //(l1.back().it)--;
        l1inv[l1.back()]=i+1;
        l3.push_back(thirdlist);
     }
     for(int i=0;i<n;i++){
     thirdlist=i+1;
     //thirdlist.index=i;
        cin>>temp;
        //temp.index=i;
          l2.push_back(temp);
        //l2.back().it = (l2.end());
        //(l2.back().it)--;
        l2inv[l2.back()]=i+1;
     }
     l3.sort(lessthan);
     for(int i=0;i<n+1;i++){
     }
     for(int i=0;i<n+1;i++){
     }cout<<endl;
     list<int>::iterator it,it2,it3;

     for(it=l3.begin();it!=l3.end();it++){
     it2=it;it2++;
           for( ;it2!=l3.end();it2++){
             if(!lessthan(*it,*it2)){cout<<"inconsistent"<<endl;
             it3=it;it3++;
             for( ;it3!=it2;it3++){
                   if(lessthan(*it,*it3)&&lessthan(*it3,*it2)){cout<< *it <<" "<< *it3<<" "<<*it2<<endl;break;}
             }
             return 0;}
        }
     }
     cout<<"consistent"<<endl;
     for(it=l3.begin();it!=l3.end();it++){
          cout<<(*it)<<" ";
     }
     cout<<endl;

}
//bool lessthan(int a,int b,list<int> &l1,list<int> &l2){}

//merge_sort(list<int>l){
//
//}

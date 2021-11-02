#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

vector <int> p,q,pInv,qInv;
int minp,n;
int a,b,c;

int minq,count1;
bool cons=1;
bool incon=0;

bool compare(int i, int j) {

if(i<j) {
    if(pInv[i]<pInv[j] || qInv[i]<qInv[j]) return 1;
    else return 0;
}
else {
    if(pInv[i]<pInv[j] && qInv[i]<qInv[j]) return 1;
    else return 0;
}
}

vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> result;
   minp = n;
   minq = n;

   while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
         if (left.front() < right.front()) {
            result.push_back(left.front());
            //cout<<left.front()<<" ";
            if ( pInv[left.front()]>minp ) {
                cons=0;
                if(incon==0) {
                a=left.front();
                b=p[minp];
                if(compare(a,b)==1) {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==1 && compare(k,a)==1) {c=k; break;}
                    }
                }
                else {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==0 && compare(k,a)==0) {c=k; break;}
                    }
                }
                incon=1;
                //cout<<"1";
                }
                }
            if ( qInv[left.front()]>minq ) {
                cons=0;
                if(incon==0) {
                a=left.front();
                b=q[minq];
                if(compare(a,b)==1) {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==1 && compare(k,a)==1) {c=k; break;}
                    }
                }
                else {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==0 && compare(k,a)==0) {c=k; break;}
                    }
                }
                incon=1;
                //cout<<"2";
                }
                }
            left.erase(left.begin());
         }
	 else {
            result.push_back(right.front());
            //cout<<right.front()<<" ";
            minp = min(pInv[right.front()],minp);
            //cout<<minp<<" ";
            minq = min(qInv[right.front()],minq);
           // cout<<minq<<endl;
            right.erase(right.begin());
         }
      }  else if (left.size() > 0) {
            for (int i = 0; i < left.size(); i++) {
               result.push_back(left[i]);
               if ( pInv[left[i]]>minp ){
                cons=0;
                if(incon==0) {
                a=left.front();
                b=p[minp];
                if(compare(a,b)==1) {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==1 && compare(k,a)==1 && k!=a && k!=b) {c=k; break;}
                    }
                }
                else {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==0 && compare(k,a)==0 && k!=a && k!=b) {c=k; break;}
                    }
                }
                incon=1;
                //cout<<"3";
                }
                }
               if ( qInv[left[i]]>minq ) {
                cons=0;
                if(incon==0) {
                a=left.front();
                b=q[minq];
                if(compare(a,b)==1) {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==1 && compare(k,a)==1 && k!=a && k!=b) {c=k; break;}
                    }
                }
                else {
                    for (int k=0;k<n;k++) {
                        if ( compare(b,k)==0 && compare(k,a)==0 && k!=a && k!=b) {c=k; break;}
                    }
                }
                incon=1;
                //cout<<"4";
                }
                }
               }
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

vector<int> mergeSort(vector<int> m)
{
   if (m.size() <= 1)
      return m;

   vector<int> left, right, result;
   int middle = (m.size()+ 1) / 2;

   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < m.size(); i++) {
      right.push_back(m[i]);
   }

   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);

   return result;
}

vector<int> merge1(vector<int> left, vector<int> right)
{
   vector<int> result;
   int tempCount=0;
   while ((left.size() > 0 || right.size() > 0)) {
      if ((left.size() > 0 && right.size() > 0)) {
         if (left.front() < right.front()) {
            result.push_back(left.front());
            count1=count1+tempCount;
            left.erase(left.begin());
         }
	 else {
            result.push_back(right.front());
            tempCount++;
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < left.size(); i++) {
               result.push_back(left[i]);
               count1=count1+tempCount;
               }
            break;
      }  else if (right.size() > 0) {
            for (int i = 0; i < right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

vector<int> mergeSort1(vector<int> m)
{
   int count1=0;
   if (m.size() <= 1)
      return m;

   vector<int> left, right, result;
   int middle = (m.size()+ 1) / 2;

   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < m.size(); i++) {
      right.push_back(m[i]);
   }

   left = mergeSort1(left);
   right = mergeSort1(right);
   result = merge1(left, right);

   return result;
}





int main () {

int countp=0;
int countq=0;
int countr=0;
a=0;
b=1;
c=2;
cin>>n;
p.resize(n);
q.resize(n);
pInv.resize(n);
qInv.resize(n);
vector <int> r (n,1);
vector <int> rTest (n);
vector <int> s (n);

for (int i=0;i<n;i++) {
    cin>>p[i];
    p[i]--;
    pInv[p[i]]=i;
}

for (int i=0;i<n;i++) {
    cin>>q[i];
    q[i]--;
    qInv[q[i]]=i;
    r[i]=i;
    s[i]=pInv[q[i]];
}

//cout<<compare(1,2)<<" "<<compare(2,3);

sort (r.begin(),r.end(),compare);
rTest=r;
//for(int i=0;i<n;i++) {
//   cout<<rTest[i]+1<<" ";
//  cout<<endl;
//}

rTest = mergeSort(rTest);
//cout<<cons<<endl;
//for(int i=0;i<n;i++) {
 //  cout<<rTest[i]+1<<" ";
  // cout<<endl;
//}

rTest = p;
rTest = mergeSort1(rTest);
countp=count1;
count1=0;

rTest = q;
rTest = mergeSort1(rTest);
countq=count1;
count1=0;

rTest = r;
rTest = mergeSort1(rTest);
countr=count1;
count1=0;

s = mergeSort1(s);

if(countr != (countp + countq - count1)/2) cons=0;

if (cons==1) {
cout<<"consistent"<<endl;
for(int i=0;i<n;i++) {
    cout<<r[i]+1<<" ";
}
}
else {
cout<<"inconsistent"<<endl;
cout<<a+1<<" "<<b+1<<" "<<c+1<<endl;
}
//for(int i=0;i<n;i++) {
//    cout<<pInv[i]<<" ";
//}



return 0;
}

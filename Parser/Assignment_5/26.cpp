#include<iostream>
#include<vector>
using namespace std;
vector<int> merge(vector<int> lt, vector<int> rt,vector<int> &invp, vector<int> &invq)
{
   vector<int> result;
   while (lt.size() > 0 || rt.size() > 0) {
      if (lt.size() > 0 && rt.size() > 0) {
         if (invp[lt.front()-1]<invp[rt.front()-1] || invq[lt.front()-1]<invq[rt.front()-1]) {
            result.push_back(lt.front());
            lt.erase(lt.begin());
         }
	 else {
            result.push_back(rt.front());
            rt.erase(rt.begin());
         }
      }  else if (lt.size() > 0) {
            for (int i = 0; i < lt.size(); i++)
               result.push_back(lt[i]);
            break;
      }  else if (rt.size() > 0) {
            for (int i = 0; i < rt.size(); i++)
               result.push_back(rt[i]);
            break;
      }
   }
   return result;
}

vector<int> mergeSort(vector<int> m,vector<int> &invp, vector<int> &invq)
{
   if (m.size() <= 1)
      return m;

   vector<int> lt, rt, result;
   int middle = (m.size()+ 1) / 2;

   for (int i = 0; i < middle; i++) {
      lt.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      rt.push_back(m[i]);
   }

   lt = mergeSort(lt,invp,invq);
   rt = mergeSort(rt,invp,invq);
   result = merge(lt, rt,invp,invq);

   return result;
}
int main()
{
    int n,i;
    cin>>n;
    n=6;
    vector<int> p(n,0);
    vector<int> q(n,0);
    vector<int> invp(n,0);
    vector<int> invq(n,0);
    vector<int> r(n,0);
    vector<int> s(n,0);
    ///////////////////////////
    //p[0]=4;p[1]=2;p[2]=6;p[3]=1;p[4]=5;p[5]=3;
    //q[0]=5;q[1]=2;q[2]=3;q[3]=6;q[4]=1;q[5]=4;
    //////////////////////Input

    for(i=0;i<n;i++){
        cin>>p[i];
        invp[p[i]-1]=i+1;
        r[i]=i+1;
    }
    for(i=0;i<n;i++){
        cin>>q[i];
        invq[q[i]-1]=i+1;
        s[i]=invp[q[i]-1];
    }


    r=mergeSort(r,invp,invq);


    int cntp=0;
    int cntq=0;
    int cnts=0;
    int cntr=0;
    bool flag=false;
    int j;
    for(int i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[j]<p[i])
                cntp++;
            if(q[j]<q[i])
                cntq++;
            if(s[j]<s[i])
                cnts++;
            if(r[j]<r[i])
                {
                cntr++;
                if(invp[r[j]-1]<invp[r[i]-1]||invq[r[j]-1]<invq[r[i]-1])
                    {flag=true;break;}
                }
        }
    }
    //cout<<temp1<<temp2<<endl;

    //cout<<cntp<<endl<<cntq<<endl<<cnts<<endl<<cntr<<endl;

    if(cntr==cntp+cntq-cnts&&!flag)
        {cout<<"consistent"<<endl;
        for(int k=0;k<n;k++)
            cout<<r[k]<<" ";}
    else
        {
        cout<<"inconsistent"<<endl;
        //cout<<r[temp2-1]<<" "<<r[temp2]<<" "<<r[temp1]<<endl;
        }



}


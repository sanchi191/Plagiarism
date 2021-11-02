//#include <stdio.h>
//#include <stdlib.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
vector<int> invp;
vector<int> invq;


bool myfunction(int i, int j)
    {
        //cout<<"into myfunction for i and j="<<i<<" "<<j<<"\n";
        bool ans=((invp[i]<invp[j])&&invq[i]<invq[j])||((invq[i]<invq[j])&&i<j)||((invp[i]<invp[j])&&i<j);
        //cout<<"bool is="<<ans<<endl;
        return(ans);

    }
int main()
{

    cin>>n;
    vector<int> p,q,r;
    p.resize(n+1);
    q.resize(n+1);
    r.resize(n+1);
    invp.resize(n+1);
    invq.resize(n+1);
    vector<int> toSort(n+1);
    for(int i=1;i<=n;i++)
    {
        r[i]=i;
        toSort[i]=i;
        cin>>p[i];
    }
    /*for(int i=1;i<=n;i++)
    cout<<p[i]<<" ";
    cout<<endl;
*/    for(int i=1;i<=n;i++)
    {
        cin>>q[i];
    }
    /* for(int i=1;i<=n;i++)
    cout<<q[i]<<" ";
    cout<<endl;
*/
    for(int i=1;i<=n;i++)
    {
        invp[p[i]]=i;
        invq[q[i]]=i;
    }

    //mergeSort(toSort,n);
    sort(toSort.begin()+1, toSort.end(), myfunction);
    int temp1,temp2,temp3,flag;
    flag=0;

   for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {


            if(myfunction(toSort[i],toSort[j]))
            {
                continue;
            }
            else
            {
                temp1=toSort[i];
                temp3=toSort[j];
                temp2=toSort[(i+j)/2];
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
      {

      cout<<"inconsistent\n";
      cout<<temp1<<" "<<temp2<<" "<<temp3<<"\n";
      }
    else
    {
    cout<<"consistent\n";
    for(int i=1;i<=n;i++)
    {
    cout<<toSort[i]<<" ";
    }

    cout<<endl;
    }




}

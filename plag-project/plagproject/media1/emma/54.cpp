#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> p;
   vector<int>q;
   int n,i,x,j,k,k1,k2,t;
    cin>>n;
   vector<int>i1(n);
    vector<int>i2(n);
      vector<int>i3(n);
    vector<int>r;
   for(i=0;i<n;i++)
   {cin>>x;
    p.push_back(x);
     i1[x-1]=i;
    }
    for(i=0;i<n;i++)
   {cin>>x;
    q.push_back(x);
     i2[x-1]=i;
      }

    for(i=0;i<n-1;i++)
       {
          for(j=i+1;j<n;j++)
            {
               if(p[i]>p[j]&&i2[p[i]-1]<i2[p[j]-1])
                  {k1=p[i];
                   k2=p[j];
                   i1[p[i]-1]=-1;
                   i1[p[j]-1]=-1;
                   break;
                  }
                }
         };
         int count=0;
         int a[n];
         int b[n];
        for(i=0;i<n;i++)
         {k=p[i];
         if(i1[k-1]==-1)
            { r.push_back(k);
              a[k-1]=-1;
             i3[k-1]=count;
             }
          }
          count=0;
          cout<<"consistent";
          for(i=0;i<n;i++)
          {
            if(a[i]==0)
            { b[i]==i+1;}
            else{
                  if(count!=r.size())
                  {
                 b[i]=r[count];

                 count++;}
                 }
                  cout<<b[i]<<' ';

          }



          return 0;
    }

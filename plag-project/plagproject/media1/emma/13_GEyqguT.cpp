#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    friend bool operator< (Cents &cC1, Cents &cC2);
};
bool operator< (Cents &cC1, Cents &cC2)
{
    return cC1.m_nCents < cC2.m_nCents;
}

struct contestant
{
    int n;
    vector<int> p,q,inverse_p,inverse_q;

    bool tempfunc(int i,int j)
    {
     bool b=(inverse_p[i]<inverse_p[j]);
     bool c=(inverse_q[i]<inverse_q[j]);

    if((b&&c))
        {
        return true;
        }
        else{ return false; }
    }

contestant()
    {

    cin>>n;
    p.resize(n+1);
    q.resize(n+1);
    inverse_p.resize(n+1);
    inverse_q.resize(n+1);
    p[0]=0;
    q[0]=0;
    inverse_p[0]=0;
    inverse_q[0]=0;
    for(int i=1;i<n+1;i++)
         {
         cin>>p[i];
         inverse_p[p[i]]=i;
         }
    for(int i=1;i<n+1;i++)
         {
          cin>>q[i];
          inverse_q[q[i]]=i;
         }

     }

};
contestant avi;

 bool checkfunc(int i,int j)
    {
     if(avi.tempfunc(i,j)){return true;}
    else {return false;}
    }


int main()
{
  int i,n;
  class person;
  int *result= new int[(avi.n)+1];

        for(i=1;i<(avi.n)+1;i++)
            {
                result[i]=i;

            }

    sort(result+1,result+(avi.n)+1,checkfunc);


        for(i=1;i<(avi.n)+1;i++)
            {
             if(i==1)
                {cout<<"consistent"<<endl;
                cout<<result[i];
                }

            else { cout<<" "<<result[i];}
            }



    return 0;

}

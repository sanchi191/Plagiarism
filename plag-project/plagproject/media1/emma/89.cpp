#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <algorithm>
using namespace std;


class sequence
{
public:

    int n;
    vector <int> a;
    vector <int> ia;
    sequence (int N);
    sequence ();
    sequence(const sequence& y);
    ~sequence();
    void setinv();
    int getelem(int i);
    void pushb(int i);
    friend bool compareij(const int i, const int j);
};

sequence::sequence()
{
    a.clear();
    n=0;
}

sequence::sequence(int N)
{
    n=N+1;
    a.resize(n);
    ia.resize(n);
    for(int i=1; i<n; i++)
        a[i]=i;
}

sequence::~sequence()
{
    a.clear();
}

void sequence::setinv()
{
    ia.resize(n);
    for(int i=1; i<n; i++)
    {
        ia[a[i]]=i;
    }
}

int sequence::getelem(int i)
{
    return a[i];
}

sequence::sequence(const sequence& y)
{
    n = y.n;
    a = y.a;
    ia = y.ia;
}

/*************************************/

   bool compareij(const int i, const int j,sequence p,sequence q)
    {
        bool flag1,flag2,flag3,flag4;

        if((p.ia[i]<p.ia[j])&&(q.ia[i]<q.ia[j]))
        {
            flag1 = true;
        }
        else
        {
            flag1 = false;
        }
        if((q.ia[i]<q.ia[j])&&(i<j))
        {
            flag2 = true;
        }
        else{flag2 = false;}
        if((p.ia[i]<p.ia[j])&&(i<j))
        {
            flag3 = true;
        }
        else{flag3 = false;}

        if(flag1||flag2||flag3)
        {
            flag4 = true;
        }
        return flag4;

    }
/***********************/
class compareseq
{
public:
    sequence p;
    sequence q;

    compareseq(sequence a,sequence b)
    {
        p = a;
        q = b;
    }

    bool operator()(int i,int j)
    {
        return compareij(i,j,p,q);
    }

 };
/********************************/
 bool consissq(sequence p,sequence q,sequence r,int n)
 {  bool flag=true;
    int i,j;
    for(i=1;i<n+1;i++){
        for(j=i+1;j<n+1;j++)
        {
                if(!(compareij(r.a[i],r.a[j],p,q)))
                {
                    flag = false;
                    return flag;
                }
        }
    }
    return flag;
 }
/********************************/
int main()
{
    int n,x,i,j;
    bool flag;
    cin>>n;
    sequence p(n),q(n);
    sequence r(n);

    for(i=1; i<n+1; i++)
    {
        cin>>x;
        p.a[i]=x;
    }

    for(i=1; i<n+1; i++)
    {
        cin>>x;
        q.a[i]=x;
    }

//end input
/***********************************/

    p.setinv();
    q.setinv();
    r.setinv();

    compareseq pqr(p,q);

    vector<int>::iterator beg = r.a.begin();
    beg++;

    sort(beg,(r.a).end(),pqr);
    r.setinv();

    flag = true;
    for(i=1;i<n+1;i++){
        for(j=i+1;j<n+1;j++)
    {
        if(!(compareij(r.a[i],r.a[j],p,q)))
            {
                flag = false;
                break;
            }
    }
    if(!flag){break;}
    }

    if(flag)
    {
    cout<<"consistent"<<endl;
    for(i=1; i<n+1; i++)
    {
        cout<<r.a[i]<<" ";
    }
    }
    else
    {
    cout<<"inconsistent"<<endl;

    cout<<r.a[i]<<" "<<r.a[j-1]<<" "<<r.a[j];
    }

    return 0;
}

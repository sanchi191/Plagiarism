#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sequence
{
private :
    int n;
public :
    vector <int> s,sin;

    sequence()
    {

    }
    sequence(int m)
    {
        n=m;
        s.resize(n+1);
        for (int i=0; i<=n; i++)
        {
            s[i]=0;
        }
    }

    void setsin()
    {
        sin.resize(n+1);
        sin[0]=0;
        for (int i=1; i<=n; i++)
        {
            sin[s[i]]=i;
        }
        return;
    }

    /******************************************************************************/

    typedef std::vector<int>::iterator vecit;
    void merge(vecit left, vecit leftend, vecit right, vecit rightend, vecit nums)
    {
        while (left != leftend)
        {
            if (*left < *right || right == rightend)
            {
                *nums = *left;
                ++left;
            }
            else
            {
                *nums = *right;
                ++right;
            }

            ++nums;
        }

        while (right != rightend)
        {
            *nums = *right;
            ++right;
            ++nums;
        }
    }

    void mergesort(std::vector<int>& nums)
    {
        if (nums.size() > 1)
        {
            std::vector<int>::size_type mid = nums.size() / 2;
            std::vector<int> left(nums.begin(), nums.begin() + mid);
            std::vector<int> right(nums.begin() + mid, nums.end());

            mergesort(left);
            mergesort(right);

            merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());
        }
        else
        {
            return;
        }
    }
    /******************************************************************************/
};

class compareseq
{
public :

    compareseq()
    {

    }

    sequence p1, q1;

    bool comparison (int i,int j,sequence p2,sequence q2)
    {
        bool result=false;
        if (p2.sin[i]<p2.sin[j]&&q2.sin[i]<q2.sin[j])
        {
            result=true;
        }
        if (p2.sin[i]<p2.sin[j]&&i<j)
        {
            result=true;
        }
        if (q2.sin[i]<q2.sin[j]&&i<j)
        {
            result=true;
        }

        return result;
    }

    bool operator() (int i, int j)
    {
        bool result=false;
        if (comparison(i,j,p1,q1)==true)
        {
            result= true;
        }
        return result;
    }

};

int main()
{
    //start taking input
    int n;
    cin>>n;
    sequence p(n),q(n),r(n);

    int x;

    for (int i=1; i<=n; i++)
    {
        cin>>x;
        (p.s)[i]=x;
    }

    for (int i=1; i<=n; i++)
    {
        cin>>x;
        (q.s)[i]=x;
    }

    p.setsin();
    q.setsin();
    //end of input
    compareseq A;
    A.p1=p;
    A.q1=q;

    for (int i=1; i<=n; i++)
    {
        (r.s)[i]=i;
    }
    r.setsin();

    sort((r.s).begin()+1,(r.s).end(),A);

    bool k=true;

    int i=1, j=1;
    for (i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(A.comparison((r.s)[i],(r.s)[j],p,q))
            {

            }
            else
            {
                k=false;
                break;
            }
        }

        if (!k)
        {
            break;
        }
    }

    if (k)
    {
        cout<<"consistent";
        for(int i=1;i<=n;i++)
        {
            cout<<(r.s)[i]<<" ";
        }

    }
    else
    {
        cout<<"inconsistent"<<endl;;
        cout<<(r.s)[i]<<" "<<(r.s)[j-1]<<" "<<(r.s)[j];
    }


    return 0;

}


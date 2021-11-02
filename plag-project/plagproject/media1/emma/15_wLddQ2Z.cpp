#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> p;
vector <int> q;
vector <int> p_inv;
vector <int> q_inv;


bool check(int a,int b) ///returns true if a < b (fancy < Operator)
{
    //cout<<"here2"<<endl;
    if(a<b)
    {
        if((p_inv[a]<p_inv[b])||(q_inv[a]<q_inv[b]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if((p_inv[a]<p_inv[b])&&(q_inv[a]<q_inv[b]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


void mergeSortedSubarrays(vector <int> &A, int start, int mid, int en)
{
    int i, j;
    vector <int> tempA(A.size()) ;
    int index = start;
    for (i = start, j = mid; ((i < mid) || (j < en)); )   // Merging loop
    {
        if ((i < mid) && (j < en))   // None of the two subarrays fully seen yet
        {
            if (check(A[j],A[i]))
            {

                tempA[index] = A[j];
                j++;
            }
            else
            {
                tempA[index] = A[i];
                i++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = A[i];    // A[mid] … A[end-1] seen
                i++;
            }
            else
            {
                tempA[index] = A[j];    // A[start] … A[mid-1] seen
                j++;
            }
        }
        index ++;
    }
    for(int i=start; i<en; i++)
    {
        A[i]=tempA[i];
    }
    return;
};


void mergeSort(vector <int> &A, int start, int en)
{
    if (en == start +1)
    {
        return;    //Subarray of interest has 1 element
    }
    int mid = (start + en)/2; //Get mid-index of subarray of interest
    mergeSort(A, start, mid); // Sort subarray A[start] … A[mid-1]
    mergeSort(A, mid, en); // Sort subarray A[mid] … A[end-1]
// Merge sorted subarrays A[start] … A[mid-1] and A[mid] … A[end-1]
    mergeSortedSubarrays(A, start, mid, en);
    return;
};


/*
class Data
{

public:
    Data() ///constructor function
    {
        cin>>n;
        p.resize(n);
         q.resize(n);
          p_inv.resize(n);
           q_inv.resize(n);
        for(int i=0; i<n; i++)
        {
            cin>>p[i];
            p_inv[p[i]]=i;
        };
        for(int i=0; i<n; i++)
        {
            cin>>q[i];
            q_inv[q[i]]=i;
        };
    };



    bool check(int a,int b) ///returns true if a < b (fancy < Operator)
    {
        if(a<b)
        {
            if(p_inv[a]<p_inv[b]||q_inv[a]<q_inv[b])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(p_inv[a]<p_inv[b]&&q_inv[a]<q_inv[b])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };


};
*/
int main()
{
    cin>>n;

    p.resize(n);
    q.resize(n);
    p_inv.resize(n);
    q_inv.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
        p[i]--;
        p_inv[p[i]]=i;
    };
    for(int i=0; i<n; i++)
    {
        cin>>q[i];
        q[i]--;
        q_inv[q[i]]=i;
    };

    vector <int> A(n);
    for(int i=0; i<n; i++)
    {
        A[i]=i;
    };
//A[0]=5;A[2]=2;A[1]=3;A[4]=1;
    mergeSort(A,0,n);
    /*
    for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"hehe"<<endl;
    */
    bool m=false;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i < j)
            {
                if(check(A[i],A[j]))
                {
//cout<<"here"<<endl;
                }
                else
                {


                    int k=j-1;
                    while((k!=i)&&(!check(A[k],A[j])))
                    {
                        k--;
                    };
                    if(k==i)
                    {
                        continue;
                    }
                    else
                    {
                        m=true;
                        cout<<"inconsistent"<<endl;
                        cout<<(A[i]+1)<<" "<<(A[k]+1)<<" "<<(A[j]+1)<<endl;
                        break;
                    }
                }
            }
        }
        if(m)
        {
            break;
        }
    }
    if(m==false)
    {
        cout<<"consistent"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<(A[i]+1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}



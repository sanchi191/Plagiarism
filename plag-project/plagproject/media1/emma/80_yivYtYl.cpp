#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool lessthan(int i, int j, vector <int> &invp1, vector <int> &invp2, vector <int> &p3)
{
    if( ( (invp1[i-1]<invp1[j-1]) && (invp2[i-1]<invp2[j-1]) ) || ( (invp1[i-1]<invp1[j-1]) && (p3[i-1]<p3[j-1]) ) || ( (invp2[i-1]<invp2[j-1]) && (p3[i-1]<p3[j-1]) ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void mergeSortedSubarrays(vector<int> &A, int start, int mid, int end, vector<int> &invp1, vector<int> &invp2, vector<int> &p3, int n)
{
    int i, j; vector<int> tempA(n); int index = start;
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {
        if ((i < mid) && (j < end))
        {
            if ( lessthan(A[i],A[j], invp1, invp2, p3) ) {tempA[index] = A[i]; i++;}
            else {tempA[index] = A[j]; j++;}
        }
        else
        {
            if (i < mid) {tempA[index] = A[i]; i++;}
            else
             if (j < end) {tempA[index] = A[j]; j++;}
        }
        index ++;
    }
    for (i = start; i < end; i++) {A[i] = tempA[i];}
    return;
}

void mergeSort(vector<int> &A, int start, int end, vector<int> &invp1, vector<int> &invp2, vector<int> &p3, int n)
{
    if (end == start +1) { return; }
    int mid = (start + end)/2;
    mergeSort(A, start, mid, invp1, invp2, p3, n);
    mergeSort(A, mid, end, invp1, invp2, p3, n);

    mergeSortedSubarrays(A, start, mid, end, invp1, invp2, p3, n);
    return;
}



int main()
{
    int n;
    vector <int> p1;
    vector <int> p2;
    vector <int> p3;

    cin>>n;

    vector <int> invp1(n);
    vector <int> invp2(n);
    vector <int> invp3(n);
    vector <int> q(n);

    for (int i=0; i<n;i++)
    {
        int temp;
        cin>>temp;
        p1.push_back(temp);
    }

    for (int i=0; i<n;i++)
    {
        int temp;
        cin>>temp;
        p2.push_back(temp);
    }

    for (int i=1; i<=n;i++)
    {
        p3.push_back(i);
    }

    q=p3;


    //input part finished

    //computing inverses of p1 and p2
    for (int i=0; i<n; i++)
    {
        invp1[(p1[i]-1)]=i+1;
    }

    for (int i=0; i<n; i++)
    {
        invp2[(p2[i]-1)]=i+1;
    }

    //computing the permutation q

    mergeSort(q, 0, n, invp1, invp2, p3, n);

    //check if q is consistent
    int c=0;
    int i1=0;
    int j1=0;
    int k1=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(!(lessthan(q[i], q[j], invp1, invp2, p3)))
            {
                c=1;//denotes q is inconsistent
                i1=q[i];
                j1=q[j-1];
                k1=q[j];
            }
        }
    }

    if(c==1)
    {
        cout<<"inconsistent"<<endl;
        cout<<i1<<" "<<j1<<" "<<k1;
    }
    else
    {
        cout<<"consistent"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<q[i]<<" ";
        }
    }


    return 0;
}

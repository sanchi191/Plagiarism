#include<iostream>
#include<vector>
using namespace std;

void invert(vector<int> &p, vector<int> &p_inv)
{
    for(int i=0;i<p.size();i++)
        p_inv[p[i]-1]=i;
    return;
}

bool lessthan(vector<int> &A, vector<int> &B, vector<int> &C, int i, int j)
{
    int flag=0;
    if( B[i] < B[j] ) flag++;
    if( C[i] < C[j] ) flag++;
    if( i < j) flag++;

    if(flag >= 2) return true;
    else return false;
}

void mergearray(vector<int> &A, vector<int> &B, vector<int> &C, int start,int mid,int stop)
{
    int n=stop-start;
    vector<int> temp;
    int i=start,j=mid;
    int index=0;
    while( i<mid && j<stop )
    {
        if( lessthan(A,B,C,i,j) )
        {
            temp.push_back(A[i]);
            index++;
            i++;
        }
        else
        {
            temp.push_back(A[j]);
            index++;
            j++;
        }
    }
    if( i==mid )
    {
        while(j!=stop)
        {
            temp.push_back(A[j]);
            index++;
            j++;
        }
    }
    else
    {
        while(i!=mid)
        {
            temp.push_back(A[i]);
            index++;
            i++;
        }
    }
    for(i=0;i<n;i++)
        A[i+start]=temp[i];
}

void mergesort(vector<int> &A, vector<int> &B, vector<int> &C, int start, int stop)
{
    if(start+1==stop)
        return;
    int mid=(start+stop)/2;
    mergesort(A,B,C,start,mid);
    mergesort(A,B,C,mid,stop);
    mergearray(A,B,C,start,mid,stop);
    return;
}

int right,left;

void mergearray_for_r(vector<int> &A, int start,int mid,int stop,int &count)
{
    int n=stop-start;
    vector<int> temp;
    int i=start,j=mid;
    int index=0;
    while( i<mid && j<stop )
    {
        if( A[i] <A[j] )
        {
            temp.push_back(A[i]);
            index++;
            i++;
        }
        else
        {
            temp.push_back(A[j]);
            index++;
            j++;
            count = count+mid-i;
        }
    }
    if( i==mid )
    {
        while(j!=stop)
        {
            temp.push_back(A[j]);
            index++;
            j++;
        }
    }
    else
    {
        while(i!=mid)
        {
            temp.push_back(A[i]);
            index++;
            i++;
        }
    }
    for(i=0;i<n;i++)
        A[i+start]=temp[i];
}

void mergesort_for_r(vector<int> &A, int start, int stop, int &count)
{
    if(start+1==stop)
        return;
    int mid=(start+stop)/2;
    mergesort_for_r(A,start,mid,count);
    mergesort_for_r(A,mid,stop,count);
    mergearray_for_r(A,start,mid,stop,count);
    return;
}

void mergearray_inv_pair(vector<int> &A, vector<int> p_inv, int start, int mid, int stop, int minp, bool &flag)
{
    int n=stop-start;
    vector<int> temp;
    int i=start,j=mid;
    int index=0;
    while( i<mid && j<stop )
    {
        if( A[i] < A[j] )
        {
            if( p_inv[A[i]-1] > minp)
            {
                ::right = A[i];
                ::left = p_inv[minp];
                flag=false;
                return;
            }
            temp.push_back(A[i]);
            index++;
            i++;
        }
        else
        {
            temp.push_back(A[j]);
            index++;
            j++;
            if( p_inv[A[j]-1]<minp)
                minp=p_inv[A[j]-1];
        }
    }
    if( i==mid )
    {
        while(j!=stop)
        {
            temp.push_back(A[j]);
            index++;
            j++;
            if( p_inv[A[j]-1]<minp)
                minp=p_inv[A[j]-1];
        }
    }
    else
    {
        while(i!=mid)
        {
            if( p_inv[A[i]-1] > minp)
            {
                ::right = A[i];
                ::left = p_inv[minp];
                flag=false;
                return;
            }
            temp.push_back(A[i]);
            index++;
            i++;
        }
    }
    for(i=0;i<n;i++)
        A[i+start]=temp[i];
}

void mergesort_inv_pair(vector<int> &A, vector<int> p_inv, int start, int stop, int minp, bool &check)
{
    if(start+1==stop)
        return;
    int mid=(start+stop)/2;
    mergesort_inv_pair(A,p_inv,start,mid,minp,check);
    mergesort_inv_pair(A,p_inv,mid,stop,minp,check);
    mergearray_inv_pair(A,p_inv,start,mid,stop,minp,check);
    return;
}

int main()
{
    vector<int> p,q,r;
    int n;
    int temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        p.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        q.push_back(temp);
    }
    for(int i=0;i<n;i++)
        r.push_back(i+1);

    vector<int> p_inv(n),q_inv(n);
    invert(p,p_inv);
    invert(q,q_inv);
    mergesort(r,p_inv,q_inv,0,n);

    //Checking if r is correct
    //Counting inv pairs of r
    vector<int> R1,R2,R3;//BEWARE
    for(int i=0;i<n;i++)
    {
        R1.push_back(r[i]);
        R2.push_back(r[i]);
        R3.push_back(r[i]);
    }
    int count=0;
    mergesort_for_r(R1,0,n,count);
    int no_inv_r = count;

    //Every inv pair in r is in p and q
    bool checkp=true;
    bool checkq=true;
    int minp=n+1;
    mergesort_inv_pair(R2,p_inv,0,n,minp,checkp);
    minp=n+1;
    mergesort_inv_pair(R3,q_inv,0,n,minp,checkq);

    //Common inv pairs in p and q
    vector<int> s;
    for(int i=0;i<n;i++)
        s.push_back(q_inv[p[i]-1]);

    int common, no_inv_p, no_inv_q, no_inv_s;
    count=0;
    mergesort_for_r(p,0,n,count);
    no_inv_p = count;

    count=0;
    mergesort_for_r(q,0,n,count);
    no_inv_q = count;

    count=0;
    mergesort_for_r(s,0,n,count);
    no_inv_s = count;

    common = (no_inv_p + no_inv_q - no_inv_s)/2;

    if( checkp && checkq && (common==no_inv_r) )
    {
        cout<<"consistent"<<endl;
        for(int i=0;i<n;i++)
            cout<<r[i]<<" ";
    }
    else
    {
        vector<int> r_inv(n);
        invert(r,r_inv);
        cout<<"inconsistent"<<endl;
        for(int i=r_inv[::left-1]+1; i<r_inv[::right-1]; i++)
        {
            if( lessthan(r,p_inv,q_inv,r_inv[::left-1]+1,i) && lessthan(r,p_inv,q_inv,r_inv[::right-1]-1,i) )
            cout<<::left<<" "<<i<<" "<<::right;
        }
    }
    return 0;
}


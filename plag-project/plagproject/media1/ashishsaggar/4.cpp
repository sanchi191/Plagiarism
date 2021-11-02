#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a,b,a1,b1,r,s;
bool checkConsistency ( vector<int> &r );
void mergesort (vector<int> &x, int low, int high, bool &flag, vector<int> &y, vector<int> &y1);
bool merge (vector<int> &x, int low, int high, int mid, vector<int> &y, vector<int> &y1);
int find_invcount(vector<int> z);
void mergesort1(vector<int> &z, int low, int high, int &count);
void merge1(vector<int> &z, int low, int high, int mid, int &count);
void find_inconsistent(vector<int> &c, int k);
bool compare (int i, int j)
{
    int count = 0;
    if (i<j){count++;}
    if (a1[i]<a1[j]){count++;}
    if (b1[i]<b1[j]){count++;}
    if (count>=2) return true;
    return false;
}
int main()
{
    cin>>n;
    a.resize(n);
    b.resize(n);
    a1.resize(n);
    b1.resize(n);
    r.resize(n);
    s.resize(n);
    int temp;
    for ( int i=0; i<n; i++)
    {
        cin>>temp;
        a[i]=--temp;  //  do -1
    }
    for ( int i=0; i<n; i++)
    {
        cin>>temp;
        b[i]=--temp;
    }
    for ( int i=0; i<n; i++)
    {
        a1[(a[i])] = i;
        b1[(b[i])] = i;
        r[i] = i;
    }
    for ( int i=0; i<n; i++)
    {
        s[i] = a1[(b[i])];
    }
    std::sort (r.begin(), r.end(), compare);
    bool flag = checkConsistency(r);
    int r_invcount = find_invcount(r);
    int a_invcount = find_invcount(a);
    int b_invcount = find_invcount(b);
    int s_invcount = find_invcount(s);
    if ( r_invcount != ( a_invcount + b_invcount - s_invcount) / 2 ) flag = false;
    if (flag)
    {
        cout<<"consistent"<<endl;
        for ( int i=0; i<n; i++)
        {
            cout<<++r[i]<<" ";
        }
    }
    else cout<<"inconsistent"<<endl;
    return 0;
}

bool checkConsistency ( vector<int> &r )
{
    vector<int> r1 = r;
    vector<int> r2 = r;
    bool flag = true;
    mergesort(r1, 0, n-1, flag, a, a1);
    mergesort(r2, 0, n-1, flag, b, b1);
    return flag;
}

void mergesort(vector<int> &x, int low, int high, bool &flag, vector<int> &y, vector<int> &y1)
{
    //cout<<"Heya!";
    int mid;
    if (low < high && !flag)
    {
        mid=(low+high)/2;
        mergesort(x,low,mid,flag,y,y1);
        mergesort(x,mid+1,high,flag,y,y1);
        flag = merge(x,low,high,mid,y,y1);
    }
    return;
}
bool merge(vector<int> &x, int low, int high, int mid, vector<int> &y, vector<int> &y1)
{
    int i, j, k, min;
    bool flag = true;
    vector<int> c;
    c.resize(n);
    i = low;
    k = low;
    j = mid + 1;
    min = 1000000;
    while (i <= mid && j <= high && flag)
    {
        if (x[i] < x[j])
        {
            c[k] = x[i];
            k++;
            i++;

            flag = (y1[ (x[i]) ]) < min ? true : false ;
            if (!flag ) find_inconsistent(c,k);
        }
        else
        {
            c[k] = x[j];
            k++;
            j++;
            min = ( y1[ (y[j]) ] >min ? min : y1[(y[j])] ) ;
        }
    }
    while (i <= mid && flag)
    {
        c[k] = x[i];
        k++;
        i++;
        flag = ( y1[ (x[i]) ] < min ? true : false );
        if (!flag ) {find_inconsistent(c,k);cout<<"Hi!";}
    }
    while (j <= high && flag)
    {
        c[k] = x[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        x[i] = c[i];
    }
    return flag;
}
int find_invcount(vector<int> z)
{
    int count = 0;
    mergesort1(z,0,n-1, count);
    return count;
}
void mergesort1(vector<int> &z, int low, int high, int &count)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort1(z,low,mid,count);
        mergesort1(z,mid+1,high,count);
        merge1(z,low,high,mid,count);
    }
    return;
}
void merge1(vector<int> &z, int low, int high, int mid, int &count)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    vector<int> c;
    c.resize(n);
    while (i <= mid && j <= high)
    {
        if (z[i] < z[j])
        {
            c[k] = z[i];
            k++;
            i++;
        }
        else
        {
            c[k] = z[j];
            k++;
            j++;
            count = count + mid - i + 1;
        }
    }
    while (i <= mid)
    {
        c[k] = z[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = z[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        z[i] = c[i];
    }
}

void find_inconsistent(vector<int> &c, int k)
{
    cout<<"Heya";
    for (int i=k; i>=0; i--)
    {
        if ( c[i]>c[k] )
        {
            cout<<"inconsistent"<<endl;
           cout<<c[i-1]<<" "<<c[k]<<" "<<c[i];
           return;
        }

    }

    return;
}

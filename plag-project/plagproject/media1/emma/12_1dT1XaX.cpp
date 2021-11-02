#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int>invp, invq, invr, p, q;
vector<int>m;
vector<int>c;
int keeptrackp = INFINITY;
int keeptrackq = INFINITY;
bool flag= true;
int count_inv = 0;
int L, R;

bool compare (int x, int y){
    int c=0;
    if (x<y) c++;
    if (invp[x-1] < invp[y-1]) c++;
        //else c--;
    if (invq[x-1] < invq[y-1]) c++;
        //else c--;
       // c++;

    /*if (x>y){
        if (invp[x] > invp[y]) c++;
        else c--;
        if (invq[x] > invq[y]) c++;
        else c--;
        c++;
    }*/
    if (c >= 2) return true;
    else return false;
}

void merge(vector<int> ,int, int , int );
void mergesort(vector<int> a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

void merge(vector<int> a, int low, int high, int mid)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i]<a[j])
        {
            c[k] = a[i];
            k++;
            i++;

            if (invq[a[i]] > keeptrackq || invp[a[i]] > keeptrackp){
                flag = false;
                L = a[i];
                R = a[j];
                return;
            }
        }
        else
        {
            keeptrackp = min (invp[a[j]-1], keeptrackp);
            keeptrackq = min (invq[a[j]-1], keeptrackq);

            if (invp[a[i]]> invp[a[j]] || invq[a[i]] > invq[a[j]]){
                flag=false;
                L = a[i];
                R=a[j];
                return;
            }

            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
}

void merge2(vector<int> ,int, int , int );
void mergesort2(vector<int> a, int low, int high)
{
    int mid, x, y, z;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort2(a,low,mid);
        mergesort2(a,mid+1,high);
        merge2(a,low,high,mid);
    }
    return;
}

void merge2(vector<int> a, int low, int high, int mid)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    //int count_inv =0;
    while (i <= mid && j <= high)
    {
        if (a[i]<a[j])
        {
            c[k] = a[i];
            k++;
            i++;

            //if (invq[a[i]] > keeptrackq || invp[a[i]] > keeptrackp)
              //  flag = false;
        }
        else
        {
            //keeptrackp = min (invp[a[j]-1], keeptrackp);
            //keeptrackq = min (invq[a[j]-1], keeptrackq);

            //if (invp[a[i]]> invp[a[j]] || invq[a[i]] > invq[a[j]])
              //  flag=false;
            count_inv = count_inv + (mid-i+1);
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    //return count_inv;
}



int main(){
    int n;
    cin>>n;
    vector<int> r;
    q.resize(n,0);
    p.resize(n,0);
    invp.resize(n,0);
    invq.resize(n, 0);
    r.resize(n,0);
    invr.resize(n,0);

    for (int i=0; i<n; i++){
        cin>>p[i];
        r[i]=i+1;
    }

    for (int i=0; i<n; i++)
        cin>>q[i];

    for (int i=0; i<n; i++){
        invp[p[i]-1] = i;
        invq[q[i]-1] = i;
    }

    c.resize(n,0);
    sort(r.begin(), r.end(), compare);

    for (int i=0; i<n; i++){
        invr[r[i]-1] = i;
    }


    vector<int> z = r;
    mergesort(z, 0, n-1);

    if (flag ==1){
        cout<<"consistent"<<endl;
    for (int i=0; i<n; i++){
        cout<<r[i]<<" ";
    }
    cout<<endl;
    return 0;
    }

    mergesort2(p, 0, n-1);
    int inv_p = count_inv;
    count_inv = 0;
    //cout<<"Sddfgnh"<<inv_p<<endl;

    mergesort2(q, 0, n-1);
    int inv_q = count_inv;
    count_inv=0;
    //cout<<"Sddfgnh"<<inv_q<<endl;

    vector<int>s(n,0);
    for (int i=0; i<n; i++){
        s[i] = invq[p[i]-1];
    }
    mergesort2(s, 0, n-1);
    int inv_s = count_inv;
    count_inv=0;

    vector<int> al = r;
    mergesort2(al, 0, n-1);
    int inv_r = count_inv;
    count_inv=0;

    int common = (inv_p + inv_q - inv_s)/2;

    //cout<<"df"<<inv_p<<"der"<<inv_q<<"dfr"<<inv_r<<"F"<<(common-inv_r)<<endl;
    //for (int i=0; i<n; i++)
      //  cout<<z[i];

    //cout<<flag;
    int i = invr[L];
    int j = invr[R];

    int mini = (i>j)?j:i;
    int maxi = (i>j)?i:j;
    while (mini<=maxi){
        if (r[mini+1] < r[maxi])
            break;

        mini++;
    }

    cout<<"inconsistent"<<endl;
    cout<<r[mini]<<" "<<r[mini+1]<<" "<<r[maxi]<<endl;

}

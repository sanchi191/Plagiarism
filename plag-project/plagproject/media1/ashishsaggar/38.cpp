#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>
vector<int> perm1,invPerm1,r,s;
vector<int> perm2,invPerm2;
bool step1=true;

void print(vector <int> sample)
{
    vector <int> ::iterator k;
    for (k=sample.begin(); k<sample.end(); k++)
    {
        cout<<(*k)<<" ";
    }
    cout<<endl;
    cout<<"--------------"<<endl;
    return;
}
bool relation(int x,int y)
{
    if (x<y)
    {
        if ((invPerm1[x]<invPerm1[y])||(invPerm2[x]<invPerm2[y]))
        {
            return true;
        }
        else return false;
    }
    else
    {
        if ((invPerm1[x]>invPerm1[y])||(invPerm2[x]>invPerm2[y]))
        {
            return false;
        }
        else return true;
    }
}
bool merge(int *a,int low, int high, int mid,int&num,int n);
void mergesort(int *a, int low, int high,int&num,int n,bool &flag)
{
    int mid;
    if (low < high&&(!flag))
    {
        mid=(low+high)/2;
        mergesort(a,low,mid,num,n,flag);
        mergesort(a,mid+1,high,num,n,flag);
        flag = merge(a,low,high,mid,num,n);
    }
    return;
}
bool merge(int *a, int low, int high, int mid,int&num,int n)
{
    int min1=n+2;
    int min2=n+2;
    int i, j, k;
    int*c = new int[high-low];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            if (min1>invPerm1[a[i]]&&min2>invPerm2[a[i]])
            {

                step1=true;
            }
            else
            {
                step1=false;
                return false;

            }
            c[k] = a[i];

            k++;
            i++;


        }
        else
        {
            num=num+mid-i+1;
            //cout<<"num "<<num<<" "<<i<<" "<<j<<endl;
            if (min1>invPerm1[j]) min1=invPerm1[j];
            if (min2>invPerm2[j]) min2=invPerm2[j];
            c[k] = a[j];
            k++;
            j++;

        }
    }
    while (i <= mid)
    {
        //num = num+high-mid;
        //cout<<"num "<<num<<" all emptied "<<i<<" "<<j<<endl;
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
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
        //cout<<"Merged "<<a[i]<<" ";
    }
    //cout<<endl;
return true;
}
int countInv(vector<int> & sample,int n)
{
    int num=0;
    int* a = new int[n];
    for (int i=0; i<n; i++)
    {
        a[i]=sample[i];
    }
    bool flag = true;
    mergesort(a,0,n-1,num,n,flag);
    return num;
}
void defaulters(int n){

}
int main()
{
    int n,i;
    cin>>n;

    perm1.resize(n);
    perm2.resize(n);
    invPerm1.resize(n);
    invPerm2.resize(n);
    r.resize(n);
    s.resize(n);
    for (i=0; i<n; i++)
    {
        cin>>perm1[i];
        perm1[i]--;
        invPerm1[perm1[i]] = i;
        r[i]=i;
    }
    for (i=0; i<n; i++)
    {
        cin>>perm2[i];
        perm2[i]--;
        invPerm2[perm2[i]] = i;
    }

    for (i=0; i<n; i++)
    {
        s[i]= invPerm1[perm2[i]];
    }
    sort (r.begin(),r.end(),relation);

    //int hello = countInv(perm1,n);
    //cout<<hello;
    bool step2;
    if (countInv(r,n)==(countInv(perm1,n)+countInv(perm2,n)-countInv(s,n))/2) step2 = true;
    else step2=false;
    //cout<<step2;
    if(step2==true&&step1==true)
    {
        cout<<"consistent"<<endl;
        for (int i=0; i<n; i++)
        {
            cout<<r[i]+1<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<step1<<step2<<endl;
        cout<<"inconsistent"<<endl;
        defaulters(n);
    }


    return 0;

}

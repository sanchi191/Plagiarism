#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int> arr_p, arr_q, invp, invq, arr_r, arr_temp, arr_s, invr;
int n_size, countinv, L, R ;
bool flaginr=true;

bool comp(int x, int y){
    int _count=0;
    if(x<y)
     _count++;
    if(invp[x]<invp[y])
     _count++;
    if(invq[x]<invq[y])
     _count++;

    if(_count>=2)
      return true;
    else
      return false;
}

void mergecheck(vector<int> ,int, int , int );
void mergesort(vector<int> a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        mergecheck(a,low,high,mid);
    }
    return;
}
void mergecheck(vector<int> a, int low, int high, int mid)
{
    int i, j, k, trackp=INT_MAX, trackq=INT_MAX ;
    vector<int> c(n_size+1);
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {

            c[k] = a[i];
            k++;
            i++;
            if(invp[a[i]]>trackp||invq[a[i]]>trackq)
             {   flaginr=false;
                 L=a[i];
                 R=a[j];
             }


        }
        else
        {
            if(invp[a[i]]>invp[a[j]]||invq[a[i]]>invq[a[j]])
             {   flaginr=false;
                 L=a[i];
                 R=a[j];
             }

            trackp=min(invp[a[i]],trackp);
            trackq=min(invq[a[i]],trackq);

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
    for (i = low; i <=high; i++)
    {
        a[i] = c[i];
    }
}
void mergecount(vector<int> ,int, int , int );
void mergesort2(vector<int> a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort2(a,low,mid);
        mergesort2(a,mid+1,high);
        mergecount(a,low,high,mid);
    }
    return ;
}
void mergecount(vector<int> a, int low, int high, int mid)
{
    int i, j, k;
    vector<int> c(n_size+1);
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
            countinv+=mid-i+1;
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
    for (i = low; i <=high; i++)
    {
        a[i] = c[i];
    }
}




int main()
{

    int n_size;
    cin>>n_size;

    arr_p.resize(n_size,0);
    arr_q.resize(n_size,0);
    invp.resize(n_size+1,0);
    invq.resize(n_size+1,0);
    arr_r.resize(n_size,0);
    arr_temp.resize(n_size,0);
    arr_s.resize(n_size,0);
    invr.resize(n_size+1,0);

    for(int i=0; i<n_size; i++)
    {
        cin>>arr_p[i];
        arr_r[i]=i + 1;
    }
    for(int i=0; i<n_size; i++)
    {
        cin>>arr_q[i];
    }


    for(int i=0; i<n_size; i++)
    {
        invp[arr_p[i]]=i;
    }
    for(int i=0; i<n_size; i++)
    {
        invq[arr_q[i]]=i;
    }

    sort(arr_r.begin(), arr_r.end(), comp);


    for(int i=0; i<n_size; i++)
    {
        arr_temp[i]=arr_r[i];
    }
    for(int i=0;i<n_size; i++)
    {
        arr_s[i]=invp[arr_q[i]];
    }


    mergesort(arr_temp, 0, n_size-1);


    for(int i=0; i<n_size; i++)
    {
        invr[arr_r[i]]=i;
    }
    int i=invr[L];
    int j=invr[R];
    int temp=i;
    i=min(i,j);
    j=max(temp,j);
    if(!flaginr)
    while(i<j)
    {
        if(arr_r[i+1]<arr_r[j])
        {
           break;
        }
        i++;

    }

    int r, p, q, s;
    for(int i=0; i<n_size; i++)
    {
        arr_temp[i]=arr_r[i];
    }
    countinv=0;
    mergesort2(arr_temp, 0, n_size-1);
    r=countinv;
    countinv=0;
    mergesort2(arr_s, 0, n_size-1);
    s=countinv;
    countinv=0;
    mergesort2(arr_q, 0, n_size-1);
    q=countinv;
    countinv=0;
    mergesort2(arr_p, 0, n_size-1);
    p=countinv;

    if(r!=(p+q-s)/2)
      flaginr=false;
    if(flaginr)
    {   cout<<"consistent"<<endl;
        for(int i=0; i<n_size; i++)
        {
            cout<<arr_r[i]<<" ";
        }
    }
    else
    {   cout<<"inconsistent"<<endl;
        cout<<temp<<" "<<i+1<<" "<<j;

    }



    return 0;

}

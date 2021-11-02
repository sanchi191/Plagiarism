#include <iostream>
#include <vector>
using namespace std;
int *a;
int *b;
bool lt(int i,int j)
{
    if( ((i<j)&&(a[i]<a[j])) || ((i<j)&&(b[i]<b[j])) || ((a[i]<a[j])&&(b[i]<b[j])))
    {
        return true;
    }
    return false;
}
void mergeSortedSubarrays(int *c, int start, int mid, int end);
void mergeSort(int *c, int start, int end)
{
    if (end == start +1)
    {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(c,start, mid);
    mergeSort(c, mid, end);
    mergeSortedSubarrays(c,start, mid, end);
    return;
}
void mergeSortedSubarrays(int *c, int start, int mid, int end)
{
    int i, j;
    int index = start;
    int *temp;
    temp =new int[end-start];
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {

        if ((i < mid) && (j < end))
        {
            if(lt(c[i],c[j]))
            {
                temp[index-start] = c[i];
                i++;
            }
            else
            {
                temp[index-start] = c[j];
                j++;

            }
        }
        else
        {
            if (i < mid)
            {
                temp[index-start] = c[i];
                i++;
            }
            else
            {
                temp[index-start] = c[j];
                j++;
            }
        }
        index++;
    }
    for(int ii=start; ii<end; ii++)
    {
        c[ii] = temp[ii-start];
    }

    return;
}


int main()
{
    int n;
    cin>>n;
    int *c;
    a = new int[n+1];
    b = new int[n+1];
    c = new int[n+1];
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        a[x] = i;
        c[i]=i;
    }
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        b[x] = i;
    }
    mergeSort(c,1,n+1);
    for(int i=1; i<n+1; i++)
    {
        for(int j=i+1; j<n+1; j++)
        {

            if(lt(c[i],c[j]))
            {

            }
            else
            {
                cout<<"inconsistent"<<endl;
                cout<<c[i]<<" "<<c[j-1]<<" "<<c[j];
                return 0;
            }

        }
    }
    cout<<"consistent"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<c[i]<<" ";
    }

    return 0;
}


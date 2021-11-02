#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)

using namespace std;

int n;
int *judge_1;
int *judge_2;
int *judge_3;
int *inj_1;
int *inj_2;
int *inj_3;
int *f_per;

/**COMPARE FUNCTION**/
bool lt(int i,int j)
{
    int count1=0;
    if(inj_1[i]<inj_1[j])count1++;
    if(inj_2[i]<inj_2[j])count1++;
    if(inj_3[i]<inj_3[j])count1++;

    if(count1>1)return true;
    else
    {
        return false;
    }
}

/**MERGESORT**/

void merge1(int* a,int start,int mid,int end)
{
    if(end==start+1)return;
    int* temp=new int [end-start];
    int i=start;
    int j=mid;
    int k=0;
    while((i!=mid)&&(j!=end))
    {
        if(lt(a[i],a[j]))
        {
            temp[k++]=a[i++];
        }
//if(a[i]<a[j]){temp[k++]=a[i++];}
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i!=mid)
    {
        temp[k++]=a[i++];
    }
    while(j!=end)
    {
        temp[k++]=a[j++];
    }
    i=start;
    fr(x,end-start)
    {
        a[i]=temp[x];
        i++;
    }
    delete[] temp;
    return;
}

void msort(int *a,int start,int end)
{
    if(end==start+1)return;
    int mid=(start+end)/2;
    msort(a,start,mid);
    msort(a,mid,end);
    merge1(a,start,mid,end);
    return;
}


int main()
{

    /**INPUT AND INITIALIZATIONS**/
    cin>>n;
    judge_1=new int[n+1];
    judge_2=new int[n+1];
    judge_3=new int[n+1];
    inj_1=new int[n+1];
    inj_2=new int[n+1];
    inj_3=new int[n+1];
    f_per=new int[n+1];
    fr1(i,n)
    {
        cin>>judge_1[i];
    }
    fr1(i,n)
    {
        cin>>judge_2[i];
    }
    fr1(i,n)
    {
        judge_3[i]=i;
        f_per[i]=i;
    }
    /**FINDING THE INVERSES **/
    fr1(i,n)
    {
        inj_1[judge_1[i]]=i;
        inj_2[judge_2[i]]=i;
        inj_3[judge_3[i]]=i;
    }
    /**SORTIING TO FIND THE PERMUTATION**/
    msort(f_per,1,n+1);

    /**CHECKING THE CONSISTANCY O(N^2)**/
    fr1(i,n)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(!lt(f_per[i],f_per[j]))
            {
                cout<<"inconsistent"<<endl;
                for(int k=i+1; k<j; k++)
                {
                    if(lt(f_per[k],f_per[j]))
                    {
                        cout<<f_per[i]<<" "<<f_per[k]<<" "<<f_per[j]<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    /**PRINTING THE PERMUTATION**/
    cout<<"consistent"<<endl;
    fr1(i,n)
    {
        cout<<f_per[i]<<" ";
    }
    /**WORKING**/
    return 0;
}

#include<iostream>
using namespace std;

void mergesortedarrays(int a[],int *invfirst,int *invsecond,int start,int mid,int last)
{
    int i, j;
    int index = 0;
    int *tempA;
    tempA = new int[last - start];
    for (i = start, j = mid; ((i < mid) || (j < last)); )
    {
        if ((i < mid) && (j < last))
        {
            if ((invfirst[a[j]] > invfirst[a[i]])||(invsecond[a[j]] > invsecond[a[i]]))
            {
                tempA[index] = a[i];
                i++;
            }
            else
            {
                tempA[index] = a[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = a[i];
                i++;
            }
            else
            {
                tempA[index] = a[j];
                j++;
            }
        }
        index ++;
    }
    for (i = start; i < last; i++)
    {
        a[i] = tempA[i-start];
    }
    delete []tempA;
    return;
}

void mergeSort(int a[],int start,int last,int *invfirst,int *invsecond)
{
    if (last == start +1)
    {
        return;
    }
    int mid = (start + last)/2;
    mergeSort(a, start, mid,invfirst,invsecond);
    mergeSort(a, mid, last,invfirst,invsecond);
    mergesortedarrays(a,invfirst,invsecond,start,mid, last);
    return;
}
int n;
int aforans,bforans;
bool mergesortedarraysForCheck(int a[],int *invfirst,int *invsecond,int start,int mid,int last)
{
    int i, j;
    int index = 0;
    int *tempA;
    int minfirst=n+2;
    int minsecond=n+2;
    bool result=true;
    tempA = new int[last - start];
    for (i = start, j = mid; ((i < mid) || (j < last)); )
    {
        if ((i < mid) && (j < last))
        {
            if (a[i]<a[j])
            {
                tempA[index] = a[i];
                if(invfirst[a[i]]>minfirst)
                {
                    /*if(aforans==-1)
                    {
                        aforans=i;
                        bforans=j;
                    }*/
                    result= false;
                }
                if(invsecond[a[j]]>minsecond)
                {
                    /*if(aforans==-1)
                    {
                        aforans=i;
                        bforans=j;
                    }*/
                    result=false;
                }
                i++;
            }
            else
            {
                tempA[index] = a[j];
                if(invfirst[a[j]]<minfirst)
                {
                    minfirst=invfirst[a[j]];
                }
                if(invsecond[a[j]]<minsecond)
                {
                    minsecond=invsecond[a[j]];
                }
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = a[i];
                i++;
                if(invfirst[a[i]]>minfirst)
                {
                    /*if(aforans==-1)
                    {
                        aforans=i;
                        bforans=j;
                    }*/
                    result=false;
                }
                if(invsecond[a[j]]>minsecond)
                {
                    /*if(aforans==-1)
                    {
                        aforans=i;
                        bforans=j;
                    }*/
                    result=false;
                }
            }
            else
            {
                tempA[index] = a[j];
                j++;
            }
        }
        index ++;
    }
    for (i = start; i < last; i++)
    {
        a[i] = tempA[i-start];
    }
    delete []tempA;
    return result;
}

bool mergeSortForCheck(int a[],int start,int last,int *invfirst,int *invsecond)
{
    if (last == start +1)
    {
        return true;
    }
    int mid = (start + last)/2;
    bool result=true;
    result=result&&mergeSortForCheck(a, start, mid,invfirst,invsecond);
    result=result&&mergeSortForCheck(a, mid, last,invfirst,invsecond);
    result=result&&mergesortedarraysForCheck(a,invfirst,invsecond,start,mid, last);
    return result;
}

int mergesortedarraysForCount(int a[],int *invfirst,int *invsecond,int start,int mid,int last)
{
    int i, j;
    int index = 0;
    int *tempA;
    int minfirst=0;
    int minsecond=0;
    int result=0;
    int num=0;
    tempA = new int[last - start];
    for (i = start, j = mid; ((i < mid) || (j < last)); )
    {
        if ((i < mid) && (j < last))
        {
            if (a[i]<a[j])
            {
                tempA[index] = a[i];
                i++;
                result=result+num;
            }
            else
            {
                tempA[index] = a[j];
                j++;
                num++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = a[i];
                i++;
                result=result+num;
            }
            else
            {
                tempA[index] = a[j];
                j++;
            }
        }
        index ++;
    }
    for (i = start; i < last; i++)
    {
        a[i] = tempA[i-start];
    }
    delete []tempA;
    return result;
}

int mergeSortForCount(int a[],int start,int last,int *invfirst,int *invsecond)
{
    if (last == start +1)
    {
        return 0;
    }
    int mid = (start + last)/2;
    int result=0;
    result=result+mergeSortForCount(a, start, mid,invfirst,invsecond);
    result=result+mergeSortForCount(a, mid, last,invfirst,invsecond);
    result=result+mergesortedarraysForCount(a,invfirst,invsecond,start,mid, last);
    return result;
}

int main()
{
    cin>>n;
    aforans=-1;
    bforans=-1;
    int *a= new int[n+1],*b= new int[n+1],*c= new int[n+1],*invfirst= new int[n+1],*invsecond= new int[n+1];
    for(int i=1; i<n+1; i++)
    {
        cin>>b[i];
        a[i] = i;
    }
    for(int i=1; i<n+1; i++)
    {
        cin>>c[i];
    }
    for(int i=1; i<n+1; i++)
    {
        invfirst[b[i]] = i;
        invsecond[c[i]] = i;
    }

    mergeSort(a,1,n+1,invfirst,invsecond);
    int *temp= new int[n+1];
    int *temp2= new int[n+1];
    for(int i=1; i<n+1; i++)
    {
        temp[i]=a[i];
    }
    bool result=mergeSortForCheck(a,1,n+1,invfirst,invsecond);
    int *newone= new int[n+1];
    for(int i=1; i<n+1; i++)
    {
        newone[i]=invfirst[c[i]];
    }
    for(int i=1; i<n+1; i++)
    {
        a[i]=temp[i];
    }
    int p=mergeSortForCount(b,1,n+1,invfirst,invsecond),q=mergeSortForCount(c,1,n+1,invfirst,invsecond),s=mergeSortForCount(temp,1,n+1,invfirst,invsecond),x=mergeSortForCount(newone,1,n+1,invfirst,invsecond);
    if((p+q-x)/2==s&&result)
    {
        cout<<"consistent\n";
        for(int i=1; i<n+1; i++)
        {
            cout<<a[i]<<" ";
        }
    }
    else
    {
        cout<<"inconsistent\n";
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int num=0;
            if(invfirst[a[i]] < invfirst[a[j]])
            {
                num++;
            }
            if(invsecond[a[i]] < invsecond[a[j]])
            {
                num++;
            }
            if(a[i] < a[j])
            {
                num++;
            }
            if(num<2)
            {
                cout<<a[i]<<" "<<a[j-1]<<" "<<a[j];
                return 1;
            }
        }
    }
    return 0;
}

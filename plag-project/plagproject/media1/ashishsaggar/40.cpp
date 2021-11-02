#include<iostream>
using namespace std;
int n;
bool chekie = true;
int inversions = 0;
void mergeSortedSubarrays(int A[], int pinv[],int qinv[],int start, int mid, int end);
void mergeSortedSubarraysinv(int p[],int start, int mid, int end);
void mergeSortedSubarrays2(int p[], int qinv[],int start, int mid, int end);
//int first = -1;
//int third = -1;



void inv(int p[],int start,int end)
{
    if (end == start +1)
    {
        return ;    //Subarray of interest has 1 element
    }
    int mid = (start + end)/2; //Get mid-index of subarray of interest
    inv(p,start, mid); // Sort subarray A[start] ... A[mid-1]
    inv(p, mid,end); // Sort subarray A[start] ... A[mid-1]
    mergeSortedSubarraysinv( p,start, mid,  end);
    return;
}
void mergeSortedSubarraysinv(int p[],int start, int mid, int end)
{
    int i, j;
    int * tempA = new int [end-start];
    int index = 0;
    int righthalf=0;
    for (i = start, j = mid; ((i < mid) || (j < end)); )   // Merging loop
    {
        if ((i < mid) && (j < end))   // None of the two subarrays fully seen yet
        {
            if (p[i]<p[j])
            {
                inversions+=righthalf;
                tempA[index] = p[i];
                i++;
            }
            else
            {
                righthalf++;
                tempA[index] = p[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                inversions+=righthalf;
                tempA[index] = p[i];    // A[mid] ... A[end-1] seen
                i++;
            }
            else
            {
                righthalf++;
                tempA[index] = p[j];    // A[start] ... A[mid-1] seen
                j++;
            }
        }
        index ++;
    } // end of merging loop
// Copy tempA[start] ... tempA[end-1] to A[start] ... A[end-1]
    for(int i = 0; i<end-start; i++)
    {
        p[i+start] = tempA[i];
    }
    delete []tempA;
    return;
}




void mergeSort(int A[],int pinv[],int qinv[], int start, int end)
{
    if (end == start +1)
    {
        return;    //Subarray of interest has 1 element
    }
    int mid = (start + end)/2; //Get mid-index of subarray of interest
    mergeSort(A,pinv,qinv, start, mid); // Sort subarray A[start] ... A[mid-1]
    mergeSort(A,pinv,qinv, mid, end); // Sort subarray A[mid] ... A[end-1]
// Merge sorted subarrays A[start] ... A[mid-1] and A[mid] ... A[end-1]
    mergeSortedSubarrays(A,pinv,qinv,start, mid, end);
    return;
}
void mergeSortedSubarrays(int A[], int pinv[],int qinv[],int start, int mid, int end)
{
    int i, j;
    int * tempA = new int [end-start],
    index = 0;
    for (i = start, j = mid; ((i < mid) || (j < end)); )   // Merging loop
    {
        if ((i < mid) && (j < end))   // None of the two subarrays fully seen yet
        {
            if (pinv[A[i]]<pinv[A[j]] || qinv[A[i]]<qinv[A[j]])
            {
                tempA[index] = A[i];
                i++;
            }
            else
            {
                tempA[index] = A[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = A[i];    // A[mid] ... A[end-1] seen
                i++;
            }
            else
            {
                tempA[index] = A[j];    // A[start] ... A[mid-1] seen
                j++;
            }
        }
        index ++;
    } // end of merging loop
// Copy tempA[start] ... tempA[end-1] to A[start] ... A[end-1]
    for(int i = 0; i<end-start; i++)
    {
        A[i+start] = tempA[i];
    }
    delete []tempA;
    return;
}




void mergeSort1(int p[],int qinv[], int start, int end)
{
    if (end == start +1)
    {
        return;    //Subarray of interest has 1 element
    }
    int mid = (start + end)/2; //Get mid-index of subarray of interest
    mergeSort1(p,qinv, start, mid); // Sort subarray A[start] ... A[mid-1]
    mergeSort1(p,qinv, mid, end); // Sort subarray A[mid] ... A[end-1]
// Merge sorted subarrays A[start] ... A[mid-1] and A[mid] ... A[end-1]
    mergeSortedSubarrays2(p,qinv,start, mid, end);
    return;
}
void mergeSortedSubarrays2(int p[], int qinv[],int start, int mid, int end)
{
    int i, j;
    int * tempA = new int [end-start],
    index = 0;
    int leftmost = n+2;
    int rightnum;
    int leftnum;
    for (i = start, j = mid; ((i < mid) || (j < end)); )   // Merging loop
    {
        if ((i < mid) && (j < end))   // None of the two subarrays fully seen yet
        {
            if (p[i]<p[j])
            {
                leftnum = p[i];
                if(qinv[leftnum]<leftmost)
                {
                    //skip
                    //cout<<"true1"<<endl;
                }
                else
                {
                    //cout<<qinv[leftnum]<<leftmost<<n<<endl;
                    //cout<<"false1"<<endl;

                    //cout<<first<<third;
                    //cout<<i<<j;
                    chekie = false;
                }
                tempA[index] = p[i];
                i++;
            }
            else
            {
                rightnum = p[j];
                if(qinv[rightnum]<leftmost)
                {
                    leftmost = qinv[rightnum];
                }
                tempA[index] = p[j];
                j++;
            }
        }
        else
        {
            if (i < mid)
            {
                rightnum = p[i];
                if(qinv[rightnum]<leftmost)
                {
                    //skip

                    //cout<<"true1"<<endl;
                }
                else
                {
                    //cout<<"false2"<<endl;

                    //cout<<first<<third;
                    // cout<<i<<j;
                    chekie = false;
                }
                tempA[index] = p[i];    // A[mid] ... A[end-1] seen
                i++;
            }
            else
            {
                rightnum = p[j];
                if(qinv[rightnum]<leftmost)
                {
                    leftmost = qinv[rightnum];
                }
                tempA[index] = p[j];    // A[start] ... A[mid-1] seen
                j++;
            }
        }
        index ++;
    } // end of merging loop
// Copy tempA[start] ... tempA[end-1] to A[start] ... A[end-1]
    for(int i = 0; i<end-start; i++)
    {
        p[i+start] = tempA[i];
    }
    delete []tempA;
    return;
}

int main()
{
    cin>>n;
    int * A = new int[n+1];
    int * p = new int[n+1];
    int * q = new int[n+1];
    int * s = new int[n+1];
    for(int i = 1; i<=n; i++)
    {
        cin>>p[i];
        A[i]=i;
    }
    for(int i = 1; i<=n; i++)
    {
        cin>>q[i];
    }
    int * pinv = new int [n+1];
    int * qinv = new int [n+1];
    for(int i = 1; i<=n; i++)
    {
        pinv[p[i]] = i;
        qinv[q[i]] = i;
    }
    for(int i = 1; i<=n; i++)
    {
        s[i] = pinv[q[i]];
    }
    mergeSort(A,pinv,qinv,1,n+1);

    int * Atemp = new int[n+1];
    for(int i = 1; i<=n; i++)
    {
        Atemp[i] = A[i];
    }
    mergeSort1(Atemp,pinv,1,n+1);



    for(int i = 1; i<=n; i++)
    {
        Atemp[i] = A[i];
    }
    mergeSort1(Atemp,qinv,1,n+1);



    if(chekie == false)
    {
        //cout<<first<<third;
        cout<<"inconsistent"<<endl;
        //The next part is the code for printing the tuple,but it does in O(N^2),so if u want to see O(nlogn)
        //then remove the next few lines of code and i mentioned till where to remove
        int first,last;
        bool temp = true;
        for(int i = 1; i<=n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                if(A[i]<A[j])
                {
                    if(pinv[A[i]]<pinv[A[j]]||qinv[A[i]]<qinv[A[j]])
                    {
                        //skip
                    }
                    else
                    {
                        first = i;
                        last = j;
                        temp = false;
                        break;
                    }
                }
                else
                {
                    if(pinv[A[i]]<pinv[A[j]]&&qinv[A[i]]<qinv[A[j]])
                    {
                        //skip
                    }
                    else
                    {
                        first = i;
                        last = j;
                        temp = false;
                        break;

                    }
                }

            }
            if(temp == false)
            {
                break;
            }
        }
        int middle = first+1;
        for(; middle<last; middle++)
        {
            if(A[middle]<A[last])
            {
                if(pinv[A[middle]]<pinv[A[last]]||qinv[A[middle]]<qinv[A[last]])
                {
                    break;
                }
                else
                {
                    //skip
                }
            }
            else
            {
                if(pinv[A[middle]]<pinv[A[last]]&&qinv[A[middle]]<qinv[A[last]])
                {
                    break;
                }
                else
                {
                    //skip
                }
            }
        }
        cout<<A[first]<<" "<<A[middle]<<" "<<A[last];
        //Remove till  here
        //END END END    END     END     END     END

        return 0;
    }



    for(int i = 1; i<=n; i++)
    {
        Atemp[i] = A[i];
    }

    inv(Atemp,1,n+1);
    int Ainversions = inversions;


    inversions = 0;

    inv(p,1,n+1);
    int pinversions = inversions;
    inversions = 0;


    inv(q,1,n+1);
    int qinversions = inversions;
    //cout<<qinversions<<endl;
    inversions = 0;


    inv(s,1,n+1);
    int sinversions = inversions;


    if(Ainversions == (pinversions+qinversions-sinversions)/2)
    {
        cout<<"consistent"<<endl;
        for(int i = 1; i<=n; i++)
        {
            cout<<A[i]<<" ";
        }
        return 0;
    }

    cout<<"inconsistent"<<endl;
        //The next part is the code for printing the tuple,but it does in O(N^2),so if u want to see O(nlogn)
        //then remove the next few lines of code and i mentioned till where to remove
    int first,last;
        bool temp = true;
        for(int i = 1; i<=n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                if(A[i]<A[j])
                {
                    if(pinv[A[i]]<pinv[A[j]]||qinv[A[i]]<qinv[A[j]])
                    {
                        //skip
                    }
                    else
                    {
                        first = i;
                        last = j;
                        temp = false;
                        break;
                    }
                }
                else
                {
                    if(pinv[A[i]]<pinv[A[j]]&&qinv[A[i]]<qinv[A[j]])
                    {
                        //skip
                    }
                    else
                    {
                        first = i;
                        last = j;
                        temp = false;
                        break;

                    }
                }

            }
            if(temp == false)
            {
                break;
            }
        }
        int middle = first+1;
        for(; middle<last; middle++)
        {
            if(A[middle]<A[last])
            {
                if(pinv[A[middle]]<pinv[A[last]]||qinv[A[middle]]<qinv[A[last]])
                {
                    break;
                }
                else
                {
                    //skip
                }
            }
            else
            {
                if(pinv[A[middle]]<pinv[A[last]]&&qinv[A[middle]]<qinv[A[last]])
                {
                    break;
                }
                else
                {
                    //skip
                }
            }
        }
        cout<<A[first]<<" "<<A[middle]<<" "<<A[last];
        //Remove till  here
        //END END END    END     END     END     END
    return 0;
}

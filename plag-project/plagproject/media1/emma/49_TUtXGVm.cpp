#include<iostream>
using namespace std;
bool compare(int i,int j, int a_inverse[],int p_inverse[],int c[])
{
    if(a_inverse[i-1]<a_inverse[j-1]){
    if((c[i-1]<c[j-1])||(p_inverse[i-1]<p_inverse[j-1]))
        {
        return true;}
        else
        {
        return false;}
    }
    if(a_inverse[i-1]>a_inverse[j-1]){
    if(c[i-1]>c[j-1]||(p_inverse[i-1]>p_inverse[j-1]))
        {
        return false;}
        else
        {

        return true;}
    }


}
void mergeSortedSubarrays(int A[], int start, int mid, int end,int a_inverse[] ,int p_inverse[],int C[],int c[]);
void mergeSort(int A[], int start, int end,int a_inverse[],int p_inverse[],int C[],int c[])
{
    if (end == start +1)
    {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(A, start, mid,a_inverse,p_inverse,C,c);
    mergeSort(A, mid, end,a_inverse,p_inverse,C,c);
    mergeSortedSubarrays(A, start, mid, end,a_inverse,p_inverse,C,c);
    return;
}
void mergeSortedSubarrays(int A[], int start, int mid, int end,int a_inverse[],int p_inverse[],int C[],int c[])
{
    int i, j;
    int * tempA = new int [end-start],
    index = 0;
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {
        if ((i < mid) && (j < end))
        {
            if (compare(A[i],A[j],a_inverse,p_inverse,c))
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
                tempA[index] = A[i];
                i++;
            }
            else
            {
                tempA[index] = A[j];
                j++;
            }
        }
        index ++;
    }
    i=0;
    while(i<end-start)
    {
        A[i+start]=tempA[i];
        C[A[i+start]]=i+start;
        i++;
    }
    return;
 }
int main()
{
    int num,j;
    cin>>num;
    int *A,*P,*C,*D ,*p_inverse,*di,*c ,*a_inverse ;
    A=new int[num];
    P=new int[num];
    p_inverse=new int[num];
    di=new int[num];
    D=new int[num];
    C=new int[num];
    c=new int[num];
    a_inverse=new int[num];
    j=0;
    while(j<num)
    {
        cin>>A[j];
        di[A[j]-1]=j;
        c[j]=j;
        j++;
    }
    j=0;
    while(j<num)
    {
        cin>>P[j];
        p_inverse[P[j]-1]=j;
        j++;
    }

    j=num;
mergeSort(A, 0, num,di,p_inverse,C,c);

mergeSort(P, 0, num,di,p_inverse,D,c);

    j=0;int a=0,b=0,c1=0,x=0;
    while(j<num){
    if(A[j]==P[j])
    {x++;
    }
    else
    {
        if(a==0)
        {
            a=A[j];
        }
        else{

        if(b==0)
        {
           b= A[j];
        }
        else
        {
        if(c1==0)
        {
        c1=A[j];
        }
        }


        }
    }
        j++;
    }
    if(a==0&&b==0&&c1==0)
    {
    cout<<"consistent"<<endl;
    j=num;
        while(j>0)
    {
        cout<<A[num-j]<<" ";
        j--;
    }
    cout<<endl; return 0;
    }
    cout<<"inconsistent"<<endl;
    cout<<P[C[a]]<<" "<<A[C[a]]<<" "<<P[C[P[C[a]]]];


return 0;
}

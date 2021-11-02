#include <iostream>
#include <vector>
using namespace std;


void mer(vector <int> &q,int &n,int start,int mid,int en,vector <int> &in_p1,vector <int> &in_p2,vector <int> &in_p3)
{
    int k=start;
    int i,j;

    vector<int> cop(n);
    for(i = start,j = mid;((i < mid) || (j < en)); )
    {

        if( ( i< mid)&&( j < en) )
        {
            if( ( ( in_p1[q[i]-1]<in_p1[q[j]-1]) && ( in_p2[q[i]-1]< in_p2[q[j]-1]) ) || ( ( in_p2[q[i]-1]< in_p2[q[j]-1]) && ( in_p3[q[i]-1]< in_p3[q[j]-1]) ) ||  ( ( in_p1[q[i]-1]< in_p1[q[j]-1]) && ( in_p3[q[i]-1]< in_p3[q[j]-1]) ) )


            {
               cop[k]=q[i];
               k++;
               i++;
            }
            else
            {
                cop[k]=q[j];
                k++;
                j++;
            }
        }
        else
        {
            if(i<mid)
            {
                cop[k]=q[i];
                k++;
                i++;
            }
            else
            {
                cop[k]=q[j];
                k++;
                j++;
            }
        }

    }
    for(int i=start;i<en;i++)
    {
        q[i]=cop[i];
    }

}
void mergeSort(vector<int> &q,int &n,int start,int en,vector<int> &in_p1,vector<int> &in_p2,vector<int> &in_p3)

{
    if(en == start +1){return ;}
    int mid=(start+en)/2;
    mergeSort(q, n, start, mid, in_p1, in_p2, in_p3);
    mergeSort(q, n, mid, en, in_p1, in_p2, in_p3);
    mer(q, n, start, mid, en, in_p1, in_p2, in_p3);
    return;
}



int main()
{

    //return 0;
    int n;
    int a,b,c;
    cin>>n;

    vector <int> p1;
    vector <int> p2;
    vector <int> p3;

    //input

    vector <int> q(n,0);
    vector <int> in_p1(n,0);
    vector <int> in_p2(n,0);
    vector <int> in_p3(n,0);
    int var;
    for(int i=0;i<n;i++)
    {
        cin>>var;
        p1.push_back(var);
    }
    for(int i=0;i<n;i++)
    {
        cin>>var;
        p2.push_back(var);
    }
    for(int i=0;i<n;i++)
    {

        p3.push_back(i+1);
    }
    q=p3;

    for(int i=0;i<n;i++)
    {
        cout<<q[i]<<" ";
    }

    for(int i=0;i<n;i++)
    {
        in_p1[(p1[i]-1)]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        in_p2[p2[i]-1]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        in_p3[p3[i]-1]=i+1;
    }


   //cout<<"ajkka"<<endl;

    mergeSort(q, n, 0, n, in_p1, in_p2, in_p3);

    int coun=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if( !( ( ( in_p1[q[i]-1]< in_p1[q[j]-1]) && ( in_p2[q[i]-1]< in_p2[q[j]-1]) ) || ( ( in_p2[q[i]-1]< in_p2[q[j]-1]) && ( in_p3[q[i]-1]< in_p3[q[j]-1]) ) ||  ( ( in_p1[q[i]-1]< in_p1[q[j]-1]) && ( in_p3[q[i]-1]< in_p3[q[j]-1]) ) ) )

            {
             coun=1;
             a=q[i];
             b=q[j-1];

             c=q[j];
            }

        }
    }
    /*
    ( (in_p1[i-1]>in_p1[j-1]) && (in_p2[i-1]>in_p2[j-1]) ) ||
             ( (in_p2[i-1]>in_p2[j-1]) && (in_p3[i-1]>in_p3[j-1]) ) ||
            ( (in_p1[i-1]>in_p1[j-1]) && (in_p3[i-1]>in_p3[j-1]) )

    */
if(coun==1)
{
cout<<"inconsistent"<<endl;
cout<<a<<" "<<b<<" "<<c;
}
else{
cout<<"consistent"<<endl;
for(int i=0;i<n;i++)
    {
        cout<<q[i]<<" ";
    }
}

return 0;

}

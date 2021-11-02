#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> invjone,invjtwo;
int totalcount=0;
bool randp=true,randq=true;
int r_i,r_j,r1_i,r1_j,rk;

bool myfunction (int i,int j);
void merge(vector<int>::iterator ,int, int , int );
void mergesort(vector<int>::iterator a, int low, int high);

int main()
{
int contestants = 0,i=0;
cin>>contestants;
vector<int> jone,jtwo,normal;
vector<int>::iterator runner,runner1;
jone.resize(contestants);
jtwo.resize(contestants);
invjone.resize(contestants);
invjtwo.resize(contestants);
normal.resize(contestants);

for(runner=jone.begin(); runner<jone.end(); runner++)
{
    cin>>*runner;
}
for(runner=jtwo.begin(); runner<jtwo.end(); runner++)
{
    cin>>*runner;
}
for(runner=normal.begin(),i=0; runner<normal.end();i++, runner++)
{
    *runner=i;
}
for(i=0; i<contestants;i++)
{
    invjone[jone[i]-1]=i-1;
}
for(i=0; i<contestants;i++)
{
    invjtwo[jtwo[i]-1]=i-1;
}

sort(normal.begin(),normal.end(),myfunction);

//vector<int> temp;
//temp.resize(contestants);
//temp=normal;
//mergesort(normal.begin(),0,contestants-1);
//int invpair_r=totalcount;
//normal=temp;
//mergesort(normal.begin(),0,contestants-1);
//if((randp==false)){cout<<"inconsistent"<<endl<<rk<<" "<<r_i+1<<" "<<r_j+1<<endl;}


for(runner=normal.begin();runner<normal.end();runner++)
{
    for(runner1=runner+1;runner1<normal.end();runner1++)
    {
        if(myfunction(*runner,*runner1)){}
        else {cout<<"inconsistent"<<endl<<*runner+1<<" "<<*(runner1-1)+1<<" "<<*runner1+1;
                return 0;}
    }
}
cout<<"consistent"<<endl;
for(runner=normal.begin(),i=0; runner<normal.end();i++, runner++)
{
    cout<<*runner+1<<" ";
}
return 0;
}


bool myfunction (int i,int j)
{
if ((invjone[i]<invjone[j])&&(invjtwo[i]<invjtwo[j])||(i<j)&&(invjtwo[i]<invjtwo[j])||(invjone[i]<invjone[j])&&(i<j))
{return true;}
return false;
}

void merge(vector<int>::iterator ,int, int , int );
void mergesort(vector<int>::iterator a, int low, int high)
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
void merge(vector<int>::iterator a, int low, int high, int mid)
{
    int i, j, k, c[50],rightcount;
    rightcount=0;
    int rightmin=a[high-1],rightmin1=a[high-1],p=0,q=0;
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
            totalcount+=rightcount;
            if(randp == true)
            {

                if((invjone[a[i]]<invjone[rightmin])&&(rightmin!=0)&&(a[i]>rightmin)){randp=false;
                            r_i=rightmin;
                            r_j=a[i];}
            }
             if((randq == true))
            {
                if((invjtwo[a[i]]<invjtwo[rightmin1])&&(rightmin1!=0)&&(a[i]>rightmin1)){randq=false;
                            r1_i=rightmin1;
                            r1_j=a[i];}
            }
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
            rightcount++;
            if(randp == true)
            {
            if(invjone[a[j]] < invjone[rightmin]){
                rightmin=invjone[a[j]];

            }

                           }
            if(randq == true)
            {
            if(invjtwo[a[j]] < invjtwo[rightmin1]){
                rightmin1=invjtwo[a[j]];

            }

                           }
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
        totalcount+=rightcount;
            if(randp == true)
            {

                if((invjone[a[i]]<invjone[rightmin])&&(rightmin!=0)&&(a[i]>rightmin)){randp=false;
                            r_i=rightmin;
                            r_j=a[i];}
            }
             if((randq == true))
            {
                if((invjtwo[a[i]]<invjtwo[rightmin1])&&(a[i]>rightmin1)&&(rightmin1!=0)){randq=false;
                            r1_i=rightmin1;
                            r1_j=a[i];}
            }
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
        rightcount++;
            if(randp == true)
            {
            if(invjone[a[j]] < invjone[rightmin]){
                rightmin=invjone[a[j]];


            }

                           }
            if(randq == true)
            {
            if(invjtwo[a[j]] < invjtwo[rightmin1]){
                rightmin1=invjtwo[a[j]];

            }

                           }
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
    rk=a[invjone[rightmin]-2];
}

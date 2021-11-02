#include <iostream>
using namespace std;

void merge(int*,int*,int*,int*,int,int,int);
bool check (int*,int*,int*,int,int);
void mergesort(int *a, int*b, int* p1, int* p2, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,p1,p2,low,pivot);
        mergesort(a,b,p1,p2,pivot+1,high);
        merge(a,b,p1,p2,low,pivot,high);
    }
}
void merge(int *a, int *b, int *p1, int *p2, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;

    while((h<=pivot)&&(j<=high))
    {
        if(check (a,p1,p2,h,j))
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) {a[k]=b[k];}
}

bool check (int*a,int*p1,int*p2,int i,int j){
    if(a[i]<a[j]){
        if((p1[a[i]-1]<p1[a[j]-1]) || (p2[a[i]-1]<p2[a[j]-1])) {return true;}
        else{return false;}
    }
    else{
        if((p1[a[i]-1]<p1[a[j]-1]) && (p2[a[i]-1]<p2[a[j]-1])) {return true;}
        else {return false;}
    }
}

void invert(int*p, int n){
    int*temp=new int[n];
    for(int i=0; i<n; i++){
        temp[p[i]-1]=i+1;
    }
    for(int i=0; i<n; i++){
        p[i]=temp[i];
    }
    return;
}

int main()
{
    int num;
    cin>>num;
    int*a=new int[num];
    int*b=new int[num];
    int*p1=new int[num];
    int*p2=new int[num];

    for(int i=0; i<num; i++){
        cin>>p1[i];
    }
    for(int i=0; i<num; i++){
        cin>>p2[i];
        a[i]=i+1;
    }

    invert(p1,num);
    invert(p2,num);

    mergesort(a,b,p1,p2,0,num-1);

    int x=-1,y=-1;
    for(int i=0; i<num; i++){
        for(int j=i+2; j<num; j++){
            if(check (a,p1,p2,i,j))
            {continue;}
            else{x=i;y=j;break;}
        }
        if(x!=-1){break;}
    }

    if (x==-1) {
        cout<<"consistent"<<endl;
        for(int i=0; i<num; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"inconsistent"<<endl;
        cout<<a[x]<<" "<<a[y-1]<<" "<<a[y]<<endl;
    }

    delete [] a;delete [] b;delete [] p1;delete [] p2;
    return 1;
}

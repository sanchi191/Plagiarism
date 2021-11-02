#include<iostream>
using namespace std;

int lessthan(int invp[],int invq[],int ri,int rj)
{
    if(ri<rj)
    {
        if((invp[ri-1]<invp[rj-1])||(invq[ri-1]<invq[rj-1]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if((invp[ri-1]<invp[rj-1])&&(invq[ri-1]<invq[rj-1]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void diffmergesortedsubarrays(int A[],int start,int mid,int end,int invp[],int invq[])
{
    int i,j,n=end-start,index=0;
    int tempA[n];
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {
        if ((i < mid) && (j < end))
        {
            if (lessthan(invp,invq,A[j],A[i])) {tempA[index] = A[j]; j++;}
            else {tempA[index] = A[i]; i++;}
        }
        else
        {
            if (i < mid) {tempA[index] = A[i]; i++;}
            else {tempA[index] = A[j]; j++;}
        }
        index ++;
    }
    for (i = start; i < end; i++) {A[i] = tempA[i-start];}
}

void diffmergesort(int a[],int start,int end,int invp[],int invq[])
{
    if((start+1)==end)
    {
        return;
    }
    else
    {
        int middle = (start+end)/2;
        diffmergesort(a,start,middle,invp,invq);
        /*cout<<"First half"<<endl;
        for(int i=start;i<middle;i++)
        {
            cout<<a[i]<<endl;
        }*/
        diffmergesort(a,middle,end,invp,invq);
        /*cout<<"Second"<<endl;
        for(int i=middle;i<end;i++)
        {
            cout<<a[i]<<endl;
        }*/
        diffmergesortedsubarrays(a,start,middle,end,invp,invq);
    }
    return;
}

int mergesortedsubarrays(int A[],int start,int mid,int end,int invp[],int N)
{
    int i,j,n=end-start,index=0,minposp=N;
    int tempA[n];
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {
        if ((i < mid) && (j < end))
        {
            if (A[j] < A[i])
            {
                tempA[index] = A[j];
                //cout<<"Hi4:"<<A[j]<<endl;
                if(invp[A[j]-1]<minposp){minposp=invp[A[j]-1];}
                //cout<<"Hi5:"<<A[j]<<endl;
                j++;
            }
            else
            {
                tempA[index] = A[i];
                if(invp[A[i]-1]>minposp){return 0;}
                i++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = A[i];
                if(invp[A[i]-1]>minposp){return 0;}
                i++;
            }
            else {tempA[index] = A[j]; j++;}
        }
        index ++;
    }
    for (i = start; i < end; i++) {A[i] = tempA[i-start];}
    return 1;
}

int mergesort(int a[],int start,int end,int invp[],int N)
{
    if((start+1)==end)
    {
        //cout<<"Hi0:"<<a[start]<<endl;
        return 1;
    }
    else
    {
        int middle = (start+end)/2;
        int check1=mergesort(a,start,middle,invp,N);
        //cout<<"Hi1:"<<a[start]<<endl;
        /*cout<<"First half"<<endl;
        for(int i=start;i<middle;i++)
        {
            cout<<a[i]<<endl;
        }*/
        int check2=mergesort(a,middle,end,invp,N);
        //cout<<"Hi2:"<<a[start]<<endl;
        /*cout<<"Second"<<endl;
        for(int i=middle;i<end;i++)
        {
            cout<<a[i]<<endl;
        }*/
        int check3=mergesortedsubarrays(a,start,middle,end,invp,N);
        //cout<<"Hi3:"<<a[start]<<endl;
        if((check1==0)||(check2==0)||(check3==0)){return 0;}
        else{return 1;}
    }
}

int invpairsortedsubarrays(int A[],int start,int mid,int end)
{
    int invhere=0;
    int i,j,n=end-start,index=0,nrightinser=0;
    int tempA[n];
    for (i = start, j = mid; ((i < mid) || (j < end)); )
    {
        if ((i < mid) && (j < end))
        {
            if (A[j] < A[i])
            {
                tempA[index] = A[j];
                //cout<<"Hi4:"<<A[j]<<endl;
                nrightinser++;
                //cout<<"Hi5:"<<A[j]<<endl;
                j++;
            }
            else
            {
                tempA[index] = A[i];
                invhere=invhere+nrightinser;
                i++;
            }
        }
        else
        {
            if (i < mid)
            {
                tempA[index] = A[i];
                invhere=invhere+nrightinser;
                i++;
            }
            else {tempA[index] = A[j]; j++;nrightinser++;}
        }
        index ++;
    }
    for (i = start; i < end; i++) {A[i] = tempA[i-start];}
    return invhere;
}

int invpairsort(int a[],int start,int end)
{
    if((start+1)==end)
    {
        return 0;
    }
    else
    {
        int invsofar=0;
        int middle = (start+end)/2;
        int inv1=invpairsort(a,start,middle);
        invsofar=invsofar+inv1;
        int inv2=invpairsort(a,middle,end);
        invsofar=invsofar+inv2;
        //cout<<"Hi2:"<<a[start]<<endl;
        /*cout<<"Second"<<endl;
        for(int i=middle;i<end;i++)
        {
            cout<<a[i]<<endl;
        }*/
        int inv3=invpairsortedsubarrays(a,start,middle,end);
        invsofar=invsofar+inv3;
        //cout<<"Hi3:"<<a[start]<<endl;
        return invsofar;
    }
}

void printthree(int r[],int invp[],int invq[],int n)
{
    int i,j,k,br=1;
    for(i=0;(i<n)&&(br==1);i++)
    {
        for(j=i+2;j<n;j++)
        {
            if(lessthan(invp,invq,r[i],r[j])){break;}

        }
        for(k=i+1;k<j;k++)
        {
            if(lessthan(invp,invq,r[k],r[j])){br=0;break;}
        }
        if(br==0){break;}
    }
    cout<<r[i]<<" "<<r[k]<<" "<<r[j]<<endl;
}

int main()
{
    int n;
    cin>>n;
    int p[n];
    int q[n];
    int r[n];
    int initr[n];
    int ansr[n];
    for(int i=0;i<n;i++){cin>>p[i];}
    for(int i=0;i<n;i++){cin>>q[i];}
    for(int i=0;i<n;i++){r[i]=i+1;initr[i]=i+1;}
    int invp[n],invq[n];
    for(int i=0;i<n;i++)
    {
        invp[p[i]-1]=i+1;
        invq[q[i]-1]=i+1;
    }
    diffmergesort(r,0,n,invp,invq);
    for(int i=0;i<n;i++){ansr[i]=r[i];}
    int checkp=mergesort(ansr,0,n,invp,n);
    for(int i=0;i<n;i++){ansr[i]=r[i];}
    int checkq=mergesort(ansr,0,n,invq,n);
    int s[n];
    for(int i=0;i<n;i++)
    {
        s[i]=invp[q[i]-1];

    }
    int npairp=invpairsort(p,0,n);
    int npairq=invpairsort(q,0,n);
    int npairr=invpairsort(ansr,0,n);
    int npairs=invpairsort(s,0,n);
    int expct=(npairp+npairq-npairs)/2;
    if((npairr==expct)&&(checkp==1)&&(checkq==1))
    {
        cout<<"consistent"<<endl;
        for(int i=0;i<n;i++){cout<<r[i]<<" ";}
        cout<<endl;
    }
    else
    {
        cout<<"inconsistent"<<endl;
        printthree(initr,invp,invq,n);
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void constmymerge(vector<int> &leftA,vector<int> &rightA,vector<int> &A,vector<int> &P,vector<int> &Q,vector<int> &R,vector<int> &S,int &n)
{
    int i=1, j=1, k;
    int a=leftA.size();
    int b=rightA.size();
    int flag=0;
    for(k=1;k<=n;k++)
    {

        if(flag==1) break;
        if(i==a)
        {
            flag=1;
            while(k<=n) { A[k]=rightA[j];k++;j++;}
            continue;
        }
        if(j==b)
        {
            flag=1;
            while(k<=n) { A[k]=leftA[i];k++;i++;}
            continue;
        }
        int count=0;
        if(P[R[leftA[i]]]<P[R[rightA[j]]]) count++;
        else count--;
        if(Q[S[leftA[i]]]<Q[S[rightA[j]]]) count++;
        else count--;
        if(count==-2)
        {
            A[k]=rightA[j]; j++;
        }
        else
        {
            A[k]=leftA[i]; i++;
        }
    }
    return;
}
void constmergesort(vector<int> &A, vector<int> &P, vector<int> &Q,vector<int> &R,vector<int> &S, int &n)
{
        if(n==1) return;
        vector<int> leftA;
        vector<int> rightA;
        int i;
        leftA.push_back(0);
        rightA.push_back(0);
        for(i=1;i<=(n/2);i++) {leftA.push_back(A[i]);}
        for(;i<=n;i++) {rightA.push_back(A[i]);}
        int m=n/2;
        int t=n-m;
        constmergesort(leftA,P,Q,R,S,m);
        constmergesort(rightA,P,Q,R,S,t);
        constmymerge(leftA,rightA,A,P,Q,R,S,n);
        leftA.clear();
        rightA.clear();
        return;
}
void checkmymerge(vector<int> &leftA,vector<int> &rightA,vector<int> &A,vector<int> &P,vector<int> &Q,vector<int> &R, vector<int> &S,int &n,int &val)
{

    int i=1, j=1, k;
    int a=leftA.size();
    int b=rightA.size();
    int flag=0;
    int minR=n, minS=n;
    for(k=1;k<=n;k++)
    {
        if(flag==1) break;
        if(i==a)
        {
            flag=1;
            while(k<=n) {if(R[rightA[j]]<minR) minR=R[rightA[j]]; if(S[rightA[j]]<minS) minS=S[rightA[j]]; A[k]=rightA[j];k++;j++;}
            continue;
        }
        if(j==b)
        {
            flag=1;
            while(k<=n) {if(R[leftA[i]]>minR) val=0; if(S[leftA[i]]>minS) val=0; A[k]=leftA[i];k++;i++;}
            continue;
        }
        int count=0;
        if(P[R[leftA[i]]]<P[R[rightA[j]]]) count++;
        else count--;
        if(Q[S[leftA[i]]]<Q[S[rightA[j]]]) count++;
        else count--;
        if(count==-2)
        {
            if(R[rightA[j]]<minR) minR=R[rightA[j]]; if(S[rightA[j]]<minS) minS=S[rightA[j]];
            A[k]=rightA[j]; j++;
        }
        else
        {
            if(R[leftA[i]]>minR) val=0; if(S[leftA[i]]>minS) val=0;
            A[k]=leftA[i]; i++;
        }
    }
    return;
}
void checkmergesort(vector<int> &A,vector<int> &P,vector<int> &Q,vector<int> &R,vector<int> &S, int& n, int& val)
{
        if(n==1) return;
        vector<int> leftA;
        vector<int> rightA;
        int i;
        leftA.push_back(0);
        rightA.push_back(0);
        for(i=1;i<=(n/2);i++) leftA.push_back(A[i]);
        for(;i<=n;i++) rightA.push_back(A[i]);
        int m=n/2;
        int t=n-m;
        checkmergesort(leftA,P,Q,R,S,m,val);
        checkmergesort(rightA,P,Q,R,S,t,val);
        checkmymerge(leftA,rightA,A,P,Q,R,S,n,val);
        leftA.clear();
        rightA.clear();
        return;
}
void countmymerge(vector<int> &leftA,vector<int> &rightA,vector<int> &A,int &n,int& count)
{
    int i=1, j=1, k;
    int a=leftA.size();
    int b=rightA.size();
    int flag=0;
    for(k=1;k<=n;k++)
    {
        if(flag==1) break;
        if(i==a)
        {
            flag=1;
            while(k<=n) { A[k]=rightA[j];k++;j++;}
        }
        if(j==b)
        {
            flag=1;
            while(k<=n) { A[k]=leftA[i];k++;i++;}
        }
        if(leftA[i]<rightA[j])
        {
            A[k]=leftA[i]; i++;
        }
         if(leftA[i]>=rightA[j])
        {
            A[k]=rightA[j]; j++;count+=n/2-i;
        }
    }
    return;
}
void countmergesort(vector<int> &A, int& n,int& count)
{
        if(n==1) return;
        vector<int> leftA;
        vector<int> rightA;
        int i;leftA.push_back(0);rightA.push_back(0);
        for(i=1;i<=(n/2);i++) {leftA.push_back(A[i]);}
        for(;i<=n;i++) {rightA.push_back(A[i]);}
        int m=n/2;
        int t=n-m;
        countmergesort(leftA,m,count);
        countmergesort(rightA,t,count);
        countmymerge(leftA,rightA,A,n,count);
        leftA.clear();
        rightA.clear();
        return;
}


int main()
{
    vector<int> A;
    vector<int> P;
    vector<int> Q;
    int i, n, t, val=1,countA=0, countP=0, countQ=0,countT=0;
    scanf("%d",&n);
    for(i=0;i<=n;i++) {A.push_back(i);}
    P.push_back(0);Q.push_back(0);
    for(i=1;i<=n;i++) { scanf("%d",&t); P.push_back(t);}
    for(i=1;i<=n;i++) { scanf("%d",&t); Q.push_back(t);}
    vector<int> R(n+1);
    vector<int> S(n+1);
    R[0]=0;S[0]=0;
    for(i=1;i<=n;i++) { R[P[i]]=i; S[Q[i]]=i;}
    vector<int> T(n+1);
    constmergesort(A,P,Q,R,S,n);
    checkmergesort(A,P,Q,R,S,n,val);T[0]=0;
    for(i=1;i<=n;i++) { T[Q[i]]=P[i];}
    countmergesort(A,n,countA);
    countmergesort(P,n,countP);
    countmergesort(Q,n,countQ);
    countmergesort(T,n,countT);
    if(countA!=(countP+countQ-countT)/2) val=0;
    if(val==1)
    {
    printf("consistent \n");
    for(i=1;i<=n;i++) printf("%d",A[i]);
    }
    else printf("inconsistent");
    return 0;
}

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int q1,q2,q3;
bool iscon(vector<int> &a,int N,vector<int> &in_p1,vector<int> &in_p2,vector<int> &p3)
{
    bool r=true;
    int i=1;
    while(i<=N-2)
    {
        if((in_p1[a[i]]>in_p1[a[i+2]])&&(in_p2[a[i]]>in_p2[a[i+2]])) r=false;
        else if((in_p1[a[i]]>in_p1[a[i+2]])&&(p3[a[i]]>p3[a[i+2]])) r=false;
        else if((in_p2[a[i]]>in_p2[a[i+2]])&&(p3[a[i]]>p3[a[i+2]])) r=false;
        if (r==false) {q1=a[i];q2=a[i+1];q3=a[i+2];break;}
        i++;
    }
    return r;

}

bool lessthan(vector<int> &ip1,vector<int> &ip2,vector<int> &p3,vector<int> &l,vector<int> &r,int s,int t)
    {
     if((ip1[l[s]]<ip1[r[t]])&&(ip2[l[s]]<ip2[r[t]])){return true;}
     if((ip1[l[s]]<ip1[r[t]])&&(p3[l[s]]<p3[r[t]])){return true;}
     if((p3[l[s]]<p3[r[t]])&&(ip2[l[s]]<ip2[r[t]])){return true;}
     return false;
    }

void merg(vector<int> &a,vector<int> &ip1,vector<int> &ip2,vector<int> &p3,int i,int m,int f)
    {
     vector<int> l;
     vector<int> r;
     int k=i;
     while(k<=m)
     {
        l.push_back(a[k]);
        k++;
     }
     while(k<=f)
     {
        r.push_back(a[k]);
        k++;
     }
     k=i;
     int s=0,t=0;
     while(k<=f)
     {
        if(s<l.size() && t<r.size())
        {
            if(lessthan(ip1,ip2,p3,l,r,s,t))
            {
                a[k]=l[s];
                s++;
            }
            else
            {
                a[k]=r[t];
                t++;
            }
        }
        else if(s==l.size() && t<r.size())
        {
            a[k]=r[t];
            t++;
        }
        else if(t==r.size() && s<l.size())
        {
            a[k]=l[s];
            s++;
        }
        k++;
     }
}

void merg_count(vector<int> &a,int i,int m,int f,int &countip)
    {
     vector<int> l;
     vector<int> r;
     int countr=0;
     int k=i;
     while(k<=m)
     {
        l.push_back(a[k]);
        k++;
     }
     while(k<=f)
     {
        r.push_back(a[k]);
        k++;
     }
     k=i;
     int s=0,t=0;
     while(k<=f)
     {
        if(s<l.size() && t<r.size())
        {
            if(l[s]<=r[t])
            {
                a[k]=l[s];
                s++;
                countip=countip+countr;
            }
            else
            {
                a[k]=r[t];
                t++;
                countr++;
            }
        }
        else if(s==l.size() && t<r.size())
        {
            a[k]=r[t];
            t++;
            countr++;
        }
        else if(t==r.size() && s<l.size())
        {
            a[k]=l[s];
            s++;
            countip=countr+countip;
        }
        k++;
     }
}


void merge_sort(vector<int> &a,vector<int> &ip1,vector<int> &ip2,vector<int> &p3,int i,int f)
{
    if(i<f)
    {
        int m=(i+f)/2;
        merge_sort(a,ip1,ip2,p3,i,m);
        merge_sort(a,ip1,ip2,p3,m+1,f);
        merg(a,ip1,ip2,p3,i,m,f);
    }
}

void merge_sort_count(vector<int> &a,int i,int f,int &countip)
{
    if(i<f)
    {
        int m=(i+f)/2;
        merge_sort_count(a,i,m,countip);
        merge_sort_count(a,m+1,f,countip);
        merg_count(a,i,m,f,countip);
    }
}

void merg_count_check(vector<int> &a,vector<int> ip1,vector<int> &ip2,int i,int m,int f,int &countip,bool &check)
    {
     vector<int> l;
     vector<int> r;
     int rmin1=ip1.size()+2;
     int rmin2=ip2.size()+2;
     int countr=0;
     int k=i;
     while(k<=m)
     {
        l.push_back(a[k]);
        k++;
     }
     while(k<=f)
     {
        r.push_back(a[k]);
        k++;
     }
     k=i;
     int s=0,t=0;
     while(k<=f)
     {
        if(s<l.size() && t<r.size())
        {
            if(l[s]<=r[t])
            {
                a[k]=l[s];
                s++;
                countip=countip+countr;
                if (ip1[l[s]]>rmin1){check=false;}
                if (ip2[l[s]]>rmin2){check=false;}
            }
            else
            {
                a[k]=r[t];
                t++;
                countr++;
                if (ip1[r[t]]<rmin1){rmin1=ip1[r[t]];}
                if (ip2[r[t]]<rmin2){rmin2=ip2[r[t]];}
            }
        }
        else if(s==l.size() && t<r.size())
        {
            a[k]=r[t];
            t++;
            countr++;
        }
        else if(t==r.size() && s<l.size())
        {
            a[k]=l[s];
            s++;
            countip=countr+countip;
            if (ip1[l[s]]>rmin1||ip2[l[s]]>rmin2){check=false;}
        }
        k++;
     }
}
void merge_sort_count_check(vector<int> &a,vector<int> &ip1,vector<int> &ip2,int i,int f,int &countip,bool &check)
{
    if(i<f)
    {
        int m=(i+f)/2;
        merge_sort_count_check(a,ip1,ip2,i,m,countip,check);
        merge_sort_count_check(a,ip1,ip2,m+1,f,countip,check);
        merg_count_check(a,ip1,ip2,i,m,f,countip,check);
    }
}


int main()
    {
     int n,x,countip1,countip2,countip3,countip4;
     bool check;
     scanf("%d",&n);

     vector<int> p1(n+1);
     vector<int> p2(n+1);
     vector<int> p3(n+1);
     vector<int> ip1(n+1);
     vector<int> ip2(n+1);
     vector<int> r(n+1);
     vector<int> s(n+1);
     vector<int> temp(n+1);
     p1[0]=0;
     p2[0]=0;
     ip1[0]=0;
     ip2[0]=0;
     r[0]=0;
     s[0]=0;
     for (int i=0;i<=n;i++)
        {
         p3[i]=i;
         r[i]=i;
        }
     for (int i=1;i<=n;i++)
            {
             scanf ("%d",&p1[i]);
             ip1[p1[i]]=i;

            }
     for (int i=1;i<=n;i++)
        {
         scanf ("%d",&p2[i]);
         ip2[p2[i]]=i;
        }
    for (int i=1;i<=n;i++)
        {
         s[i]=ip2[p1[i]];
        }

//cout<<p1[1];
//cout<<ip1[1]<<"\n";
merge_sort(r,ip1,ip2,p3,1,n);
for (int i=0;i<=n;i++)
    {
     temp[i]=r[i];
    }
//cout<<r[1]<<r[2]<<r[3]<<r[4]<<r[5]<<r[6]<<"\n";
countip1=0;
countip2=0;
countip3=0;
countip4=0;
check=true;
merge_sort_count(p1,1,n,countip1);
merge_sort_count(p2,1,n,countip2);
merge_sort_count(s,1,n,countip3);
merge_sort_count_check(temp,ip1,ip2,1,n,countip4,check);
//cout<<countip1<<"\n";
//cout<<check;
//cout<<"\n"<<countip4<<"\n";
int countnet;
countnet=(countip1+countip2-countip3)/2;

if (check==true&&countnet==countip4)
    {
     cout<<"consistent"<<"\n";
     for (int i=1;i<=n;i++)
        {cout<<r[i]<<" ";}
    }
else
    {
     cout<<"inconsistent"<<"\n";
     if(iscon(r,n,ip1,ip2,p3)==false)
        {
         cout<<q1<<" "<<q2<<" "<<q3;
        }

    }
}

#include<iostream>
#include<vector>
using namespace std;

int compare(int i,int j,vector<int> &ai,vector<int> &bi,vector<int> &ci)
{
    int c=0;

    if(ai[i]>ai[j])
    {
        c++;
    }
    if(bi[i]>bi[j])
    {
        c++;
    }
    if(ci[i]>ci[j])
    {
        c++;
    }

    if(c>=2)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}


void mer(long long &co,int s, int m,int e,vector<int> &ai,vector<int> &bi,vector<int> &ci,vector<int> &d)
{
    vector<int> temp(e-s);
    int i=0,j=s,k=m;
    for(i=0; i<(e-s); i++)
    {
        if((j!=m)&&(k!=e))
        {
          if(compare(d[j],d[k],ai,bi,ci)==1)
          {
          temp[i]=d[j];j++;
          }
          else{
            temp[i]=d[k];k++;
            co=co+(m-j);
          }
          continue;
        }

        if((j==m))
        {
        temp[i]=d[k];k++;
        continue;
        }
        if(k==e)
        {
        temp[i]=d[j];j++;
         continue;
        }

        }

       for(i=0;i<(e-s);i++)
       {
       d[i+s]=temp[i];
       }

        return ;

}

void mergesort(long long &co,int s,int e,vector<int> &ai,vector<int> &bi,vector<int> &ci,vector<int> &d)
{
    if((s+1)>=e)
    {
        return ;
    }
    int m;
    m=(s+e)/2;
    mergesort(co,s,m,ai,bi,ci,d);
    mergesort(co,m,e,ai,bi,ci,d);
    mer(co,s,m,e,ai,bi,ci,d);

    return ;
}


void mer1(long long &co,int s, int m,int e,vector<int> &d)
{
    vector<int> temp(e-s);
    int i=0,j=s,k=m;
    for(i=0; i<(e-s); i++)
    {
        if((j!=m)&&(k!=e))
        {
          if(d[k]>d[j])
          {
          temp[i]=d[j];j++;
          }
          else{
            temp[i]=d[k];k++;
            co=co+(m-j);
          }
          continue;
        }

        if((j==m))
        {
        temp[i]=d[k];k++;
        continue;
        }
        if(k==e)
        {
        temp[i]=d[j];j++;
         continue;
        }

        }

       for(i=0;i<(e-s);i++)
       {
       d[i+s]=temp[i];
       }

        return ;

}

void mergesort1(long long &co,int s,int e,vector<int> &d)
{
    if((s+1)>=e)
    {
        return ;
    }
    int m;
    m=(s+e)/2;
    mergesort1(co,s,m,d);
    mergesort1(co,m,e,d);
    mer1(co,s,m,e,d);

    return ;
}


bool fmerge(int s,int m,int e,vector<int> &b,vector<int> &bi,vector<int> &d)
{   bool flag=true;
  int i=0,j=s,k=m,mindex=d.size()+10;
  vector<int> temp(e-s);
  for(i=0;i<(e-s);i++)
  {
       if((j!=m)&&(k!=e))
        {
         if(d[j]>d[k])
         {
          if(bi[d[k]]<mindex)
          {
          mindex=bi[d[k]];
          }
          temp[i]=d[k];
          k++;
          continue;
         }
         else{

              if(bi[d[j]]>mindex)
              {
                flag=false;
              }
              temp[i]=d[j];j++;

              continue;
             }

        }

        if((j==m))
        {

           if(bi[d[k]]<mindex)
          {
          mindex=bi[d[k]];
          }
          temp[i]=d[k];
          k++;
          continue;
        }
        if(k==e)
        {
                       if(bi[d[j]]>mindex)
              {
                flag=false;
              }
              temp[i]=d[j];j++;

              continue;
        }

  }

   for(i=0;i<(e-s);i++)
       {
       d[i+s]=temp[i];
       }
   return flag;
}




bool fmsort(int s,int e,vector<int> &b,vector<int> &bi,vector<int> &d)
{bool f1,f2,f3;
if((s+1)>=e)
{
return true;
}
int m;
m=(e+s)/2;
f1=fmsort(s,m,b,bi,d);
if(f1==false)
{
return false;
}


f2=fmsort(m,e,b,bi,d);
if(f2==false)
{
return false;
}
f3=fmerge(s,m,e,b,bi,d);
if(f3==false)
{
return false;
}

return true;
}

void check(vector<int> &ai,vector<int> &bi,vector<int> &ci,vector<int> &d)
{
    bool c=true;
    int n;
    n=ai.size()-1;
    int i,j,k,f1,f2,f3;
    for(i=1; (c==true)&&(i<=n); i++)
    {
        for(j=i+1; (c==true)&&(j<=n); j++)
        {
           f1=compare(d[i],d[j],ai,bi,ci);
           if(f1==1)
           {
           continue;
           }

            for(k=i+1; (c==true)&&(k<j); k++)
            {
                f1=compare(d[i],d[k],ai,bi,ci);
                 if(f1==0)
                 {
                 continue;
                 }
                 else
                 {
                  f1=compare(d[k],d[j],ai,bi,ci);
                   if(f1==1)
                   {
                     cout<<"inconsistent"<<endl;
                     cout<<d[i]<<" "<<d[k]<<" "<<d[j]<<" "<<endl;
                     c=false;
                   }


                 }
            }

        }


    }
if(c==true)
{
cout<<"consistent"<<endl;
for(i=1;i<=n;i++)
{
cout<<d[i]<<" ";
}
}

return ;

}




int main()
{
    int i,n;
    vector<int> a,ai,b,bi,c,ci;

    cin>>n;
    a.resize(n+1);
    ai.resize(n+1);
    b.resize(n+1);
    bi.resize(n+1);
    c.resize(n+1);
    ci.resize(n+1);

    for(i=1; i<=n; i++)
    {
        a[i]=i;
        ai[i]=i;
    }
    for(i=1; i<=n; i++)
    {
        cin>>b[i];
        bi[b[i]]=i;
    }

    for(i=1; i<=n; i++)
    {
        cin>>c[i];
        ci[c[i]]=i;
    }

    vector<int>  d(n+1);
    vector<int>  dtemp(n+1);
    for(i=1; i<=n; i++)
    {
        d[i]=i;
    }

    long long co=0;

  mergesort(co,1,n+1,ai,bi,ci,d);
   //cout<<co<<endl;
    for(i=1; i<=n; i++)
    {
        dtemp[i]=d[i];
    }
   bool f1=fmsort(1,n,b,bi,dtemp);
    for(i=1; i<=n; i++)
    {
        dtemp[i]=d[i];
    }
   bool f2=fmsort(1,n,c,ci,dtemp);

   if((f1!=true)||(f2!=true))
   {
     check(ai,bi,ci,d);
   }
   else{

   vector<int> btemp(n+1),ctemp(n+1),s(n+1);

   for(i=1;i<=n;i++)
   {
   btemp[i]=b[i];
   ctemp[i]=c[i];
   s[i]=bi[c[i]];
   dtemp[i]=d[i];
   }
   long long w1=0,w2=0,w3=0,w4=0;
   mergesort1(w1,1,n+1,btemp);
    mergesort1(w2,1,n+1,ctemp);
     mergesort1(w3,1,n+1,s);
      mergesort1(w4,1,n+1,dtemp);
   if(((w1+w2)-w3)!=(2*w4))
   {
   check(ai,bi,ci,d);
   }
   else
   {
   cout<<"consistent"<<endl;
for(i=1;i<=n;i++)
{
cout<<d[i]<<" ";
}
   }
   }
return 0;
}


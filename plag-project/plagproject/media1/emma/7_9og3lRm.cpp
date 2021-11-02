#include <iostream>
#include <vector>
#include<list>

using namespace std;

void get_inverse_perm(vector<int> v,vector<int> &inv_v,int n)
{
  for(int i=0;i<n;i++)
  {
    int temp=v[i];
    inv_v[temp-1]=i;
  }
}


vector<int> merge(vector<int> left, vector<int> right,vector<int> &inv_p,vector <int> &inv_q)
{
   vector<int> result;
   while (left.size() > 0 || right.size() > 0)
   {
      if (left.size() > 0 && right.size() > 0)
       {
         if (inv_p[(left.front())-1] <=inv_p[(right.front())-1]||inv_q[(left.front())-1]<=inv_q[right.front()-1])
         {
            result.push_back(left.front());
            left.erase(left.begin());
         }
	     else
	     {
            result.push_back(right.front());
            right.erase(right.begin());
         }
      }

      else if (left.size() > 0)
      {
            for (int i = 0; i < left.size(); i++)
               {
                result.push_back(left[i]);
                break;
                }
      }
      else if (right.size() > 0)
      {
            for (int i = 0; i < right.size(); i++)
            {
               result.push_back(right[i]);
               break;
             }
      }
   }
   return result;
}

vector<int> mergeSort(vector<int> m,vector<int> &inv_p,vector<int> &inv_q)
{
   if (m.size() <= 1)
      return m;

   vector<int> left, right, result;
   int middle = (m.size()+ 1) / 2;

   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < m.size(); i++) {
      right.push_back(m[i]);
   }

   left = mergeSort(left,inv_p,inv_q);
   right = mergeSort(right,inv_p,inv_q);
   result = merge(left, right,inv_p,inv_q);

   return result;
}

/*void get_inverse_perm(vector<int> v,vector<int> &inv_v,int n)
{
  for(int i=0;i<n;i++)
  {
    int temp=v[i];
    inv_v[temp-1]=i;
  }
}
*/
int get_inv_pair(vector<int> p,int n)
{
  int temp=0;

  for(int i=0;i<(n-1);i++)
  {
     for(int j=i+1;j<=n-1;j++)
     {
       if(p[i]>p[j]) temp++;
     }
  }

  return temp;
}



bool is_same_inv_pair(vector<int> p, vector<int> q,vector<int> &inv_q,int n)
{

  //get_inverse_perm(q,inv_q,n);

  for(int i=0;i<n-1;i++)
  {
     for(int j=i+1;j<=n-1;j++)
     {
        if(p[i]>p[j])
        {
            if(inv_q[p[i]-1]<inv_q[p[j]-1])
            {

              continue;
            }

            else return false;
         }

     }
  }

  return true;

}

int common_inv_pair(vector<int> p, vector<int> q,vector<int> &inv_q,int n)
{
  int temp=0;

  //get_inverse_perm(q,inv_q,n);

  for(int i=0;i<n-1;i++)
  {
     for(int j=i+1;j<=n-1;j++)
     {
        if(p[i]>p[j])
        {
            if(inv_q[p[i]-1]<inv_q[p[j]-1])
            {
              temp++;
              continue;
            }

         }

     }
  }

  return temp;

}

int main()
{
    int n;
    cin>>n;
    vector<int> p(n,0),q(n,0),inv_q(n,0),inv_p(n,0),r(n,0),inv_r(n,0);

    int common_inv_pair_p_q=0;


    for(int i=0;i<n;i++)
    {
    cin>>p[i];
    }

    for(int i=0;i<n;i++)
    {
    cin>>q[i];
    }

    for(int i=0;i<n;i++)
    {
    r[i]=i+1;
    }


    int inv_pair_r=get_inv_pair(r,n);
    //int inv_pair_r=0;

     //cout<<"ankur"<<endl;
    //cout<<endl<<"ankur"<<endl;

    get_inverse_perm(q,inv_q,n);


    //for(int i=0;i<n;i++)
    //{
    //cout<<inv_q[i]<<" ";
    //}

     //cout<<endl<<"ankur"<<endl;
    get_inverse_perm(p,inv_p,n);


    //for(int i=0;i<n;i++)
    //{
    //cout<<inv_p[i]<<" ";
    //}

     //cout<<endl<<"ankur"<<endl;

    //r=mergeSort(r,inv_p,inv_q);

    //for(int i=0;i<n;i++)
    //{//
    //cout<<r[i]<<" ";
    //}


    common_inv_pair_p_q=common_inv_pair(p,q,inv_q,n);


    if((is_same_inv_pair(r,q,inv_q,n)) && (is_same_inv_pair(r,p,inv_p,n)) && (common_inv_pair_p_q==inv_pair_r))
       {
          cout<<endl<<"consistent "<<endl;
          for(int i=0;i<n;i++)
            {
              cout<<r[i]<<" ";
            }

            cout<<endl;

        }
    else cout<<endl<<"inconsistent"<<endl;

return 0;

}

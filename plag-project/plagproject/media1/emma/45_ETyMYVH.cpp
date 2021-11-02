#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
void merger(vector<int>&, vector<int>&, vector<int>&, int, int, int);
int consistency(vector<int> p_, vector<int> q_, vector<int> r_, int n);
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> p(n),p_(n+1),q(n),q_(n+1),r_(n+1);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        p_[p[i]] = i+1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
        q_[q[i]] = i+1;
        r_[i+1] = i+1;
    }
    merger(p_,q_,r_,1,n+1,n);
    /*
    for(int i=1;i<n+1;i++)
    {
        cout<<r_[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<n+1;i++)
    {
        cout<<p_[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<n+1;i++)
    {
        cout<<q_[i]<<" ";
    }
    cout<<"\n";
    */
    int check = consistency(p_,q_,r_,n);
    if(check == 1)
    {
        cout<<"consistent \n";
        for(int i=1;i<n+1;i++)
        {
            cout<<r_[i]<<" ";
        }
        cout<<"\n";
    }
}


void merger(vector<int>& p_, vector<int>& q_, vector<int>& r_, int a, int b, int n)
{
    if(n>1)
    {
        int count1 = 0, count2 = 0, i, j, k;
        if(n%2 == 0)
        {
            count1 = n/2;
            count2 = n/2;
            merger(p_,q_,r_,a,((n/2)+a),(n/2));
            merger(p_,q_,r_,((n/2)+a),b,(n/2));
        }
        else
        {
            count1 = (n-1)/2;
            count2 = (n+1)/2;
            merger(p_,q_,r_,a,(((n-1)/2)+a),((n-1)/2));
            merger(p_,q_,r_,(((n-1)/2)+a),b,((n+1)/2));
        }
        int* temp = new int[n];
        i = a; j = count1+a; k = 0;
        for(;k<n;k++)
        {
            temp[k] = 0;
        }
        k = 0;
        while(i<j && j<b)
        {
            if((r_[i]<r_[j]) && ((p_[r_[i]] < p_[r_[j]]) || (q_[r_[i]] < q_[r_[j]])))
            {
                temp[k] = r_[i];
                i++;
                k++;
            }
            else if((r_[i]>r_[j]) && ((p_[r_[i]] < p_[r_[j]]) && (q_[r_[i]] < q_[r_[j]])))
            {
                temp[k] = r_[i];
                k++;
                i++;
            }
            else
            {
                temp[k] = r_[j];
                k++;
                j++;
            }
        }
        if(i<(count1+a))
        {
            for(;i<(count1+a);i++,k++)
            {
                temp[k] = r_[i];
            }
        }
        else
        {
            for(;j<b;j++,k++)
            {
                temp[k] = r_[j];
            }
        }
        for(int i=a,j=0;i<b,j<n;i++,j++)
        {
            r_[i] = temp[j];
        }
        delete[] temp;
    }
}

int consistency(vector<int> p_, vector<int> q_, vector<int> r_, int n)
{
    for(int i=1;i<n+1;i++)
    {
        for(int j=i+1;j<n+1;j++)
        {
            if((r_[i]<r_[j]) && ((p_[r_[i]] < p_[r_[j]]) || (q_[r_[i]] < q_[r_[j]])))
            {
            }
            else if((r_[i]>r_[j]) && ((p_[r_[i]] < p_[r_[j]]) && (q_[r_[i]] < q_[r_[j]])))
            {
            }
            else
            {
                cout<<"inconsistent \n";
                cout<<r_[i]<<" "<<r_[j-1]<<" "<<r_[j]<<"\n";
                return -1;
            }
        }
    }
    return 1;
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class order
{
public:
    int n;
    vector<int >v1,v2,inv_v1,inv_v2;
    order()
    {
        cin>>n;
        v1.resize(n+1);
        inv_v1.resize(n+1);
        v2.resize(n+1);
        inv_v2.resize(n+1);
        v1[0]=0;
        v2[0]=0;
        inv_v1[0]=0;
        inv_v2[0]=0;
        for(int i=1; i<n+1; i++)
        {
            cin>>v1[i];
            inv_v1[v1[i]]=i;
        }
        for(int i=1; i<n+1; i++)
        {
            cin>>v2[i];
            inv_v2[v2[i]]=i;
        }
    }
    bool lessthan (int i ,int j)
    {
        bool a=(i<j);
        bool b=(inv_v1[i]<inv_v1[j]);
        bool c=(inv_v2[i]<inv_v2[j]);
        if((a&&b)||(b&&c)||(c&&a))
        {
            return true;
        }
        else return false;
    }
};
order cntstnts;
bool lesser(int i ,int j)
{
    return cntstnts.lessthan(i,j);
}
int main()
{
    vector<int > sorted((cntstnts.n)+1);
    sorted[0]=0;
    for(int i=1; i<sorted.size(); i++)
    {
        sorted[i]=i;
    }
    sort(sorted.begin()+1,sorted.end(),lesser);
    for(int i=1; i<sorted.size(); i++)
    {
        int j;
        for(j=i+2; j<sorted.size(); j++)
        {
            if(lesser(sorted[i],sorted[j]))
            {
                continue;
            }
            else
            {
                cout<<"inconsistent"<<endl;
                cout<<sorted[i]<<" "<<sorted[j-1]<<" "<<sorted[j];
                return 0;
            }
        }
    }
    cout<<"consistent"<<endl;
    for(int i=1; i<sorted.size(); i++)
    {
        cout<<sorted[i]<<" ";
    }
    return 0;
}

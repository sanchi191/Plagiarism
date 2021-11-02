#include<iostream>
#include<list>
using namespace std;
int *invA,*invB;
class player
{
public:
    int a;
    bool operator<(player &A)
    {
        if(a<A.a)
        {
            if(invA[a]<invA[A.a] || invB[a]<invB[A.a])
                return true;
            else
                return false;
        }
        else
        {
            if(invA[a]<invA[A.a] && invB[a]<invB[A.a])
                return true;
            else
                return false;
        }
    }

};
int main()
{
    int n;
    cin>>n;
    list<player>perm(n);
    invA=new int[n+1];
    invB=new int[n+1];
    int i=1;
    for(list<player>::iterator it=perm.begin(); i<n+1; i++ ,it++)
    {
        it->a=i;
        int input;
        cin>>input;
        invA[input]=i;
    }
    for(i=1; i<n+1; i++)
    {
        int input;
        cin>>input;
        invB[input]=i;
    }
    perm.sort();
    for(list<player>::iterator it1=perm.begin(); it1!=(--perm.end()); it1++)
    {
        list<player>::iterator it2=it1;
        it2++;
        for(it2++; it2!=perm.end(); it2++)
        {
            if((*it1)<(*it2))
            {
                ;
            }
            else
            {
                cout<<"inconsistent"<<endl;
                list<player>::iterator it3=it2;
                it3--;
                cout<<it1->a<<" "<<it3->a<<" "<<it2->a;
                return 0;
            }
        }
    }
    cout<<"consistent"<<endl;
    for(list<player>::iterator it=perm.begin(); it!=perm.end(); it++)
    {
        cout<<it->a<<" ";
    }
}

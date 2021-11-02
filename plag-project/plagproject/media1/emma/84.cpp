# include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector<int> f,p,q;
//int *a,*p,*q,*inv_a,*inv_p,*inv_q;
vector<int> a,p,q,inv_a,inv_p,inv_q;
bool lessthan(int i,int j)
{

    if(inv_a[i]<inv_a[j])
    {
//i>j till now
        if(inv_p[i]<inv_p[j] || inv_q[i]<inv_q[j])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(inv_p[i]<inv_p[j] && inv_q[i]<inv_q[j])
        {
            return true;

        }
        else
        {
            return false;
        }

    }


}

void printit(vector<int> r,int i,int n)
{
    bool ctillnow=true;
    int j;
    for(; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(!lessthan(r[i],r[j]))
            {
                ctillnow=false;
                break;
            }
        }
        if(!ctillnow)
        {
            //foound anamoly
            //wrongindex1=i;
            //wrongindex12=j;
            break;
        }

    }

    if(!ctillnow)
    {
        cout<<"inconsistent"<<endl;
        cout<<r[i]+1<<" "<<r[i+1]+1<<" "<<r[j]+1<<" ";
    }
    else
    {
        cout<<"consistent"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<r[i]+1<<" ";
        }

    }
    return;

}


//now write algo ofor checking if each number of inversion pa

void n_invs(int startindex,int endindex,vector<int>first,vector<int> second,int &inv)
{
    if (startindex==endindex)
    {
        return;//size 1 sorted
    }
    else
    {
        int midindex=(startindex+endindex)/2;
        n_invs(startindex,midindex,first,second,inv);//sort first half
        n_invs(midindex+1,endindex,first,second,inv);//sort right half
        //merge the sorted arrays

        int i=startindex,j=midindex+1,k=startindex;

        while(true)
        {
            if(i<= midindex && j<=endindex)
            {
                if (lessthan(first[i],first[j]))//change this condition
                {

                    second[k]=first[i];
                    k++;
                    i++;

                }
                else
                {
                    inv=inv+midindex-i+1;
                    second[k]=first[j];
                    j++;
                    k++;


                }

            }
            else if(i>midindex && j<=endindex) //i reached it value
            {
                second[k]=first[j];
                j++;
                k++;

            }
            else if (j>endindex&& i<=midindex)
            {
                second[k]=first[i];
                k++;
                i++;


            }
            else
            {
                break;
            }
        }

        for(int l=startindex; l<=endindex; l++)
        {
            first[l]=second[l];
        }

    }



    return;
}

bool correcttillnow;
int errfrmthis,errtillthis;
void checkrina(int startindex,int endindex,vector<int>first,vector<int> second,vector<int>q,vector<int> invq)
{
    if(correcttillnow)
    {
        if (startindex==endindex)
        {
            return;//size 1 sorted
        }
        else
        {
            int midindex=(startindex+endindex)/2;
            checkrina(startindex,midindex,first,second,q,invq);//sort first half
            checkrina(midindex+1,endindex,first,second,q,invq);//sort right half
            //merge the sorted arrays
            if(correcttillnow)
            {
                int i=startindex,j=midindex+1,k=startindex;
                int minright=invq[j];
                while(true)
                {
                    if(i<= midindex && j<=endindex)
                    {
                        if (lessthan(first[i],first[j]))//change this condition
                        {
                            if(invq[i])
                                second[k]=first[i];
                            k++;
                            i++;

                        }
                        else
                        {
                            //required case
                            if(!invq[first[i]]<minright)
                            {
                                //this inver in r doesnot exists in p
                                errfrmthis=i;
                                errtillthis=j;
                                correcttillnow=false;
                                return;
                            }
                            second[k]=first[j];
                            j++;
                            k++;
                            if(invq[j]<minright)
                            {
                                minright=invq[j];
                            }

                        }

                    }
                    else if(i>midindex && j<=endindex) //i reached it value
                    {
                        second[k]=first[j];
                        j++;
                        k++;

                    }
                    else if (j>endindex&& i<=midindex)
                    {
                        second[k]=first[i];
                        k++;
                        i++;


                    }
                    else
                    {
                        break;
                    }
                }

                for(int l=startindex; l<=endindex; l++)
                {
                    first[l]=second[l];
                }


            }

            return;
        }



        return;
    }
    /////////
    return;
}


int main()
{
    int n;
    cin>>n;
    a.resize(n);
    p.resize(n);
    q.resize(n);
    inv_a.resize(n);
    inv_p.resize(n);
    inv_q.resize(n);
    int temp;
//take input
    for(int i=0; i<n; i++)
    {
        a[i]=i;
        inv_a[a[i]]=i;
        cin>>temp;
        p[i]=temp-1;
        inv_p[p[i]]=i;

    }
    for (int i=0; i<n; i++)
    {
        cin>>temp;
        q[i]=temp-1;
        inv_q[q[i]]=i;

    }

    //int * b=new int[n];
    // mergesort(0,n,a,b);
    vector <int> r=a;
    sort(r.begin(),r.end(),lessthan);


    //now write code for checking inverse simple one
    int i,j;
    bool ctillnow=true;

int rinvs=0,commoninvs=0,pinvs=0,qinvs=0;
    // for(int i=0)
    correcttillnow=true;
    vector<int> tempr=r;
    vector<int> ttempr(n);
    errfrmthis=0;
    errtillthis=n;
    checkrina(0,n-1,r,r,q,inv_q);
    if(correcttillnow)
    {
        tempr=r;
        checkrina(0,n-1,r,r,p,inv_p);
        if(correcttillnow){
        //move forward
        tempr=r;

        n_invs(0,n-1,r,r,rinvs);
        n_invs(0,n-1,p,p,pinvs);
        n_invs(0,n-1,q,q,qinvs);
        //cout<<rinvs<<endl;
        //cout<<qinvs<<endl;
        //cout<<pinvs<<endl;
        vector<int> s(n);
        for(int i=0;i<n;i++){
        s[i]=inv_p[q[i]];
        }
        n_invs(0,n-1,s,s,commoninvs);
        //cout<<commoninvs<<endl;
        if(rinvs==pinvs+qinvs-commoninvs){
        cout<<"consistent"<<endl;
            for(int i=0;i<n;i++){

                cout<<r[i]+1<<" ";

            }
            return 0;
        }
        else{
            cout<<"inconsistent"<<endl;
            //printit(r,errfrmthis,errtillthis);
        }

        return 0;

        }
        else{
        //cout<<"r not in q"<<endl;
        cout<<"inconsistent"<<endl;
        //printit(r,errfrmthis,errtillthis);
        return 0;
        }

    }
    else
    {
        cout<<"inconsistent"<<endl;
        //printit(r,errfrmthis,errtillthis);
        return 0;


    }




}




#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector< int > perm1;
vector< int > perm2;
list<int> r;
vector< int > invperm1;
vector< int > invperm2;
vector< int > invr;
vector<int> vectorr;
vector<int> rcopy;
bool a=true;
int n;
int counts=0;
int ii;
int jj;
int m=0;


bool func(int a , int b)
{
    if(a<b)
    {
        if((invperm1[a]<invperm1[b] )|| (invperm2[a]<invperm2[b])) return true;
        else return false;
    }
    else
    {
        if((invperm1[a]<invperm1[b] )&& (invperm2[a]<invperm2[b])) return true;
        else return false;
    }
}

vector<int> merge1(const vector<int>& left, const vector<int>& right)
{
    // Fill the resultant vector with sorted results from both vectors
    vector<int> result;
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size())
    {
        // If the left value is smaller than the right it goes next
        // into the resultant vector
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            counts += left.size()-left_it;
            result.push_back(right[right_it]);
            right_it++;
        }
    }

    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}

vector<int> merge_sort1(vector<int>& vec)
{
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1)
    {
        return vec;
    }

    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    // Perform a merge sort on the two smaller vectors
    left = merge_sort1(left);
    right = merge_sort1(right);

    return merge1(left, right);
}

vector<int> merge(const vector<int>& left, const vector<int>& right)
{
    // Fill the resultant vector with sorted results from both vectors
    vector<int> result;
    int minindex1=n,minindex2=n;
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size())
    {

        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            if(!(invperm1[left[left_it]]<minindex1 && invperm2[left[left_it]]<minindex2))
            {
                a=false;
                /*ii=right[right_it];
                jj=perm1[minindex1];

                int i=rcopy[invr[jj]+1];

                while(!(func(i,ii)&& func(ii,jj) && func(jj,i))&&
                        !(func(ii,i)&& func(jj,ii) && func(i,jj)))
                        {
                            jj=i;
                            i=rcopy[invr[i]+1];
                        }
                m=i;


                /*for(int i=1;i<left.size();i++)
                {
                    if(left[left_it+i]<right[right_it])
                    {
                            jj=left[left_it];
                            m=left[left_it+i];
                            break;
                    }
                }*/
                vector <int> e;
                return e;
            }
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            if(invperm1[right[right_it]] < minindex1 )
            {
                minindex1=invperm1[right[right_it]];
            }
            if(invperm2[right[right_it]] < minindex2 )
            {
                minindex2=invperm2[right[right_it]];
            }
            right_it++;
        }
    }

    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        if(!(invperm1[left[left_it]]<minindex1 && invperm2[left[left_it]]<minindex2))
        {
            a=false;
            //ii=right[right_it];
            //jj=perm1[minindex1];
            //int i=rcopy[invr[jj]+1];
                /*
            while(!(func(i,ii)&& func(ii,jj) && func(jj,i))&&
                        !(func(ii,i)&& func(jj,ii) && func(i,jj)))
                        {
                            jj=i;
                            i=rcopy[invr[i]+1];
                        }
            m=i;

            /*for(int i=1;i<left.size();i++)
                {
                    if(left[left_it+i]<right[right_it])
                    {
                            jj=left[left_it];
                            m=left[left_it+i];
                            break;
                    }
                }*/
            vector <int> e;
            return e;
        }
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}


vector<int> merge_sort(vector<int>& vec)
{
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1)
    {
        return vec;
    }

    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    // Perform a merge sort on the two smaller vectors
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}


int main(){
    cin>>n;
    perm1.resize(n);
    perm2.resize(n);
    invr.resize(n);
    invperm1.resize(n);
    invperm2.resize(n);
    vectorr.resize(n);
    rcopy.resize(n);
    vector<int> newr;
    vector<int> s;
    newr.resize(n);
    s.resize(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        perm1[i]=x-1;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        perm2[i]=x-1;
    }
    for(int i=0;i<n;i++)
    {
        r.push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        invperm1[perm1[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        invperm2[perm2[i]]=i;
        s[i]=invperm1[perm2[i]];
    }
    r.sort(func);
    int j=0;
    for(list<int>::iterator iterators =r.begin();iterators!=r.end();iterators++)
    {
        vectorr[j]=(*iterators);
        newr[j]=(*iterators);
        rcopy[j]=(*iterators);
        j++;
    }
    for(int i=0;i<n;i++)
    {
        invr[vectorr[i]]=i;
    }
    //cout<<*r.begin()+1;
    merge_sort(vectorr);
    //cout<<endl<<a<<endl;
    int cp,cq,cs,cr;
    merge_sort1(newr);
    cr=counts;
    counts=0;
    merge_sort1(perm1);
    cp=counts;
    counts=0;
    merge_sort1(perm2);
    cq=counts;
    counts=0;
    merge_sort1(s);
    cs=counts;
    counts=0;
    /*int abcd,efgh;
    abcd=jj;
    efgh=invr[ii];
    if(a==0)
    {
        for(int i=invr[abcd];i<ii;i++)
        {
            if((rcopy[i] < rcopy[efgh]) && (rcopy[efgh] < rcopy[i+1]) && (rcopy[i+1] < rcopy[i]))
                {
                    jj=i;
                    m=i+1;

                    //abcd=1;
                    break;
                }
        }
    }
    if(abcd==0 && a==0)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=ii && i!=jj)
            {
                if((invperm2[ii]<invperm2[jj]) && (invperm2[jj]<invperm2[i]) && (invperm2[i]<invperm2[ii]))
                {
                    kk=i;
                    cout<<"lalalalalalalla"<<endl;
                    break;
                }
            }
        }
    }*/
    bool answer=false;
    if((cr*2)==(cp+cq-cs)) answer=true;
    if(a==1 && answer==true)
    {
        cout<<"consistent"<<endl;
        for(list<int>::iterator iterators =r.begin();iterators!=r.end();iterators++)
        {
            cout<<*iterators+1<<" ";
        }
    }
    else
    {
        cout<<"inconsistent"<<endl;
        cout<<ii+1<<" "<<jj+1<<" "<<m+1;


    }//cout<<cp<<endl;
    //cout<<cq<<endl;
    //cout<<cs<<endl;
    //cout<<cr<<endl;

}

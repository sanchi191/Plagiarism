#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
int n,sum=0,sump=0,sumq=0,sum_in=0,sums=0,i_final,j_final,k_final=0;
bool consistent=true,done=false;
vector<int> p,q, p_inv, q_inv,s,fin_vec1,fin_inverse;
bool comp(int i, int j)
{
    if((p_inv[i]<p_inv[j] && q_inv[i]<q_inv[j]) || (i<j && p_inv[i]<p_inv[j]) || (i<j && q_inv[i]<q_inv[j]))
        return true;
    else return false;
}
vector<int> merge(const vector<int>& left, const vector<int>& right)
{
    vector<int> result;
    unsigned left_it = 0, right_it = 0;
    int r_count=right.size();
    int minp=n;
    int minq=n;

    while(left_it < left.size() && right_it < right.size())
    {
        // If the left value is smaller than the right it goes next
        // into the resultant vector
        if(left[left_it] < right[right_it])
        {
            if(p_inv[left[left_it]]>minp)
            {
                consistent=false;
                if(!done)
                {
                    i_final=left[left_it];
                    j_final=p[minp];
                    int i=fin_vec1[fin_inverse[j_final]+1];
                    done=true;
                    while(!(comp(i,i_final)&& comp(i_final,j_final) && comp(j_final,i))&&
                    !(comp(i_final,i)&& comp(j_final,i_final) && comp(i,j_final)))
                    {
                        j_final=i;
                        i=fin_vec1[fin_inverse[i]+1];
                    }
                    k_final=i;

                }
            }
            if(q_inv[left[left_it]]>minq)
            {
                consistent=false;
                if(!done)
                {
                    i_final=left[left_it];
                    j_final=q[minq];
                    int i=fin_vec1[fin_inverse[j_final]+1];
                    done=true;
                    while(!(comp(i,i_final)&& comp(i_final,j_final) && comp(j_final,i))&&
                    !(comp(i_final,i)&& comp(j_final,i_final) && comp(i,j_final)))
                    {
                        j_final=i;
                        i=fin_vec1[fin_inverse[i]+1];
                    }
                    k_final=i;
                }

            }
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            minp=min(minp, p_inv[right[right_it]]);
            minq=min(minq, q_inv[right[right_it]]);
            sum+=left.size() - left_it;
            result.push_back(right[right_it]);
            right_it++;
        }
    }

    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        if(p_inv[left[left_it]]>minp)
        {
            consistent=false;
            if(!done)
            {
                i_final=left[left_it];
                j_final=p[minp];
                int i=fin_vec1[fin_inverse[j_final]+1];
                done=true;
                while(!(comp(i,i_final)&& comp(i_final,j_final) && comp(j_final,i))&&
                !(comp(i_final,i)&& comp(j_final,i_final) && comp(i,j_final)))
                {
                    j_final=i;
                    i=fin_vec1[fin_inverse[i]+1];
                }
                k_final=i;
            }
        }
        if(q_inv[left[left_it]]>minq)
        {
            consistent=false;
            if(!done)
            {
                i_final=left[left_it];
                j_final=q[minq];
                int i=fin_vec1[fin_inverse[j_final]+1];
                done=true;
                while(!(comp(i,i_final)&& comp(i_final,j_final) && comp(j_final,i))&&
                !(comp(i_final,i)&& comp(j_final,i_final) && comp(i,j_final)))
                {
                    j_final=i;
                    i=fin_vec1[fin_inverse[i]+1];
                }
                k_final=i;
            }
        }
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
vector<int> merge_sort(vector<int>& vec)
{
    if(vec.size() == 1)
    {
        return vec;
    }

    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}
vector<int> merge_count(const vector<int>& left, const vector<int>& right)
{
    vector<int> result;
    unsigned left_it = 0, right_it = 0;
    int r_count=right.size();

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
            sum_in+=left.size() - left_it;
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
vector<int> merge_sort_count(vector<int>& vec)
{
    if(vec.size() == 1)
    {
        return vec;
    }

    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    left = merge_sort_count(left);
    right = merge_sort_count(right);

    return merge_count(left, right);
}
int main()
{
    //Input
    int temp;
    cin>>n;
    p.resize(n);
    q.resize(n);
    p_inv.resize(n);
    q_inv.resize(n);
    s.resize(n);
    fin_vec1.resize(n);
    fin_inverse.resize(n);

    list<int> fin;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        p[i]=temp-1;
        p_inv[p[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        q[i]=temp-1;
        q_inv[q[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        s[i]=p_inv[q[i]];
    }
    //Process
    for(int i=0;i<n;i++)
        fin.push_back(i);

    fin.sort(comp);
    list<int>:: iterator it=fin.begin();
    vector<int> fin_vec(n);
    temp=0;
    while(it!=fin.end())
    {
        fin_vec[temp]=(*it);
        it++;
        temp++;
    }
    for(int i=0;i<n;i++)
    {
        fin_vec1[i]=fin_vec[i];
        fin_inverse[fin_vec1[i]]=i;
    }
    merge_sort(fin_vec);
    vector<int> v=merge_sort_count(p);
    sump=sum_in;
    sum_in=0;
    v=merge_sort_count(q);
    sumq=sum_in;
    sum_in=0;
    v=merge_sort_count(s);
    sums=sum_in;
    sum_in=0;
    //cout<<"sump is "<<sump<<" sumq is "<<sumq<<" sums is "<<sums<<" sumr is "<<sum<<endl;
    if(sum!=(sump+sumq-sums)/2)
        consistent=false;
    //Output
    if(consistent)
    {
        cout<<"consistent\n";
        for(int i=0;i<n;i++)
        {
            cout<<fin_vec[i]+1<<" ";
        }
    }
    else
    {
        cout<<"inconsistent\n";
        cout<<i_final+1<<" "<<j_final+1<<" "<<k_final+1;
    }
    return 0;
}

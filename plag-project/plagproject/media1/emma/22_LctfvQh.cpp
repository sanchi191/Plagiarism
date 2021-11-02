#include<iostream>
#include<limits>

#define inf numeric_limits<int>::max()

using namespace std;
void mergeSort(int [],int,int[],int[]);
void m_sort(int [],int [],int, int,int[],int[]);
int m_sort(int [],int [],int, int);
void merge(int [],int [],int,int,int,int[],int[]);
int merge(int [],int [],int,int,int);
bool less_than(int,int,int [],int []);
int num_pairs(int [],int);
bool all_pairs(int [],int [],int);
bool merge(int [], int [], int , int , int,int []);

bool m_sort(int [], int [], int , int ,int []);

int main()
{
int n=0;
cin>>n;
int r[n],p[n],q[n],c[n],p_inv[n],q_inv[n],s[n];
for(int i=0;i<n;i++)
    {
    cin>>p[i];
    p[i]--;
    }
for(int i=0;i<n;i++)
    {
    cin>>q[i];
    q[i]--;
    }
for(int i=0;i<n;i++)
    {
    r[i]=i;
    c[i]=i;
    p_inv[p[i]]=i;
    q_inv[q[i]]=i;
    }
for(int i=0;i<n;i++)
    {
    s[i]=p_inv[q[i]];
    }

bool flag=true;
mergeSort(r,n,p_inv,q_inv);
if(((num_pairs(p,n)+num_pairs(q,n)-num_pairs(s,n))/2)!=num_pairs(r,n))
flag=false;
bool a=all_pairs(r,p_inv,n);
bool b=all_pairs(r,q_inv,n);
if(a==false||b==false)
flag=false;
if(flag==false)
    {
    cout<<"inconsistent";
    }
else
    {
    cout<<"consistent\n";
    for(int i=0;i<n;i++)
        cout<<r[i]+1<<" ";
    }

}


void mergeSort(int numbers[],int array_size,int p_inv[],int q_inv[])

{       int temp[array_size];
        m_sort(numbers, temp, 0, array_size - 1,p_inv,q_inv);

}



void m_sort(int numbers[], int temp[], int left, int right,int p_inv[],int q_inv[])

{
        int mid;

        if (right > left)

        {

            mid = (right + left) / 2;

            m_sort(numbers, temp, left, mid,p_inv,q_inv);

            m_sort(numbers, temp, mid+1, right,p_inv,q_inv);


            merge(numbers, temp, left, mid+1, right,p_inv,q_inv);

        }

}



void merge(int numbers[], int temp[], int left, int mid, int right,int p_inv[],int q_inv[])

        {

            int i, left_end, num_elements, tmp_pos;


            left_end = mid - 1;

            tmp_pos = left;

            num_elements = right - left + 1;



while ((left <= left_end) && (mid <= right))

        {

                if (less_than(numbers[left],numbers[mid],p_inv,q_inv))

                {

                        temp[tmp_pos] = numbers[left];

                        tmp_pos = tmp_pos + 1;

                        left = left +1;

                }

                else

                {

                        temp[tmp_pos] = numbers[mid];

                        tmp_pos = tmp_pos + 1;

                        mid = mid + 1;

                }

        }



        while (left <= left_end)

                {

                        temp[tmp_pos] = numbers[left];

                        left = left + 1;

                        tmp_pos = tmp_pos + 1;

                }

                while (mid <= right)

                {

                        temp[tmp_pos] = numbers[mid];

                        mid = mid + 1;

                        tmp_pos = tmp_pos + 1;

                }



                for (i = 0; i <= num_elements; i++)

                {

                        numbers[right] = temp[right];

                        right = right - 1;

                }

        }



bool less_than(int i,int j,int p_inv[],int q_inv[])
{
    if(((p_inv[i]<p_inv[j])&&(q_inv[i]<q_inv[j]))||((p_inv[i]<p_inv[j])&&(i<j))||((q_inv[i]<q_inv[j])&&(i<j)))
    {
    return true;
    }
    return false;
}

int num_pairs(int numbers[],int array_size)
{
int temp[array_size];
return m_sort(numbers, temp, 0, array_size - 1);

}

int m_sort(int numbers[], int temp[], int left, int right)

{
        int mid;

        if (right > left)

        {

            mid = (right + left) / 2;

            int i=m_sort(numbers, temp, left, mid);

            int j=m_sort(numbers, temp, mid+1, right);


            int k=merge(numbers, temp, left, mid+1, right);

            return i+j+k;
        }
    return 0;
}



int merge(int numbers[], int temp[], int left, int mid, int right)

{
            int count=0;
            int MID=mid;

            int i, left_end, num_elements, tmp_pos;


            left_end = mid - 1;

            tmp_pos = left;

            num_elements = right - left + 1;



while ((left <= left_end) && (mid <= right))

        {

                if (numbers[left] < numbers[mid])

                {

                        temp[tmp_pos] = numbers[left];

                        tmp_pos = tmp_pos + 1;

                        left = left +1;
                        count=count+mid-MID;
                }

                else

                {

                        temp[tmp_pos] = numbers[mid];

                        tmp_pos = tmp_pos + 1;

                        mid = mid + 1;

                }

        }



            while (left <= left_end)

                {

                        temp[tmp_pos] = numbers[left];

                        left = left + 1;

                        tmp_pos = tmp_pos + 1;
                    count=count+mid-MID;

                }

                while (mid <= right)

                {

                        temp[tmp_pos] = numbers[mid];

                        mid = mid + 1;

                        tmp_pos = tmp_pos + 1;

                }



                for (i = 0; i <= num_elements; i++)

                {

                        numbers[right] = temp[right];

                        right = right - 1;

                }

        return count;
}

bool all_pairs(int numbers[],int q_inv[],int array_size)
{

int temp[array_size];
return m_sort(numbers,temp,0,array_size-1,q_inv);


}

bool m_sort(int numbers[], int temp[], int left, int right,int q_inv[])

{
        int mid;

        if (right > left)

        {

            mid = (right + left) / 2;

            bool i=m_sort(numbers, temp, left, mid,q_inv);

            bool j=m_sort(numbers, temp, mid+1, right,q_inv);


            bool k=merge(numbers, temp, left, mid+1, right,q_inv);

            if(i==false||j==false||k==false)
            return false;
            else return true;
        }
   return true;
}



bool merge(int numbers[], int temp[], int left, int mid, int right,int q_inv[])

{
            int min=inf;
            bool value=true;

            int i, left_end, num_elements, tmp_pos;


            left_end = mid - 1;

            tmp_pos = left;

            num_elements = right - left + 1;



while ((left <= left_end) && (mid <= right))

        {

                if (numbers[left] < numbers[mid])

                {

                        temp[tmp_pos] = numbers[left];

                        tmp_pos = tmp_pos + 1;

                        left = left +1;
                        if(q_inv[numbers[left]]>=min)
                        return false;
                }

                else

                {
                        if(q_inv[numbers[mid]]<min){
                            min=q_inv[numbers[mid]];

                        }
                        else
                        temp[tmp_pos] = numbers[mid];

                        tmp_pos = tmp_pos + 1;

                        mid = mid + 1;

                }

        }



            while (left <= left_end)

                {

                        temp[tmp_pos] = numbers[left];

                        left = left + 1;

                        tmp_pos = tmp_pos + 1;
            if(q_inv[numbers[left]]>=min)
                        return false;
                }

                while (mid <= right)

                {

                        temp[tmp_pos] = numbers[mid];

                        mid = mid + 1;

                        tmp_pos = tmp_pos + 1;

                }



                for (i = 0; i <= num_elements; i++)

                {

                        numbers[right] = temp[right];

                        right = right - 1;

                }
        return value;
}

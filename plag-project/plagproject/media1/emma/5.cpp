#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a,int b);
bool consistent(vector<int> result,int n);
bool check1(vector<int> &result,int a,int b);
bool check2(vector<int> &result,int a,int b);
bool check_merge1(vector<int> &result,int a,int b);
bool check_merge2(vector<int> &result,int a,int b);
bool commonpairs(vector<int> result,int n);
int count(vector<int> &result,int a,int b);
int counted(vector<int> &result,int a,int b);
vector<int> judge_1;
vector<int> judge_2;
vector<int> inv_judge_1;
vector<int> inv_judge_2;
int INF;
int main()
{
	int n,temp;
	cin>>n;
	vector<int> result(n);
	judge_1.resize(n);
	judge_2.resize(n);
	inv_judge_1.resize(n);
	inv_judge_2.resize(n);
	INF=n+1;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		judge_1[i]=temp-1;
		result[i]=i;
		inv_judge_1[judge_1[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		judge_2[i]=temp-1;
		inv_judge_2[judge_2[i]]=i;
	}

	sort(result.begin(),result.end(),compare);
	//result is the sorted array
/*	for(int i=0;i<n;i++)
		cout<<result[i]+1<<"	";*/

	if(consistent(result,n))
	{
		cout<<"consistent"<<endl;
		for(int i=0;i<n;i++)
			cout<<result[i]+1<<" ";
	}
	else
	{
		cout<<"inconsistent"<<endl;
	}


}

bool compare(int a,int b)
{
	int k=0;
	if(a < b)
		k++;
	if(inv_judge_1[a] < inv_judge_1[b])
		k++;
	if(inv_judge_2[a] < inv_judge_2[b])
		k++;
	if (k>=2)
		return true;
	else
		return false;
}
bool consistent(vector<int> result,int n)
{
	vector<int> temp(n);
	temp=result;
	if(!check1(temp,0,n-1))
	{
		return false;
    }
    temp=result;
    if(!check2(temp,0,n-1))
    	return false;
/*	for(int i=0;i<3;i++)
    			cout<<result[i]+1<<"	";*/
    if(!commonpairs(result,n))
    	return false;

    return true;

}
bool check1(vector<int> &result,int a,int b)
{
    bool a1,b1;
    if(a==b)
        return true;

    a1=check1(result,a,(a+b)/2);
    if(a1)
    {
        b1=check1(result,(a+b)/2+1,b);
    }
    else
        return false;
    if(!b1)
        return false;


	if(!check_merge1(result,a,b))
	{
		return false;
    }
    else
    {
        return true;
    }

}
bool check_merge1(vector<int> &result,int a,int b)
{

	int i=a;
	int j=(a+b)/2+1;
	int k=0;
	int mini=INF;
	vector<int> temp(b-a+1);
	while(i!=(a+b)/2 +1 && j!=b+1)
	{
        if(result[i] < result[j])
        {
            temp[k]=result[i];
            if(result[i] > mini)
            {
                return false;
            }
            i++;
            k++;

        }
        else
        {
            temp[k]=result[j];
            mini=min(mini,inv_judge_1[result[j]]);
            j++;
            k++;
        }



	}
	if(i==(a+b)/2 + 1 && j!=b)
	{
		while(j!=b)
		{
			temp[k]=result[j];
			j++;
			k++;
		}
	}
	if(j==b+1 && a!=(a+b)/2)
	{
		while(a!=(a+b)/2)
		{
			temp[k]=result[i];
			if(result[i] > mini)
				return false;
			i++;
			k++;
		}

	}
	for(k=0;k<(b-a+1);k++)
		result[a+k]=temp[k];
	return true;

}

bool check2(vector<int> &result,int a,int b)
{
    bool a1,b1;
    if(a==b)
        return true;

    a1=check2(result,a,(a+b)/2);
    if(a1)
    {
        b1=check2(result,(a+b)/2+1,b);
    }
    else
        return false;
    if(!b1)
        return false;


	if(!check_merge2(result,a,b))
	{
		return false;
    }
    else
    {
        return true;
    }

}

bool check_merge2(vector<int> &result,int a,int b)
{

	int i=a;
	int j=(a+b)/2+1;
	int k=0;
	int mini=INF;
	vector<int> temp(b-a+1);
	while(i!=(a+b)/2 +1 && j!=b+1)
	{
        if(result[i] < result[j])
        {
            temp[k]=result[i];
            if(result[i] > mini)
            {
                return false;
            }
            i++;
            k++;

        }
        else
        {
            temp[k]=result[j];
            mini=min(mini,inv_judge_2[result[j]]);
            j++;
            k++;
        }



	}
	if(i==(a+b)/2 + 1 && j!=b)
	{
		while(j!=b)
		{
			temp[k]=result[j];
			j++;
			k++;
		}
	}
	if(j==b+1 && a!=(a+b)/2)
	{
		while(a!=(a+b)/2)
		{
			temp[k]=result[i];
			if(result[i] > mini)
				return false;
			i++;
			k++;
		}

	}
	for(k=0;k<(b-a+1);k++)
		result[a+k]=temp[k];
	return true;

}

bool commonpairs(vector<int> result,int n)
{
	int r,p,q,s;
	vector<int> temp(n);
	temp=result;
	r=count(temp,0,n-1);
	temp=judge_1;
	p=count(temp,0,n-1);
	temp=judge_2;
	q=count(temp,0,n-1);
	temp=inv_judge_1;
	s=count(temp,0,n-1);
	if(r==(p+q-s)/2)
		return true;
	else
		return false;
}


int count(vector<int> &result,int a,int b)
{
    int a1,b1,c1;
    if(a==b)
        return true;

    a1=count(result,a,(a+b)/2);
    b1=count(result,(a+b)/2+1,b);


	c1=counted(result,a,b);

    return a1+b1+c1;


}
int counted(vector<int> &result,int a,int b)
{
	int count,totalcount;
	int i=a;
	int j=(a+b)/2+1;
	int k=0;
	vector<int> temp(b-a+1);
	while(i!=(a+b)/2 +1 && j!=b+1)
	{
        if(result[i] < result[j])
        {
            temp[k]=result[i];
            totalcount=totalcount+count;
            i++;
            k++;

        }
        else
        {
            temp[k]=result[j];
            count++;
            j++;
            k++;
        }



	}
	if(i==(a+b)/2 + 1 && j!=b)
	{
		while(j!=b)
		{
			temp[k]=result[j];
			j++;
			k++;
		}
	}
	if(j==b+1 && a!=(a+b)/2)
	{
		while(a!=(a+b)/2)
		{
			temp[k]=result[i];
			totalcount=totalcount+count;
			i++;
			k++;
		}

	}
	for(k=0;k<(b-a+1);k++)
		result[a+k]=temp[k];
	return true;

}



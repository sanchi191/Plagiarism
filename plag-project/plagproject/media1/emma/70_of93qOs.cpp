#include <iostream>
#include <vector>
using namespace std;

std::vector<int> rank1;
std::vector<int> rank2;
//int numInv;

bool aLessThanb (int a,int b);
void mergesort (vector<int> *v, int start, int end);

int main ()
{
	int n;
	cin>>n;
	std::vector<int> p_n;
	p_n.resize(n);
	std::vector<int> q_n;
	q_n.resize(n);
	std::vector<int> r_n;
	r_n.resize(n);
	rank1.resize(n);
	rank2.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>p_n[i];
		r_n[i]=i+1;
		rank1[p_n[i]-1]=i;
	}
	for (int j = 0; j < n; ++j)
	{
		cin>>q_n[j];
		rank2[q_n[j]-1]=j;
	}

	int numInvR;
	int numInvP;
	int numInvQ;

	std::vector<int> toSort;
	//numInv=0;
	toSort=r_n;
    mergesort(&toSort,0,n-1);
    //numInvR=numInv;
    //cout<<"numInv "<<numInvR<<endl;
/*
    numInv=0;
    toSort=p_n;
    mergesort(&toSort,0,n-1);
    numInvP=numInv;
   //cout<<"numInv "<<numInvP<<endl;

    numInv=0;
    toSort=q_n;
    mergesort(&toSort,0,n-1);
    numInvQ=numInv;*/
    //cout<<"numInv "<<numInvQ<<endl;
    cout<<"Consistent"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<toSort[i]<<" ";
	}
	return 0;
}

bool aLessThanb (int a,int b)
{
	if (a<b)
	{
		if (rank1[a-1]<rank1[b-1] || rank2[a-1]<rank2[b-1])
			return true;
		else
			return false;
	}
	if (a>b)
	{
		if (rank1[a-1]<rank1[b-1] && rank2[a-1]<rank2[b-1])
			return true;
		else
			return false;
	}
}

void mergesort (vector<int> *v, int start, int end)
{
	if (start < end)
	{
		int mid;
		mid=(start+end)/2;
		mergesort(v, start, mid);
		mergesort(v, mid+1, end);

		//merge
		int i,j,k;
		j=mid+1;
		k=start;
		std::vector<int> temp(mid - start +1);

		for (i = 0; i < (mid- start +1); ++i)
		{
			temp[i]=(*v)[k];
			//cout<<"temp "<<temp[i]<<endl;
			k++;
		}
		k=start;
		i=0;
		while (i<=(mid-start) && j<=end)
		{
			if (aLessThanb(temp[i],(*v)[j]))
			{
				(*v)[k]=temp[i];
				//cout<<"here1 "<<k<<" "<<(*v)[k]<<endl;
				k++;
				i++;
			}
			else
			{
				(*v)[k]=(*v)[j];
				//cout<<"here2 "<<k<<" "<<(*v)[k]<<endl;
				k++;
				j++;
				//cout<<"da"<<mid-i+1<<endl;
				//numInv=numInv+(mid-(i+start)+1);
			}
		}

		while (i<=(mid-start))
		{
			(*v)[k]=temp[i];
			//cout<<"here3 "<<k<<" "<<(*v)[k]<<endl;
			k++;
			i++;
		}
		while (j<=end)
		{
			(*v)[k]=(*v)[j];
			//cout<<"here4 "<<k<<" "<<(*v)[k]<<endl;
			k++;
			j++;
		}
	}
	return;
}

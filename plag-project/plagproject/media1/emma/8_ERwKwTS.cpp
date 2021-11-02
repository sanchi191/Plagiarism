#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p,q,p1,q1,r,s;
int n;

bool compare(int a,int b)
{
	bool res1,res2,res3;
	res1 = a<b;
	res2 = p1[a]<p1[b];
	res3 = q1[a]<q1[b];
	return( (res1&&res2) || (res2&&res3) || (res1&&res3) );
}

void sort_checkinv(int lt,int rt,int& value1, int& value2, vector<int>& C)
{
	if(rt-lt==1)
	{
		C[0]=r[lt];
		return; 
	}

	int a=0,b=0,c=0,minp1 = n+1, minq1=n+1,asize,bsize;
	asize = (lt+rt)/2-lt;
	bsize = rt-(lt+rt)/2;

	vector<int> A(asize);
	vector<int> B(bsize);

	sort_checkinv(lt,(lt+rt)/2,value1,value2,A);
	if(value1!=-1)
	{
		return;
	}
	sort_checkinv((lt+rt)/2,rt,value1,value2,B);
	if(value1!=-1)
	{
		return;
	}
	
	while(a<asize && b<bsize)
	{
		if(A[a]<B[b])
		{
			if(! (p1[A[a]]<minp1 && q1[A[a]]<minq1) )
			{
				value1=A[a];
				if(! q1[A[a]]<minq1)
					value2=q[minq1];
				else
					value2=p[minp1];
				return;
			}
			C[c]=A[a];
			c++;
			a++;
		}
		else
		{
			
			if(q1[B[b]]<minq1)
			{
				minq1=q1[B[b]];
			}
			if(p1[B[b]]<minp1)
			{
				minp1=p1[B[b]];
			}
			C[c]=B[b];
			c++;
			b++;
		}
	}
	while(a<asize)
	{
		if(! (p1[a]<minp1 && q1[a]<minq1))
		{
			value1=A[a];
			if(! q1[A[a]]<minq1)
				value2=q[minq1];
			else
				value2=p[minp1];
			return;
		}
		C[c]=A[a];
		c++;
		a++;
	}
	while(b<bsize)
	{
		C[c]=B[b];
		c++;
		b++;
	}
	return;
}

void countinv(vector<int> v,int lt,int rt, vector<int>& C,int& inv)
{
	if(rt-lt==1)
	{
		C[0]=v[lt];
		return; 
	}

	int a=0,b=0,c=0,asize,bsize;
	asize = (lt+rt)/2-lt;
	bsize = rt-(lt+rt)/2;

	vector<int> A(asize);
	vector<int> B(bsize);

	countinv(v,lt,(lt+rt)/2,A,inv);
	countinv(v,(lt+rt)/2,rt,B,inv);
	while(a<asize&&b<bsize)
	{
		if(A[a]<B[b])
		{
			inv+=b;
			C[c]=A[a];
			a++;
			c++;
		}
		else
		{
			C[c]=B[b];
			c++;
			b++;
		}
	}
	while(a<asize)
	{
		inv+=b;
		C[c]=A[a];
		c++;
		a++;
	}
	while(b<bsize)
	{
		C[c]=B[b];
		c++;
		b++;
	}
	return;
}

int main()
{
	cin>>n;
	p.resize(n);
	q.resize(n);
	r.resize(n);
	s.resize(n);
	p1.resize(n+1);
	q1.resize(n+1);
	int value1=-1,value2=-1,value3,index1,index2,i,p_inv=0,q_inv=0,r_inv=0,s_inv=0;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		p1[p[i]]=i;
		r[i]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>q[i];
		q1[q[i]]=i;
	}
	sort(r.begin(),r.end(),compare);

	vector<int> temp(n);
	temp.resize(n);
	sort_checkinv(0,n,value1,value2,temp);
	if(value1!=-1)
	{
		cout<<"inconsistent"<<endl;
		while(r[i]!=value1)
		{
			i++;
		}
		for(i=0;i<n;i++)
		{
			if(compare(r[i+1],value2))
			{
				value1=r[i];
				value3=r[i+1];
				break;
			}
		}
		cout<<value1<<" "<<value3<<" "<<value2<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			s[i]=p1[q[i]];
		}
		countinv(p,0,n,temp,p_inv);
		countinv(q,0,n,temp,q_inv);
		countinv(s,0,n,temp,s_inv);
		countinv(r,0,n,temp,r_inv);
		if( (p_inv + q_inv - s_inv)/2==r_inv)
		{	
			cout<<"consistent"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<r[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<"inconsistent"<<endl;
			if(n>=4)
			{
				cout<<r[0]<<" "<<r[1]<<" "<<r[3]<<endl;
			}
		}
	}
	return 0;
}
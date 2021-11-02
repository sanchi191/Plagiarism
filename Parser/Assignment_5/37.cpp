#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

	
	vector<int> J1;
	vector<int> J2;
	vector<int> I1;
	vector<int> I2;

bool compare(int i,int j){
	
	if(i<j){

	if(I1[i-1]<I1[j-1]||I2[i-1]<I2[j-1]){return true;}
	else{return false;}
			}
	else {

		if(I1[i-1]<I1[j-1]&&I2[i-1]<I2[j-1]){return true;}
		else{return false;}

		}
}

	
int main(){

	int n;
	cin>>n;
	int x;
	
	for(int p=0;p<n;p++)
	{	
		cin>>x;
		J1.push_back(x);
	}


	for(int p=0;p<n;p++)
	{	
		cin>>x;
		J2.push_back(x);
	}

	for(int p=1;p<n+1;p++)
	{
		for(int k=0;k<n;k++)
		{
		if(J1[k]==p){I1.push_back(k+1);break;}
		}
	}

	for(int p=1;p<n+1;p++)
	{
		for(int k=0;k<n;k++)
		{
		if(J2[k]==p){I2.push_back(k+1);break;}
		}
	}


	
	vector<int> OV;
	
	
	
	for(int p=1;p<n+1;p++)
	{
		OV.push_back(p);
	}

	sort(OV.begin(),OV.end(),compare);


	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(compare(OV[i],OV[j])==1&&compare(OV[j],OV[k]))
				{
					if(compare(OV[k],OV[i])==1)
					{
						cout<<"inconsistent"<<endl;
						cout<<OV[i]<<" "<<OV[j]<<" "<<OV[k];
						goto end;
					}

					else
					{ 

					}
				}
			}
		}
	}


	
	cout<<"consistent"<<endl;


	

	for(int p=0;p<OV.size();p++)
	{
		cout<<OV[p]<<" ";
	}

end:




	return 0;
}
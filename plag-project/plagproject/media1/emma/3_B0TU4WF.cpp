#include <iostream>
#include <algorithm>
using namespace std;


int intersections(int arr1[], int arr2[], int m, int n)
{
  int i = 0, j = 0;
  while (i < m && j < n)
  {
    if (arr1[i] < arr2[j])
      i++;
    else if (arr2[j] < arr1[i])
      j++;
    else /* if arr1[i] == arr2[j] */
    {
      cout<<arr2[j++];
      i++;
    }
  }
  cout<<endl;
} 

int lessthan(int p[],int q[],int r[],int n,int i,int j){
	int ilte=0;
	for(int k=0;k<n;k++){
		if(p[k] == i){
			ilte++;break;
		}
		if(p[k] == j){
			break;
		}
	}
	for(int k=0;k<n;k++){
		if(q[k] == i){
			ilte++;break;
		}
		if(q[k] == j){
			break;
		}
	}
	for(int k=0;k<n;k++){
		if(r[k] == i){
			ilte++;break;
		}
		if(r[k] == j){
			break;
		}
	}
	
	return ilte;
}



int main(){
	
int n;
cin>>n;

int p[n];
for (int i=0;i<n;i++) {
	cin>>p[i];
	
	}

int q[n];
for (int i=0;i<n;i++) {
	cin>>q[i];
	}

int r[n];
for(int i=0;i<n;i++){
	r[i]=i+1;
}

int arr[n+1];
for(int i=0;i<=n;i++){
	arr[i]=n;
}

for(int i=1;i<=n;i++){
	//~ int tmp=0;
	//~ int tmp1=0;
	for(int j=1;j<=n;j++){
		if(i!=j){
			int tmp = lessthan(p,q,r,n,i,j);
			if(tmp>=2){
				arr[i]--;
			}
		}
	}
	
}
	int res[n+1];
	for(int i=0;i<n+1;i++)res[i]=0;
	for(int i=1;i<=n;i++){
		res[arr[i]]=i;
	}	
	for(int i=1;i<n+1;i++){
		if(res[i]==0){
			cout<<"inconsistent"<<endl;return 0;
		}
	}
	cout<<"consistent"<<endl;
	for(int i=1;i<n+1;i++)
	cout<<res[i]<<" ";
	cout<<endl;

}

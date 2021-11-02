# include <iostream>
# include <algorithm>

using namespace std;

bool check_inverse(int *A, int n, int x, int y){
		int x1=0;
		int y1=0;
		for (int i=0; i<n; i++){
			if(A[i]==x) x1=i;
			if(A[i]==y) y1=i;
			}
		
		if(x1 > y1) return true;
		else return false;
			
}
int main(){
	int x;
	int count = 0;
	int sum = 0;
	bool swi = true;
	bool pwi = false;
	cin >> x;
	
	int p[x];
	int q[x];
	int r[x];
	int s[x];
	for (int i=0; i<x; i++){
		cin >> p[i];
		}
		
	for (int i=0; i<x; i++){
		cin >> q[i];
		}

	
	for (int i=0; i<x; i++){
		r[i]=i+1;
		}
		
	while(next_permutation(r, r +x)){
		for (int i=0; i<x-1; i++){
			for (int j=i+1; j<x; j++){
				if (r[i]>r[j]){
					count++;
					if (check_inverse(p,x,r[j],r[i])==false){
							i=x-2;j=x-1;count=0;swi=false;
							}
						else if (check_inverse(q,x,r[j],r[i])==false)
						{
							i=x-2;j=x-1;count=0;swi=false;
							}
							
					}
				}
			}
			//cout<<count<<" ";
			//cout<<r[0]<<r[1]<<r[2]<<r[3]<<r[4]<<r[5]<<endl;
			 if (count>0 && swi==true){
				 
				for (int i=0; i<x-1; i++){
			for (int j=i+1; j<x; j++){
				if (p[i]>p[j]){
					if (check_inverse(q,x,p[j],p[i])==true){
						sum++;
						}
			 }
			 }
			 }
			 //cout<<r[0]<<r[1]<<r[2]<<r[3]<<r[4]<<r[5]<<endl;
			 //cout<<sum<<" "<<count<<endl;
			if (sum==count) {
				//cout<<"sum=count"<<endl;
				for (int i=0; i<x; i++){
			s[i]=r[i];
			}
			pwi=true;
			break;
				}	 
			
			//cout<<"not broken"<<endl;
			}//if count,swi
			//cout<<r[0]<<r[1]<<r[2]<<r[3]<<r[4]<<r[5]<<endl;
		count=0;swi=true;sum=0;
		}//while
		sum=0;
		if(pwi==false){
		for (int i=0; i<x-1; i++){
			for (int j=i+1; j<x; j++){
				if (p[i]>p[j]){
					if (check_inverse(q,x,p[j],p[i])==true){
						sum++;
						}
			 }
			 }
			 }
			if (sum==0){pwi=true; 
				for (int i=0; i<x; i++){
			s[i]=i+1;
			}
				}
	}
	if (pwi==true) {cout<<"consistent"<<endl;
		for (int i=0; i<x; i++){
			cout<<s[i];
			cout<<" ";
			
			}
		cout<<endl;	
		}
		
	else {cout<<"inconsistent"<<endl;}
}

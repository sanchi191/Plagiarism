#include<bits/stdc++.h>

using namespace std;

int *P, *Q;

class contestant{
	public:
	int idx;
	int inP;
	int inQ;
	contestant(){
		idx=0; inP=0; inQ=0;
	}
	void update_idx(int a){ idx=a; return; }
	void update_inP(int a){ inP=a; return; }
	void update_inQ(int a){	inQ=a; return; }
	// bool operator<(contestant& a){
	// 	if ( this->idx < a.idx ){
	// 		cout<< (this->inP) ;
	// 		return ( this->inP < a.inP || this->inQ < a.inQ );
	// 	}
	// 	else {
	// 		return ( this->inP < a.inP && this->inQ < a.inQ );
	// 	}
	// }
};

bool comp(contestant A, contestant B){
	if ( A.idx < B.idx ){
		return ( A.inP<B.inP || A.inQ<B.inQ );
	}
	else {
		return ( A.inP<B.inP && A.inQ<B.inQ );
	}
}

int main(){
	int n; cin>>n;
	P = new int[n]; for(int i=0; i<n; i++) { cin>>P[i]; --P[i]; } 
	Q = new int[n]; for(int i=0; i<n; i++) { cin>>Q[i]; --Q[i]; }
	vector<contestant> W(n);
	for(int i=0; i<n; i++){
		W[i].update_idx(i);
		W[P[i]].update_inP(i);
		W[Q[i]].update_inQ(i);
	}

	sort(W.begin(),W.end(),comp);
	
	// for (std::vector<contestan.begin(); it!=W.end(); ++it) {cout<<((*it).idx)<<" ";}
	int i,k;
	for (i=0; i<n; i++){
		for (k=i+1; k<n; k++){
			if ( !comp(W[i],W[k]) ) {break;}
		}
		if (k!=n) {break;}
	}

	if (i == n ) {//consistent
		printf("%s\n", "consistent");
		for (int i=0; i<n; i++){ printf("%d ", W[i].idx+1); };
	}
	if (i != n ){//inconsistent
		printf("%s\n", "inconsistent");
		int j;
		for (j=i+1; j<n; j++){
			if (j==k) {continue;}
			if ( comp(W[i],W[j]) && comp(W[j],W[k]) ) {break;}
		}
		if (j==n){
		j=i-1; 
			printf("%d %d %d", W[j].idx+1, W[i].idx+1, W[k].idx+1 );
		}
		else{
			printf("%d %d %d", W[i].idx+1, W[j].idx+1, W[k].idx+1 );
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p_inv;
vector<int> q_inv;
int countInv = 0;
bool check = true;
int _i=-1, _k=-1;

void merge(vector<int> &v, vector<int> &a, int begin, int middle, int end, bool t);
void merge_sort(vector<int> &v, vector<int> &a, int begin, int end, bool t);

void merge_sort(vector<int> &v, vector<int> &a, int begin, int end, bool t) {
	if (end - begin == 1) {
		return;
	}
	int middle = (begin+end)/2;
	merge_sort(v, a, begin, middle, t);
	merge_sort(v, a, middle, end, t);
	merge(v, a, begin, middle, end, t);
	for (int k=begin; k<end; k++) {
		v[k] = a[k];
	}
}

void merge(vector<int> &v, vector<int> &a, int begin, int middle, int end, bool t) {
	int b=begin, m=middle;
	int min = 100000000;
	int mina = -1;
	for (int k=b; k<end; k++) {
		if (b<middle && (m>=end || v[b]<=v[m])) {
			a[k] = v[b];
			if (t) {
			if(!(q_inv[v[b]-1]<min)){
				check = false;
				if(_i==-1) {
					_i = mina;
					_k = v[b];
			}
			}
			}
			else {
			if(!(p_inv[v[b]-1]<min)){
				check = false;
				if(_i==-1) {
					_i = mina;
					_k = v[b];
			}
			}
			}
			
			b++;
		}
		
		else {
			a[k] = v[m];
			countInv+=(middle -b);
			if (t) {
			if(q_inv[v[m]-1]<min){
				min = q_inv[v[m]-1];
				mina = v[m];
			}
			}
			else {
			if(p_inv[v[b]-1]<min){
				min = p_inv[v[m]-1];
				mina = v[m];
			}
			}
			m++;
		}
	}
	
}

bool less_than(int i, int j) {
	//return p_inv[i-1]<p_inv[j-1] && q_inv[i-1]<q_inv[j-1];
	bool a = p_inv[i-1]<p_inv[j-1];
	bool b = q_inv[i-1]<q_inv[j-1];
	bool c = i < j;
	return (a && b || b && c || c && a);
}

int main() {
	int n = 10;
	cin>>n;
	// vector<int> v(n, 1);
	// for(int i=0; i<n; i++) {
	// 	v[i] = i*10;
	// }
	// vector<int> a(n);
	// merge_sort(v, a, 0, n);
	// for(int i=0; i<n; i++) {
	// 	cout<<v[i]<<" ";
	// }
	// cout<<endl;
	vector<int> p(n);
	vector<int> q(n);
	int temp;
	for(int i=0; i<n; i++) {
		cin>>temp;
		p[i] = temp;
	}
	for(int i=0; i<n; i++) {
		cin>>temp;
		q[i] = temp;
	}
	p_inv.resize(n);
	q_inv.resize(n);
	for(int i=0; i<n; i++) {
		p_inv[p[i]-1] = i+1;
		q_inv[q[i]-1] = i+1;
	}
	// for(int i=0; i<n; i++) {
	// 	cout<<p_inv[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=0; i<n; i++) {
	// 	cout<<q_inv[i]<<" ";
	// }
	// cout<<endl;
	vector<int> r(n);
	for(int i=0; i<n; i++) {
		r[i] = i+1;
	}

	sort(r.begin(), r.end(), less_than);
	// for(int i=0; i<n; i++) {
	// 	cout<<r[i]<<" ";
	// }
	// cout<<endl;
	
	vector<int> r_inv(n);
	for(int i=0; i<n; i++) {
		r_inv[r[i]-1] = i+1;
	}
	vector<int> t1(n);
	vector<int> t2(n);
	// countInv=0; check = true;
	// merge_sort(s, t, 0, n, 1);
	// cout<<countInv<<endl;
	// for(int i=0; i<n; i++) {
	// 	cout<<p[i]<<" ";
	// }
	// cout<<endl;
	// cout<<check<<endl;
	vector<int> s(n);
	for(int i=0; i<n; i++) {
		s[i] = p_inv[q[i]-1];
	}
	bool rinp, rinq;
	int r_pairs, p_pairs, q_pairs, s_pairs;
	int p_i, p_k, q_i, q_k;

	t1 = r;
	t2 = r;
	countInv=0; check = true; _i=-1; _k=-1;
	merge_sort(t1, t2, 0, n, 0);
	rinp = check;
	p_i = _i;
	p_k = _k;

	t1 = r;
	t2 = r;
	countInv=0; check = true; _i=-1; _k=-1;
	merge_sort(t1, t2, 0, n, 1);
	rinq = check;
	q_i = _i;
	q_k = _k;

	t1 = r;
	t2 = r;
	countInv=0; check = true; _i=-1; _k=-1;
	merge_sort(t1, t2, 0, n, 1);
	r_pairs = countInv;

	t1 = p;
	t2 = p;
	countInv=0; check = true; _i=-1; _k=-1;
	merge_sort(t1, t2, 0, n, 1);
	p_pairs = countInv;

	t1 = q;
	t2 = q;
	countInv=0; check = true; _i=-1; _k=-1;
	merge_sort(t1, t2, 0, n, 1);
	q_pairs = countInv;

	t1 = s;
	t2 = s;
	countInv=0; check = true; _i=-1, _k=-1;
	merge_sort(t1, t2, 0, n, 1);
	s_pairs = countInv;



	int compairs = (p_pairs + q_pairs - s_pairs)/2;
	if(rinp && rinq && (r_pairs == compairs)) {
		cout<<"consistent"<<endl;
		for(int i=0; i<n; i++) {
		cout<<r[i]<<" ";
		}
		cout<<endl;
	}
	else {
		cout<<"inconsistent"<<endl;

	// 		if(p_i==-1 && q_i==-1) {
	// 	p = p_inv;
	// 	q = q_inv;
	// 	for(int i=0; i<n; i++) {
	// 	p_inv[p[i]-1] = i+1;
	// 	q_inv[q[i]-1] = i+1;
	// }
	// sort(r.begin(), r.end(), less_than);
	// t1 = r;
	// t2 = r;
	// countInv=0; check = true; _i=-1; _k=-1;
	// merge_sort(t1, t2, 0, n, 0);
	// rinp = check;
	// p_i = _i;
	// p_k = _k;

	// t1 = r;
	// t2 = r;
	// countInv=0; check = true; _i=-1; _k=-1;
	// merge_sort(t1, t2, 0, n, 1);
	// rinq = check;
	// q_i = _i;
	// q_k = _k;



	// }





		// int i_final=1, k_final=1;
		// if (p_i==-1 && q_i!=-1) {
		// 	i_final = q_i;
		// 	k_final = q_k;
		// }
		// else if (q_i==-1 && p_i!=-1){
		// 	i_final = p_i;
		// 	k_final = p_k;
		// }

		// 					int c = 1;
		// 				for(int b = r_inv[i_final-1]; b<r_inv[k_final-1]-1; b++ ) {
		// 					if (less_than(r[b], k_final)) {
		// 						c = r[b];
		// 						break;
		// 					}
		// 				}
		// 				cout<<i_final<<" "<<c<<" "<<k_final<<endl;
		if(n<1000){
			bool flag = false;
		
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if (j!=i) {
				if(less_than(i+1, j+1)) {
					if(r_inv[i]<r_inv[j]) {

					}
					else {
						//cout<<i+1<<j+1;
						flag = true;
						//cout<<"inconsistent"<<endl;
						int c;
						for(int b = r_inv[j]; b<r_inv[i]-1; b++ ) {
							if (less_than(r[b], i+1)) {
								c = r[b];
								break;
							}
						}
						cout<<j+1<<" "<<c<<" "<<i+1<<endl;
						break;
					}
				}
			}
		}
		if (flag) {
			break;
		}
	}
}
	}


	return 0;
}
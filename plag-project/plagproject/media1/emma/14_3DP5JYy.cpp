#include <bits/stdc++.h>
using namespace std;

vector<int> create_invsn_pair_vec(vector<int> P){
	vector<int> inversion_pair;
	int n = P.size();
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(i < j && P[i] > P[j]){
				inversion_pair.push_back(P[i]);
				inversion_pair.push_back(P[j]);
			}
		}
	}
	return inversion_pair;
}

vector<int> merge(vector<int> vec1, vector<int> vec2){
	int a = vec1.size();
	int b = vec2.size();
	vector<int> merger(a+b);
	int i=1;
	while(i<=a+b){
		if(vec1[i] < vec2[i]) merger[i] = vec1[i]; 
		else merger[i] = vec2[i];
		i++;
	}
	return merger;
}

bool check(int a, int b, vector<int> J){
	int tmp1, tmp2;
	int n = J.size();
	for(int i=1; i<=n; i++){
		if(J[i] == a) tmp1 = i;
		if(J[i] == b) tmp2 = i;
	}
	if(tmp1 < tmp2) return true;
	else return false;
}

int main(){
	int n;
	cin >> n;
	vector<int> judge_1(n+1);
	vector<int> judge_2(n+1);
	vector<int> judge_3(n+1);
	vector<int> output(n);
	
	for(int i=1; i<=n; i++){
		cin >> judge_1[i];
	}
	for(int i=1; i<=n; i++){
		cin >> judge_2[i];
	}
	for(int i=1; i<=n; i++){
		judge_3[i] = i;
	}
	
	for(int i=1; i<n; i++){
		for(int j=1; j<=n; j++){
			bool flag = false;
			if(i == judge_1[j]){
				for(int k=j+1; k<=n; k++){
					if(judge_1[k] == i+1){
						output[i-1] = i;
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
			if(i == judge_2[j]){
				for(int k=j+1; k<=n; k++){
					if(judge_2[k] == i+1){
						output[i-1] = i;
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
		}
	}
	
	if(output[n-2] == n-1) output[n-1] = n;
	
	int count = 0;
	for(int i=0; i<n; i++){
		if(output[i] == i+1) count++;
	}
	
	if(count == n){
		cout << "consistent" << endl;
		for(int i=0; i<output.size(); i++){
			cout << output[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "inconsistent" << endl;
	}
	
	//New code(method) starts here
	/*vector<int> Judge_1(n+1), Judge_2(n+1), Judge_3(n+1);
	for(int i=1; i<=n; i++){
		Judge_1[judge_1[i]] = i;
		Judge_2[judge_2[i]] = i;
		Judge_3[judge_3[i]] = i;
	}
	
	vector<int> inv_1 = create_invsn_pair_vec(Judge_1);
	vector<int> inv_2 = create_invsn_pair_vec(Judge_2);
	
	sort(inv_1.begin(), inv_1.end());
	sort(inv_2.begin(), inv_2.end());
	for(int i=1; i<=n; i++) cout << inv_1[i] << " ";
	cout << endl;
	for(int i=1; i<=n; i++) cout << inv_2[i] << " ";
	cout << endl;
	
	vector<int> R(n+1);
	R = merge(inv_1, inv_2);
	int num = R.size();
	for(int i=0; i<=n; i++) cout << R[i] << " ";
	cout << endl;
	*/
}

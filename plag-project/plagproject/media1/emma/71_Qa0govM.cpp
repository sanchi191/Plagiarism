#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

# define INF std::numeric_limits<int>::max()

class contestant{
public:
	int index;//0 redundant to N(inclusive) 
	int rank1;//1 - N
	int rank2;//1 - N 
	int rank;
	contestant(){};
	contestant(int a, int b, int c):index(a),rank1(b),rank2(c){};
	bool operator >(const contestant& rhs) const{
		if(index>rhs.index){
			if(rank1>rhs.rank1 || rank2>rhs.rank2){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if(rank1>rhs.rank1 && rank2>rhs.rank2){
				return true;
			}
			else{
				return false;
			}
		}
	}
	bool operator <(const contestant& rhs) const{
		return !(*this>rhs);
	}
	bool operator==(const contestant& rhs) const{
		return false;
	}
};

int minimum(int a , int b){
	if(a<b) return a;
	else return b;
}

// void find_gaddar(vector<contestant> array, contestant bad_guy , vector<int> inv_rank1){
// 	int len = length(array);
// 	int bad_guy_index = bad_guy.index;
// }

bool mergesort(vector<contestant>&participant , int start, int end, vector<int>&inv_rank1){
	if(end == start+1){
		return true;
	}
	if(mergesort(participant,start,(start+end)/2, inv_rank1) && mergesort(participant,(start+end)/2, end, inv_rank1)){
		
		vector<contestant> temp(end - start);
		int i=0; int min = INF;
		int ptr1 = start; int ptr2 = (start+end)/2; 
		while(ptr1<(start+end)/2 || ptr2<end){
			
			if(ptr1==(start+end)/2){
				temp[i] = participant[ptr2];
				i++;ptr2++;
				min = minimum(min , inv_rank1[participant[ptr2].index]);
			}
			else if(ptr2 == end){
				temp[i] = participant[ptr1];
				i++;ptr1++;
				if(inv_rank1[participant[ptr1].index] < min){
					
				}else{
					// find_gaddar(temp,participant[ptr2].index,inv_rank1);

					return false;
				}
			}
			else{
				if( participant[ptr1].index < participant[ptr2].index){
					temp[i] = participant[ptr1];
					i++;ptr1++;
					if(inv_rank1[participant[ptr1].index] < min){
						////
					}else{
						// find_gaddar(temp,participant[ptr2].index,inv_rank1);
						// for(){
							
						// }

						return false;
					}
				}
				else{
					temp[i] = participant[ptr2];
					i++;ptr2++;
					min = minimum(min , inv_rank1[participant[ptr2].index]);
				}
			}
		}

		return true;

	}
	else{
		return false;
	}
}

int count_inversions(vector<contestant>&participant , int start, int end){
	if(end == start+1){
		return 0;
	}
	int num1 = count_inversions(participant,start,(start+end)/2);
	int num2 = count_inversions(participant,(start+end)/2,end);
	vector<int> temp(end - start);
	int i=0; int num=0;
	int ptr1 = start; int ptr2 = (start+end)/2; 
	while(ptr1<(start+end)/2 && ptr2<end){
		if(ptr1==(start+end)/2){
			temp[i] = participant[ptr2].index;
			i++;ptr2++;
			num+=(start+end)/2 - ptr1;
		}
		else if(ptr2 == end){
			temp[i] = participant[ptr1].index;
			i++;ptr1++;
		}
		else{
			if( participant[ptr1].index < participant[ptr2].index){
				temp[i] = participant[ptr1].index;
				i++;ptr1++;
			}
			else{
				temp[i] = participant[ptr2].index;
				i++;ptr2++;
				num+=(start+end)/2 - ptr1;
			}
		}

	}

	return num1+num2+num;
}

int count_inversions(vector<int> permutation , int start, int end){
	if(end == start+1){
		return 0;
	}
	int num1 = count_inversions(permutation,start,(start+end)/2);
	int num2 = count_inversions(permutation,(start+end)/2,end);
	vector<int> temp(end - start);
	int i=0; int num=0;
	int ptr1 = start; int ptr2 = (start+end)/2; 
	while(ptr1<(start+end)/2 && ptr2<end){
		if(ptr1==(start+end)/2){
			temp[i] = permutation[ptr2];
			i++;ptr2++;
			num+=(start+end)/2 - ptr1;
		}
		else if(ptr2 == end){
			temp[i] = permutation[ptr1];
			i++;ptr1++;
		}
		else{
			if( permutation[ptr1] < permutation[ptr2]){
				temp[i] = permutation[ptr1];
				i++;ptr1++;
			}
			else{
				temp[i] = permutation[ptr2];
				i++;ptr2++;
				num+=(start+end)/2 - ptr1;
			}
		}

	}

	return num1+num2+num;
}
int count_inversions_a(vector<contestant>&participant , int start, int end){
	return count_inversions(participant,start,end);
}
//participant is a sorted vector;
bool check_inv_pair_subset(vector<contestant> participant , int N, vector<int> inv_rank1){
	return mergesort(participant,1,N,inv_rank1);
}

int main(){
	int N;
	cin >>N;
	std::vector<contestant> participant(N+1);
	std::vector<int> inv_rank1(N+1);
	std::vector<int> inv_rank2(N+1);
	std::vector<int> S(N+1);
	std::vector<int> list_rank1(N+1);
	std::vector<int> list_rank2(N+1);
	
	for (int i = 1; i <= N; ++i)
	{
		int index1;
		cin>>index1;
		index1;

		//Setting participant.index,rank1,
		//inv_rank1 maps rank (parti.rank to its index)
		participant[index1].index = index1;
		participant[index1].rank1 = i;
		inv_rank1[index1] = i;
		list_rank1[i] = index1;
	}
	for (int i = 1; i <= N; ++i)
	{
		int index2;
		cin>>index2;
		index2;

		//Setting rank2,inv_rank2
		participant[index2].rank2 = i;
		inv_rank2[index2] = i;
		list_rank2[i] = index2;
		//Setting S
		S[i] = inv_rank1[index2];
	}

	sort(++participant.begin(), participant.end());
	// for (int i = 1; i <= N; ++i)
	// {
	// 	cout<<participant[i].index<<" ";
	// }

	for (int i = 1; i <= N; ++i)
	{
		participant[i].rank = i;
	}

	bool is_consistent = true;
	if(check_inv_pair_subset(participant ,N+1, inv_rank1) && check_inv_pair_subset(participant ,N+1, inv_rank2)){
		// cout<<"Continuing with true"<<endl;
		int p = count_inversions(list_rank1,1,N+1);
		// cout<<p<<endl;
		int q = count_inversions(list_rank2,1,N+1);
		// cout<<q<<endl;
		int s = count_inversions(S,1,N+1);
		// cout<<s<<endl;
		int commom_count = (p + q - s)/2;
		// cout<<commom_count<<endl;
		int count_r = count_inversions_a(participant,1,N+1);
		// cout<<count_r<<endl;
		if(count_r == commom_count){
			// cout<<"Booyah!!"<<endl;
			cout<<"consistent"<<endl;
				for (int i = 1; i <= N; ++i)
			{
				cout<<participant[i].index<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<"inconsistent"<<endl;
			is_consistent = false;
		}
	}
	else{
		is_consistent = false;
		cout<<"inconsistent"<<endl;
	}

	if(!is_consistent){
		bool x=true;
		int l,m,n; //n<l; l<m; m<n; 
		for (int i = 1; i < N - 1; ++i)
		{
			for (int j = i+2 ; j <= N; ++j)
			{
				if(participant[i]>participant[j]){
					x=false;
					l=participant[i].index;
					m=participant[j-1].index;
					n=participant[j].index;
				}
			}
			if(x==false){
				break;
			}
		}
		cout<< n <<" "<< l <<" "<< m<<endl;
	}

	return 0;
}

	// bool x=true;
	// int l,m,n; //n<l; l<m; m<n; 
	// for (int i = 1; i < N - 1; ++i)
	// {
	// 	for (int j = i+2 ; j <= N; ++j)
	// 	{
	// 		if(participant[i]>participant[j]){
	// 			x=false;
	// 			l=i;
	// 			m=j-1;
	// 			n=j;
	// 		}
	// 	}
	// 	if(x==false){
	// 		break;
	// 	}
	// }
	// if(x==true){
	// 	cout<<"consistent"<<endl;
	// 	for (int i = 1; i <= N; ++i)
	// 	{
	// 		cout<<participant[i].index<<" ";
	// 	}
	// 	cout<<endl;
	// }else{
	// 	cout<<"inconsistent"<<endl;
	// 	cout<< n <<" "<< l <<" "<< m<<endl;
	// }

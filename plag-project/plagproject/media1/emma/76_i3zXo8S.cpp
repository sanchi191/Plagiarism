#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v)
{
	for(int i = 0; i < v.size(); i++) 
      cout << v[i] << " ";
	cout << endl;
}

int n;
std::vector<int> p, q, i_p, i_q;

bool comp(const int& i, const int& j)
{
	if(i < j) {
		if(i_p[i - 1] < i_p[j - 1] || i_q[i - 1] < i_q[j - 1])
			return true;
	}
	else {
		if(i_p[i - 1] < i_p[j - 1] && i_q[i - 1] < i_q[j - 1])
			return true;
	}
    return false;
}

void merge_every(vector<int> &left, vector<int> &right, vector<int> &i_right, 
 vector<int> &result, bool &res)
{
   int min_index = 10000000;

   // cout << "min index " << min_index << endl;


   // cout <<"left size " << left.size() <<endl;
   // cout << "LEFT" <<endl;
   // print(left);
   // cout <<"right size " << right.size() <<endl;
   // cout << "right" <<endl;
   // print(right);
   while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
         if (left.front() <= right.front()) {
         	// cout << "left front " << left.front() <<"    " << "right front " <<right.front() <<endl;
          //   result.push_back(left.front());
          //   cout << "taking from left " << "take index " <<  i_right[left.front() - 1] <<
          //   	"min index" << min_index <<endl;
            if(i_right[left.front() - 1] >= min_index) {
            	res = false;
            }
            left.erase(left.begin());
         } else {
         	// cout << "left front " << left.front() <<"    " << "right front " <<right.front() <<endl;
         	// cout << "taking from right " << "take index " <<  i_right[right.front() - 1] <<
          //   	"min index " << min_index <<endl;
       	    if(i_right[right.front() - 1] <= min_index)
            	min_index = i_right[right.front() - 1];
            result.push_back(right.front());
            right.erase(right.begin());
         }
      }  else if (left.size() > 0) {
            while (!left.empty()) {
       	       if(i_right[left.front() - 1] >= min_index) {
            		res = false;
       	       }
               result.push_back(left.front());
               left.erase(left.begin());
            }
            break;
      }  else if (right.size() > 0) {
            while (!right.empty()) {
       	       if(i_right[right.front() - 1] <= min_index)
            		min_index = i_right[right.front() - 1];
               result.push_back(right.front());
               right.erase(right.begin());
            }
      }
   }
}

void every_ipair_exists(std::vector<int> &p, std::vector<int> &q, 
	std::vector<int> &i_right, std::vector<int> &res, bool &result) {
	if(p.size() <= 1) {
		res = p;
		return;
	}

	vector<int> left, right, res_left, res_right;
	int middle = (p.size()+ 1) / 2;

	for (int i = 0; i < middle; i++) {
	  left.push_back(p[i]);
	}

	for (int i = middle; i < p.size(); i++) {
	  right.push_back(p[i]);
	}

	every_ipair_exists(left, q, i_right, res_left, result);
	every_ipair_exists(right, q, i_right, res_right, result);
	merge_every(res_left, res_right, i_right, res, result);
}

void merge_no_of_pairs(vector<int> &left, vector<int> &right, vector<int> &result, int &count)
{
   int temp = 0;
   while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
         if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.erase(left.begin());
            count += temp;
         } else {
            result.push_back(right.front());
            right.erase(right.begin());
            temp++;
         }
      }  else if (left.size() > 0) {
            for (int i = 0; i < left.size(); i++) {
               	result.push_back(left[i]);
            	count += temp;
           	}
            break;
      }  else if (right.size() > 0) {
            for (int i = 0; i < right.size(); i++) {
               result.push_back(right[i]);
           		//temp++;
            }
            break;
      }
   }
}

void no_of_pairs(std::vector<int> &m, std::vector<int> &res, int &count) {
	if(m.size() <= 1) {
		res = m;
		return;
	}
	vector<int> left, right, res_left, res_right;
	int middle = (m.size()+ 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(m[i]);
	}

	for (int i = middle; i < m.size(); i++) {
		right.push_back(m[i]);
	}

	no_of_pairs(left, res_left, count);
	no_of_pairs(right, res_right, count);
	merge_no_of_pairs(res_left, res_right, res, count);
}

int main() {
    cin >> n;
    p.resize(n);
    q.resize(n);
    i_p.resize(n);
    i_q.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for(int i = 0; i < n; i++) {
        i_p[p[i] - 1] = i;
    }
    for(int i = 0; i < n; i++) {
        i_q[q[i] - 1] = i;
    }

	std::vector<int> r(n);
	for(int i = 0; i < n; i++) {
		r[i] = i + 1;
	}
	std::sort(r.begin(), r.end(), comp);



	// print(r);
// std::vector<int> s(n);
// 		for(int i = 0; i < n; i++) {
// 			s[i] = i_p[q[i] - 1];
// 		}
// 		int s_count = 0, r_count = 0, p_count = 0, q_count = 0;
// 		std::vector<int> sortp, sortr, sorts, sortq; 
// 		no_of_pairs(s, sorts, s_count);
// 		no_of_pairs(r, sortr, r_count);
// 		no_of_pairs(p, sortp, p_count);
// 		no_of_pairs(q, sortq, q_count);

// 		cout << p_count << endl << q_count << endl << r_count << endl << s_count << endl;

// 		print(s);

	std::vector<int> sortp, sortq;

	bool inconsistent = false;
	bool r_p = true;
	bool r_q = true;
	every_ipair_exists(r, p, i_p, sortp,  r_p);
	every_ipair_exists(r, q, i_q, sortq, r_q);

	if (r_q && r_p) {
		std::vector<int> s(n);
		for(int i = 0; i < n; i++) {
			s[i] = i_p[q[i] - 1];
		}
		int s_count = 0, r_count = 0, p_count = 0, q_count = 0;
		std::vector<int> sortp, sortr, sorts, sortq; 
		no_of_pairs(s, sorts, s_count);
		no_of_pairs(r, sortr, r_count);
		no_of_pairs(p, sortp, p_count);
		no_of_pairs(q, sortq, q_count);
		if((p_count + q_count - s_count)/2 == r_count) {
			cout << "consistent" << endl;
			for(int i = 0; i < n - 1; i++) {
				cout << r[i] << " ";
			}
			cout << r[n - 1] << endl;
		}
		else
			inconsistent = true;
	}
	else
		inconsistent = true;

	if(inconsistent) {

		cout << "inconsistent" << endl;
		std::vector<int> i_r(n);
		for(int i = 0; i < n; i++) {
	        i_r[r[i] - 1] = i;
	    }
	    for(int i = 1; i <n+1; i++){
	    	for (int j=1; j < n+1; j++) {
	    		if(i == j)
	    			continue;
	    		else if(comp(i, j)){
	    			if(i_r[i-1] > i_r[j-1]){
	    				for(int k = i_r[j-1]; k < i_r[i-1]; k++) {
	    					if(comp(r[k], i)) {
							cout << j << " " << r[k] << " " << i <<endl;
	    					}
	    				}

	    			}

	    			
	    		}
	    	}
	    }
	}

	return 0;
}

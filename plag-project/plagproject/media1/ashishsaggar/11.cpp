#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> perm;
int n, inf;
int inv_count;
bool cons;
perm *qinv;
perm inv1, inv2;

vector<int> merge (vector<int> const &v1, vector<int> const &v2) {
	vector<int> ret;
	vector<int>::const_iterator i1 = v1.begin(), i2 = v2.begin();
	int num_r = 0, min_r = inf;
	while (!(*i1==inf && *i2==inf)) {
		if (*i1 < *i2) {
			ret.push_back(*(i1++));
			inv_count += num_r;
			cons = cons && (qinv->at(ret.back()) < min_r);
		}
		else {
			ret.push_back(*(i2++));
			++num_r;
			min_r = min(min_r, qinv->at(ret.back()));
		}
	}
	ret.push_back(inf);
	return ret;
}

vector<int> mergeSort (vector<int> const &v, int start, int finish) {
	if (finish == start + 1) {
		vector<int> ret(2, inf);
		ret[0] = v[start];
		return ret;
	}
	else
		return merge(mergeSort(v,start,(start+finish)/2), mergeSort(v,(start+finish)/2, finish));
}

int countInversion (perm &p) {
	inv_count = 0;
	qinv = &p;
	mergeSort(p,0,n);
	return inv_count;
}

bool subInversion (perm &p, perm &q) { //tests if all inversions in p are also in q
	perm q_inv(n);
	qinv = &q_inv;

	for (int i=0; i<n; ++i)
		q_inv[q[i]] = i;

	cons = true;
	mergeSort(p,0,n);
	return cons;
}

bool compare (int const &a, int const &b) {
	return ((int)(a<b) + (int)(inv1[a]<inv1[b]) + (int)(inv2[a]<inv2[b])) >= 2;
}

int main () {
	cin >> n;
	inf = n;
	perm p1(n), p2(n), r(n), s(n);
	for (int i=0; i<n; ++i)
		cin >> p1[i], --p1[i];

	for (int i=0; i<n; ++i)
		cin >> p2[i], --p2[i];

	inv1.resize(n);
	inv2.resize(n);
	for (int i=0; i<n; ++i)
		r[i] = inv1[p1[i]] = inv2[p2[i]] = i;

	for (int i=0; i<n; ++i)
		s[i] = inv1[p2[i]];
	
	sort(r.begin(), r.end(), compare);
	bool cons = (countInversion(r) == (countInversion(p1) + countInversion(p2) - countInversion(s))/2);
	cons = cons && subInversion(r, p1) && subInversion(r,p2);

	if (cons) {
		cout << "consistent\n";
		for (int i=0; i<n; ++i)
			cout << r[i]+1 << ' ';
		cout << endl;
	}
	else {
		cout << "inconsistent\n";
	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int min(int a, int b){ return (a<b)?a:b; }
int mergeSort(int a[], int s, int e);
int merge(int a[], int s, int e);
bool cmp(int ri, int rj);
bool mergeSortCheck(int a[], int s, int e);
bool mergeCheck(int a[], int s, int e);

class Judge{
public:
	int n;
	int *p, *q, *s, *r, *pInv, *qInv;;
	int rInvCount, pInvCount, qInvCount, sInvCount; //they have values means their corresponding arrays are useless
	int WRONGI, WRONGJ, WRONGK;
	bool isConsistent;
	Judge();
	void takeInput();
	void constructInv();
	void constructS();
	void getR();
	bool verifyR1();
	bool verifyR2();
	bool verifyR();
	void printR();
	void constructInvCount();
	void findK();
	void godKnows();
};

void Judge::takeInput(){
	scanf("%d", &n);
	p = new int[n+1];
	q = new int[n+1];
	for(int i=1; i<=n; i++) scanf("%d", &p[i]);
	for(int i=1; i<=n; i++) scanf("%d", &q[i]);
}

void Judge::godKnows(){
	int *pcopy = new int[n+1];
	for(int i=1; i<=n; i++)
		pcopy[i] = p[i];

	for(int i=1; i<=n; i++){
		r[i] = pInv[r[i]];
		q[i] = pInv[q[i]];
		p[i] = pInv[i];
	}
	constructInv();
	verifyR1();
	findK();
	WRONGI = pcopy[WRONGI];
	WRONGJ = pcopy[WRONGJ];
	WRONGK = pcopy[WRONGK];
}

void Judge::findK(){
	int I, J;
	for(int i=1; i<=n; i++){
		if(WRONGI == r[i]){ I=i; break;}
	}
	for(int j=1; j<=n; j++){
		if(WRONGJ == r[j]){ J=j; break;}
	}
	for(; J<=I-2;){
		if(cmp(r[J+1], r[I])){
			WRONGJ = r[J];
			WRONGK = r[J+1];
			break;
		}
		else{
			J++;
		}
	}
}

void Judge::constructInv(){
	pInv = new int[n+1];
	qInv = new int[n+1];
	for (int i = 1; i<=n; i++)	{
		pInv[p[i]] = i;
		qInv[q[i]] = i;
	}
}

void Judge::constructS(){
	s = new int[n+1];
	for(int i=1; i<=n; i++){
		s[i] = pInv[q[i]];
	}
}

void Judge::getR(){
	r = new int[n+1];
	for(int i=0; i<=n; i++) r[i] = i;
	sort(r+1, r+n+1, cmp);
}

Judge::Judge(){
	takeInput();
	constructInv();
	getR();
	isConsistent = verifyR();
	if(isConsistent){
		printf("consistent\n");
		printR();
	}
	else{
		printf("inconsistent\n");
		printf("%d %d %d\n", WRONGI, WRONGJ, WRONGK);
	}
}

void Judge::printR(){
	for(int i=1; i<=n; i++)
		printf("%d ", r[i]);
	printf("\n");
}

bool Judge::verifyR1(){
	int *rcopy = new int[n+1];
	for(int i=1; i<=n; i++)
		rcopy[i] = r[i];
	bool ans = mergeSortCheck(rcopy, 1, n+1);
	delete[] rcopy;
	return ans;
}

bool Judge::verifyR2(){
	constructS();
	constructInvCount();
	if(rInvCount == (pInvCount + qInvCount - sInvCount)/2)
		return true;
	else
		return false;
}

bool Judge::verifyR(){
	bool pass1 = verifyR1();
	// if pass1==true => rInvCount stores the correct inversion count
	// if pass1==false =>rInvCount stores the wrong inversion count
	if(!pass1){
		findK();
		return false;
	}
	bool pass2 = verifyR2();
	if(!pass2){
		godKnows();
		return false;
	}
	return true;
}

void Judge::constructInvCount(){
	// if program reaches this => rInvCOunt is already initialised!
	int *copy = new int[n+1];
	for(int i=1; i<=n; i++)
		copy[i] = p[i];
	pInvCount = mergeSort(copy, 1, n+1);
	for(int i=1; i<=n; i++)
		copy[i] = q[i];
	qInvCount = mergeSort(copy, 1, n+1);
	for(int i=1; i<=n; i++)
		copy[i] = s[i];
	sInvCount = mergeSort(copy, 1, n+1);
	delete[] copy;
}

Judge govind;

int main(){
	return 0;
}

int mergeSort(int a[], int s, int e){
	if(s+1==e) return 0;
	int m = (s+e)/2;
	int x = mergeSort(a, s, m);
	int y = mergeSort(a, m, e);
	int z = merge(a, s, e);
	return x+y+z;
} 

int merge(int a[], int s, int e){
	int m = (s+e)/2;
	int *t = new int[e-s];
	int z = 0;

	int i=s, j=m, k=0;
	while(i<m && j<e){
		if(a[i]<=a[j]){
			t[k++] = a[i++];
		}
		else{
			t[k++]=a[j++];
			z+=(m-i);
		}
	}
	while(i<m) t[k++] = a[i++];
	while(j<e) t[k++] = a[j++];
	for(k=0, i=s; i<e; i++, k++) a[i]=t[k];
	delete[] t;
	return z;
}

bool cmp(int ri, int rj){
	if( (ri<rj) + (govind.pInv[ri]<govind.pInv[rj]) + (govind.qInv[ri]<govind.qInv[rj]) >= 2)
		return true;
	else
		return false;
}

bool mergeSortCheck(int a[], int s, int e){
	if(s+1==e) {return true;}
	int m = (s+e)/2;
	bool x = mergeSortCheck(a, s, m);
	if(!x) return x;
	bool y = mergeSortCheck(a, m, e);
	if(!y) return y;
	bool z = mergeCheck(a, s, e);
	return (x && y && z);
}

bool mergeCheck(int a[], int s, int e){
	int m = (s+e)/2;
	int i, j, k;

	int pMin = govind.n + 1;
	int qMin = govind.n + 1;

	int *t = new int[e-s];
	int z = 0;

	i=s, j=m, k=0;
	while(i<m && j<e){
		if(a[i]<a[j]){
			if(govind.pInv[a[i]] > pMin) { govind.WRONGI = govind.p[pMin]; govind.WRONGJ = a[i]; return false;}
			if(govind.qInv[a[i]] > qMin) { govind.WRONGI = govind.q[qMin]; govind.WRONGJ = a[i]; return false;}
			t[k++] = a[i++];
		}
		else{
			pMin = min(pMin, govind.pInv[a[j]]);
			qMin = min(qMin, govind.qInv[a[j]]);
			t[k++]=a[j++];
			govind.rInvCount += (m-i);
		}
	}

	while(i<m){

		if(govind.pInv[a[i]] > pMin) { govind.WRONGI = govind.p[pMin]; govind.WRONGJ = a[i]; return false;}
		if(govind.qInv[a[i]] > qMin) { govind.WRONGI = govind.q[qMin]; govind.WRONGJ = a[i]; return false;}
		t[k++] = a[i++];
	}

	while(j<e) t[k++] = a[j++]; // no need to update pMin and qMin
	for(k=0, i=s; i<e; i++, k++) a[i]=t[k];
	delete[] t;
	return true;
}
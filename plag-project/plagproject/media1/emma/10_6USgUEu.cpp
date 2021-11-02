#include <iostream>

using namespace std;
int n,r,w,e;
int p_judge[100];
int q_judge[100];
int p[100];//inverse of p//
int q[100];//inverse of q//

void merge(int*, int*, int, int, int);
bool mergecheck(int*, int, int, int);

void mergesort(int *a, int*b, int start, int end) {
  int halfpoint;
  if (start < end) {
    halfpoint = (start + end) / 2;
    mergesort(a, b, start, halfpoint);
    mergesort(a, b, halfpoint + 1, end);
    merge(a, b, start, halfpoint, end);
  }
}

void merge(int *a, int *b, int start, int halfpoint, int end) {
  int h, i, j, k;
  h = start;
  i = start;
  j = halfpoint + 1;

  while ((h <= halfpoint) && (j <= end)) {
    if ((a[h] <= a[j])&&((p[a[h]]<p[a[j]])||(q[a[h]]<q[a[j]]))) {
      b[i] = a[h];
      h++;
    } else {
      b[i] = a[j];
      j++;
    }
    i++;
  }
  if (h > halfpoint) {
    for (k = j; k <= end; k++) {
      b[i] = a[k];
      i++;
    }
  } else {
    for (k = h; k <= halfpoint; k++) {
      b[i] = a[k];
      i++;
    }
  }

  // Write the final sorted array to our original one
  for (k = start; k <= end; k++) {
    a[k] = b[k];
  }
}
bool mergesortcheck(int *a, int start, int end) {
  int halfpoint;
  if (start < end) {
    halfpoint = (start + end) / 2;
    mergesortcheck(a,  start, halfpoint);
    mergesortcheck(a,  halfpoint + 1, end);
    mergecheck(a,  start, halfpoint, end);
  }
}

bool mergecheck(int *a,  int start, int halfpoint, int end) {
  int h, i, j, k;
  h = start;
  i = start;
  j = halfpoint + 1;

  while ((h <= halfpoint) && (j <= end)) {
    if ((a[h] <= a[j])&&((p[a[h]]<p[a[j]])||(q[a[h]]<q[a[j]]))) {
return true;


    } else {
     return false;
     break;

    }
    i++;
  }
  }



int main(){
cout<<"give n"<<endl;
cin>>n;

int a[n];
 int b[n];

   for(int i=0;i<n;i++){
       a[i]=i+1;}

    cout<<"give the rankings by two judges"<<endl;
    for(int i=0;i<n;i++)
    {  cin>>p_judge[i];}

      for(int i=0;i<n;i++)
    {  cin>>q_judge[i];}

     for(int i=0;i<n;i++){
         int x=p_judge[i];
             p[x]=i;
         int y=q_judge[i];
            q[y]=i;}

     mergesort(a,b,0,n-1);

     if( mergesortcheck(a,0,n-1)==true ){

   cout<<"consistent"<<endl;
     for(int i=0;i<n;i++)
     { cout<<a[i]<<" ";}
     }
     else cout<<"inconsistent"<<endl;


     return 0;
     }

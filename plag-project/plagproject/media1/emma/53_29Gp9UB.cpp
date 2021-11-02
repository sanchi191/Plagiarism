#include <iostream>
#include <vector>

using namespace std;

bool lessc(int a, int b, int pc[], int qc[]){
    int count=0;
    if(a<b){count++;}
    if(pc[a]<pc[b]){count++;}
    if(qc[a]<qc[b]){count++;}
    if(count>1){return true;}
    else{return false;}
}

//  left half is A[iBegin :iMiddle-1]
// right half is A[iMiddle:iEnd-1   ]
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, vector<int> &B, int pc[], int qc[], int &p_sub, int &q_sub, int &total)
{
    int i0 = iBegin, i1 = iMiddle;

    // While there are elements in the left or right runs
    for (int j = iBegin; j < iEnd; j++) {
        // If left run head exists and is <= existing right run head.
        if (i0 < iMiddle && (i1 >= iEnd || lessc(A[i0],A[i1],pc,qc) )) {
            B[j] = A[i0];
            i0 = i0 + 1;
        } else {
            B[j] = A[i1];
            i1 = i1 + 1;
            }
        }
    return;
}

// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set)
void TopDownSplitMerge(int A[], int iBegin, int iEnd, vector<int> &B, int pc[], int qc[], int &p_sub, int &q_sub, int &total)
{
    if(iEnd - iBegin < 2)                       // if run size == 1
        {return;}                                 //   consider it sorted
    // recursively split runs into two halves until run size == 1,
    // then merge them and return back up the call chain
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    TopDownSplitMerge(A, iBegin, iMiddle, B, pc, qc,p_sub,q_sub,total);  // split / merge left  half
    TopDownSplitMerge(A, iMiddle, iEnd, B, pc, qc,p_sub,q_sub,total);  // split / merge right half
    TopDownMerge(A, iBegin, iMiddle, iEnd, B, pc, qc,p_sub,q_sub,total);  // merge the two half runs
    //CopyArray(B, iBegin, iEnd, A);              // copy the merged runs back to A
    return;
}

/* array A[] has the items to sort; array B[] is a work array */
void TopDownMergeSort(int A[], int n, vector<int> &B, int pc[], int qc[], int &p_sub, int &q_sub, int &total)
{
    TopDownSplitMerge(A, 0, n, B, pc, qc,p_sub,q_sub,total);
    return;
}

void Merge(int A[], int iBegin, int iMiddle, int iEnd, int pc[], int qc[], int &p_sub, int &q_sub, int &total)
{
    int i0 = iBegin;
    int i1 = iMiddle;
    int countleft=(i1-i0);

    // While there are elements in the left or right runs
    for(int j=iBegin; j<iEnd; j++) {
        // If left run head exists and is <= existing right run head.
        if(i0<iMiddle && (i1>=iEnd || lessc(A[i0],A[i1],pc,qc) )){
            i0 = i0 + 1;
            countleft = countleft - 1;
        }
        else{
            i1 = i1 + 1;
            total = total + countleft;
            //if(total>0){cout<<A[i0]<<" "<<A[i1-1]<<i0<<i1<<" "<<total<<endl;}
            for(int t=i0; t<iMiddle; t++){
                if(pc[A[t]]>pc[A[i1-1]]){p_sub++;cout<<t<<i1-1<<endl;}
                if(qc[A[t]]>qc[A[i1-1]]){q_sub++;cout<<t<<i1-1<<endl;}
            }
        }
    }
    return;
}

void SplitMerge(int A[], int iBegin, int iEnd, int pc[], int qc[], int &p_sub, int &q_sub, int &total)
{
    if(iEnd - iBegin < 2)                       // if run size == 1
        {return;}                                 //   consider it sorted
    // recursively split runs into two halves until run size == 1,
    // then merge them and return back up the call chain
    int iMiddle = (iEnd + iBegin) / 2;             // iMiddle = mid point
    SplitMerge(A, iBegin, iMiddle, pc, qc,p_sub,q_sub,total);  // split / merge left  half
    SplitMerge(A, iMiddle, iEnd, pc, qc,p_sub,q_sub,total);  // split / merge right half
    Merge(A, iBegin, iMiddle, iEnd, pc, qc,p_sub,q_sub,total);  // merge the two half runs
    //CopyArray(B, iBegin, iEnd, A);              // copy the merged runs back to A
    return;
}

int main(){
    int n,t;
    cin>>n;
    int p[n],q[n],pc[n],qc[n],A[n],r[n];
    for(int w=0; w<n; w++){A[w]=w;}
    vector<int> B(n);
    for(int i=0; i<n ;i++){
        cin>>t;
        p[i]=(t-1);
        pc[p[i]]=i;B.push_back(-1);
    }
    for(int j=0; j<n ;j++){
        cin>>t;
        q[j]=(t-1);
        qc[q[j]]=j;
    }

    int p_sub = 0;
    int q_sub = 0;
    int total = 0;
    TopDownMergeSort(A,n,B,pc,qc,p_sub,q_sub,total);
    //cout<<total<<endl;
/*
    //this contains the O(n^2) case
    for(int x=n-1; x>=0; x--){
        for(int y=x-2 , z=x-1 ; y>=0 ; y--){
            if(lessc(B[x],B[y],pc,qc)){
                for(; z>=0; z--){
                    if((lessc(B[z],B[x],pc,qc))&&(lessc(B[y],B[z],pc,qc))){break;}
                }
                cout<<"inconsistent\n"<<B[y]+1<<" "<<B[z]+1<<" "<<B[x]+1<<endl;
                return 0;
            }
        }
    }
    cout<<"consistent"<<endl;
    for(int l=0; l<n ;l++){
            cout<<B[l]+1<<" ";
    }
*/

    for(int k=0; k<n; k++){r[k]=B[k];}
    p_sub = 0;
    q_sub = 0;
    total = 0;
    SplitMerge(r,0,n,pc,qc,p_sub,q_sub,total);
    //p_sub equals the number of times an inverse pair belongs in r but not in p
    //q_sub equals the number of times an inverse pair belongs in r but not in q
    //total represents the number of pairs not in inverse
    if(p_sub==0 && q_sub==0){
        cout<<"consistent"<<endl;
        for(int l=0; l<n ;l++){
                cout<<B[l]+1<<" ";
        }
        return 0;
    }
    if(total>0 || p_sub>0 || q_sub>0){cout<<"inconsistent"<<endl;}
//cout<<total<<p_sub<<q_sub;
/*for(int l=0; l<n ;l++){
            cout<<r[l]+1<<" ";
    }*/
    return 0;
}

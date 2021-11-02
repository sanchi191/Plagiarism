#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;

/*
// To count the number of inversion pairs
int merge_sort(int arr[], int temp[], int left, int right);
int mer(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size){
    int*temp = (int*)malloc(sizeof(int)* array_size);
    return merge_sort(arr, temp, 0, array_size-1);
}

int merge_sort(int arr[], int temp[], int left, int right){
    int mid, inv_count;
    if(right>left){
        mid = (right+left)/2;
        inv_count = merge_sort(arr,temp,left,mid);
        inv_count += merge_sort(arr,temp,mid+1,right);

        inv_count += mer(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int mer(int arr[],int temp[], int left, int mid, int right){
    int i,j,k;
    int inv_count = 0;
    i=left;
    j=mid;
    k=right;

    while((i<=(mid-1)) && (j<=right)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            inv_count=inv_count+(mid-1);
        }
    }

    while(i<=(mid-1)){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }

    for(int i=left;i<=right;i++){
        arr[i]=temp[i];
    }

return inv_count;

}
*/
vector<int> jud1;
vector<int> jud2;
vector<int> inv_jud1;
vector<int> inv_jud2;

bool cmp(int a,int b){

	if(a<b){

	if(inv_jud1[a-1]<inv_jud1[b-1] || inv_jud2[a-1]<inv_jud2[b-1]){return true;}
	else{return false;}
			}
	else {

		if(inv_jud1[a-1]<inv_jud1[b-1] && inv_jud2[a-1]<inv_jud2[b-1]){return true;}
		else{return false;}

		}
}


/*struct contestant{
    int rank,cont_num;
};

void swap(contestant a[], int i, int j);
*/
int main(){

vector<int> jud3;
int num_of_conts;

for(int i=0;i<num_of_conts;i++){
    jud3.push_back(i);
}


int x;

for(int i=0;i<num_of_conts;i++){
    cin>>x;
    jud1.push_back(x);
}

for(int i=0;i<num_of_conts;i++){
    cin>>x;
    jud2.push_back(x);
}

for(int i=1;i<num_of_conts+1;i++)
	{
		for(int j=0;j<num_of_conts;j++)
		{
		if(jud1[j]==i){
            inv_jud1.push_back(j+1);
            break;
		}
		}
	}

for(int i=1;i<num_of_conts+1;i++)
	{
		for(int j=0;j<num_of_conts;j++)
		{
		if(jud2[j]==i){
            inv_jud2.push_back(j+1);
            break;
		}
		}
	}

sort(jud3.begin(),jud3.end(),cmp);


for(int i=0;i<num_of_conts;i++){
    for(int j=i+1;j<num_of_conts;j++){
        for(int k=j+1;k<num_of_conts;k++){
            if(cmp(jud3[i],jud3[j]) && cmp(jud3[j],jud3[k])){
                if(cmp(jud3[k],jud3[i])){
                    cout<<"inconsistent"<<endl;
                    cout<<jud3[i]<<" "<<jud3[j]<<" "<<jud3[k]<<endl;
                    goto end;
                }
            }

        }
    }
}


cout<<"consistent"<<endl;

for(int i=0;i<num_of_conts;i++){
    cout<<jud3[i]<<" ";
}

end:

























/*
contestant*judge1;
contestant*judge2;

cin>>num_of_conts;

while(cin){
    contestant*judge1 = new contestant[num_of_conts];
    contestant*judge2 = new contestant[num_of_conts];
}


for(int i=0;i<num_of_conts;i++){
        cin>>judge1[i].rank;
        judge1[i].cont_num = i;
}

for(int j=0;j<num_of_conts;j++){
    cin>>judge2[j].rank;
    judge2[j].cont_num = j;
}
*/
return 0;
}



/*void swap( contestant a[], int i, int j )
{
   contestant temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}*/



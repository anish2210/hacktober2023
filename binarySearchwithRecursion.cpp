#include<bits/stdc++.h>
using namespace std;
int idx = -1;
void binarySearch(vector<int>arr,int target,int start,int end){
	int mid = 0;
	while(start <= end){
		mid = (start + end)/2;
		if(arr[mid] == target){
           idx = mid;
           return;
		}
		if(arr[mid] > target){
			binarySearch(arr,target,start,mid-1);
		}
		else{
			binarySearch(arr,target,mid+1,end);
		}
		return;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif
    vector<int>arr = {1,2,3,4,5};
    int target = 8;
    int start = 0;
    int end = arr.size()-1;
    binarySearch(arr,target,start,end);
    cout<<idx;

}
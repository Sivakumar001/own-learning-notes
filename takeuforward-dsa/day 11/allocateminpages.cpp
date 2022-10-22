#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &books, int students, int mid){
	int count=1;
	int page_allocated=0;
	for(int i=0;i<books.size();i++){
		if(page_allocated+books[i]<=mid){
			page_allocated+=books[i];
		}else{
			page_allocated = books[i];
			count++;
			if(count > students || books[i]>mid)return false;
		}
	}
	return true;

}
int min_allocation(vector<int> &books, int students){
	int low=books[0], high=0;
	for(auto it: books){
		high+=it;
		low = min(low, it);
	}
	int ans=-1;
	while(low<=high){
		int mid = (low+high) >> 1;
		if(isPossible(books, students, mid)){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return ans;
}

int main(){
	vector<int> books = {12, 34, 67, 90};
	int students = 2;
	cout << min_allocation(books, students);
	return 0;
}
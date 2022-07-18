// https://www.hackerrank.com/challenges/deque-stl/problem
#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> dq;
    for(int i=0; i < k-1; i++){
        int el = arr[i];
        while(!dq.empty() && arr[dq.back()] <= el)dq.pop_back();
        if (!dq.empty() && dq.front() <= i-k)dq.pop_front();
        dq.push_back(i);
    }
    for(int i = k-1; i < n; i++){
        int el = arr[i];
        while(!dq.empty() && arr[dq.back()] <= el)dq.pop_back();
        if (!dq.empty() && dq.front() <= i-k)dq.pop_front();
        dq.push_back(i);
        cout << arr[dq.front()] << " \n"[i==n-1];
    }
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

// https://www.codechef.com/problems/DC206

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	stack<int> st;
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)cin >> arr[i];
	for(int i = n-1; i >=0 ; i--){
	    int el = arr[i];
	    while(st.size() && st.top() <= el)st.pop();
	    if (st.size())arr[i] = st.top();
	    else arr[i] = -1;
	    st.push(el);
	}
	for(int i = 0; i < n; i++)cout << arr[i] << " \n"[i==n-1];
	return 0;
}

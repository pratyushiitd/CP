//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


struct node{
    int num;
    node* child[2];
    node(){
        num = 0;
        for(int i = 0; i < 2; i++)child[i] = NULL;
    }
};

void add(int n, node* root){
    node* tmp = root;
    for(int i = 30; i >= 0; i--){
        int val = (n>>i)%2;
        if (tmp->child[val] == NULL)tmp->child[val] = new node();
        tmp = tmp->child[val];
    }
    tmp->num = n;
}
int get(int n, node* root){
    node* tmp = root;
    for(int i = 30; i >= 0; i--){
        int val = (n >> i)%2;
        if (tmp->child[val] != NULL){
            tmp = tmp->child[val];
        }else if (tmp->child[1-val] != NULL)
        tmp = tmp->child[1-val];
    }
    return tmp->num;
}
class Solution{   
public:
    int minxorpair(int N, int arr[]){    
        //code here
        node* root = new node();
        int ans = INT_MAX;
        for(int i = 0; i < N; i++){
            int v = get(arr[i], root);
            ans = min(ans, v^arr[i]);
            add(arr[i], root);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

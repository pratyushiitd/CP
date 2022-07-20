// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/digital-string-b2b5401b/

#include<stdio.h>
#include <bits/stdc++.h>
#include<string.h>

using namespace std;
#define PR(x) printf("%d\n",x)
const int MAXSIZE=100001;

int dp[MAXSIZE][5];

int solve(int N,int P[MAXSIZE],int Q[MAXSIZE],int R[MAXSIZE],int S[MAXSIZE])
{
    //write code here 
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    dp[0][4] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= 4; j++)dp[i][j] = INT_MAX;
    }
    vector<vector<int>> vec(MAXSIZE, vector<int> (5));
    for(int i = 1; i < MAXSIZE; i++){
        vec[i][0] = P[i-1];
        vec[i][1] = Q[i-1];
        vec[i][2] = R[i-1];
        vec[i][3] = S[i-1];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 1; k <= 4; k++){
                if (k!=j)
                dp[i][j] = min(dp[i-1][k]+ vec[i][j-1], dp[i][j]);
            }
        }
    }
    return min(dp[N][1], min(dp[N][2], min(dp[N][3], dp[N][4]))) ;
}
int main()
{

    int p[MAXSIZE];
    int q[MAXSIZE];
    int r[MAXSIZE];
    int s[MAXSIZE];

    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        for(int i=0;i<n;i++)
            scanf("%d %d %d %d",&p[i],&q[i],&r[i],&s[i]);
        printf("%d\n",solve(n,p,q,r,s));
    }

    return 0;
}

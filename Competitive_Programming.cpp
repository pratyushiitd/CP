#include <bits/stdc++.h>

using namespace std;

#define test int t; cin>> t; while (t--)
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define ro(i, k, n) for (ll i = n-1; i>=k; i--)
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << " " << x << '\n'
#define is_sorted(v) std::is_sorted(all(v))
#define pb push_back
#define pf push_front

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef map<int, int> Mii;
typedef map<ll, ll> Mll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const int mod = 1e9 + 7;
const double pi = 3.1415926535897932384626;
const double e = 2.71828182845904523536;

bool visited[100001];
vector<int> adj[100001];
int Distance[100001];

void dfs(int s){
    if (visited[s])return;
    visited[s] = true;
    for (auto x : adj[s])dfs(x);
}

void bfs(int s)
{
    queue<int> q;visited[s] = true;q.push(s);Distance[s] = 0;
    while (!q.empty()){
        int s = q.front();q.pop();
        for (auto x : adj[s]){
            if (!visited[x]){visited[x] = true;Distance[x] = Distance[s] + 1;q.push(x);}
        }
    }
}

bool is_prime(int n)
{   if (n <= 1)return false;if (n <= 3) return true;if (n%2==0 || n%3 == 0)return false;
    for (int i=5; i*i<=n; i+=6) if (n%i == 0 || n%(i + 2) == 0)return false;
    return true;
}

pair<ll, ll> extremes_array(ll arr[],ll n)
{
    ll min = arr[0];ll max = arr[0];
    for (i, 1, n){
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    return make_pair(min, max);
}
ll c_div(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll f_div(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //solve();
    test{solve();}
    return 0;
}

/*
LOOK FOR -> Special int overflow, 
            array bounds
	        special cases (n=1?)
            Different approaches
*/

#include <bits/stdc++. h>

using namespace std;

#test int t; cin>> t; while (t--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define fo(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << " " << x << '\n'
#define is_sorted(v) std::is_sorted(all(v))
#define pb push_back
#define pf push_front

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef set<int> Si;
typedef set<ll> Sll;
typedef set<pii> Spii;
typedef set<pll> Spll;
typedef map<int, int> Mii;
typedef map<ll, ll> Mll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const int mod = 10e9 + 7;
const double pi = 3.1415926535897932384626;
const double e = 2.71828182845904523536;

bool visited[10e5 + 1];
vector<int> adj[10e5 + 1];
int Distance[10e5 + 1];

void dfs(int s)
{
    if (visited[s])
    {
        return;
    }
    visited[s] = true;
    for (auto x : adj[s])
    {
        dfs(x);
    }
}

void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    Distance[s] = 0;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (auto x : adj[s])
        {
            if (!visited[x])
            {
                visited[x] = true;
                Distance[x] = Distance[s] + 1;
                q.push(u);
            }
        }
    }
}

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

pair<int, int> extremes_array(int arr[], n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return make_pair(min, max);
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //solve();
    test{solve()};
    return 0;
}

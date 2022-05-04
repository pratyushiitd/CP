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
#define in(a) int a; cin >> a
#define st(a) string a; cin >> a
#define in(a,n) int arr[n]; fo(i, 0, n)cin >> arr[i]
#define st(a,n) string arr[n]; fo(i, 0, n) cin >> arr[i]

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef map<int, int> Mii;
typedef map<ll, ll> Mll;
typedef vector<vi> vvi;
typedef vector<vl> vvll;

#define tcT template<typename T
#define tcTU tcT, class U
#define lb lower_bound
#define ub upper_bound 
#define each(a, x) for (auto a : x)
tcT> int lwb(vector<T>& a, const T& b) { return int(lb(all(a),b)-a.begin()); }//less/eq
tcT> int upb(vector<T>& a, const T& b) { return int(ub(all(a),b)-a.begin()); }//greater
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
tcT> void remDup(vector<T>& v) {
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcT> void erase(vector<T>& vec, const T& u) {
	auto it = find(all(vec),u); assert(it != vec.end());
	vec.erase(it); }

const int mod = 1e9 + 7;
const double pi = 3.1415926535897932384626;
const double e = 2.71828182845904523536;

ll maxof(ll n_args, ...)
{
    va_list ap;
    va_start(ap, n_args);
    int max = va_arg(ap, int);
    for(int i = 2; i <= n_args; i++) {
        int a = va_arg(ap, int);
        if(a > max) max = a;
    }
    va_end(ap);
    return max;
}


bool visited[100001];
vector<int> adj[100001];
int Distance[100001];
void pn() {cout << '\n';}
tcT> void pn(T t) {cout << t << '\n';}
tcT> void ps(T t) {cout << t << '\n';}
tcT> void pr(T t) {cout << t << '\n';}
tcT, typename... Args>
void pn(T t, Args... args){
cout << t <<'\n' ;pn(args...) ;
}
tcT, typename... Args>
void ps(T t, Args... args){
cout << t <<' ' ;ps(args...) ;
}
tcT, typename... Args>
void pr(T t, Args... args){
cout << t ;pr(args...) ;
}
tcT> void show_vec(T const& vec){
    typename T::const_iterator pos;
    for (pos=vec.begin(); pos!=vec.end(); ++pos) ps(*pos);pn();
}
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

bool is_prime(ll n)
{   if (n <= 1)return false;if (n <= 3) return true;if (n%2==0 || n%3 == 0)return false;
    for (ll i=5; i*i<=n; i+=6) if (n%i == 0 || n%(i + 2) == 0)return false;
    return true;
}
tcT>
pair<T, T> extremes_array(T arr[],ll n)
{
    T min = arr[0];T max = arr[0];
    fo (i, 1, n){
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
LOOK FOR -> int overflow, 
            array bounds
	        special cases (n=1?)
            Different approaches
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <sys/resource.h>
 
using namespace std;
using namespace __gnu_pbds;
 
#define INF 1000000007
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;
 
 
#define TRACE
 
#ifdef TRACE
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define pr(...)
#define pra(a,n)
#define praa(a,n,m)
#endif
 
#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pres(s,x) (s.find(x)!=s.end())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a, int b, int m = INF) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = INF) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = INF) {return (int)(((ll)a * (ll)b) % m);}
 
 
 
 
int main()
{
	boost;
	inc_stack_limit;
	int n; cin >> n;
	vi a(n);
	FOR(i, 0, n - 1)cin >> a[i];
	
	vvi dp_rmq(18, vi(n, -1));
	FOR(i, 0, n - 1)dp_rmq[0][i] = i;
	for (int i = 1; (1 << i) <= n; ++i) {
		for (int j = 0; j + (1 << i) <= n; ++j) {
			dp_rmq[i][j] = a[dp_rmq[i - 1][j]] > a[dp_rmq[i - 1][j + (1 << (i - 1))]] ? dp_rmq[i - 1][j] : dp_rmq[i - 1][j + (1 << (i - 1))];
		}
	}
 
	auto rmq = [&](int l, int r) {
		int lg = 31 - __builtin_clz(r - l + 1);
		return a[dp_rmq[lg][l]] > a[dp_rmq[lg][r - (1 << lg) + 1]] ? dp_rmq[lg][l] : dp_rmq[lg][r - (1 << lg) + 1];
	};
 
	vector<pair<pair<ii, int>, vi>> queries;
	ll ans = 0;
	function<void(int, int)> f = [&](int l, int r) {
		if (l >= r)
			return void(ans += (l == r ? a[l] : 0));
 
		int mid = rmq(l, r);
 
		pair<pair<ii, int>, vi> now;
		if (mid - l < r - mid) {
			now.F = {{mid, r}, a[mid]};
			FOR(i, l, mid)
			now.S.pb(a[i]);
		}
		else {
			now.F = {{l, mid}, a[mid]};
			FOR(i, mid, r)
			now.S.pb(a[i]);
		}
		queries.pb(now);
		f(l, mid - 1);
		f(mid + 1, r);
	};
 
	f(0, n - 1);
 
	const int block_size = sqrt(n);
	const int num_of_blocks = (n + block_size - 1) / block_size;
	vector<vvi> dp1(num_of_blocks, vvi(15, vi()));
	vector<vvi> dp2(num_of_blocks, vvi(15, vi()));
 
	// pr(queries);
	FOR(i, 0, num_of_blocks - 1) {
		int l = i * block_size;
		int r = min(n - 1, l + block_size - 1);
 
		dp2[i][0] = dp1[i][0] = vi(1<<14, 0);
		FOR(j, l, r)dp1[i][0][a[j]]++;
		FOR(j, l, r)dp2[i][0][a[j]]++;
		
		FOR(j, 0, 13) {
			dp2[i][j+1] = dp1[i][j+1] = vi(1<<14);
			FOR(k, 0, (1 << 14) - 1) {
				if (k & (1 << j))
					dp1[i][j+1][k] = dp1[i][j][k ^ (1 << j)] + dp1[i][j][k],
					               dp2[i][j+1][k] = dp2[i][j][k];
				else
					dp1[i][j+1][k] = dp1[i][j][k],
					               dp2[i][j+1][k] = dp2[i][j][k ^ (1 << j)] + dp2[i][j][k];
			}
			dp1[i][j].clear();
			dp2[i][j].clear();
		}
 	
		FOR(j, l, r)
		dp1[i][14][a[j]]--;
 
		FOR(j, 0, (1 << 14))
		dp1[i][14][j] += dp2[i][14][j];
 
	}
	
	
	for (auto &it : queries) {
		int l = it.F.F.F, r = it.F.F.S;
		ll temp = 0;
		if(r-l+1<=block_size){
			for(int x : it.S)
			FOR(i,l,r)
			temp+=(((a[i] & x) == x) or ((a[i] & x) == a[i]));
			ans += temp * it.F.S;
			continue;
		}
		
		int lblock = (l + block_size - 1) / block_size, rblock = r/block_size;
		
		
		for (auto x : it.S) {
			FOR(i, lblock, rblock-1)
			temp += dp1[i][14][x];
 
			FOR(i, l, lblock * block_size - 1)
			temp += (((a[i] & x) == x) or ((a[i] & x) == a[i]));
 
			NFOR(i, r, rblock * block_size)
			temp += (((a[i] & x) == x) or ((a[i] & x) == a[i]));
		}
 
		ans += temp * it.F.S;
	}
 
	FOR(i,0,n-1)
	ans-=a[i];
 
	cout << ans;
 
	return 0;
}

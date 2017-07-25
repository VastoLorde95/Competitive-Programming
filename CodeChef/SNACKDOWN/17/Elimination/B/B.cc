#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 500500;
const ll MOD = 1e9 + 7;

//const int MAXN = N;
//int tree[MAXN]; // Careful, indexing begins from 1.

//ll query(ll idx, ll sum = 0){
//    for(; idx; idx -= (idx & -idx)) sum += tree[idx];
//    return sum;
//}

//void update(ll idx, ll val){
//    for(; idx < MAXN; idx += (idx & -idx)) tree[idx] += val;
//}

int last[N];
int a[N];

ll dp[N];
ll sum[N];
ll ans[N];

set<int> pos;

int main(){ _
	int n, k;
	cin >> n >> k;
	
	k = min(k, n+1);
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		
		if(a[i] <= k){
			if(last[a[i]] == 0){
				last[a[i]] = i;
				pos.insert(i);
			}
			else{
				pos.erase(last[a[i]]);
				last[a[i]] = i;
				pos.insert(i);
			}
		}
		
		if(pos.size() == k+1){
			int id = *pos.begin();
			dp[i] = (sum[i-1] - sum[id-1] + MOD) % MOD;
		}
		else{
			dp[i] = (sum[i-1] + 1) % MOD;
		}
		
		sum[i] = (sum[i-1] + dp[i]) % MOD;
	}
	
	cout << dp[n] << endl;
	
	return 0;
}

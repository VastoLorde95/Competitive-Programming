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

const int T = 500;
const int N = 50001;
const ll MOD = 1e9 + 7;

ll fast(ll a, ll b){
	ll ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int isprime[N];
vector<int> primes;

int ans[T];
int f[N];
ll inv[100];

int main(){ _
	for(int i = 1; i < 100; i++){
		inv[i] = fast(i, MOD-2);
	}

	for(int i = 2; i < N; i++){
		if(isprime[i]) continue;
		for(int j = 2*i; j < N; j += i){
			isprime[j] = 1;
		}
		
		primes.pb(i);
	}
	
	int t;
	cin >> t;
	
	vector<pii> q;
	
	for(int i = 0; i < t; i++){
		int x;
		cin >> x;
		q.pb(mp(x,i));
	}
	
	sort(q.begin(), q.end());

	ll cur = 1;
	
	int i = 1;
	for(int j = 0; j < q.size(); j++){
		int x = q[j].fi;
		
		if(x == 0){
			ans[q[j].se] = 1;
			continue;
		}
		
		while(i <= x){
			int tmp = i;
			for(int &p : primes){
				if(p > tmp) break;
				
				int cnt = 0;
				
				while(tmp % p == 0){
					tmp /= p;
					cnt++;
				}
				
				if(!cnt) continue;
				
				cur = (cur * fast(f[p]+1, MOD-2)) % MOD;
				f[p] += cnt;
				cur = (cur * (f[p]+1)) % MOD;
			}
			
			i++;
		}
		
		int id = q[j].se;
		ans[id] = cur;
	}
	
	for(int i = 0; i < t; i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}

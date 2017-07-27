/*
	Solution for SPOJ problem - http://www.spoj.com/problems/MAXISET/
	Solution using meet-in-the-middle, bitmasking and dynamic programming
*/

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

const int N = 20;
const int M = 40;

int n, m;

ll g[M];
int w[M];

int sum[1 << N];
int ok[1 << N];
int best[1 << N];

void solve(){
	sd2(n,m);
	
	for(int i = 0; i < n; i++){
		sd(w[i]);
		g[i] = 0;
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		sd2(u,v);
		
		g[u] |= (1ll << v);
		g[v] |= (1ll << u);
	}
	
	int k1 = n >> 1, k2 = n - k1;
	
	int other = (1 << k2) - 1;
	
	
	int up1 = 1 << k1;
	for(int i = 1; i < up1; i++){
		int sub = i&(i-1);
		
		int lo = 0;
		while(!(i&(1 << lo))) lo++;
		
		if(!sub){
			ok[i] = (g[lo] >> k1) ^ other;
			sum[i] = w[lo];
			continue;
		}
		
		if(g[lo]&sub){
			ok[i] = 0;
			sum[i] = 0;
			continue;
		}
		
		ok[i] = ok[sub]&((g[lo] >> k1) ^ other);
		sum[i] = sum[sub] + w[lo];
	}
	
	int up2 = 1 << k2;
	for(int i = 1; i < up2; i++){
		ll sub = i&(i-1);
		
		int lo = 0;
		while(!(i&(1<<lo))) lo++;
		
		if(!sub){
			best[i] = w[k1+lo];
			continue;
		}
		
		if(!(g[k1+lo]&(sub << k1))){
			best[i] = best[sub] + w[k1+lo];
			continue;
		}
		
		best[i] = 0;
		for(int j = 0; j < k2; j++){
			if(i&(1<<j)){
				best[i] = max(best[i], best[i^(1<<j)]);
			}
		}
	}
	
	int q;
	sd(q);
	
	while(q--){
		ll mask1 = 0, mask2 = 0;
		int sz;
		sd(sz);
		
		for(int i = 0; i < sz; i++){
			int v;
			sd(v);
			
			if(v < k1) mask1 |= (1 << v);
			else mask2 |= (1 << (v-k1));
		}
		
		if(n == 1){
			printf("%d\n", w[0]);
			continue;
		}
		
		ll ssub = mask1;
		
		int ans = best[mask2];
		
		while(ssub){
			if(sum[ssub]){
				ans = max(ans, sum[ssub] + best[ok[ssub]&mask2]);
			}
			
			ssub = mask1&(ssub-1);
		}
		
		printf("%d\n", ans);
	}
	
}

int main(){
	int t;
	sd(t);
	while(t--){
		solve();
		if(t) printf("\n");
	}
	return 0;
}

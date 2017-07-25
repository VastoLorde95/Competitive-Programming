#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int MAXN = 10100;
long long tree[MAXN]; // Careful, indexing begins from 1.

int n, q, u, v, type, m, MOD = 1e9 + 7, MOD2 = 100000, cnt = 0;
vector<int> g[1<<15];
int indx[1<<15], last[1<<15];

long long query(int idx){
    long long sum = 0;
    while(idx){
        (sum += tree[idx]) %= MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, long long val){
    val %= MOD;
    while(idx < MAXN){
        (tree[idx] += val) %= MOD;
        idx += (idx & -idx);
    }
}

void dfs(int cur, int prev){
	indx[cur] = ++cnt;
	foreach(it, g[cur]){
		if(*it == prev) continue;
		
		dfs(*it, cur);
	}
	last[cur] = cnt;
}

unordered_map<long long, long long> F;

long long fib(int x){
	if(F.count(x)) return F[x];
	int k = x/2;
	if(x%2 == 0){
		return F[x] = (((fib(k)*fib(k))%MOD2) + ((fib(k-1)*fib(k-1))%MOD2))%MOD2;
	}
	else{
		return F[x] = (((fib(k)*fib(k+1))%MOD2) + ((fib(k-1)*fib(k))%MOD2))%MOD2;
	}
}

int main(){
	sd2(n,q);
	for(int i = 1; i < n; i++){
		sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}	
	
	dfs(1,0);
	
	for(int i = 1; i <= n; i++){
		update(indx[i], 1);
	}
	
	F[0] = F[1] = 1;	
		
	while(q--){
		sd(type);
		if(type == 0){
			sd2(v,m);
			if(m%2 == 0){
				long long ways = fib(m/2);
				update(indx[v], (long long) ways*m);
			}
		}
		else{
			sd(v);
			long long ans = (query(last[v]) - query(indx[v]-1) + MOD)%MOD;
			printf("%lld\n", ans);
		}
	}
	
	return 0;
}

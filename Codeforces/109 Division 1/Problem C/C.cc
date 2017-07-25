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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef long long ll;

const int N = 1000100;

int n, m, u, v;
ll p[N], MOD =  22222223333355757ll, h[N];
unordered_map<ll, ll> hsh;
unordered_map<ll, ll> hsh2;

int main(){
	p[0] = 1;
	for(int i = 1; i < N; i++) p[i] = (p[i-1]*2)%MOD;
	sd2(n,m);
	
	for(int i = 1; i <= n; i++) h[i] = p[i];
	
	for(int j = 0; j < m; j++){
		sd2(u,v);
		h[u] += p[v];
		if(h[u] >= MOD) h[u] -= MOD;
		h[v] += p[u];
		if(h[v] >= MOD) h[v] -= MOD;
	}
	
	for(int i = 1; i <= n; i++) hsh[h[i]]++;
	
	ll res = 0;
	foreach(it, hsh){
		ll val = it->se;
		res += (val*(val-1));
	}
	
	for(int i = 1; i <= n; i++){
		if(hsh[h[i]] == 1){
			h[i] = h[i] - p[i];
			if(h[i] < 0) h[i] += MOD;
			hsh2[h[i]]++;
		}	
	}
	
	foreach(it, hsh2){
		ll val = it->se;
		res += (val*(val-1));
	}
	
	cout << res/2 << '\n';
	
	return 0;
}

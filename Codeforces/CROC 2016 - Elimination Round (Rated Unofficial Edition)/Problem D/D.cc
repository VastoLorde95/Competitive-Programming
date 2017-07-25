#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;

int n, m;
vector<pii> g[N];

int d[N], l[N];

bool f(int k){
	for(int i = 1; i <= n; i++){
		d[i] = 0, l[i] = 0;
	}
	
	for(int i = 1; i <= n; i++){
		foreach(it, g[i]){
			if(it->se <= k){
				d[it->fi]++;
			}	
		}
	}
	
	int start = -1;
	for(int i = 1; i <= n; i++){
		if(d[i] == 0){
			if(start != -1) return false;
			start = i;
		}
	}
	
	if(start == -1) return false;
	
	l[start] = 1;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		
		foreach(it, g[cur]){
			if(it->se > k) continue;
			int nxt = it->fi;
			d[nxt]--;
			l[nxt] = max(l[nxt], l[cur] + 1);
			if(d[nxt] == 0) q.push(nxt);
		}
	}		
	
	for(int i = 1; i <= n; i++){
		if(l[i] == n) return true;
	}
	return false;
	
}

int main(){
	sd2(n,m);
	
	int u, v;
	for(int i = 1; i <= m; i++){
		sd2(u,v);
		g[u].pb(mp(v, i));
	}	
	
	int lo = 0, hi = m+1, mid;
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		if(f(mid)) hi = mid;
		else lo = mid;
	}
	
	if(hi == m+1) hi = -1;
	
	cout << hi << endl;
	
	return 0;
}

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

const int N = 510;

int n, m, k;
int g[N][N];
int v[N];

void dfs(int cur, int prev){
	if(v[cur]) return;
	v[cur] = 1;
	for(int i = 1; i <= n; i++){
		if(!g[cur][i]) continue;
		if(i == prev) continue;
		
		dfs(i, cur);
	}
}

int main(){
	sd3(n,m,k);
	for(int i = 1; i <= m; i++){
		int u, v; sd2(u,v);
		g[u][v] = g[v][u] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			g[i][j] ^= 1;
			g[j][i] ^= 1;
		}
	}
	
	dfs(1, -1);
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			puts("impossible");
			return 0;
		}
	}
	
	int bad = 0;
	for(int i = 2; i <= n; i++){
		if(g[i][1] == 1){
			int cnt = 0;
			for(int j = 2; j <= n; j++){
				if(j == i) continue;
				cnt += g[i][j];
			}
			if(cnt == 0) bad++;
		}
	}
	
	int xx = 0;
	for(int i = 1; i <= n; i++){
		xx += g[1][i];
	}	
	
	if(bad > k){
		puts("impossible");
	}
	else if(bad == k and k != n-1){
		puts("impossible");	
	}
	else if(xx < k){
		puts("impossible");
	}
	else{
		puts("possible");		
	}
	
	return 0;
}

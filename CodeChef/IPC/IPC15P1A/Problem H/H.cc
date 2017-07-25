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

const long double PI = 3.1415926535897932384626433832795;

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

const int N = 101;
const int M = 151;
const int K = 128;

int v[N][M][K];

vector<pii> g[N];
int w[M];

int main(){
	int n, m;
	sd2(n,m);
	
	for(int i = 1; i <= m; i++){
		int u, v, c;
		sd3(u,v,c);
		g[u].pb(mp(v,i));
		g[v].pb(mp(u,i));
		w[i] = c;
	}
	
	int best = 0;

	queue<pair<int, pii> > q;
	for(int i = 1; i <= n; i++){
		q.push(mp(i, mp(0,0)));
	}
	
	while(!q.empty()){
		int x = q.front().fi, e = q.front().se.fi, c = q.front().se.se;
		q.pop();
		
		v[x][e][c] = 1;
		best = max(best, c);
		
		foreach(it, g[x]){
			int y = it->fi, id = it->se, nc = c ^(w[e] & w[id]);
			if(v[y][id][nc]) continue;
			
			v[y][id][nc] = 1;
			q.push(mp(y, mp(id, nc)));
		}
	}
	
	printf("%d\n", best);
	
	return 0;
}

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

const int N = 1001;
const ll INF = 1ll << 50;

int n, m, k;

vector<pair<int, pii> > g[N];
ll d[N][1 << 10];
int v[N][1 << 10];

int main(){
	sd3(n,m,k);
	
	for(int i = 1; i <= m; i++){
		int x, y, z;
		sd3(x,y,z);
		g[x].pb(mp(y, mp(z, 0)));
		g[y].pb(mp(x, mp(z, 0)));
	}
	
	for(int i = 1; i <= k; i++){
		int x, y, z;
		sd3(x,y,z);
		g[x].pb(mp(y, mp(z, i)));
		g[y].pb(mp(x, mp(z, i)));
	}

	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1 << k); j++){
			d[i][j] = INF;
		}
	}
	
	d[1][0] = 0;
	
	set<pair<ll, pii> > q;
	q.insert(mp(0, mp(1, 0)));
	
	while(!q.empty()){
		pair<ll, pii> p = *q.begin();
		q.erase(p);
		
		int cur = p.se.fi, mask = p.se.se;
		
		if(v[cur][mask]) continue;
		
		v[cur][mask] = 1;
		
		foreach(it, g[cur]){
			int nxt = it->fi;
			int wt = it->se.fi;
			int type = it->se.se;
			int nmask = mask;
			if(type) nmask |= (1 << (type-1));
	
			if(v[nxt][nmask]) continue;
	
			ll ndis = d[cur][mask] + wt;
			
			if(ndis < d[nxt][nmask]){
				d[nxt][nmask] = ndis;
				q.insert(mp(ndis, mp(nxt, nmask)));
			}
		}
	}
	
	cout << d[n][(1<<k)-1] << endl;
	
	
	return 0;
}

#include <bits/stdc++.h>

#define sd(x)		scanf("%d",&x)
#define sd2(x,y)	scanf("%d%d",&x,&y)
#define sd3(x,y,z)	scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
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

const int N   = 105;
const int INF = 1e9;

int n, m;

vector<pii> g1[N];
vector<pii> g2[N];

int d1[N];
int d2[N];

int shortestPath(vector<pii> g[], int d[], bool mx){
	for(int i = 2; i <= n+1; i++) d[i] = mx? INF : -1;
	bool ok = true;
	
	d[1] = 0;
	while(ok){
		ok = false;
		for(int i = 1; i <= n; i++){
			if((mx and d[i] == INF) or (!mx and d[i] < 0)) continue;
			foreach(it, g[i]){
				int j = it->fi, c = it->se;
				if((mx and d[j] > d[i] + c) or (!mx and d[j] < d[i] + c)){
					d[j] = d[i] + c;
					ok = true;
				}
			}
		}
	}
	
	return d[n+1];
}

int main(){
	sd2(n,m);
	
	int a, b, c;
	for(int i = 0; i < m; i++){
		sd3(a,b,c); b++;
		g1[a].pb(mp(b, c));
		g1[b].pb(mp(a,-c));
		
		g2[a].pb(mp(b, c));
		g2[b].pb(mp(a,-c));
	}
	
	for(int i = 1; i <= n; i++){
		g1[i].pb(mp(i+1, 1));
		g1[i+1].pb(mp(i, 0));
		
		g2[i].pb(mp(i+1, 0));
		g2[i+1].pb(mp(i, -1));
	}
	
	int mxl = shortestPath(g1, d1, true);
	int mnl = shortestPath(g2, d2, false);
	
	printf("%d %d\n", mnl, mxl);
	
	return 0;
}

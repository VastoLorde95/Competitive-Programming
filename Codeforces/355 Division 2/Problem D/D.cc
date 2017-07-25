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

const int N = 330;
const int INF = 1e9;

int n, m, p;
int g[N][N];

vector<pii> pts[N*N];

int d[N][N];
int v[N][N];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int manhattan(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

bool comp(const pii &p1, const pii &p2){
	return d[p1.fi][p1.se] < d[p2.fi][p2.se];
}

bool good(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true;
	return false;
}

int main(){
	sd3(n,m,p);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sd(g[i][j]);
			pts[g[i][j]].pb(mp(i,j));
			d[i][j] = (g[i][j] > 1)? INF : manhattan(1,1,i,j);
		}
	}
	
	for(int i = 2; i <= p; i++){
		if(pts[i-1].size() < 300){
			foreach(it, pts[i]){
				int x = it->fi, y = it->se;
				for(int j = 0; j < pts[i-1].size(); j++){
					int nx = pts[i-1][j].fi, ny = pts[i-1][j].se;
					d[x][y] = min(d[x][y], d[nx][ny] + manhattan(x,y,nx,ny));
				}
			}
		}
		else{
			for(int x = 1; x <= n; x++){
				for(int y = 1; y <= m; y++){
					v[x][y] = INF;
				}
			}
			
			vector<pair<int, pii> > prev;
			vector<pair<int, pii> > q;
			
			foreach(it, pts[i-1]){
				int x = it->fi, y = it->se;
				prev.pb(mp(d[x][y], mp(x,y)));
//				v[x][y] = d[x][y];
			}
			
			sort(prev.begin(), prev.end());
			reverse(prev.begin(), prev.end());
			
			int ptr = 0;
			int j = 0;
			
			q.pb(prev.back());
			v[prev.back().se.fi][prev.back().se.se] = prev.back().fi;
			prev.pop_back();
			
			while(j < q.size()){
				int x =  q[j].se.fi;
				int y = q[j].se.se;
				int dis = q[j].fi;
				j++;
				v[x][y] = dis;

				while(prev.size() > 0 and prev.back().fi == dis){
					q.pb(prev.back());
					prev.pop_back();
				}
				
				for(int ii = 0; ii < 4; ii++){
					int nx = x + dx[ii];
					int ny = y + dy[ii];
					if(good(nx,ny) and v[nx][ny] == INF){
						v[nx][ny] = v[x][y] + 1;
						q.pb(mp(v[nx][ny], mp(nx,ny)));
					}
				}
			}
			
			foreach(it, pts[i]){
				int x = it->fi, y = it->se;
				d[x][y] = v[x][y];
			}
			
		}
	}	

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == p){
				printf("%d\n", d[i][j]);
				return 0;
			}
		}
	}	

	return 0;
}

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

const int N = 100100;
const int M = 10;
const int magic = N;

vector<pii> g[N];
vector<int> comp[N];
int vis[N];
int n, e;
int poss[N][M];

void dfs(int x, int col){
	vis[x] = 1;
	comp[col].pb(x);
	
	foreach(it, g[x]){
		if(vis[it->fi]) continue;
		
		dfs(it->fi, col);
	}
}

void dfs2(int x, int p){
	poss[x][p] = 1;
	
	foreach(it, g[x]){
		int np = (p + it->se) % 10;
		if(poss[it->fi][np]) continue;
		
		dfs2(it->fi, np);
	}
}

int cbs(int x, int y){
	int z = x << y;
	z &= ((1 << M) - 1);
	z |= (x >> (M-y));
	return z;
}

ll ans[M];

int main(){ _
	cin >> n >> e;
	
	for(int i = 0; i < e; i++){
		int x, y, r;
		cin >> x >> y >> r;
		r %= 10;
		
		g[x].pb(mp(y,r));
		g[y].pb(mp(x,(10-r)%10));
	}
	
	int col = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		
		dfs(i, col++);
	}

	for(int i = 0; i < col; i++){
		int sz = comp[i].size();
		
		if(sz <= magic){
			for(int &x : comp[i]){
				for(int &y : comp[i]){
					for(int j = 0; j < M; j++){
						poss[y][j] = 0;
					}
				}
				
				dfs2(x, 0);
				
				for(int &y : comp[i]){
					if(x != y){
						for(int j = 0; j < M; j++){
							ans[j] += poss[y][j];
						}
					}
				}
			}
		}
		else{
			dfs2(comp[i][0], 0);
			
			ll cnt[1<<M];
			memset(cnt, 0, sizeof cnt);
			
			for(int &x : comp[i]){
				int mask = 0;
				for(int j = 0; j < M; j++){
					if(poss[x][j]){
//						tr(x, j);
						mask |= (1 << j);
					}
				}
				
				int submask = mask;
				while(submask > 0){
					cnt[submask]++;
//					tr(submask, cnt[submask]);
					submask = mask & (submask-1);
				}
			}
			
			for(int j = 0; j < M; j++){
				ans[0] += cnt[1<<j] * (cnt[1<<j]-1);		
			}
			
			for(int j = 1; j < M; j++){
				for(int mask = 1; mask < (1<<M); mask++){
					if(!cnt[mask]) continue;
					int ss = __builtin_popcount(mask);
					
					int other = cbs(mask, j);
					
					if(ss&1)
						ans[j] += cnt[mask] * cnt[other];// - cnt[common] * cnt[common];
					else
						ans[j] -= cnt[mask] * cnt[other];// - cnt[common] * cnt[common];
						
//					if(j == 5){
//						tr(ans[j], mask, other, cnt[mask], cnt[other]);
//					}
				}
			}
			
			for(int j = 1; j < M; j++){
				for(int &x : comp[i]){
					for(int k = 0; k < M; k++){
						if(poss[x][k] and k+j < 10 and poss[x][(k+j)%10]){
							ans[j]--;
							break;
						}
					}
				}	
			}
		}
	}
	
	for(int i = 0; i < M; i++){
		assert(ans[i] >= 0);
		cout << ans[i] << endl;
	}
	
	return 0;
}

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

//#define DEBUG

int g_seed;

inline int fastrand() { 
  g_seed = (214013 * g_seed + 2531011); 
  return (g_seed >> 16)&0x7FFF; 
} 

const int N = 211;
string g[N];
int n, m;

pii del[24][4] = {{mp(1,0), mp(-1,0), mp(0,1), mp(0,-1)},{mp(1,0), mp(-1,0), mp(0,-1), mp(0,1)},{mp(1,0), mp(0,1), mp(-1,0), mp(0,-1)}, {mp(1,0), mp(0,1), mp(0,-1), mp(-1,0)}, {mp(1,0), mp(0,-1), mp(-1,0), mp(0,1)}, {mp(1,0), mp(0,-1), mp(0,1), mp(-1,0)}, {mp(-1,0), mp(1,0), mp(0,1), mp(0,-1)}, {mp(-1,0), mp(1,0), mp(0,-1), mp(0,1)}, {mp(-1,0), mp(0,1), mp(1,0), mp(0,-1)}, {mp(-1,0), mp(0,1), mp(0,-1), mp(1,0)}, {mp(-1,0), mp(0,-1), mp(1,0), mp(0,1)}, {mp(-1,0), mp(0,-1), mp(0,1), mp(1,0)}, {mp(0,1), mp(1,0), mp(-1,0), mp(0,-1)}, {mp(0,1), mp(1,0), mp(0,-1), mp(-1,0)}, {mp(0,1), mp(-1,0), mp(1,0), mp(0,-1)}, {mp(0,1), mp(-1,0), mp(0,-1), mp(1,0)}, {mp(0,1), mp(0,-1), mp(1,0), mp(-1,0)}, {mp(0,1), mp(0,-1), mp(-1,0), mp(1,0)}, {mp(0,-1), mp(1,0), mp(-1,0), mp(0,1)}, {mp(0,-1), mp(1,0), mp(0,1), mp(-1,0)}, {mp(0,-1), mp(-1,0), mp(1,0), mp(0,1)}, {mp(0,-1), mp(-1,0), mp(0,1), mp(1,0)}, {mp(0,-1), mp(0,1), mp(1,0), mp(-1,0)}, {mp(0,-1), mp(0,1), mp(-1,0), mp(1,0)}};

inline bool inrange(int x, int y){ return (x >= 0 and x < n and y >= 0 and y < m and g[x][y] != '#'); }

int vis[N][N];
int gen;

bool verify(string &s){
	pii S, F;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == 'S') S = mp(i,j);
			if(g[i][j] == 'F') F = mp(i,j);
		}
	}
	
	int vis3[N][N];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) vis3[i][j] = 0;
	
	vis3[S.fi][S.se] = 1;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'L') S.se -= 1;
		else if(s[i] == 'R') S.se += 1;
		else if(s[i] == 'U') S.fi -= 1;
		else S.fi += 1;
		
		if(!inrange(S.fi, S.se)) return false;
		if(vis3[S.fi][S.se]) return false;
		vis3[S.fi][S.se] = 1;
	}
	
	if(S != F) return false;
	
	return true;
}

string getString(vector<pii> &v){
	int n = v.size();
#ifdef DEBUG
	assert(n > 1);
#endif

	reverse(v.begin(), v.end());
	
	string s;
	for(int i = 1; i < n; i++){
		pii &px = v[i-1], &py = v[i];
		
		if(px.fi == py.fi){
			if(px.se < py.se) s += 'R'; else s += 'L';
		}
		else{
			if(px.fi < py.fi) s += 'D'; else s += 'U';
		}
	}

#ifdef DEBUG
	assert(verify(s));
#endif

	return s;
}

bool randomDFS(pii cur, pii des, vector<pii> &v){
	if(cur == des){
		v.pb(des);
		return true;
	}
	
	vis[cur.fi][cur.se] = gen;
	
//	pii del[4] = {mp(1,0), mp(-1,0), mp(0,1), mp(0,-1)};
//	random_shuffle(del, del + 4);
	
	int id = fastrand() % 24;
	
	for(int i = 0; i < 4; i++){
		int nx = cur.fi + del[id][i].fi;
		int ny = cur.se + del[id][i].se;
		
		if(inrange(nx, ny) and vis[nx][ny] != gen){
			if(randomDFS(mp(nx, ny), des, v)){
				v.pb(cur);
				return true;
			}
		}
	}
	return false;
}

int vis2[N][N];
int genn;

bool randomDFS2(pii cur, pii des, vector<pii> &v){
	if(cur == des){
		v.pb(des);
		return true;
	}
	
	vis2[cur.fi][cur.se] = genn;
	
//	pii del[4] = {mp(1,0), mp(-1,0), mp(0,1), mp(0,-1)};
//	random_shuffle(del, del + 4);
	
	int id = fastrand() % 24;
	
	for(int i = 0; i < 4; i++){
		int nx = cur.fi + del[id][i].fi;
		int ny = cur.se + del[id][i].se;
		
		if(inrange(nx, ny) and vis2[nx][ny] != genn and !vis[nx][ny]){
			if(randomDFS2(mp(nx, ny), des, v)){
				v.pb(cur);
				return true;
			}
		}
	}
	return false;
}

vector<pii> getAugmentingPath(int x1, int y1, int x2, int y2){
	const int ITER = 200;
	
	int mx = 0;
	vector<pii> res;
	
	for(int iter = 0; iter < ITER; iter++){
		vector<pii> v;
		genn++;
		
		randomDFS2(mp(x1, y1), mp(x2, y2), v);

#ifdef DEBUG
		for(auto &p : v) assert(vis[p.fi][p.se] == 0);
#endif
		
		if(v.size() > mx){
			mx = v.size();
			res = v;
		}
	}
	
	reverse(res.begin(), res.end());
	
	return res;
}

vector<pii> t_ans;

void solve(){
	pii S, F;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == 'S') S = mp(i,j);
			if(g[i][j] == 'F') F = mp(i,j);
		}
	}
	
	int mx = 0;
	
	const int BASE_ITER = 3000;
	for(int i = 0; i < BASE_ITER; i++){
		gen++;
		vector<pii> v;
		
		randomDFS(S, F, v);
		
		if(v.empty()) continue;
		
		if(v.size() > mx){
			mx = v.size();
			t_ans = v;
		}	
	}
	
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) vis[i][j] = 0;
	
	for(auto &x : t_ans) vis[x.fi][x.se] = 1;
	
	int iter = 20;
	while(iter--){
		for(int i = 1; i < t_ans.size(); i++){
			pii p1 = t_ans[i-1];
			pii p2 = t_ans[i];
			
			vector<pii> best, v;
			
			int x = p1.fi, y = p1.se;			
			
			if(p1.fi == p2.fi){
				if(p1.se < p2.se){
					if(inrange(x-1,y) and !vis[x-1][y] and !vis[x-1][y+1]){
						v = getAugmentingPath(x-1, y, x-1, y+1);
						if(v.size() > best.size()) best = v;
					}
					if(inrange(x+1,y) and !vis[x+1][y] and !vis[x+1][y+1]){
						v = getAugmentingPath(x+1, y, x+1, y+1);
						if(v.size() > best.size()) best = v;
					}
				}
				else{
					if(inrange(x-1,y) and !vis[x-1][y] and !vis[x-1][y-1]){
						v = getAugmentingPath(x-1, y, x-1, y-1);
						if(v.size() > best.size()) best = v;
					}
					if(inrange(x+1,y) and !vis[x+1][y] and !vis[x+1][y-1]){
						v = getAugmentingPath(x+1, y, x+1, y-1);
						if(v.size() > best.size()) best = v;
					}				
				}
			}
			else{
				if(p1.fi < p2.fi){
					if(inrange(x,y-1) and !vis[x][y-1] and !vis[x+1][y-1]){
						v = getAugmentingPath(x, y-1, x+1, y-1);
						if(v.size() > best.size()) best = v;	
					}
					if(inrange(x,y+1) and !vis[x][y+1] and !vis[x+1][y+1]){
						v = getAugmentingPath(x, y+1, x+1, y+1);
						if(v.size() > best.size()) best = v;
					}
				}
				else{
					if(inrange(x,y-1) and !vis[x][y-1] and !vis[x-1][y-1]){
						v = getAugmentingPath(x, y-1, x-1, y-1);
						if(v.size() > best.size()) best = v;
					}
					if(inrange(x,y+1) and !vis[x][y+1] and !vis[x-1][y+1]){
						v = getAugmentingPath(x, y+1, x-1, y+1);
						if(v.size() > best.size()) best = v;
					}
				}
			}
			
			if(best.empty()) continue;
			
			vector<pii> tmp;
			for(int k = 0; k < i; k++){
				tmp.pb(t_ans[k]);
			}
			
			for(int k = 0; k < best.size(); k++){
				tmp.pb(best[k]);
			}
			
			for(int k = i; k < t_ans.size(); k++){
				tmp.pb(t_ans[k]);
			}
			
			for(auto &pt : best){
				vis[pt.fi][pt.se] = 1;
			}
			
			i += best.size();
			t_ans = tmp;
		}
	}
	
////////////////////////////////////////////////////////////////
//	
//	
//	const int PAPPE = 10;
//	int iiith_kutte = PAPPE;
//	
//	for(int i = 1; i < t_ans.size() and iiith_kutte > 0; i++){
//			pii p1 = t_ans[i-1];
//			pii p2 = t_ans[i];
//			
//			vector<pii> best, v;
//			
//			int x = p1.fi, y = p1.se;			
//			
//			if(p1.fi == p2.fi){
//				if(p1.se < p2.se){
//					if(inrange(x-1,y) and !vis[x-1][y] and !vis[x-1][y+1]){
//						v = getAugmentingPath(x-1, y, x-1, y+1);
//						if(v.size() > best.size()) best = v;
//					}
//					if(inrange(x+1,y) and !vis[x+1][y] and !vis[x+1][y+1]){
//						v = getAugmentingPath(x+1, y, x+1, y+1);
//						if(v.size() > best.size()) best = v;
//					}
//				}
//				else{
//					if(inrange(x-1,y) and !vis[x-1][y] and !vis[x-1][y-1]){
//						v = getAugmentingPath(x-1, y, x-1, y-1);
//						if(v.size() > best.size()) best = v;
//					}
//					if(inrange(x+1,y) and !vis[x+1][y] and !vis[x+1][y-1]){
//						v = getAugmentingPath(x+1, y, x+1, y-1);
//						if(v.size() > best.size()) best = v;
//					}				
//				}
//			}
//			else{
//				if(p1.fi < p2.fi){
//					if(inrange(x,y-1) and !vis[x][y-1] and !vis[x+1][y-1]){
//						v = getAugmentingPath(x, y-1, x+1, y-1);
//						if(v.size() > best.size()) best = v;	
//					}
//					if(inrange(x,y+1) and !vis[x][y+1] and !vis[x+1][y+1]){
//						v = getAugmentingPath(x, y+1, x+1, y+1);
//						if(v.size() > best.size()) best = v;
//					}
//				}
//				else{
//					if(inrange(x,y-1) and !vis[x][y-1] and !vis[x-1][y-1]){
//						v = getAugmentingPath(x, y-1, x-1, y-1);
//						if(v.size() > best.size()) best = v;
//					}
//					if(inrange(x,y+1) and !vis[x][y+1] and !vis[x-1][y+1]){
//						v = getAugmentingPath(x, y+1, x-1, y+1);
//						if(v.size() > best.size()) best = v;
//					}
//				}
//			}
//			
//			if(best.empty()) continue;
//			
//			iiith_kutte--;
//			
//			vector<pii> tmp;
//			for(int k = 0; k < i; k++){
//				tmp.pb(t_ans[k]);
//			}
//			
//			for(int k = 0; k < best.size(); k++){
//				tmp.pb(best[k]);
//			}
//			
//			for(int k = i; k < t_ans.size(); k++){
//				tmp.pb(t_ans[k]);
//			}
//			
//			for(auto &pt : best){
//				vis[pt.fi][pt.se] = 1;
//			}
//			
//			i += best.size();
//			t_ans = tmp;
//		}

	
}

int main(){ _
	srand(unsigned(time(0)));
	g_seed = rand();

	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> g[i];
	
	solve();
	
	cout << getString(t_ans) << endl;
	
	return 0;
}

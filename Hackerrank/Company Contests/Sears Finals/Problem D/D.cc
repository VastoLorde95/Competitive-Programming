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

const int N = 110;

int n, m, p, aa;
int g[N][N];

int get(int x1, int y1, int x2, int y2){
	return g[x2][y2] - g[x2][y1-1] - g[x1-1][y2] + g[x1-1][y1-1];
}

vector<pair<pair<pii, pii>, int> > r;

bool cmp(const pair<pair<pii, pii>, int> &p1, const pair<pair<pii, pii>, int> &p2){
	int x1 = p1.fi.fi.fi;
	int y1 = p1.fi.fi.se;
	int x2 = p1.fi.se.fi;
	int y2 = p1.fi.se.se;
	
	int a1 = p1.se;
	
	int x3 = p2.fi.fi.fi;
	int y3 = p2.fi.fi.se;
	int x4 = p2.fi.se.fi;
	int y4 = p2.fi.se.se;
	
	int a2 = p2.se;
	
	if(a1 != a2) return a1 > a2;
	
	if(x1 != x3) return x1 < x3;
	else if(y1 != y3) return y1 < y3;
	else if(x2 != x4) return x2 < x4;
	else return y2 < y4;
}

int main(){ _
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> g[i][j];
		}
	}
	
	cin >> aa;
	cin >> p;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			g[i][j] += g[i][j-1];
		}
	}
	
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			g[i][j] += g[i-1][j];
		}
	}
	
	for(int a = 1; a <= n; a++){
		for(int b = 1; b <= m; b++){
			for(int x = a; x <= n; x++){
				for(int y = b; y <= m; y++){
					int ar = (x-a+1) * (y-b+1);
				
					if(ar < aa) continue;
					
					int cnt = get(a,b,x,y);
					
					if(cnt * 100 >= p * ar){
						r.pb(mp(mp(mp(a,b),mp(x,y)), ar)); 
					}
				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			g[i][j] = 0;
		}
	}

	if(r.empty()){
		return 0;
	}
	
	sort(r.begin(), r.end(), cmp);
	
	vector<pair<pii, pii> > res;
	res.pb(r[0].fi);
	
	foreach(it, res){
		for(int x = it->fi.fi; x <= it->se.fi; x++){
			for(int y = it->fi.se; y <= it->se.se; y++){
				assert(g[x][y] == 0);
				g[x][y] = 1;
			}
		}
	}
	
	for(int i = 1; i < r.size(); i++){
		bool ok = true;
		
		
		int x1 = r[i].fi.fi.fi;
		int y1 = r[i].fi.fi.se;
		int x2 = r[i].fi.se.fi;
		int y2 = r[i].fi.se.se;
		
		for(int a = x1; a <= x2; a++){
			for(int b = y1; b <= y2; b++){
				if(g[a][b] != 0){
					ok = false;
					a = N+1;
					break;
				}
			}
		}
		
		if(!ok) continue;
		
		for(int a = x1; a <= x2; a++){
			for(int b = y1; b <= y2; b++){
				g[a][b] = 1;
			}
		}
		
//		for(int j = 0; j < res.size(); j++){
//			
//			
//			int x3 = res[j].fi.fi;
//			int y3 = res[j].fi.se;
//			int x4 = res[j].se.fi;
//			int y4 = res[j].se.se;
//			
//			for(int a = x1; a <= x2; a++){
//				for(int b = y1; b <= y2; b++){
//					if(g[a][b] != 0){
//						ok = false;
//						a = N+1;
//						break;
//					}
//				}
//			}
//			
////			if(x3 <= x1 and x1 <= x4 and y3 <= y1 and y1 <= y4) ok = false;
////			if(x3 <= x2 and x2 <= x4 and y3 <= y2 and y2 <= y4) ok = false;
////			if(x3 <= x1 and x1 <= x4 and y3 <= y2 and y2 <= y4) ok = false;
////			if(x3 <= x2 and x2 <= x4 and y3 <= y1 and y1 <= y4) ok = false;
////			
////			if(x1 <= x3 and x3 <= x2 and y1 <= y3 and y3 <= y2) ok = false;
////			if(x1 <= x4 and x4 <= x2 and y1 <= y4 and y4 <= y2) ok = false;
////			if(x1 <= x3 and x3 <= x2 and y1 <= y4 and y4 <= y2) ok = false;
////			if(x1 <= x4 and x4 <= x2 and y1 <= y3 and y3 <= y2) ok = false;
//			

//			if(!ok) break;			
//			
//		}
		
		if(ok) res.pb(r[i].fi);
	}

//	foreach(it, res){
//		for(int x = it->fi.fi; x < it->se.fi; x++){
//			for(int y = it->fi.se; y < it->se.se; y++){
//				assert(g[x][y] == 0);
//				g[x][y] = 1;
//			}
//		}
//	}

	foreach(it, res){
		cout << it->fi.fi <<  ' ' << it->fi.se << ' ' << it->se.fi << ' ' << it->se.se << endl;
	}
	
	return 0;
}

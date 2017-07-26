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
const ll INF = 1ll << 40;

ll e[N];
ll s[N];
ll dis[N][N];
ld mtime[N][N];

void solve(){
	int n, q;
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++){
		cin >> e[i] >> s[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> dis[i][j];
			if(dis[i][j] == -1) dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dis[i][j] <= e[i]){
				mtime[i][j] = (ld) dis[i][j] / (ld) s[i];
			}
			else{
				mtime[i][j] = INF;
			}
		}
		mtime[i][i] = 0;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				mtime[i][j] = min(mtime[i][j], mtime[i][k] + mtime[k][j]);
			}
		}
	}
	
	for(int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		assert(mtime[x][y] < INF);
		cout << fixed << setprecision(12) << mtime[x][y] << ' ';
	}
	cout << endl;
	
}

int main(){ _
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}

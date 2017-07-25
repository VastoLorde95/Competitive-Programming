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

int n, m;

int r[N];
int c[N];
int g[N][N];

int rf[N];
int cf[N];

void fliprow(int x){
	rf[x] ^= 1;
	
	r[x] = -r[x];
	for(int i = 1; i <= m; i++){
		c[i] -= g[x][i] * 2;
		g[x][i] = -g[x][i];
	}
}

void flipcol(int x){
	cf[x] ^= 1;
	
	c[x] = -c[x];
	for(int i = 1; i <= n; i++){
		r[i] -= g[i][x] * 2;
		g[i][x] = -g[i][x];
	}
}

int main(){ _
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> g[i][j];
			r[i] += g[i][j];
			c[j] += g[i][j];
		}
	}
	
	while(true){
		int id = 0;
		for(int i = 1; i <= n; i++){
			if(r[i] < 0){
				id = i;
				break;
			}
		}
		
		if(id){
			fliprow(id); 
			continue;
		}
		
		for(int i = 1; i <= m; i++){
			if(c[i] < 0){
				id = i;
				break;
			}
		}
		
		if(id){
			flipcol(id);
			continue;
		}
		
		break;
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += rf[i];
	}
	
	cout << cnt << ' ';
	for(int i = 1; i <= n; i++){
		if(rf[i]) cout << i << ' ';
	}
	cout << endl;
	
	cnt = 0;
	for(int i = 1; i <= m; i++){
		cnt += cf[i];
	}
	
	cout << cnt << ' ';
	for(int i = 1; i <= m; i++){
		if(cf[i]) cout << i << ' ';
	}
	cout << endl;
	
	return 0;
}

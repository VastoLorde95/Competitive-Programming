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

const int N = 300100;
const int M = 26;

int n;

vector<pii> gr[N];
int trie[N][M];
int ttrie[N][M];
int ok[N][M];
int sz[N];
int h[N];
int ans[N];

int mxh = 0;

void dfs(int x, int p){
	h[x] = p;
	sz[x] = 1;
	
	mxh = max(mxh, p);
	
	for(int i = 0; i < M; i++){
		if(!trie[x][i]) continue;
		dfs(trie[x][i], p+1);
		sz[x] += sz[trie[x][i]];
	}
}

int stamp;
void merge(int x, int y, int dep){
	ans[dep]++;
	
	for(int i = 0; i < M; i++){
		if(!trie[y][i]) continue;
		if(trie[x][i]){
			merge(trie[x][i], trie[y][i], dep);
		}
		else if(ok[x][i] == stamp){
			merge(ttrie[x][i], trie[y][i], dep);
		}
		else{
			ok[x][i] = stamp;
			ttrie[x][i] = trie[y][i];
		}
	}
}


void get(int x){
	vector<int> gc[M];
	
	for(auto i : gr[x]){
		get(i.fi);
		ans[h[x]+1]++;
		
		for(auto j : gr[i.fi]){
			gc[j.se].pb(j.fi);
		}
	}

	for(int k = 0; k < M; k++){
		if(gc[k].empty()) continue;
		
		for(int i = gc[k].size() - 1; i > 0; i--){
			if(sz[gc[k][i]] > sz[gc[k][i-1]]){
				swap(gc[k][i], gc[k][i-1]);
			}
		}
		
		++stamp;	
		for(int i = 1; i < gc[k].size(); i++){
			merge(gc[k][0], gc[k][i], h[x]+1);
		}
	}	
	
}

int main(){ _
	int n;
	cin >> n;
	
	for(int i = 1; i < n; i++){
		int a, b; char c;
		cin >> a >> b >> c;
		trie[a][c-'a'] = b;
		gr[a].pb(mp(b,c-'a'));
	}
	
	dfs(1, 0);
	get(1);
	
	int mx = 0, pos = -1;
	for(int i = 1; i <= mxh; i++){
		if(ans[i] > mx){
			mx = ans[i];
			pos = i;
		}
	}
	
	cout << n-mx << endl << pos << endl;
	
	return 0;
}

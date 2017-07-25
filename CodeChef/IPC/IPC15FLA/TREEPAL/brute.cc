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

int lps(string &s){
	int n = s.length();
	int dp[n][n];
	
	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
	}
	
	for(int i = 1; i < n; i++){
		dp[i-1][i] = (s[i] == s[i-1]);
	}

	for(int l = 3; l <= n; l++){
		for(int i = 0; i + l - 1 < n; i++){
			if(dp[i+1][i+l-2] and s[i] == s[i+l-1]) dp[i][i+l-1] = 1;
			else dp[i][i+l-1] = 0;
		}
	}
	
	int mx = 1;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(dp[i][j]) mx = max(mx, j-i+1);
		}
	}
	
	return mx;
	
}

vector<int> g[N];
char str[N];

ll ans;

void dfs(int x, int p, string s){
	s += str[x-1];
	
	ans += lps(s);
	
	foreach(it, g[x]){
		if(*it == p) continue;
		dfs(*it, x, s);
	}
		
}

int main(){
	int n;	
	sd(n);
	scanf("%s", str);
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	string cur;
	
	dfs(1, 1, cur);
	
	cout << ans << endl;
	
	return 0;
}

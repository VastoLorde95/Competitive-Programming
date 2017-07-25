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

const ll MOD = 1e9 + 7;
const int N = 100100;

vector<int> g[N];
ll dp[N][2][2];
int n;

void dfs(int x, int p){
	
	bool leaf = true;
	
	vector<int> ch;
	
	foreach(it, g[x]){
		if(*it == p) continue;
		
		leaf = false;
		ch.pb(*it);
		dfs(*it, x);
	}
	
	if(leaf) dp[x][0][1] = dp[x][1][1] = 1;
	else{
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) dp[x][i][j] = 1;
	
		ll sub1 = 1, sub2 = 1;
	
		for(int j = 0; j < ch.size(); j++){
			int y = ch[j];
			
			dp[x][0][0] *= (dp[y][0][0] + dp[y][0][1] + dp[y][1][0]) % MOD;
			dp[x][0][0] %= MOD;
	
			sub1 *= (dp[y][1][0]);
			sub1 %= MOD;
			
			dp[x][1][0] *= (dp[y][0][0] + dp[y][1][0] + dp[y][1][1]) % MOD;
			dp[x][1][0] %= MOD;
			
			sub2 *= (dp[y][0][0]);
			sub2 %= MOD;
			
			dp[x][0][1] *= (dp[y][1][0]);
			dp[x][0][1] %= MOD;
			
			dp[x][1][1] *= (dp[y][0][0]);
			dp[x][1][1] %= MOD;
			
		}
		
		dp[x][0][0] -= sub1 - MOD;
		dp[x][0][0] %= MOD;
		
		dp[x][1][0] -= sub2 - MOD;
		dp[x][1][0] %= MOD;
	}
}

int main(){ _
	cin >> n;
	
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(1, -1);

	cout << (dp[1][0][0] + dp[1][1][0]) % MOD << endl;
	
	return 0;
}

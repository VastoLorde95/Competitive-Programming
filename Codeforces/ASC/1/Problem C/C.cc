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
#define __ freopen("grant.in","r",stdin);freopen("grant.out","w",stdout);

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

const int N = 500100;
const int inf = 1e9;

vector<int> g[N];

int dp[N][2];
int nxt[N];
vector<int> v;

void dfs(int cur){
	if(!g[cur].empty()) dp[cur][1] = 1;
	
	foreach(it, g[cur]){
		dfs(*it);
		dp[cur][0] += max(dp[*it][0], dp[*it][1]);
		dp[cur][1] += max(dp[*it][0], dp[*it][1]);
	}
	
	int mx = 0, id = -1, t = -1;
	foreach(it, g[cur]){
		int y = *it;
		if(dp[y][0] >= dp[y][1]){
			mx = dp[cur][1];
			nxt[cur] = y;
			return;
		}
		else{
			int nmx = dp[cur][1] - dp[y][1] + dp[y][0];
			if(mx < nmx){
				mx = nmx;
				id = y;
			}
		}
	}
	
	dp[cur][1] = mx;
	nxt[cur] = id;
}

void dfs2(int cur, int t){
	if(t == 1){
		if(dp[cur][1] > dp[cur][0]){
			v.pb(nxt[cur]);
			foreach(it, g[cur]){
				if(*it != nxt[cur])
					dfs2(*it, 1);
				else
					dfs2(*it, 0);
			}
		}
		else{
			foreach(it, g[cur]){
				dfs2(*it, 1);
			}
		}
	}
	else{
		foreach(it, g[cur]){
			dfs2(*it, 1);
		}
	}
	
}

int main(){ __
	int n; sd(n);
	
	for(int i = 2; i <= n; i++){
		int p; sd(p);
		g[p].pb(i);
	}
	
	dfs(1);
	printf("%d\n", max(dp[1][0], dp[1][1]) * 1000);
	dfs2(1,1);
	
	assert(v.size() == max(dp[1][0], dp[1][1]));
	
	sort(v.begin(), v.end());
	foreach(it, v) printf("%d ", *it); puts("");
	
	return 0;
}

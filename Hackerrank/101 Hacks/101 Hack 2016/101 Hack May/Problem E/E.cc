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

int n, m;
set<int> g[N];

int c[N];
int sz[N];
int col;

void dfs(int cur, int prev){
	stack<pii> s;
	s.push(mp(cur,prev));
	while(!s.empty()){
		cur = s.top().fi, prev = s.top().se;
		s.pop();
		
		c[cur] = col;
		++sz[col];
		
		foreach(it, g[cur]){
			if(*it == prev) continue;
			s.push(mp(*it, cur));
		}
	}
}

bool dfs2(int cur, int prev, int &rem){
	if(--rem < 0) return false;
	
	foreach(it, g[cur]){
		if(*it == prev) continue;
		if(!dfs2(*it, cur, rem))
			return false;
	}
	return true;
}

int getSmallest(int u, int v){
	int k = 1;
	while(true){
		int jump1 = k, jump2 = k;
		
		dfs2(u, -1, jump1);
		dfs2(v, -1, jump2);
		
		if(jump1 == -1 and jump2 == -1) k <<= 1;
		else{
			if(jump1 >= jump2)
				return u;
			return v;
		}
	}
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		int u, v;
		sd2(u,v);
		g[u].insert(v);
		g[v].insert(u);
	}

	dfs(1, -1);
	col++;
	
	sd(m);
	int ans = 0, x;
	while(m--){
		sd(x);
		x ^= ans;

		ans = sz[c[x]];

		set<int> gg = g[x];
		
		foreach(it, gg){
			int y = *it;

			g[y].erase(x);
			g[x].erase(y);

			int rem = getSmallest(x,y);
			
			dfs(rem, -1);
			col++;

			if(rem == x)
				sz[c[y]] -= sz[c[x]];
			else
				sz[c[x]] -= sz[c[y]];
		}
		printf("%d\n", ans);
	}

	return 0;
}

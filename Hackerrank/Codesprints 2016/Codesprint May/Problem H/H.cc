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

const int N = 100100;

int n;
int c[N];
int ptr[N], sz[N];

ll d[N];
ll dx[N];

map<int, int> cnt[N];

int store[N];

vector<int> g[N];

int oldptr[N];
int old1[N];
int old2[N];

bool comp(const int &x, const int &y){
	return cnt[ptr[x]].size() > cnt[ptr[y]].size();
}

void merge(map<int, int> &m1, map<int, int> &m2){
	foreach(it, m2) m1[it->fi] += it->se;
	m2.clear();
}

int vis[N];
stack<pii> st;
void dfs(int start){
	st.push(mp(start,-1));
	while(!st.empty()){
		int cur = st.top().fi, prev = st.top().se;
		if(vis[cur]){
			st.pop();
			
			sz[cur] = 1;
			ptr[cur] = cur;
			d[cur] = 1;
			
			vector<int> v;
			int col = c[cur];
	
			foreach(it, g[cur]){
				int nxt = *it;
				if(nxt == prev) continue;
		
				sz[cur] += sz[nxt];
				dx[nxt] = d[nxt] + sz[nxt] - cnt[ptr[nxt]][col];
				d[cur] += dx[nxt];
				store[nxt] = cnt[ptr[nxt]][c[cur]];
		
				v.pb(nxt);
			}
	
			sort(v.begin(), v.end(), comp);
			while(v.size() > 1){
				merge(cnt[ptr[v[0]]], cnt[ptr[v.back()]]);
				v.pop_back();
			}
	
			if(!v.empty()) ptr[cur] = ptr[v[0]];
			v.clear();
	
			cnt[ptr[cur]][c[cur]] = sz[cur];
			
		}
		else{
			vis[cur] = 1;
			foreach(it, g[cur]){
				if(*it == prev) continue;
				st.push(mp(*it, cur));
			}
		}
	}
}

void dfs2(int start){
	st.push(mp(start,-1));
	for(int i = 1; i <= n; i++) vis[i] = 0;
	
	while(!st.empty()){
		int cur = st.top().fi, prev = st.top().se;
		if(vis[cur]){
			st.pop();
			cnt[ptr[cur]][c[cur]] = old2[cur];
			cnt[ptr[cur]][c[prev]] = old1[cur];
			ptr[cur] = oldptr[cur];
		}
		else{
			vis[cur] = 1;
			if(prev == -1){
				foreach(it, g[cur]) st.push(mp(*it, cur));
				continue;
			}
			
			d[cur] += d[prev] - dx[cur] + (n - sz[cur] - (cnt[ptr[prev]][c[cur]] - sz[cur]));
		
			oldptr[cur] = ptr[cur];
			ptr[cur] = ptr[prev];
		
			old1[cur] = cnt[ptr[cur]][c[prev]];
			old2[cur] = cnt[ptr[cur]][c[cur]];
		
			if(c[prev] != c[cur]){
				cnt[ptr[cur]][c[prev]] -= sz[cur] - store[cur];
				cnt[ptr[cur]][c[cur]] = n;
			}
		
			foreach(it, g[cur]){
				if(*it == prev) continue;
				st.push(mp(*it, cur));
			}
		}
	}
}

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		sd(c[i]);
	}

	for(int i = 1; i < n; i++){
		int a, b;
		sd2(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(1);
	dfs2(1);
	
	for(int i = 1; i <= n; i++){
		printf("%lld\n", d[i]);
	}
	
	return 0;
}

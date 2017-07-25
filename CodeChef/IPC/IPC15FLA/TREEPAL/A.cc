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

typedef unsigned long long ull;

const int LOGN = 17;
const int N = 1 << LOGN;
const int M = 26;

int pr[LOGN][N], lvl[N];

int getAncestorAtH(int x, int h){
	if(lvl[x] == h) return x;
	
	int del = lvl[x] - h, tmp = 0;
	while((1 << tmp) <= del) tmp++;
	tmp--;
	
	while(true){
		if(lvl[x] == h) return x;
		
		if(lvl[pr[tmp][x]] >= h) x = pr[tmp][x];
		tmp--;
	}
}

struct node {
	int next[26];
	int len, sufflink, num;
	node(){
		for(int i = 0; i < M; i++) next[i] = 0;
	}
};

node tree[N]; 
int num; 			// node 1 - root with len -1, node 2 - root with len 0
int suff; 			// max suffix palindrome

char str[N];

void initialize(){
	for(int i = 1; i < N; i++){
		tree[i] = node();
	}
	
	num = 2, suff = 2;
	tree[1].len = -1; tree[1].sufflink = 1;
	tree[2].len = 0; tree[2].sufflink = 1;
	
}

int best[N];

bool addLetter(int pos, char cc, int nd) {
	int cur = suff, curlen = 0, let = cc-'a';

//	tr(pos, cc, nd, tree[1].next[);

	while(true){
		curlen = tree[cur].len;
//		tr(curlen);
		if (pos - 1 - curlen >= 0){
			int anc = getAncestorAtH(nd, pos - (1 + curlen));
//			tr(anc, str[anc-1], cc);
			if(str[anc-1] == cc) break;
		}
		cur = tree[cur].sufflink;
	}	
	
//	tr("ok");
	
	if(tree[cur].next[let]){
//		tr("ok", cur);
		suff = tree[cur].next[let];
		return false;
	}
	
//	tr("ok");

	suff = ++num;
	tree[num].len = tree[cur].len + 2;
//	tr(tree[num].len, num, suff, tree[suff].len);
	
	tree[cur].next[let] = num;

//	tr(tree[num].len, num, suff, tree[suff].len);

	if(tree[num].len == 1){
		tree[num].sufflink = 2, tree[num].num = 1;
		return true;
	}

	while(true){
		cur = tree[cur].sufflink, curlen = tree[cur].len;
		if (pos - 1 - curlen >= 0){
			int anc = getAncestorAtH(nd, pos - (1 + curlen));
			if(str[anc-1] == cc){
				tree[num].sufflink = tree[cur].next[let];
				break;
			}
		}
	}           

	tree[num].num = 1 + tree[tree[num].sufflink].num;

	return true;
}

int n;
vector<int> g[N];

int treeState[N];

void dfs1(int x, int p){
	pr[0][x] = p;
	foreach(it, g[x]){
		if(*it == p) continue;
		
		lvl[*it] = lvl[x] + 1;
		dfs1(*it, x);
	}
}

void dfs(int x, int p, int d, int cur_best){
//	tr(x, suff, p, d, cur_best);
	addLetter(d, str[x-1], x);
	treeState[x] = suff;
	best[x] = max(tree[suff].len, cur_best);

//	tr(x, p, best[x], treeState[x]);
	
	foreach(it, g[x]){
		if(*it == p) continue;
		suff = treeState[x];
		dfs(*it, x, d+1, best[x]);
	}
}

int main(){
	sd(n);
	scanf("%s", str);
	
	for(int i = 1; i < n; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs1(1, 1);
	
	for(int i = 1; i < LOGN; i++){
		for(int j = 1; j <= n; j++){
			pr[i][j] = pr[i-1][pr[i-1][j]];
		}
	}

	initialize();

	dfs(1, 1, 0, 0);
	
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += best[i];
	}
	
	printf("%lld\n", ans);
		

	return 0;
}

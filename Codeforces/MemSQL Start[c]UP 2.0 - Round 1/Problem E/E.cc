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

const int N = 300100;
const int M = 29;
const ll MOD = 1e9 + 7;

ll res[N];
int vis[2*N];

struct suffixAutomaton{
	struct state{
		int len;
		int link;
		int next[M];
		ll endpos_size;
		bool terminal;	// by default, empty string is a suffix
		ll ways[4];
		
		state(){
			len         =  0;
			link        = -1;
			endpos_size =  0;
			terminal    =  false;
			for(int i = 0; i < M; i++) next[i] = -1;
			memset(ways, 0, sizeof ways);
		}
	
		ll prod(){
			return (ways[1] * (ways[2] * ways[3]) % MOD) % MOD;
		}	
	};
	
	state st[N*2];
	int sz, last, l;
	char offset = 'a';	// Careful!

	suffixAutomaton(string &s){
		int l = s.length();
			
		for(int i = 0; i < 2*l; i++) st[i] = state();
	
		sz         =  1;
		last       =  0;
		st[0].len  =  0;
		st[0].link = -1;
		
		for(int i = 0; i < l; i++)
			addChar(s[i] - offset);
		
		for(int i = last; i != -1; i = st[i].link)
			st[i].terminal = true;
	}
	
	void addChar(int c){
		int cur = sz++; assert(cur < N*2);
		st[cur].len = st[last].len + 1;
		st[cur].endpos_size = 1;
		
		int p = last;
		while(p != -1 and st[p].next[c] == -1){
			st[p].next[c] = cur;
			p = st[p].link;
		}
		
		last = cur;
		
		if(p == -1){
			st[cur].link = 0; return;
		}
		
		int q = st[p].next[c];
		
		if(st[q].len == st[p].len + 1){
			st[cur].link = q; return;
		}
		
		int clone = sz++;
		
		for(int i = 0; i < M; i++)
			st[clone].next[i] = st[q].next[i];
		st[clone].link        = st[q].link;
		st[clone].len         = st[p].len + 1;
		st[clone].endpos_size = 0;
		
		while(p != -1 and st[p].next[c] == q){
			st[p].next[c] = clone;
			p = st[p].link;
		}
		
		st[q].link = st[cur].link = clone;
		
		return;
	}

	void add(ll &x, ll y){
		x += y;
		if(x >= MOD) x -= MOD;
	}
	
	void dfs(int cur){
		if(vis[cur]) return;
		vis[cur] = 1;
		
		for(int i = 0; i < M; i++){
			int nxt = st[cur].next[i];
			if(nxt == -1) continue;
			
			if(i >= 26){
				int j = i - 25;
				st[cur].ways[j] = 1;
			}
			
			dfs(nxt);
		}
	}
	
	vector<pii> g[2*N];
	int indeg[2*N];
	queue<int> q;
	
	void compute(){
		dfs(0);
		
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < M; j++){
				int nxt = st[i].next[j];
				if(nxt == -1) continue;
				g[nxt].pb(mp(i,j));
				indeg[i]++;
			}
		}
		
		for(int i = 0; i < sz; i++) if(!indeg[i]) q.push(i);
		
		while(!q.empty()){
			int cur = q.front(); q.pop();
			foreach(it, g[cur]){
				int x = it->fi, y = it->se;
				if(y < 26){
					add(st[x].ways[1], st[cur].ways[1]);
					add(st[x].ways[2], st[cur].ways[2]);
					add(st[x].ways[3], st[cur].ways[3]);
				}
				if(--indeg[x] == 0) q.push(x);
			}	
		}
		
		for(int i = 1; i < sz; i++){
			int l1 = st[i].len;
			int l2 = st[st[i].link].len;
			
			ll p = st[i].prod();
			add(res[l1], p);
			add(res[l2], (MOD - p) % MOD);
		}
	}
	
};

string s1, s2, s3;

int main(){ _
	cin >> s1 >> s2 >> s3;
	
	string s = s1 + '{' + s2  +  '|' + s3 + '}';
	
	suffixAutomaton *suf = new suffixAutomaton(s);
	suf->compute();
	
	int l = min(s1.length(), min(s2.length(), s3.length()));
	
	for(int i = l; i > 0; i--)
		suf->add(res[i-1], res[i]);
	
	for(int i = 1; i <= l; i++) cout << res[i] << ' '; cout << endl;
	
	return 0;
}

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

const int N = 100100;
const int M = 26;

struct suffixAutomaton{
	struct state{
		int len;		// length of longest string in this class
		int link;		// pointer to suffix link
		int link_char;
		int next[M]; 	// adjacency list
		ll ways[M];
		ll cnt;			// number of times the strings in this state occur in the original string
		
		bool terminal;	// by default, empty string is a suffix
						// a state is terminal if it corresponds to a suffix
		
		state(){
			len = 0, link = -1, cnt = 0;
			terminal = false;
			for(int i = 0; i < M; i++) next[i] = -1, ways[i] = 0;
		}
	};
	
	state st[N*2];
	int sz, last, l;
	char offset = 'a';	// Careful!

	ll vis[N*2];

	suffixAutomaton(string &s){
		int l = s.length();
		
		for(int i = 0; i < 2*l; i++) st[i] = state();

		sz = 1, last = 0;
		st[0].len = 0;
		st[0].link = -1;
		
		for(int i = 0; i < l; i++)
			addChar(s[i] - offset);
		
		for(int i = last; i != -1; i = st[i].link) st[i].terminal = true;
	}
	
	void addChar(int c){
		int cur = sz++; assert(cur < N*2);
		st[cur].len = st[last].len + 1;
		st[cur].cnt = 1;
		st[cur].link_char = c;

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
			st[cur].link = q;
			return;
		}
		
		int clone = sz++;
		
		for(int i = 0; i < M; i++) st[clone].next[i] = st[q].next[i];
		st[clone].link = st[q].link;
		st[clone].len = st[p].len + 1;
		st[clone].cnt = 0;				// cloned states initially have cnt = 0
		
		while(p != -1 and st[p].next[c] == q){
			st[p].next[c] = clone;
			p = st[p].link;
		}
		
		st[q].link = st[cur].link = clone;
		
		return;
	}
	
	ll dfs(int cur){
		if(vis[cur]) return vis[cur];
		vis[cur] = 1;
		for(int j = 0; j < M; j++){
			if(st[cur].next[j] == -1) continue;
			st[cur].ways[j] += dfs(st[cur].next[j]);
			vis[cur] += st[cur].ways[j];
		}
		return vis[cur];
	}
	
	void numberOfOccPreprocess(){
		dfs(0);
	}
		
	void query(int k){
		int cur = 0;
		string res;
		
		while(k > 0){
			ll cnt = 0;
			
			for(int j = 0; j < M; j++){
				if(st[cur].ways[j] + cnt < k){
					cnt += st[cur].ways[j];
				}
				else{
					k -= cnt;
					res += (char)('a' + j);
					cur = st[cur].next[j];
					break;
				}
			}
			
			k--;
		}
		cout << res << '\n';
	}
	
};

int main(){ _
	string s;
	cin >> s;
	suffixAutomaton *suf = new suffixAutomaton(s);
	suf->numberOfOccPreprocess();
	
	int q, k;
	cin >> q;
	while(q--){
		cin >> k;
		suf->query(k);
	}

	return 0;
}

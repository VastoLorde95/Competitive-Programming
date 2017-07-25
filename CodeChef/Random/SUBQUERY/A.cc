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

const int L = 500100;
const int N = 200100;
const int M = 26;

vector<pii> events[L];

struct suffixAutomaton{
	struct state{
		int len, link;
		int next[M];
		ll endpos_size;
		
		bool terminal;	// by default, empty string is a suffix
		
		state(){
			len = 0, link = -1, endpos_size = 0;
			terminal = false;
			for(int i = 0; i < M; i++) next[i] = -1;
		}
	};
	
	state st[N*2];
	int sz, last, l;
	char offset = 'a';	// Careful!

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
		
		for(int i = 0; i < M; i++) st[clone].next[i] = st[q].next[i];
		st[clone].link = st[q].link;
		st[clone].len = st[p].len + 1;
		st[clone].endpos_size = 0;
		
		while(p != -1 and st[p].next[c] == q){
			st[p].next[c] = clone;
			p = st[p].link;
		}
		
		st[q].link = st[cur].link = clone;
		
		return;
	}
	
	bool contains(string &t){
		int cur = 0;
		for(int i = 0; i < t.length(); i++){
			cur = st[cur].next[t[i] - offset];
			if(cur == -1) return false;
		}
		return true;
	}
	
	// alternatively, compute the number of paths in a DAG
	// since each substring corresponds to one unique path in SA
	ll numberOfSubstrings(){
		ll res = 0;
		for(int i = 1; i < sz; i++) res += st[i].len - st[st[i].link].len;
		return res;
	}
	
	void numberOfOccPreprocess(){
		vector<pii> v;
		for(int i = 1; i < sz; i++) v.pb(mp(st[i].len, i));
		
		sort(v.begin(), v.end(), greater<pii>());
		
		for(int i = 0; i < sz-1; i++){
			int suf = st[v[i].se].link;
			st[suf].endpos_size += st[v[i].se].endpos_size;
		}

		for(int i = 1; i < sz; i++){
			int x = st[i].len + 1;
			int y = st[st[i].link].len + 1;
			events[st[i].endpos_size].pb(mp(y, 0));
			events[st[i].endpos_size].pb(mp(x, 1));
		}
	}	
		
	ll numberOfOcc(string &t){
		int cur = 0;
		for(int i = 0; i < t.length(); i++){
			cur = st[cur].next[t[i] - offset];
			if(cur == -1) return 0;
		}
		
		return st[cur].endpos_size;
	}
	
	
};

string s;

map<pii, ll> ans;

vector<pii> q;

int main(){ _
	cin >> s;
	int n;
	cin >> n;
	
	suffixAutomaton *suf = new suffixAutomaton(s);
	suf->numberOfOccPreprocess();
	
	int li, pi, mx = 0, mn = 1e9;
	for(int i = 0; i < n; i++){
		cin >> li >> pi;
		mx = max(mx, pi);
		mn = min(mn, pi);
		events[pi].pb(mp(li,2));
		
		q.pb(mp(li,pi));
	}

	for(int i = mn; i <= mx; i++){
		sort(events[i].begin(), events[i].end());
		
		int cnt = 0;
		foreach(it, events[i]){
			if(it->se == 0) cnt++;
			else if(it->se == 1) cnt--;
			else ans[mp(it->fi, i)] = cnt;
		}
	}
	
	foreach(it, q){
		cout << ans[*it] << '\n';
	}
	
	return 0;
}

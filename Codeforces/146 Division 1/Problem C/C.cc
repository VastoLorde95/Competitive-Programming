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

const int N = 1001000;
const int M = 26;

struct suffixAutomaton{
	struct state{
		int len, link;
		int next[M];
		ll cnt;
		
		bool terminal;	// by default, empty string is a suffix
		
		state(){
			len = 0, link = -1, cnt = 0;
			terminal = false;
			for(int i = 0; i < M; i++) next[i] = -1;
		}
	};
	
	state st[N*2];
	int sz, last;
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
		st[cur].cnt = 1;

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
		st[clone].cnt = 0;
		
		while(p != -1 and st[p].next[c] == q){
			st[p].next[c] = clone;
			p = st[p].link;
		}
		
		st[q].link = st[cur].link = clone;
		
		return;
	}
	
	ll h[2*N], p[2*N];
	ll base = 29, pr = 1e9 + 7;
	unordered_set<ll> done;
	
	void numberOfOccPreprocess(){
		vector<pii> v;
		for(int i = 1; i < sz; i++) v.pb(mp(st[i].len, i));
		
		sort(v.begin(), v.end(), greater<pii>());
		
		for(int i = 0; i < sz-1; i++){
			int suf = st[v[i].se].link;
			st[suf].cnt += st[v[i].se].cnt;
		}
		
		p[0] = 1;
		for(int i = 1; i < 2*N; i++)
			p[i] = (p[i-1] * base) % pr;
	}	
		
	ll numberOfOcc(string &t){
		ll res = 0;
		int l = 0, m = t.length();
		done.clear();
		
		string tmp = t+t;
		h[0] = 0;
		for(int i = 1; i <= 2*m; i++)
			h[i] = ((h[i-1] * base) + (tmp[i-1] - offset + 1)) % pr;

		int cur = 0, nxt;
		for(int i = 0; i < 2*m - 1; i++){
			while(cur != 0 and st[cur].next[tmp[i] - offset] == -1){
				cur = st[cur].link;
				l = st[cur].len;
			}
			
			nxt = st[cur].next[tmp[i] - offset];
			if(nxt == -1) nxt = 0, l = 0;
			else l++;
			
			cur = nxt;
			
			if(l > m){
				if(l-1 == st[st[cur].link].len) cur = st[cur].link;
				l--;
			}
			
			if(l == m){
				ll v1 = h[i+1];
				ll v2 = (h[i+1-m] * p[m]) % pr;
				v1 = (v1 - v2 + pr) % pr;
				if(!done.count(v1)){
					res += st[cur].cnt;
					done.insert(v1);
				}
			}
		}
		
		return res;	
	}
	
};

string s;
string t;

int main(){ _
	cin >> s;
	suffixAutomaton *suf = new suffixAutomaton(s); 
	suf->numberOfOccPreprocess();
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		cout << suf->numberOfOcc(t) << '\n';
	}

	return 0;
}

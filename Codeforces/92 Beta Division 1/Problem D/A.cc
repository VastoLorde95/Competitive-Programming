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
const int M = 26;

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
	
	ll numberOfOccPreprocess(){
		vector<pii> v;
		for(int i = 1; i < sz; i++) v.pb(mp(st[i].len, i));
		
		sort(v.begin(), v.end(), greater<pii>());
		
		for(int i = 0; i < sz-1; i++){
			int suf = st[v[i].se].link;
			st[suf].endpos_size += st[v[i].se].endpos_size;
		}
		
		ll res = 0;
		for(int i = 1; i < sz; i++){
			ll t1 = st[i].len - st[st[i].link].len;
			ll t2 = st[i].endpos_size;
			t2 = (t2 * (t2+1))/2;
			res += t2 * t1;
		}
		
		return res;
		
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

int main(){ _
	string s;
	cin >> s;
	
	suffixAutomaton *sa = new suffixAutomaton(s);
	
	cout << sa->numberOfOccPreprocess() << endl;
	
	return 0;
}

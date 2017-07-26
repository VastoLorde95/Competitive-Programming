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

/*
Suffix Automaton

All substrings can be distributed into equivalence classes on the basis of their endpos sets

Let u and w be two substrings

WLOG len(u) <= len(w)

if u is a suffix of w then endpos(w) is a subset of enpos(u)
otherwise the intersection of the two sets is null

Any endpos equivalence class contains a set of strings that are consecutive suffixes of each other

suffix link of any state is the longest suffix of a string that does not belong in the same equivalence
class as itself

=> endpos(v) is a subset of endpos(link(v))

minlen(v) = len(link(v)) + 1

For each substring, there exists a unique path from the start state to its equivalence class in the DAG

You can also find

1. Lexicogaphically K'th substring
=> Use greedy approach while traversing the DAG

2. Smallest cyclic shift
=> Construct automaton for the string S+S. Then the lexicographically shortest path of length |S| will give the answer

3. Position of first occurence of a pattern
=> Maintain pointers in each state that tell the index in the string where this pattern ends first

4. Shortest string not present in S
=> Use dynamic programming dp[i] => length of shortest string starting from state i that is not present in S
dp[u] = 1 + min(dp[v])

answer is dp[t0]

5. Longest common substring of two strings in O(|S| + |T|) time
=> Build automaton over one string and cleverly traverse the DAG w.r.t T and do book-keeping

6. Longest common substring of k strings in O(\sum |S_i| * K) time
=> Construct S1 D1 S2 D2 ... Sk Dk s.t all Di are unique characters

Do a dfs and maintain for each state if it is possible to reach Dj and no other D_i on the way for all j
The answer will be the longest string which belongs to a state from which you can reach all Dj

*/

const int N = 100100;
const int M = 26;

struct suffixAutomaton{
	struct state{
		int len;		// length of longest string in this class
		int link;		// pointer to suffix link
		int next[M]; 	// adjacency list
		ll cnt;			// number of times the strings in this state occur in the original string
		
		bool terminal;	// by default, empty string is a suffix
						// a state is terminal if it corresponds to a suffix
		
		state(){
			len = 0, link = -1, cnt = 0;
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
		st[clone].cnt = 0;				// cloned states initially have cnt = 0
		
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
			st[suf].cnt += st[v[i].se].cnt;
		}	
	}	
		
	ll numberOfOcc(string &t){
		int cur = 0;
		for(int i = 0; i < t.length(); i++){
			cur = st[cur].next[t[i] - offset];
			if(cur == -1) return 0;
		}
		
		return st[cur].cnt;
	}
};

int main(){
	return 0;
}

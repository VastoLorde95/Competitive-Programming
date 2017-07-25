#include<stack>
#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


namespace PalindromicTree {
    struct Node {
	int len;
	int pos;
	LL cnt, al;
	Node *suffix;
	map<char, Node*> next;
	vector<Node*> ch;
	Node(int l=0) : len(l) {
	    pos = 0; cnt = 0;
	    al = 0;
	    suffix = NULL;
	}
    };
    const int MAXN = 1000111;
    Node node[MAXN];
    int node_i = 0;
    Node *root0, *rootm, *suffix;
    string s;
    Node *new_node(int pos=-1, int cnt=0) {
	Node *r = &node[node_i++];
	*r = Node();
	r->pos = pos; r->cnt = cnt;
	return r;
    }
    struct ORDER {
	const string &s;
	ORDER(string &s_) : s(s_) {}
	bool operator()(const Node *x, const Node *y) const {
	    if (x == y || x->pos == y->pos) return false;
	    int a = x->pos - x->len + 1;
	    int b = y->pos - y->len + 1;
	    REP (i, 100111) if (s[a + i] != s[b + i]) return s[a+i] < s[b+i];
	    return false;
	}
    };
    void init(const string s_) {
	s = s_;
	node_i = 0;
	root0 = new_node(-1, 0); rootm = new_node(-1, 0);
	root0->suffix = rootm; root0->len = 0;
	rootm->suffix = rootm; rootm->len = -1;
	suffix = root0;
    }
    bool add(int pos) {
	Node *cur = suffix;
	int let = s[pos] - 'a';
	while (true) {
	    if (pos - 1 - cur->len >= 0 && s[pos - 1 - cur->len] == s[pos]) break;
	    cur = cur->suffix;
	}
	if (cur->next.count(let)) {
	    suffix = cur->next[let];
	    suffix->cnt++;
	    return false;
	}
	suffix = new_node(pos, 1);
	suffix->len = cur->len + 2;
	cur->next[let] = suffix;
	if (suffix->len == 1) {
	    suffix->suffix = root0;
	    return true;
	}
	while (true) {
	    cur = cur->suffix;
	    if (pos - 1 - cur->len >= 0 && s[pos - 1 - cur->len] == s[pos]) {
		suffix->suffix = cur->next[let];
		return true;
	    }
	}
    }
    void end() {
	ORDER ord(s);
	for (int i=node_i-1; i>=0; i--) {
	    if (i == 1) continue;
	    if (i > 1) node[i].al += node[i].cnt;
	    node[i].suffix->cnt += node[i].cnt;
	    node[i].suffix->al += node[i].al;
	    node[i].suffix->ch.push_back(&node[i]);
	    sort(node[i].ch.begin(), node[i].ch.end(), ord);
	}
	root0->cnt = 0;
    }
    string show(Node *x) {
	if (x->pos < 0) return "-1";
	return s.substr(x->pos - x->len + 1, x->len);
    }

    void print(Node *x, int d) {
	if (!x) return;
	eprintf("%s%d : %s %lld %lld\n", string(2*d, ' ').c_str(), x->pos, s.substr(max(0, x->pos-x->len+1), x->len).c_str(), x->cnt, x->al);
//	EACH (e, x->next) print(e->second, d+1);
	EACH (e, x->ch) print(*e, d+1);
    }
    void print() { print(root0, 0); }

};

// MOD 2^64
typedef long long ULL;
struct RollingHash {
    static const ULL BASE = 100001; ///2e9 + 11; // 3e9+19, 4e9+7 
    static const ULL MOD = 1000000007;
    static const int MAX_LEN = 1000000;
    static const vector<ULL>powB;
    static const vector<ULL>buildB();
    vector<char> S;
    vector<ULL> H; // H[i] := hash(S[0 .. i])
    RollingHash(const string &str) {
	init(str);
    }
    void init(const string &str) {
	S.clear(); H.assign(1, 0ULL);
	for (int i=0; i<(int)str.size(); i++) {
	    S.push_back(str[i]);
	    H.push_back((H.back() * BASE + str[i]) % MOD);
	}
    }
    ULL get(int l, int r) { // hash(S[l .. r-1])
	return ((H[r] - H[l] * powB[r-l]) % MOD + MOD) % MOD;
    }
    void push(char c) {
	S.push_back(c);
	H.push_back((H.back() * BASE + c) % MOD);
    }
    void pop() {
	S.pop_back();
	H.pop_back();
    }
};
const vector<ULL>RollingHash::buildB() {
    vector<ULL>h(MAX_LEN);
    h[0] = 1;
    for (int i=1; i<MAX_LEN; i++) h[i] = h[i-1]*BASE % MOD;
    return h;
}
const vector<ULL>RollingHash::powB = RollingHash::buildB();

int N, Q;
char buf[100111];
string S;



pair<LL, int> O[100111];
PalindromicTree::Node *ans[100111];

int cur;

void dfs(PalindromicTree::Node *x, LL ac) {
    if (!x) return;
    if (cur == Q) return;
    if (O[cur].first - ac >= x->al) return;

    while (cur < Q && O[cur].first - ac < x->cnt) {
	ans[O[cur].second] = x;
	cur++;
    }
    ac += x->cnt;
    EACH (e, x->ch) {
	dfs(*e, ac);
	ac += (*e)->al;
    }
}

int main() {
    scanf("%d%d", &N, &Q);
    scanf("%s", buf);
    S = buf;

    PalindromicTree::init(S);
    REP (i, S.size()) PalindromicTree::add(i);
    PalindromicTree::end();
//    PalindromicTree::print();



    REP (i, Q) {
	LL w;
	scanf("%lld", &w);
	O[i].second = i;
	O[i].first = w-1;
    }

    sort(O, O+Q);
    dfs(PalindromicTree::root0, 0);

    RollingHash RH(S);

    REP (i, Q) {
	if (!ans[i]) puts("-1");
	else {
	    printf("%llu\n", RH.get(ans[i]->pos - ans[i]->len + 1, ans[i]->pos + 1));
	}
    }



    return 0;
}



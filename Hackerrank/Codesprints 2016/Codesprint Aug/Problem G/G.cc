#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const int LOGN = 17;
const ll MOD = 1e9 + 7, a = 100001;
const int N = 1 << LOGN;
const int M = 26;

struct node {
	int next[M], len, sufflink, left, right;
	ll cnt; char c;
	node(){
		for(int i = 0; i < M; i++) next[i] = 0;
		cnt = 0;
	}
};

ll h[N];
ll pwr[N];

struct PalindromicTree{
	string s;
	node tree[N]; 
	int num, suff;
	int p[LOGN][N];

	ll sum[N];

	PalindromicTree(string &t) {
		s = t;
		num = 2, suff = 2;
		tree[1].len = -1; tree[1].sufflink = 1;
		tree[2].len = 0; tree[2].sufflink = 1;
		tree[1].cnt = tree[2].cnt = 0;
		
		p[0][1] = 1;
		p[0][2] = 1;
		
		for(int i = 0; i < s.length(); i++) tree[i+3] = node();
		for(int i = 0; i < s.length(); i++) addLetter(i);
		for(int i = num; i > 2; i--) tree[tree[i].sufflink].cnt += tree[i].cnt;

		for(int j = 1; j < LOGN; j++){
			for(int i = 3; i <= num; i++){
				p[j][i] = p[j-1][p[j-1][i]];
			}
		}
		
		for(int i = 0; i < LOGN; i++){
			
		}

		sort(tree + 3, tree + num + 1);

		sum[2] = 0;
		for(int i = 3; i <= num; i++) sum[i] = sum[i-1] + tree[i].cnt;
	}
	
	void addLetter(int pos) {
		int cur = suff, curlen = 0, let = s[pos] - 'a';

		while(true){
			curlen = tree[cur].len;
			if (pos - 1 - curlen >= 0 and s[pos - 1 - curlen] == s[pos]) break;
			cur = tree[cur].sufflink;
		}
		
		if(tree[cur].next[let]){	
			suff = tree[cur].next[let], tree[suff].cnt++;
			return;
		}

		suff = ++num;
		tree[num].len = tree[cur].len + 2;
		tree[num].left = pos - tree[num].len + 1;
		tree[num].right = pos;
		tree[num].c = s[pos];
		tree[cur].next[let] = num;
		p[0][num] = cur;

		if(tree[num].len == 1){
			tree[num].sufflink = 2, tree[num].cnt = 1;
			return;
		}

		tree[num].cnt++;
		while(true){
			cur = tree[cur].sufflink, curlen = tree[cur].len;
			if(pos - 1 - curlen >= 0 and s[pos - 1 - curlen] == s[pos]){
				tree[num].sufflink = tree[cur].next[let];
				break;
			}    	
		}           
		return;
	}
	
	void query(ll k){
		if(k > sum[num]){ cout << -1 << endl; return; }
		
		int lo = lower_bound(sum+2, sum+num+1, k) - (sum + 2);
		int l = tree[2+lo].left;
		int r = l + tree[2+lo].len - 1;
		
		ll ans = MOD + h[r] - ((l-1 >= 0)? (h[l-1] * pwr[r-l+1] % MOD) : 0);
		if(ans >= MOD) ans -= MOD;
		
		cout << ans << endl;
	}
};

int main(){ _
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	pwr[0] = 1;
	for(int i = 1; i <= n; i++) pwr[i] = pwr[i-1] * a % MOD;
	
	h[0] = s[0];
	for(int i = 1; i < n; i++){
		h[i] = (h[i-1] * a) % MOD;
		h[i] += s[i];
		if(h[i] >= MOD) h[i] -= MOD;
	}
	
	PalindromicTree *ptree = new PalindromicTree(s);
	
	while(q--){
		ll k; cin >> k;
		ptree->query(k);
	}
	return 0;
}

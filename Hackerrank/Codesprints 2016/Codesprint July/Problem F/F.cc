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

const int LOGN = 18;
const int N = 1 << LOGN;
const int M = 26;

struct PalindromicTree{
	struct node {
		int next[26];
		int len, sufflink, num;
		node(){
			for(int i = 0; i < M; i++) next[i] = 0;
		}
	};

	string s;
	node tree[N]; 
	int num; 			// node 1 - root with len -1, node 2 - root with len 0
	int suff; 			// max suffix palindrome

	PalindromicTree(string &t) {
		s = t;
		num = 2, suff = 2;
		tree[1].len = -1; tree[1].sufflink = 1;
		tree[2].len = 0; tree[2].sufflink = 1;
		
		for(int i = 0; i < s.length(); i++){
			tree[i+3] = node();
		}
	}

	bool addLetter(int pos) {
//		tr(meta, "adding", pos, "of", s, "with", suff);
		int cur = suff, curlen = 0, let = s[pos] - 'a';

		while(true){
			curlen = tree[cur].len;
			if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])    	
				break;	
			cur = tree[cur].sufflink;
		}		
		if(tree[cur].next[let]){	
			suff = tree[cur].next[let];
			return false;
		}

		suff = ++num;
		tree[num].len = tree[cur].len + 2;
		tree[cur].next[let] = num;

		if(tree[num].len == 1){
			tree[num].sufflink = 2, tree[num].num = 1;
			return true;
		}

		while(true){
			cur = tree[cur].sufflink, curlen = tree[cur].len;
			if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]){
				tree[num].sufflink = tree[cur].next[let];
				break;
			}    	
		}           

		tree[num].num = 1 + tree[tree[num].sufflink].num;

		return true;
	}
};

#define FI fi
#define SE se.fi
#define TH se.se

typedef pair<int, pii> tri;

bool sufcmp(const tri &i, const tri &j){
	if(i.FI != j.FI) return i.FI < j.FI;
	return (i.SE != -1 and j.SE != -1)? i.SE < j.SE : i.TH < j.TH; // careful!
}

int k[N], o[N];
void pre(){
	for(int i = 2; i < N; i++){
		k[i] = k[i-1] + ((i&(i - 1)) == 0);
		o[i] = (k[i] == k[i-1])? o[i-1] : (((o[i-1] + 1) << 1) - 1);
	}
}

int rmq[LOGN][N], p[LOGN][N], lcp[N], pos[N];
tri L[N];

// ties are broken in sorting by longer suffix length
struct suffixArray{
	int l, indx;
	string s;
	int len1, len2;
	
	suffixArray(string &str, int _len1, int _len2){
		s = str, l = s.length(), len1 = _len1, len2 = _len2;
		makeSuffixArray();
		buildLCP();
	}
	
	void makeSuffixArray(){
		for(int i = 0; i < l; i++) p[0][i] = s[i] - 'a'; // careful!
	
		indx = 0;
		for(int step = 0, cnt = 1; (cnt >> 1) < l; step++, cnt <<= 1){
			for(int i = 0; i < l; i++){
				L[i].FI = p[indx][i];
				L[i].SE = (i + cnt < l)? p[indx][i+cnt]: -1;
				L[i].TH = i;
			}
		
			sort(L, L + l, sufcmp);
		
			p[++indx][L[0].TH] = 0;
			for(int i = 1; i < l; i++){
				p[indx][L[i].TH] = p[indx][L[i-1].TH] + sufcmp(L[i-1], L[i]);
			}
		}
		
		for(int i = 0; i < l; i++) pos[L[i].TH] = i;	// pos[k] gives the lexicographical index of the suffix starting at k
	}
	
	int LCPHelper(int x, int y){
		if(x == y) return l - x;
		
		int len = 0;
		for(int k = indx; k >= 0 and x < l and y < l; k--)
			if(p[k][x] == p[k][y]){
				int jump = 1 << k;
				x += jump, y += jump, len += jump;
			}
		return len;
	}
	
	void buildLCP(){
		for(int i = 0; i < l; i++){
			if(pos[i] == l - 1) continue;
			lcp[pos[i]] = LCPHelper(i, L[pos[i] + 1].TH);
		}
		
		int n = l-1;
		for(int i = 0; i < n; i++) rmq[0][i] = lcp[i];
	
		for(int j = 1; j < LOGN; j++)
			for(int i = 0; (i + (1 << j) - 1) < n; i++){
				rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
			}
	}

	int getLCP(int x, int y){
		int l = y-x+1;
		return min(rmq[k[l]][x], rmq[k[l]][y - o[l]]);
	}
	
	string solve(int maxl[]){
//		tr(meta, s);
//		for(int i = 0; i < l; i++){
//			tr(meta, i, pos[i]);
//		}
	
		int best = -1, bestpos = -1, bestl1 = -1, sid = 1e9;

		int rk = -1;		
		for(int i = 0; i < l; i++){
			if(L[i].TH > len1)
				rk = i;
			else if(L[i].TH < len1 and rk != -1){
				int l1 = getLCP(rk, i-1);
				int l2 = (L[i].TH + l1 < len1)? maxl[L[i].TH + l1] : 0;
				
				if(l1 == 0) continue;
				
//				if(i == 2){
//					tr(meta, l1, l2, rk, L[i].TH, best, sid);
//				}
				
				if(l1 + l2 + l1 > best){
					best = l1 + l2 + l1;
					bestpos = L[i].TH;
					bestl1 = l1;
					sid = i;
				}
			}
		}
		
		rk = -1;
		for(int i = l-1; i >= 0; i--){
			if(L[i].TH > len1)
				rk = i;
			else if(L[i].TH < len1 and rk != -1){
				int l1 = getLCP(i, rk-1);
				int l2 = (L[i].TH + l1 < len1)? maxl[L[i].TH + l1] : 0;

//				if(i == 3){
//					tr(meta, l1, l2, rk, L[i].TH, best, sid);
//				}
				
				if(l1 == 0) continue;
				
				if(l1 + l2 + l1 > best){
					best = l1 + l2 + l1;
					bestpos = L[i].TH;
					bestl1 = l1;
					sid = i;
				}
				else if(l1 + l2 + l1 == best and i < sid){
					best = l1 + l2 + l1;
					bestpos = L[i].TH;
					bestl1 = l1;
					sid = i;
				}
			}
		}

//		tr(meta, best, bestl1, bestpos);
		string res;
		if(best == -1) return res;
		
		for(int i = bestpos; i < bestpos + bestl1; i++){
			res += s[i];
		}
//		tr(meta,res);
		if(bestpos+bestl1 < len1)
			for(int i = bestpos+bestl1, j = 0; j < maxl[bestpos+bestl1]; i++, j++){
				res += s[i];
			}
//		tr(meta,res);
		for(int i = bestpos + bestl1-1; i >= bestpos; i--){
			res += s[i];
		}
//		tr(meta,res);
		
		return res;
	}
};

int maxl1[N];
int maxl2[N];

void solve(){
	string a, b;
	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	PalindromicTree *ptree1 = new PalindromicTree(a);
	for(int i = 0; i < a.length(); i++){
		ptree1->addLetter(i);
		maxl1[a.length()-i-1] = ptree1->tree[ptree1->suff].len;
	}
	delete ptree1;
	reverse(a.begin(), a.end());

	PalindromicTree *ptree2 = new PalindromicTree(b);
	for(int i = 0; i < b.length(); i++){
		ptree2->addLetter(i);
		maxl2[b.length()-i-1] = ptree2->tree[ptree2->suff].len;
	}
	delete ptree2;
	reverse(b.begin(), b.end());
	
	string c = a + "$" + b;
	suffixArray *arr1 = new suffixArray(c, a.length(), b.length());
	string s1 = arr1->solve(maxl1);
	delete arr1;
	
	c = b + "$" + a;
	suffixArray *arr2 = new suffixArray(c, b.length(), a.length());
	string s2 = arr2->solve(maxl2);
	delete arr2;
	
	if(s1 == "" and s2 == ""){
		cout << -1 << endl;
	}
	else if(s1.length() < s2.length()){
		cout << s2 << endl;
	}
	else if(s1.length() > s2.length()){
		cout << s1 << endl;
	}
	else{
		if(s1 < s2) cout << s1 << endl; else cout << s2 << endl;
	}
}



int main(){ _
	pre();
	int q; cin >> q; while(q--) solve();
	return 0;
}

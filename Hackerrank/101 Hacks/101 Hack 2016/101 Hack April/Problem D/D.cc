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

#define FI fi
#define SE se.fi
#define TH se.se

const int LOGN = 20;
const int MAXN = 1 << LOGN;

const int N = 100100;
const int M = 26;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

ll presum[M+1][N];
int fstpos[M+1][N];

/*
 new suffixArray();
 makeSuffixArray();
 buildLCP();
 getLCP();
*/

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

typedef pair<int, pii> tri;

bool sufcmp(const tri &i, const tri &j){
	if(i.FI != j.FI) return i.FI < j.FI;
	return (i.SE != -1 and j.SE != -1)? i.SE < j.SE : i.TH < j.TH; // careful!
}


// ties are broken in sorting by longer suffix length
struct suffixArray{
	int l, indx;
	int p[LOGN][MAXN], lcp[MAXN], pos[MAXN];;
	int rmq[LOGN][MAXN], k[MAXN], o[MAXN];
	
	tri L[MAXN];
	
	string s;
	
	suffixArray(string &str){
		s = str, l = s.length();
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
	
		for(int i = 2; i <= n; i++){
			k[i] = k[i-1] + ((i&(i - 1)) == 0);
			if(k[i] == k[i-1]) o[i] = o[i-1];
			else o[i] = ((o[i-1] + 1) << 1) - 1;
		}
	}

	int getLCP(int x, int y){
		int l = y-x+1;
		return min(rmq[k[l]][x], rmq[k[l]][y - o[l]]);
	}
	
	ll countDistinctSubstrings(){
		ll ret = 0;
		vector<int> fpos;		
		for(int i = 0; i < l; i++){
			fpos.clear();
			for(int j = 0; j < M; j++) if(fstpos[j][L[i].TH] != INF) fpos.pb(fstpos[j][L[i].TH]);
			sort(fpos.begin(), fpos.end());
			
			int low = (i == 0)? L[i].TH : L[i].TH + lcp[i-1];
			
			int dcnt = fpos.size();
			int sln = l - L[i].TH;

			
			if(fpos.back() >= low){
				ret += (presum[dcnt][sln] - presum[dcnt][fpos.back() - L[i].TH] + MOD) % MOD;
				if(ret >= MOD) ret -= MOD;
			}
			else{
				ret += (presum[dcnt][sln] - presum[dcnt][low - L[i].TH] + MOD) % MOD;
				if(ret >= MOD) ret -= MOD;
				continue;
			}
			
			for(int j = dcnt-2; j >= 0; j--){
				
				if(fpos[j] >= low){
					ret += (presum[j+1][fpos[j+1] - L[i].TH] - presum[j+1][fpos[j] - L[i].TH] + MOD) % MOD;
					if(ret >= MOD) ret -= MOD;
				}
				else{
					ret += (presum[j+1][fpos[j+1] - L[i].TH] - presum[j+1][low - L[i].TH] + MOD) % MOD;
					if(ret >= MOD) ret -= MOD;
					break;
				}
			}
			
		}
		
		return ret;
	}
	
};

suffixArray *suf;

void solve(){
	string s; cin >> s;
	
	int lgt = s.length();
	
	for(int i = 0; i < M; i++){
		int mn = INF;
		for(int j = lgt-1; j >= 0; j--){
			if(s[j] - 'a' == i) mn = j;
			fstpos[i][j] = mn;
		}
	}
	
	suf = new suffixArray(s);
	suf->makeSuffixArray();
	suf->buildLCP();
	
	ll ans = suf->countDistinctSubstrings();
	assert(ans >= 0 and ans < MOD);
	cout << ans << '\n';
	
	delete suf;
}

int main(){ _
	int t; cin >> t;
	
	for(int i = 1; i <= M; i++){
		presum[i][0] = 0;
		for(int j = 1; j < N; j++){
			presum[i][j] = presum[i][j-1] + fast(j, i);
			if(presum[i][j] >= MOD) presum[i][j] -= MOD;
		}
	}
	
	while(t--){
		solve();
	}
	
	return 0;
}

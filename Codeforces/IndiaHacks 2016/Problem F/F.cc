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

const int LOGN = 20;
const int MAXN = 1 << LOGN;

/*
 new suffixArray();
 makeSuffixArray();
 buildLCP();
 getLCP();
*/

struct suffixArray{
	typedef pair<int, pii> tri;
	
	#define FI fi
	#define SE se.fi
	#define TH se.se

	int l, indx;
	int p[LOGN][MAXN], lcp[MAXN], sa[MAXN];
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
		
			sort(L, L + l);
		
			p[++indx][L[0].TH] = 0;
			for(int i = 1; i < l; i++){
				p[indx][L[i].TH] = (L[i].FI == L[i-1].FI and L[i].SE == L[i-1].SE)? p[indx][L[i-1].TH] : i;
			}
		}
		
		for(int i = 0; i < l; i++) sa[p[indx][i]] = i;
		
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
			if(p[indx][i] == l - 1) continue;
			lcp[p[indx][i]] = LCPHelper(i, sa[p[indx][i] + 1]);
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
		ll ret = l - sa[0];
		for(int i = 1; i < l; i++) ret += (l - sa[i]) - lcp[i-1];
		return ret;
	}
	
	int getKthSuffix(int k){
		assert(k < l);
		return sa[k];
	}
};

int main(){ _ 

	return 0;
}

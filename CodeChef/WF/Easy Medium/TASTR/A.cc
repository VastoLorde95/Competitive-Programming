#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define FI fi
#define SE se.fi
#define TH se.se

const int LOGN = 20;
const int MAXN = 1 << LOGN;

typedef pair<int, pii> tri;

bool sufcmp(const tri &i, const tri &j){
	if(i.FI != j.FI) return i.FI < j.FI;
	return (i.SE != -1 and j.SE != -1)? i.SE < j.SE : i.TH < j.TH; // careful!
}


int p[LOGN][MAXN], lcp[MAXN], pos[MAXN];
int rmq[LOGN][MAXN], k[MAXN], o[MAXN];
tri L[MAXN];

vector<int> a_front;
vector<int> a_back;
vector<int> b_front;
vector<int> b_back;

// ties are broken in sorting by longer suffix length
struct suffixArray{
	int l, indx;
	
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
		if(!(x <= y and x >= 0 and y >= 0)) while(true);
		int l = y-x+1;
		return min(rmq[k[l]][x], rmq[k[l]][y - o[l]]);
	}
	
	ll countDistinctSubstrings(){
		ll ret = l - L[0].TH;
		for(int i = 1; i < l; i++) ret += (l - L[i].TH) - lcp[i-1];
		return ret;
	}
	
	ll countDistinctSubstrings(int l1, int l2){
		ll ret = 0;
		
		if(L[0].TH < l1){
			ret += l1 - L[0].TH;
		}
		else{
			ret += l - L[0].TH;
		}
		
		for(int i = 1; i < l; i++){
			ret += max(((L[i].TH < l1)? l1 : l) - min(lcp[i-1], ((L[i-1].TH < l1)? l1 : l) - L[i-1].TH) - L[i].TH, 0);
		}
		
		ret -= l2+1;
		
		return ret;
	}
	
};

suffixArray *suff;
string a, b, s;

int main(){ _
	cin >> a >> b;
	
	suff = new suffixArray(a);
	suff->makeSuffixArray();
	suff->buildLCP();
	
	ll x = suff->countDistinctSubstrings();
	
	delete suff;
	
	suff = new suffixArray(b);
	suff->makeSuffixArray();
	suff->buildLCP();
	
	ll y = suff->countDistinctSubstrings();
	
	delete suff;
	
	s = a+"$"+b;
	suff = new suffixArray(s);
	suff->makeSuffixArray();
	suff->buildLCP();
	
	ll z = suff->countDistinctSubstrings(a.length(), b.length());

	delete suff;

	cout << (x+y)-((x+y-z)*2) << endl;
	
	return 0;
}

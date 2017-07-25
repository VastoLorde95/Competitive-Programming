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

const int N = 125125;
const int M = 10;

const unsigned int b = 103;
//const ll p = 1024383257;
const int INF = 1e9;

int n, q;
//string s, t;
char s[N], t[N];

unsigned int h1[N][M], h2[N], pwr[N];

void init(){
	pwr[0] = 1;
	for(int i = 1; i < N; i++) pwr[i] = pwr[i-1] * b;
}

int low[N][M];

void precompute(){
	for(int i = 0; i < M; i++) h1[0][i] = 0;
	h1[0][s[0]-'a'] = 1;
	h2[0] = t[0];
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < M; j++) h1[i][j] = (h1[i-1][j] * b) + (s[i] - 'a' == j);
		h2[i] = (h2[i-1] * b) + t[i];
	}
	
	for(int i = 0; i < M; i++) low[n][i] = INF;
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < M; j++) low[i][j] = low[i+1][j];
		low[i][s[i]-'a'] = i;
	}
}

int per[M];
int assign1[M], assign2[M];

inline unsigned int hash_s(int i, int j){
	unsigned int ret = 0;
	for(int k = 0; k < M; k++){
		if(low[i][k] > j) continue;
		
		unsigned int val = (h1[j][k] - ((i-1 >= 0)? h1[i-1][k] * pwr[j-i+1] : 0));
		val = val * (per[k] + 'a');
		ret += val;
	}
	return ret;
}

inline unsigned int hash_t(int i, int j){
	unsigned int ret = (h2[j] - ((i-1 >= 0)? h2[i-1] * pwr[j-i+1] : 0));
	return ret;
}

int LCP(int x, int y){
	int lo = 0, hi = min(n-x, n-y) + 1, mid;
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		if(hash_s(x, x+mid-1) == hash_t(y, y+mid-1)) lo = mid; else hi = mid;
	}
	return lo;
}

void getAnswer(int x, int y){
	for(int i = 0; i < M; i++){
		per[i] = i;
		assign1[i] = assign2[i] = 0;
	}
	
	int ans = 0;
	
	for(int iter = 0; iter < M and x < n and y < n; iter++){
		int l = LCP(x, y);
		ans += l;
		
		for(int i = 0; i < M; i++){
			if(low[x][i] < x+l){
				assign1[i] = 1, assign2[per[i]] = 1;
			}
		}
		
		x += l, y += l;
		if(x >= n or y >= n) break;
		if(assign1[s[x]-'a'] or assign2[t[y]-'a']) break;
		
		int id = -1;
		for(int i = 0; i < M; i++){
			if(per[i] == t[y]-'a'){
				id = i;
				break;
			}
		}
		
		per[id] = per[s[x]-'a'];
		per[s[x]-'a'] = t[y]-'a';
		assign1[s[x]-'a'] = 1;
		assign2[t[y]-'a'] = 1;
		
		ans++, x++, y++;
		
	}
	
	vector<int> v;
	for(int i = 0; i < M; i++) if(!assign2[i]) v.pb(i);
	
	int j = 0;
	for(int i = 0; i < M; i++) if(!assign1[i]) per[i] = v[j++];
	
	printf("%d ", ans);
	
	for(int i = 0; i < M; i++){
		printf("%c", (char)('a' + per[i]));
	}
	printf("\n");
}

void solve(){
	sd2(n,q);
	scanf("%s%s", s, t);
	
	precompute();

	while(q--){
		int x, y;
		sd2(x,y);
		getAnswer(x-1, y-1);
	}
}

int main(){
	init();
	int t; sd(t);
	while(t--) solve();
	return 0;
}

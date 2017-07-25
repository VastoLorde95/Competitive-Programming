#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define pb push_back

using namespace std;

const int N = 125125;
const int M = 10;
const int INF = 1e9;

const unsigned int b = 103;

int n, q;

char s[N], t[N];

unsigned int h1[N][M], h2[N], pwr[N];

void init(){
	pwr[0] = 1;
	for(int i = 1; i < N; i++) pwr[i] = pwr[i-1] * b;
}

int low[N][M];

void precompute(){
	for(int i = 0; i < M; i++) h1[0][i] = 0;
	h1[0][s[0]-'a'] = 1, h2[0] = t[0];
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < M; j++) h1[i][j] = h1[i-1][j] * b + (s[i] - 'a' == j);
		h2[i] = h2[i-1] * b + t[i];
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
		
		ret += (h1[j][k] - ((i-1 >= 0)? h1[i-1][k] * pwr[j-i+1] : 0)) * (per[k] + 'a');
	}
	return ret;
}

inline unsigned int hash_t(int i, int j){
	return (h2[j] - ((i-1 >= 0)? h2[i-1] * pwr[j-i+1] : 0));
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
	for(int i = 0; i < M; i++) per[i] = i, assign1[i] = assign2[i] = 0;
	
	int ans = 0;
	
	for(int iter = 0; iter < M; iter++){
		int l = LCP(x, y);
		ans += l;
		
		for(int i = 0; i < M; i++) if(low[x][i] < x+l) assign1[i] = 1, assign2[per[i]] = 1;
		
		x += l, y += l;
		if(x >= n or y >= n or assign1[s[x]-'a'] or assign2[t[y]-'a']) break;
		
		int id = -1;
		for(int i = 0; i < M; i++){
			if(per[i] == t[y]-'a'){
				id = i;
				break;
			}
		}
		
		per[id] = per[s[x]-'a'], per[s[x]-'a'] = t[y]-'a';
		assign1[s[x]-'a'] = 1, assign2[t[y]-'a'] = 1;
	}
	
	vector<int> v;
	for(int i = 0; i < M; i++) if(!assign2[i]) v.pb(i);
	for(int i = 0, j = 0; i < M; i++) if(!assign1[i]) per[i] = v[j++];
	
	printf("%d ", ans);
	for(int i = 0; i < M; i++) printf("%c", (char)('a' + per[i])); printf("\n");
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

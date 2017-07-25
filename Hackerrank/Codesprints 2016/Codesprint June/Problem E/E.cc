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
typedef __int128 bll;
typedef pair<ll,ll> pii;

const ll B = 26;
const ll P = 1344409044431ll;
const int N = 610;

unordered_set<ll> s;
unordered_set<ll> dp[2][N];

string g[2];

int n;

ll pw[2*N];

void generate(int x, int y){
	int i = x, j = y;
	bll h = 0;
	
	while(j >= 0){
		h = ((h * B % P) + (g[i][j] - 'a'+1)) % P;
		j--;
	}
	i ^= 1;
	j = 0;
	while(j <= y){
		h = ((h * B % P) + (g[i][j] - 'a'+1)) % P;
		j++;
	}

	int l = 2*n - (2 * (y+1));
	h = (h * pw[l]) % P;
	
	foreach(it, dp[x^1][y+1]){
		s.insert((h + *it) % P);
	}	
	
}

void doit(){
	for(int i = 0; i < 2; i++) for(int j = 0; j < N; j++) dp[i][j].clear();
	
	dp[0][n-1].insert((((B * (g[0][n-1]-'a'+1))%P) + (g[1][n-1]-'a'+1)) % P);
	dp[1][n-1].insert((((B * (g[1][n-1]-'a'+1))%P) + (g[0][n-1]-'a'+1)) % P);
	
	bll v;
	bll h;
	for(int j = n-2; j >= 0; j--){
		for(int i = 0; i < 2; i++){
			h = 0;
			int x = i, y = j;
			
			while(y < n){ h = (((h * B)%P) + (g[x][y] - 'a'+1)) % P; y++;}
			y = n-1; x ^= 1;
			while(y >= j){ h = (((h * B)%P) + (g[x][y] - 'a'+1)) % P; y--;}
			dp[i][j].insert(h);
			
			int l = (n-j)*2;
			
			h = (((B * (g[i][j] - 'a'+1)) % P) + (g[i^1][j] - 'a'+1)) % P;
			h = (h * pw[l-2]) % P;
			
			foreach(it, dp[i^1][j+1]){
				dp[i][j].insert((h + *it) % P);
			}
		}
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 1; j < n-1; j++){
			generate(i,j);
		}
	}
	
	foreach(it, dp[0][0]) s.insert(*it);
	foreach(it, dp[1][0]) s.insert(*it);
}

int mx;

void solve(){
	cin >> n;
	cin >> g[0] >> g[1];
	mx = max(mx, n);

	s.clear();

	if(n == 1){
		if(g[0] == g[1]) cout << 1 << endl;
		else cout << 2 << endl;
		return;
	}

	doit();
	reverse(g[0].begin(), g[0].end());
	reverse(g[1].begin(), g[1].end());
	doit();
	
	int ans = s.size();
	assert(ans >= 1);
	cout << ans << endl;
}

int main(){ _
	pw[0] = 1;
	for(int i = 1; i < 2*N; i++){
		pw[i] = (pw[i-1] * B) % P;
	}

	int p; cin >> p;
	while(p--) solve();
	
	return 0;
	
}

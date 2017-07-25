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
typedef long double ld;
typedef pair<int,int> pii;

const int N = 2010;

int n;

int g[N][N];
int h[N][N];

int ax, ay;

int hor[4][N][N];
int ver[4][N][N];

bool good(int x, int y, int l){
	if(x-l >= 1 and x+l <= n and y-l >= 1 and y+l <= n) return true;
	return false;
}

void update(int bx, int by){
	ld v1 = log((ld)2) * ax + log((ld)(3)) * ay;
	ld v2 = log((ld)2) * bx + log((ld)(3)) * by;
	if(v1 < v2){
		ax = bx;
		ay = by;
	}
	return;
}

void solve(){
	for(int k = 0; k < 4; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				hor[k][i][j] = hor[k][i][j-1] + (g[i][j] == k);
				ver[k][j][i] = ver[k][j-1][i] + (g[j][i] == k);
			}
		}		
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(g[i][j] == 0 or g[i][j] == -1) continue;
			
			int lo = 0, hi = n, mid;
			while(lo+1 < hi){
				mid = (lo + hi) >> 1;
				if(!good(i,j,mid)) hi = mid;
				else if(hor[0][i][j+mid] - hor[0][i][j-mid-1] > 0 or ver[0][i+mid][j] - ver[0][i-mid-1][j] > 0) hi = mid;
				else lo = mid;
			}
			
			int len = lo;
			
			int x = hor[2][i][j+len] - hor[2][i][j-len-1] + ver[2][i+len][j] - ver[2][i-len-1][j];
			int y = hor[3][i][j+len] - hor[3][i][j-len-1] + ver[3][i+len][j] - ver[3][i-len-1][j];
			
			if(g[i][j] == 2) x--;
			if(g[i][j] == 3) y--;
			update(x,y);
		}
	}
	
}

void rotate(){
	int nn = 2*n - 1;
	for(int i = 1; i <= nn; i++){
		for(int j = 1; j <= nn; j++){
			h[i][j] = -1;		
		}
	}
	
	int x, y;
	for(int i = 1; i <= n; i++){
		x = i, y = n+1-i;
		for(int j = i, k = 1; k <= n; k++){
			h[x][y] = g[j][k];
			x++, y++;
		}
	}

	for(int i = 1; i <= nn; i++){
		for(int j = 1; j <= nn; j++){
			g[i][j] = h[i][j];
		}
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 1; i+j <= n; j++){
			g[i][j] = 0;
			g[i][nn-j+1] = 0;
			g[nn-i+1][j] = 0;
			g[nn-i+1][nn-j+1] = 0;
		}
	}
	
	n = nn;
}

int main(){ _
	cin >> n;

	bool ok = false;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(int j = 1; j <= n; j++){
			g[i][j] = s[j-1] - '0';
			if(g[i][j]) ok = true;
		}
	}
	
	if(!ok){
		puts("0");
		return 0;
	}
	
	solve();
	rotate();
	solve();

	ll ans = 1;
	ll MOD = 1e9 + 7;
	while(ax--) ans = ans * 2 % MOD;
	while(ay--) ans = ans * 3 % MOD;

	cout << ans << endl;
		
	return 0;
}

#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 600;

int h, w;
int g[N][N], dp[N][N], row[N][N], col[N][N];
string s;

int main(){ _
	cin >> h >> w;
	
	for(int i = 1; i <= h; i++){
		cin >> s;
		for(int j = 1; j <= w; j++){
			if(s[j-1] == '.') g[i][j] = 1; else g[i][j] = 0;
		}
	}
	
	for(int i = 2; i <= w; i++){
		if(g[1][i] == 1 and g[1][i-1] == 1){
			dp[1][i] = dp[1][i-1] + 1;
		}
		else{
			dp[1][i] = dp[1][i-1];
		}
	}
	
	for(int i = 2; i <= h; i++){
		if(g[i][1] == 1 and g[i-1][1] == 1){
			dp[i][1] = dp[i-1][1] + 1;
		}
		else{
			dp[i][1] = dp[i-1][1];
		}
	}

	for(int i = 2; i <= h; i++){
		for(int j = 2; j <= w; j++){
			int cnt = 0;
			if(g[i][j] == 1 and g[i-1][j] == 1) cnt++;
			if(g[i][j] == 1 and g[i][j-1] == 1) cnt++;
			
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + cnt;
		}
	}
	
	
	for(int i = 1; i <= h; i++){
		for(int j = 2; j <= w; j++){
			row[i][j] = row[i][j-1] + (g[i][j] == 1 and g[i][j-1] == 1);
		}
	}
	
	for(int i = 1; i <= w; i++){
		for(int j = 2; j <= h; j++){
			col[j][i] = col[j-1][i] + (g[j][i] == 1 and g[j-1][i] == 1);
		}
	}
	
	int q, r1, c1, r2, c2;
	cin >> q;
	while(q--){
		cin >> r1 >> c1 >> r2 >> c2;
		
		int ans1 = dp[r2][c2] - dp[r2][c1] - dp[r1][c2] + dp[r1][c1];
		int ans2 = col[r2][c1] - col[r1][c1];
		int ans3 = row[r1][c2] - row[r1][c1];
		cout << ans1+ans2+ans3 << '\n';
	}
	
	return 0;
}

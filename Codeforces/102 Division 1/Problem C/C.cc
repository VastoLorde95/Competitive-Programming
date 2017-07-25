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
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 10;
const int d[4][5][2] = {
	0,0,1,0,1,1,1,2,2,0,
	0,0,0,1,0,2,1,1,2,1,
	0,2,1,0,1,1,1,2,2,2,
	0,1,1,1,2,0,2,1,2,2};

int n, m;
int g[N][N], res[N][N], ans;

bool ok(int x, int y){
	if(x <= 0 or x > n or y <= 0 or y > m) return false;
	return (g[x][y] == 0);
}

void go(int x, int y, int cur, int rem){
	if(y > m) x++, y = 1;
	if(cur + rem/5 <= ans) return;
	if(x == n+1 and cur > ans){
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) res[i][j] = g[i][j];
		ans = cur;
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int j;
		for(j = 0; j < 5; j++) if(!ok(x+d[i][j][0], y+d[i][j][1])) break;
		
		if(j == 5){
			for(j = 0; j < 5; j++) g[x+d[i][j][0]][y+d[i][j][1]] = cur+1;
			go(x,y+1,cur+1,rem-5-(g[x][y] == 0));
			for(j = 0; j < 5; j++) g[x+d[i][j][0]][y+d[i][j][1]] = 0;
		}
	}
	
	go(x,y+1,cur,rem-(g[x][y] == 0));
	
	return;
}

int main(){
	sd2(n,m);
	
	go(1,1,0,n*m);
	
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(res[i][j] > 0) printf("%c", (char)('A'+res[i][j]-1));
			else printf(".");
		}
		puts("");
	}
	
	return 0;
}

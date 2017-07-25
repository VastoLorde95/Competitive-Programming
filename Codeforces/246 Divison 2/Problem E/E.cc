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

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 110;

int n, m;
int g[N][N];
int l[N][N];
	
bool ok(int x, int y){
	if(x <= 0 or x > n or y <= 0 or y > m) return false;
	return true;
}

bool check(int x, int y, int len, int k){
	if(x+len-1 > n or y-len+1 <= 0) return false;
	for(int i = x; i < x+len; i++){
		if(g[i][y]) return false;
	}
	for(int i = y; i > y-len; i--){
		if(g[x+len-1][i]) return false;
	}
	return true;
}

int inf = 1e9;

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]) continue;
			
			for(int k = 1; k <= 26; k++){
				if(ok(i-1,j) and g[i-1][j] == k) continue;
				if(ok(i,j+1) and g[i][j+1] == k) continue;
				if(g[i][j-1] != k){
					g[i][j] = k;
					l[i][j] = 1;
					break;
				}	
				else{
					int len = l[i][j-1]+1;
					if(check(i,j,len,k)){
						for(int x = i; x < i+len; x++) g[x][j] = k, l[x][j] = inf;
						for(int y = j; y > j-len; y--) g[i+len-1][y] = k, l[i+len-1][y] = inf;
						l[i][j] = len;
						break;
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%c", (char)('A'+g[i][j]-1));
		}
		puts("");
	}
	
	return 0;
}

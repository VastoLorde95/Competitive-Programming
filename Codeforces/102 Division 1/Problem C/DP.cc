/*
DP with broken profile

t[i][j] -> dx, dy for jth cell in ith transition
id[i][j] -> bit number for the cell (j+1)th cell in the ith transition in mask

We can check if the following states can be placed using (2*n)+1 bits where n is the number of rows

$
###
#

$##
 #
 #
 
  #
$##
  #
  
 #
 #
$##

Bits are numbers as ($ represents the current (x,y)

	y ->
x	$		n-1		(2*n-1)
|	0		n		2*n
v	1		n+1
	.		.
	.		.
	n-2 	2*n-2
*/

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

const int N = 9;

int t[4][5][2] = {
	0,0,1,0,2,0,1,1,1,2,
	0,0,0,1,0,2,1,1,2,1,
	0,0,0,1,0,2,-1,2,1,2,
	0,0,0,1,0,2,-1,1,-2,1};

vector<int> id[4];

int n, m, dp[N+1][N][1<<(2*N+1)], res[N][N], mx;

bool good(int x, int y){
	if(x < 0 or x >= n or y < 0 or y >= m) return false;
	return true;
}

int go(int x, int y, int mask){
	int &ret = dp[x][y][mask];
	if(ret != -1) return ret;
	else if(y >= m) return ret = 0;
	else if(x == n) return ret = go(0, y+1, mask);
	
	ret = 0;
	
	ret = max(ret, go(x+1, y, mask >> 1));
	
	if((mask&1) == 0){
		for(int i = 0; i < 4; i++){
			bool ok = true;
			int nmask = mask >> 1;
			for(int j = 0; j < 4; j++){
				if((nmask&(1<<id[i][j])) or !good(x+t[i][j+1][0], y+t[i][j+1][1])){
					ok = false;
					break;
				}
				nmask |= (1<<id[i][j]);
			}
		
			if(ok) ret = max(ret, go(x+1,y,nmask)+1);
		}
	}
	
	return ret;
}


int cur = 0;
void get(int x, int y, int mask){
	int &ret = dp[x][y][mask];
	
	if(y == m) return;
	else if(x == n){
		get(0,y+1,mask);
		return;
	}
	else if(ret == go(x+1,y,mask >> 1)){
		get(x+1,y,mask >> 1);
		return;
	}
	
	if((mask&1) == 0){
		for(int i = 0; i < 4; i++){
			bool ok = true;
			int nmask = mask >> 1;
			for(int j = 0; j < 4; j++){
				if((nmask&(1<<id[i][j])) or !good(x+t[i][j+1][0], y+t[i][j+1][1])){
					ok = false;
					break;
				}
				nmask |= (1<<id[i][j]);
			}
		
			if(ok and ret == go(x+1,y,nmask)+1){
				++cur;
				for(int j = 0; j < 5; j++) res[x+t[i][j][0]][y+t[i][j][1]] = cur;
				get(x+1,y,nmask);
				return;
			}
		}
	}
	return;
}

int main(){
	sd2(n,m);
	
	if(n < 2 or m < 2){
		printf("0\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) printf(".");
			puts("");
		}
		return 0;
	}
	
	id[0] = {0,1,n,2*n};
	id[1] = {n-1,n,n+1,2*n-1};
	id[2] = {n-1,2*n-2,2*n-1,2*n};
	id[3] = {n-3,n-2,n-1,2*n-1};
	
	memset(dp, -1, sizeof dp);
	
	mx = go(0,0,0);
	
	printf("%d\n", mx);
	
	get(0,0,0);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(res[i][j] > 0) printf("%c", (char)('A'+res[i][j]-1));
			else printf(".");
		}
		puts("");
	}
	
	return 0;
}

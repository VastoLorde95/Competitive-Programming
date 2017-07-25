#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef pair<pair<int,int>, int> tri;

#define F first.first
#define S first.second
#define T second
#define mt(x,y,z) mp(mp(x,y),z)

const int N = 50;

long long MOD = 1e9+7, c[51][51], ways[51][51][2], v[51][51][2], step[51][51][2];
long long n, K, a, b, w, inf = 1e9;

int main(){
	c[0][0] = 1;
	for(int i = 1; i <= 50; i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++) c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;
	}

	cin >> n >> K;
	
	for(int i = 0; i < n; i++){
		cin >> w;
		if(w == 50) a++; else b++;
	}
	
	for(int i = 0; i <= a; i++) for(int j = 0; j <= b; j++) step[i][j][0] = step[i][j][1] = inf;
	
	queue<tri> q;
	q.push(mt(0,0,0));
	ways[0][0][0] = 1;	
	step[0][0][0] = 0;
	
	while(!q.empty()){
		tri cur = q.front(); q.pop();
		int x = cur.F, y = cur.S, z = cur.T;

		if(v[x][y][z]) continue;
		v[x][y][z] = 1;
		
//		tr3(x,y,z);
		
		if(z == 0){
			for(int i = 0; i <= a-x and 50*i <= K; i++){
				for(int j = 0; j <= b-y and 50*i + 100*j <= K; j++){
					if(v[x+i][y+j][1-z]) continue;
					if(i == 0 and j == 0) continue;
					
					(ways[x+i][y+j][1-z] += (ways[x][y][z]*(c[a-x][i]*c[b-y][j])%MOD)%MOD) %= MOD;

					if(step[x+i][y+j][1-z] == inf){
						step[x+i][y+j][1-z] = step[x][y][z]+1;					
						q.push(mt(x+i,y+j,1-z));
					}
				}
			}
		}
		else{
			for(int i = 0; i <= x and 50*i <= K; i++){
				for(int j = 0; j <= y and 50*i + 100*j <= K; j++){
					if(v[x-i][y-j][1-z]) continue;
					if(i == 0 and j == 0) continue;
					
					(ways[x-i][y-j][1-z] += (ways[x][y][z]*(c[x][i]*c[y][j])%MOD)%MOD) %= MOD;
					
					if(step[x-i][y-j][1-z] == inf){					
						step[x-i][y-j][1-z] = step[x][y][z] + 1;
						q.push(mt(x-i,y-j,1-z));
					}
				}
			}	
		}
	}
	
	if(ways[a][b][1] == 0) puts("-1\n0");
	else cout << step[a][b][1] << endl << ways[a][b][1] << endl;	
	
	return 0;
}

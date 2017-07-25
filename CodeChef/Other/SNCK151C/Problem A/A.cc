#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int t, n;
int s1, s2, e1, e2, b1, b2;

int d[21][21], v[21][21];


bool inrange(int x, int y){
	if(!(x == b1 and y == b2) and x >= 1 and x <= n and y >= 1 and y <= n and v[x][y] == 0) return true;
	return false;
}

void bfs(){
	queue<pair<int, int> > q;
	q.push(mp(s1,s2));
	
	int x, y;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			d[i][j] = 100000;
			v[i][j] = 0;
		}
	}
	
	d[s1][s2] = 0;
	
	while(!q.empty()){
		x = q.front().fi, y = q.front().se;
		
		q.pop();
		
		if(v[x][y] == 1) continue;
		
		v[x][y] = 1;
		
		if(inrange(x+1,y)){
			q.push(mp(x+1,y));
			d[x+1][y] = min(d[x+1][y], d[x][y]+1);
		}
		if(inrange(x-1,y)){
			q.push(mp(x-1,y));
			d[x-1][y] = min(d[x-1][y], d[x][y]+1);
		}
		if(inrange(x,y+1)){
			q.push(mp(x,y+1));
			d[x][y+1] = min(d[x][y+1], d[x][y]+1);
		}
		if(inrange(x,y-1)){
			q.push(mp(x,y-1));
			d[x][y-1] = min(d[x][y-1], d[x][y]+1);
		}
		
	}
	
}

int main(){
	sd(t);
	while(t--){
		sd(n);
		sd2(s1,s2);
		sd2(e1,e2);
		sd2(b1,b2);
		
		bfs();
		
		printf("%d\n", d[e1][e2]);		
		
	}
	return 0;
}

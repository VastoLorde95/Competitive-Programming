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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef pair<int,int> pii;

int n, m, cnt;
char s[2001];
int g[2001][2001], r[2001][2001], d[2001][2001];

queue<pii> q;

bool inrange(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true;
	return false;
}

void getnext(int &nxt, int &xx, int &yy){
	if(inrange(xx-1,yy) and g[xx-1][yy]){
		nxt = 4, xx = xx-1;
		r[xx][yy] = 2;
	}
	else if(inrange(xx+1,yy) and g[xx+1][yy]){
		nxt = 2, xx = xx+1;
		r[xx][yy] = 4;
	}
	else if(inrange(xx,yy-1) and g[xx][yy-1]){
		nxt = 3, yy = yy-1;
		r[xx][yy] = 1;
	}
	else if(inrange(xx,yy+1) and g[xx][yy+1]){
		nxt = 1, yy = yy+1;
		r[xx][yy] = 3;
	}
	else{
		puts("Not unique");
		exit(0);
	}
}

int main(){
	sd2(n,m);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		for(int j = 1; j <= m; j++){
			g[i][j] = (s[j-1] == '.');
			cnt += g[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!g[i][j]) continue;
			if(inrange(i-1,j) and g[i-1][j]) d[i][j]++;
			if(inrange(i+1,j) and g[i+1][j]) d[i][j]++;
			if(inrange(i,j-1) and g[i][j-1]) d[i][j]++;
			if(inrange(i,j+1) and g[i][j+1]) d[i][j]++;
			
			if(d[i][j] == 1) q.push(mp(i,j));
		}
	}			
			
	if(q.empty() and cnt > 0){
		puts("Not unique"); return 0;
	}
	
	int nxt;
	
	while(!q.empty()){
		pii p = q.front(); q.pop();
		
		int x = p.fi, y = p.se;
		if(!g[x][y]) continue;
		
		cnt -= 2;
		
		g[x][y] = 0;
		d[x][y] = 0;
		getnext(r[x][y],x,y);
		
		g[x][y] = 0;
		d[x][y]--;
		
		if(inrange(x-1,y) and g[x-1][y]){
			d[x-1][y]--;
			if(d[x-1][y] == 1) q.push(mp(x-1,y));
		}
		if(inrange(x+1,y) and g[x+1][y]){
			d[x+1][y]--;
			if(d[x+1][y] == 1) q.push(mp(x+1,y));
		}
		if(inrange(x,y-1) and g[x][y-1]){
			d[x][y-1]--;
			if(d[x][y-1] == 1) q.push(mp(x,y-1));
		}
		if(inrange(x,y+1) and g[x][y+1]){
			d[x][y+1]--;
			if(d[x][y+1] == 1) q.push(mp(x,y+1));
		}
	}
	
	if(cnt > 0){
		puts("Not unique"); return 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(r[i][j] == 1) printf("<");
			else if(r[i][j] == 2) printf("^");
			else if(r[i][j] == 3) printf(">");
			else if(r[i][j] == 4) printf("v");
			else printf("*");
		}
		printf("\n");
	}
	
	return 0;
}

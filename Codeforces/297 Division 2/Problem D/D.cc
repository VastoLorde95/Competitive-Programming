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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, v[2001][2001], g[2001][2001];
string s;

queue<pair<int, int> > q;

bool inrange(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true; 
	return false;
}

int main(){ _
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			g[i][j] = (s[j-1] == '.');
		}
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= m; j++){
			int c1 = 0, c2 = 0, ax = -1, ay = -1;
			for(int dx = 0; dx < 2; dx++){
				for(int dy = 0; dy < 2; dy++){
					if(g[i-dx][j-dy] == 1) c1++; else c2++, ax = i-dx, ay = j-dy;
				}
			}
			
			if(c2 == 1)	q.push(mp(ax, ay));
		}
	}
	
	while(!q.empty()){
		int i = q.front().fi, j = q.front().se; q.pop();
		int x = i, y = j;
		if(g[x][y] == 1) continue;
		
//		tr2(x,y);
		
		g[x][y] = 1;
		
		if(inrange(x-1,y-1)){
			int c1 = 0, c2 = 0, ax = -1, ay = -1;
			for(int dx = 0; dx < 2; dx++){
				for(int dy = 0; dy < 2; dy++){
					if(g[i-dx][j-dy] == 1) c1++; else c2++, ax = i-dx, ay = j-dy;
				}
			}
		
//			tr2(c1,c2);
			if(c2 == 1){
				q.push(mp(ax, ay));
//				continue;
			}
		}
		
		if(inrange(x+1,y+1)){
			int c1 = 0, c2 = 0, ax = -1, ay = -1;
			for(int dx = 0; dx < 2; dx++){
				for(int dy = 0; dy < 2; dy++){
					if(g[i+dx][j+dy] == 1) c1++; else c2++, ax = i+dx, ay = j+dy;
				}
			}
		
//			tr2(c1,c2);
			if(c2 == 1){
				q.push(mp(ax, ay));
//				continue;
			}
		}
		
		if(inrange(x-1,y+1)){
			int c1 = 0, c2 = 0, ax = -1, ay = -1;
			for(int dx = 0; dx < 2; dx++){
				for(int dy = 0; dy < 2; dy++){
					if(g[i-dx][j+dy] == 1) c1++; else c2++, ax = i-dx, ay = j+dy;
				}
			}
			
//			tr2(c1,c2);
			if(c2 == 1){
//				tr2(ax,ay);
				q.push(mp(ax, ay));
//				continue;
			}
		}
		
		if(inrange(x+1,y-1)){
			int c1 = 0, c2 = 0, ax = -1, ay = -1;
			for(int dx = 0; dx < 2; dx++){
				for(int dy = 0; dy < 2; dy++){
					if(g[i+dx][j-dy] == 1) c1++; else c2++, ax = i+dx, ay = j-dy;
				}
			}
			
//			tr2(c1,c2);
			
			if(c2 == 1){
				q.push(mp(ax, ay));
//				continue;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j]) cout << "."; else cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}

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

int n, cnt;
string s;
int b[50][50], a[101][101];
vector<pair<int, int> > valid;
set<pair<int, int> > ss;

bool inrange(int x, int y){
	if(x >= 0 and x < n and y >= 0 and y < n) return true;
	return false;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			if(s[j] == 'o') b[i][j] = 1;
			else if(s[j] == 'x') b[i][j] = 2, cnt++;
		}
	}
	
	for(int dx = 1-n; dx < n; dx++){
		for(int dy = 1-n; dy < n; dy++){
			bool ok = true, ok2 = false;
			if(dx == 0 and dy == 0) continue;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(b[i][j] == 1 and inrange(i+dx,j+dy)){
						if(b[i+dx][j+dy] == 0) ok = false;
						else ok2 = true;
					}
				}
			}
			if(ok and ok2){
//				tr2(dx,dy);
				valid.pb(mp(dx,dy));	
				
				for(int i = 0; i < n; i++){
					for(int j = 0; j < n; j++){
						if(b[i][j] == 2 and inrange(i-dx,j-dy)){
							if(b[i-dx][j-dy] == 1){
//								tr6(i,j,dx,dy,b[i][j],b[i-dx][j-dy]);
								ss.insert(mp(i,j));
							}
						}
					}
				}
				
			}			
		}
	}
	
	
//	foreach(it, ss) tr2(it->fi,it->se);
	
//	tr3(ss.size(),cnt, valid.size());	
	if(ss.size() != cnt or (valid.size() == 0 and cnt > 0)){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	
	a[n-1][n-1] = 1;
	foreach(it, valid){
		a[n-1+it->fi][n-1+it->se] = 2;
	}
	
	for(int i = 0; i < n+n-1; i++){
		for(int j = 0; j < n+n-1; j++){
			if(a[i][j] == 0) printf(".");
			else if(a[i][j] == 2) printf("x");
			else printf("o");
		}
		printf("\n");
	}
	
	return 0;
}

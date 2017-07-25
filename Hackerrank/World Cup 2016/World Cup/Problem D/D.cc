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

int n, m, cnt, p[30];
char s[20][20];
int g[20][20];

void go(int lvl, int x, int y){
//	if(lvl == n){
//		cnt++;
//		return;
//	}
	if(lvl < n-1){
		for(int i = 0; i < m; i++){
			if(!g[lvl][i]){
				if((x & p[n+lvl-i]) > 0) x ^= p[n+lvl-i];
				if((y & p[lvl+i]) > 0) y ^= p[lvl+i];
			}
		}
		for(int i = 0; i < m; i++){
			if(!(x & p[n+lvl-i]) and !(y & p[lvl+i]) and g[lvl][i]){
				go(lvl+1, x|p[n+lvl-i], y|p[lvl+i]);
			}
		}
	}
	else{
		for(int i = 0; i < m; i++){
			if(!(x & p[n+lvl-i]) and !(y & p[lvl+i]) and g[lvl][i]){
				cnt++;
			}
		}
	}
}

int main(){
	sd2(n,m);
	p[0] = 1;
	for(int i = 1; i < 30; i++){
		p[i] = p[i-1]*2;
	}
	
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
		for(int j = 0; j < m; j++){
			g[i][j] = (s[i][j] == '.');
		}
	}
	
	if(n == 1){
		for(int i = 0; i < m; i++){
			if(g[0][i]) cnt++;
		}
		tr(cnt);
		return 0;
	}
	
	for(int i = 0; i < m; i++){
		if(g[0][i]){
			int num1 = 0, num2 = 0;
			num1 |= (1<<(n-i));
			num2 |= (1<<i);
			go(1,num1, num2);		
		}
	}	
	
	tr(cnt);
	
	return 0;
}

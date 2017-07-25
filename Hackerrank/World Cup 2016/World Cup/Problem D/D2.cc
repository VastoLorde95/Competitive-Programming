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

int n, m, cnt;
char g[20][20];

void go(int lvl, vector<int> &v1, vector<int> &v2){
	if(lvl == n){
		cnt++;
		return;
	}
	
	for(int i = 0; i < m; i++){
		if(g[lvl][i] == '*'){
			v1[n+lvl-i] = 0;
			v2[lvl+i] = 0;
		}
	}
	
	for(int i = 0; i < m; i++){
		if(!v1[n+lvl-i] and !v2[lvl+i] and g[lvl][i] == '.'){
			vector<int> t1 = v1, t2 = v2;
			t1[n+lvl-i] = 1;
			t2[lvl+i] = 1;
			go(lvl+1, t1, t2);
		}
	}
}

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		scanf("%s", g[i]);
	}
	
	for(int i = 0; i < m; i++){
		if(g[0][i] == '.'){
			vector<int> v1(2*n+1,0);
			vector<int> v2(2*n+1,0);
			v1[n-i] =1;
			v2[i] = 1;
			go(1,v1, v2);		
		}
	}	
	
	tr(cnt);
	
	return 0;
}

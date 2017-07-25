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

int q, v, v1, v2, d, n, p[20][1<<20], l[1<<20];

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);
	
	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];
	
	return p[0][x];
}

void update(){
	n++;
	p[0][n] = v, l[n] = l[v]+1;
	
	for(int j = 1; j < 20; j++)
		if(p[j-1][n] > 0) p[j][n] = p[j-1][p[j-1][n]];
	
	if(l[n] + l[v1] - 2*l[LCA(n, v1)] > d) d++, v2 = n;
	else if(l[n] + l[v2] - 2*l[LCA(n, v2)] > d) d++, v1 = n;
}

int main(){
	p[0][2] = 1; p[0][3] = 1; p[0][4] = 1;	
	l[2] = 1; l[3] = 1; l[4] = 1;
	v1 = 2, v2 = 4, d = 2; 
	n = 4;
	
	sd(q);
	while(q--){
		sd(v);
		update();
		update();
		printf("%d\n", d);
	}
	return 0;
}

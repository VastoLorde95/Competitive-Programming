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

int g[50][50];

int main(){
	int x1, y1, x2, y2;
	sd2(x1,y1);
	sd2(x2,y2);
	for(int i = 21+x1; i <= 21+x2; i++){
		for(int j = 21+y2; j <= 21+y1; j++){
			g[i][j]++;
		}
	}
	
	sd2(x1,y1);
	sd2(x2,y2);
	for(int i = 21+x1; i <= 21+x2; i++){
		for(int j = 21+y2; j <= 21+y1; j++){
			g[i][j]++;
		}
	}
	
	for(int i = 1; i < 50; i++){
		for(int j = 1; j < 50; j++){
			if(g[i][j] == 2){
				puts("overlap");
				return 0;
			}
		}
	}
	puts("no overlap");
	return 0;
}

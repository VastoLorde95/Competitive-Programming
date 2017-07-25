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

int n;
double a[18][18], p[1<<18];

int main(){
	sd(n);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%lf", &a[i][j]);
	
	int up = 1<<n;
	p[0] = 1;
	for(int i = 0; i < up; i++){
		int cnt = 0;
		for(int j = 0; j < n; j++) if((i&(1<<j)) == 0) cnt++;
		
		if(cnt == 1) continue;
		
		for(int j = 0; j < n; j++){
			if((i&(1<<j)) == 0){
				for(int k = j+1; k < n; k++){
					if((i&(1<<k)) == 0){
						p[i | (1<<j)] += ((p[i]*a[k][j]*2)/cnt)/(cnt-1);
						p[i | (1<<k)] += ((p[i]*a[j][k]*2)/cnt)/(cnt-1);
					}
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) printf("%.9lf ", p[(up-1)^(1<<i)]);
	puts("");
	
	return 0;
}

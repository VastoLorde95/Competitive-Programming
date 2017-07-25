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


int t, n, m;
double p[13][10000];
double eps = 1e-15;

int main(){
	sd(t);
	while(t--){
		sd2(n,m);
		if(m > 4){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					scanf("%lf", &p[i][j]);
				}
			}
		
			long double y = 1;
			for(int i = 0; i < m; i++){
				if(p[0][i] == 0){
					printf("0.000000\n"); continue;
				}
			}
		
			for(int i = 1; i < n; i++){
				long double tmp = 1.0f;
				for(int j = 0; j < m; j++){
					tmp *= (long double) p[i][j] / (long double) p[0][j] ;
				}
				y += tmp;
			}
		
			long double res = (long double) 1.0f / y;
			printf("%.6lf\n", (double) res);
		}
		else{
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					scanf("%lf", &p[i][j]);
				}
			}
		
			long double x = 1, y = 1;
			for(int i = 0; i < m; i++){
				x *= p[0][i];
			}
		
			y -= x;
			
			for(int i = 1; i < n; i++){
				long double tmp = 1.0f;
				for(int j = 0; j < m; j++){
					tmp *= (long double) p[i][j];
				}
				y -= tmp;
			}
			
			if(y == 1){
				printf("%.6lf\n", (double) x); continue;
			}
			
			long double res = (long double) x / (-y + 1.0f);
			printf("%.6lf\n", (double) res);
		}
		
	}
	return 0;
}

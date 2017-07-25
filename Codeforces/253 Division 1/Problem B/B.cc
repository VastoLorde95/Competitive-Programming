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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n;
double p[101], ans = 0;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%lf", &p[i]);
	}
	
	sort(p, p+n, greater<double>());
	
	double p1 = p[0], p2 = 1-p[0];
	
	ans = p1;
	
	for(int i = 1; i < n; i++){
		double t = (p1*(1-p[i])) + (p2*p[i]);
		if(t > ans){
			ans = t;
			p1 = t;
			p2 = p2*(1-p[i]);
		}
		
//		tr(ans);
		
	}	
	printf("%.17lf\n", ans);
	
	return 0;
}

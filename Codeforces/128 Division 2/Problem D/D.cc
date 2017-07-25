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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

double a, b, m;
double vx, vy, vz;

double x0, z0;

int main(){
	scanf("%lf%lf%lf",&a,&b,&m);
	scanf("%lf%lf%lf",&vx,&vy,&vz);
	
	double t = fabs(m/vy);
	
	double d = vx*t;
	
	if((d >= 0 and a/2.0 + d <= a) or (d < 0 and a/2.0 + d >= 0)){
		x0 = a/2.0 + d;
	}
	else{
		if(d > 0){
			d -= a/2.0;
			int cnt = (int)(d/a);
			
			d -= a*cnt;
			
			if(cnt%2 == 0){
				x0 = a-d;
			}
			else{
				x0 = d;
			}
		}
		else{
			d += a/2.0;
			d = fabs(d);
			
			int cnt = (int)(d/a);
			
			d -= a*cnt;
			
			if(cnt%2 == 0){
				x0 = d;
			}
			else{
				x0 = a-d;
			}
		}
	}
	
	d = vz*t;
	
	if(d <= b){
		z0 = d;
	}
	else{
		d -= b;
		int cnt = (int)(d/b);
		
		d -= b*cnt;
		
		if(cnt%2 == 0){
			z0 = b-d;
		}
		else{
			z0 = d;
		}
	}
	
	printf("%.9lf %.9lf\n", x0, z0);
	
	return 0;
}

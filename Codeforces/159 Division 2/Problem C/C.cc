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

using namespace std;

int n;
double x, y, mn;
double PI = 3.14159265358979323846f, a[100000];
int main(){
	sd(n);
	
	mn = 2*PI;
	
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		scanf("%lf %lf",&x,&y);
		
		if(x > 0){
			a[i] = atan(y/x);	
			if(a[i] < 0)
				a[i] += 2*PI;
		}	
		else if(x == 0){
			if(y > 0) a[i] = PI/2.0;
			else a[i] = 1.5*PI;
		}	
		else{
			a[i] = PI + atan(y/x);
		}
	}
	
	sort(a, a+n);
	
	mn = min(mn, a[n-1] - a[0]);
	
	for(int i = 1; i < n; i++){
		mn = min(mn, PI+PI-(a[i]-a[i-1]));
	}
	
	printf("%.12lf\n", (mn*180.0f)/PI);
	return 0;
}

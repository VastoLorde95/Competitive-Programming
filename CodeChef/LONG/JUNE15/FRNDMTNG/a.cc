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

int t;
int T1, T2, t1, t2;

double sum;

int main(){
	sd(t);
	
	while(t--){
		sd2(T1,T2); sd2(t1,t2);
		
		if(T1 < T2){
			swap(T1,T2);
			swap(t1,t2);
		}
		
		sum = (double)(t1/T1)*(double)(t2/T2) + (((double)(t2/T1)*(double)(t2/T2)) / 2.0);
		
		if(t2 < T1-t1){
			double a = (double)(t1+t2)/T1;
			a /= T2;
			
			a *= (T1-t1-t2);
			
			sum += a;
		}
		
		if(t2 < T1){
			double a = (double)(3*t1*t2)/T1;
			a /= T2;
			
			a -= (((double)(t2/T1)*(double)(t2/T2)) / 2.0);
			
			sum += a;
		}
		
//		if(sum > 1.0) sum = 1.0;
		
		printf("%.9lf\n", sum);
		
	}
	
	return 0;
}

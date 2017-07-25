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

using namespace std;

long long k, b, n, t, r1, r2, l;
long long v[1000000], sum[1000000];
int main(){ _
	
	cin >> k >> b >> n >> t;
	
	if(t == 1){
		tr(n);
		return 0;
	}	

	long long x = 1;
	
	while(x <= t){
		x = k*x + b;
		n--;
	}
	
	n++;
	
	tr(max(0LL,n));
	
	return 0;
}

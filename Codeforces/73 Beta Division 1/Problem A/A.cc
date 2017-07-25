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

long long a, b, t1, t2;

int c1, c2;

int main(){ _
	cin >> a >> b;
	
	t1 = a, t2 = b;
	
	long long lcm = (a*b)/__gcd(a,b);
	
	while(t1 <= lcm or t2 <= lcm){
		if(t1 == t2){
			if(a > b) c1++;
			else c2++;
			t1 += a, t2 += b;
		}
		else if(t1 < t2) c1++, t1 += a;
		else c2++, t2 += b;
	}
	
	if(c1 > c2) puts("Dasha");
	else if(c1 < c2) puts("Masha");
	else puts("Equal");
	
	return 0;
}

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

int n, x[100000], d;
long long res, p1, p2;

int main(){
	sd2(n,d);
	for(int i = 0; i < n; i++) sd(x[i]);
	
	p1 = p2 = 0;
	
	for(; p1 < n; p1++){
		while(p2 < n and x[p2]-x[p1] <= d) p2++;
		
		long long tmp = p2-p1-1;
		
//		cout << p1 << " " << tmp << endl;
		
		if(tmp > 1)
			res += (tmp*(tmp-1))/2;
	}
	
	cout << res << endl;
		
	return 0;
}

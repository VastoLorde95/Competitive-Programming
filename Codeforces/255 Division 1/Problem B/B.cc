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

priority_queue<long long> q1, q2;
long long n, m, k, p, a[1000][1000];
long long c1[1000001], c2[1000001];	
long long ans = -1e18, x, y;

int main(){
	cin >> n >> m >> k >> p;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}
	
	long long s;
	
	for(int i = 0; i < n; i++){
		s = 0;
		for(int j = 0; j < m; j++){
			s += a[i][j];
		}
		q1.push(s);
	}
	
	for(int j = 0; j < m; j++){
		s = 0;
		for(int i = 0; i < n; i++){
			s += a[i][j];
		}
		q2.push(s);
	}
	
	for(int  i = 1; i <= k; i++){
		x = q1.top(); q1.pop();
		y = q2.top(); q2.pop();
		c1[i] = c1[i-1] + x;
		c2[i] = c2[i-1] + y;
		q1.push(x-(m*p));
		q2.push(y-(n*p));
	}
	
	for(int i = 0; i <= k; i++){
		ans = max(ans, c1[i]+c2[k-i]-(i*(k-i)*p));
	}
	
	cout << ans << "\n";
	
	return 0;
}

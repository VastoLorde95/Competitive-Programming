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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long m;
long long h1, a1, x1, Y1;
long long h2, a2, x2, y2;

long long t[2000001], a[1000001];

long long get(long long x, long long y){
	long long cnt = 0;
	while(x != y and cnt < m){
		x = (x1*x + Y1)%m;
		cnt++;
	}
	if(cnt == m) return -1;
	return cnt;
}

long long cycle(long long x){
	long long cnt = 1;
	long long y = (x1*x + Y1)%m;
	while(y != x and cnt <= m){
//		tr2(x,y)m;
		cnt++;
		y = (x1*y + Y1)%m;
	}
	
	if(cnt > m) return -1;
	return cnt;
}

int main(){
	cin >> m >> h1 >> a1 >> x1 >> Y1 >> h2 >> a2 >> x2 >> y2;

	long long t1 = get(h1, a1);
	long long t2 = cycle(a1);
	
//	tr2(t1, t2);	
	
	t[0] = h2;
	
	for(int i = 0; i <= 2*m; i++){
		a[i] = 1e9;
	}
	
	a[h2] = 0;
	
	for(int i = 1; i <= 2*m; i++){
		t[i] = (t[i-1]*x2 + y2)%m;
		a[t[i]] = min(a[t[i]], (long long) i);
//		tr3("build",i, t[i]);
	}
	
	if(t1 == -1){
		cout << -1 << endl; return 0;
	}
	
	if(t[t1] == a2){
		cout << t1 << endl; return 0;
	}
	
	if(t2 == -1){
		cout << -1 << endl; return 0;	
	}
	
	long long ans = t1, tt = t1;
	
	for(int i = 1; i <= m; i++){
		ans += t2;
		tt += t2;
		
//		tr3(ans, tt, t[tt]);
		
		if(t[tt] == a2){
			cout << ans << endl;
			return 0;
		}
		
		tt = a[t[tt]];
	}
	
	cout << -1 << endl;
	
	
	return 0;
}

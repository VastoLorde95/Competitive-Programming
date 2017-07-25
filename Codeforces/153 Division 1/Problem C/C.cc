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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef long long ll;

ll a, b, k, l;
int v[1000100], d[1000100];

ll lcm(ll x, ll y){
	return (x*y)/__gcd(x,y);
}

ll go(int cur, int dest){
	queue<int> q;
	q.push(cur);
	memset(v, 0, sizeof v);
	memset(d, 0, sizeof d);
	
	while(!q.empty()){
		cur = q.front(); q.pop();
		if(v[cur]) continue;
		v[cur] = 1;
		
		for(int i = 2; i <= k; i++){
			int nxt = cur - (cur%i);
			if(!v[nxt] and d[nxt] == 0){
				d[nxt] = d[cur] + 1;
				q.push(nxt);
			}
		}
		
		if(cur > 0 and !v[cur-1] and d[cur-1] == 0){
			d[cur-1] = d[cur]+1;
			q.push(cur-1);
		}
		
	}
	return d[dest];
}

int main(){ _
	cin >> b >> a >> k;
	
	if(b == a){
		cout << 0 << endl; return 0;
	}
	if(k == 1){
		cout << b-a << endl; return 0;
	}
	
	l = 1;
	for(int i = 2; i <= k; i++) l = lcm(l, i);

	if(a/l == b/l){
		cout << go(b%l, a%l) << endl;
		return 0;
	}
	
	
	ll v1 = go(l-1, 0);
	ll v2 = (b%l == 0)? 0: go(b%l, 0);
	ll v3 = (a%l == 0)? 0: go(l-1, a%l)+1;
	ll cnt = (b/l - (a-1)/l);
	
	
	ll res = (cnt-1)*(v1+1) + v2 + v3;
	
	cout << res << endl;
	
	return 0;
}

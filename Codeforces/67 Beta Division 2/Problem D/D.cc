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

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef long long ll;

ll n, m;
ll l[51];
ll sum[51], psum[51], ssum[51], a[51][5000], best[51]; 
ll b[250010];



int main(){ _
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> l[i];
		
		for(int j = 0; j < l[i]; j++){
			cin >> a[i][j];
			sum[i] += a[i][j];
		}
		
		ll cur;
		cur = psum[i] = a[i][0];
		for(int j = 1; j < l[i]; j++){
			cur += a[i][j];
			psum[i] = max(psum[i], cur);
		}
		
		cur = ssum[i] = a[i][l[i]-1];
		for(int j = l[i]-2; j >= 0; j--){
			cur += a[i][j];
			ssum[i] = max(ssum[i], cur);
		}
		
		cur = a[i][0];
		ll tmp = cur;
		if(cur < 0) cur = 0;
		for(int j = 1; j < l[i]; j++){
			cur += a[i][j];
			tmp = max(tmp, cur);
			if(cur < 0) cur = 0;
		}
		best[i] = tmp;
		
//		tr5(i,sum[i],psum[i],ssum[i],best[i]);
	}
	
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	
	ll res = max(max(ssum[b[1]], psum[b[1]]), sum[b[1]]);
	res = max(res, best[b[1]]);
	ll cur = max(sum[b[1]], ssum[b[1]]);
	
	if(cur < 0) cur = 0;
	
//	tr(res);
	
	for(int i = 2; i <= m; i++){
		res = max(res, max(cur+psum[b[i]], cur+sum[b[i]]));
		cur += sum[b[i]];
		res = max(res, best[b[i]]);
		cur = max(max(ssum[b[i]], sum[b[i]]), cur);
		if(cur < 0) cur = 0;
//		tr3(i,cur,res);
	}
	
	cout << res << "\n";
	
	return 0;
}

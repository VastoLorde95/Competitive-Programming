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

const int N = 1000100;

long long MOD = 1e9 + 7;

int t, n, m;
int dp[N], cnt[N][3];
int a[N];
int d[10];

long long fast(long long a, long long b){
	long long ret = 1;
	while(b){
		if((b&1)) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ret;
}

int main(){
	for(int i = 0; i < 10; i++){
		dp[i] = 1;	// 1 implies losing for first
	}
	
	d[0] = 1;
	for(int i = 1; i <= 9; i++){
		d[i] = d[i-1]*10;
	}	
	
	for(int i = 10; i < N; i++){
		int res = 0, len = 0, tmp = i;
		while(tmp){len++; tmp /= 10;}
		
		for(int j = 1; j < len; j++){
			int d1 = (i%d[j+1])/d[j];
			int d2 = (i%d[j])/d[j-1];
			d1 += d2;
			if(d1 >= 10) d1 -= 10;
			int nxt = (i/d[j+1])*d[j] + d1*d[j-1] + (i%d[j-1]);
			
			res |= dp[nxt];
		}
		if(res == 1){
			dp[i] = 2;	// odd number of steps
		}
		else if(res == 2){
			dp[i] = 1;	// even number of steps
		}
		else if((res&1) > 0 and (res&2) > 0){
			dp[i] = 4;	// first player can choose what he wants
		}
		else if((res&1) > 0){
			dp[i] = 2;
		}
		else if((res&2) > 0){
			dp[i] = 1;
		}
	}
	
	for(int i = 1; i < N; i++){
		for(int j = 0; j < 3; j++){
			cnt[i][j] = cnt[i-1][j] + (dp[i] == (1<<j));
		}
	}
	
	sd(t);
	while(t--){
		sd2(n,m);
		int s1 = 0, s2 = 0, s3 = 0;
		int t1 = cnt[n][0], t2 = cnt[n][1], t3 = cnt[n][2];
		
		
		for(int i = 0; i < m; i++){
			sd(a[i]);
			s1 += (dp[a[i]] == 1), s2 += (dp[a[i]] == 2), s3 += (dp[a[i]] == 4);
		}
	
		t1 -= s1;
		t2 -= s2;
		t3 -= s3;
		
		long long ans = fast(2,t1);
		tr4(ans, s2, t2, t3);
		if(s2%2 == 1){
			long long x1 = 1;
			if(t2 > 1 and t3 > 0){
				x1 = (x1 * fast(2, t2-1 + t3-1))%MOD;
			}
			else if(t3 > 0){
				x1 = (x1 * fast(2, t3-1))%MOD;
			}
			else x1 = 0;
			
			long long x2 = 1;
			int sub = 0;
			if(t2 > 0){
				x2 = (x2 * fast(2, t2-1))%MOD;
				if(t3 > 1){
					x2 = (x2 * fast(2, t3-1))%MOD;
				}
				else{
					sub = 1;
				}
			}
			else x2 = 0;
			
			ans = (ans*(x1+x2)%MOD)%MOD;
			ans = (ans-sub+MOD)%MOD;
		}
		else{
			tr("here");
			bool ok = false;
			long long x1 = 1;
			int sub = 0;
			if(t2 > 1){
				x1 = (x1* fast(2, t2-1))%MOD;
				if(t3 > 1){
					x1 = (x1 * fast(2, t3-1))%MOD;
				}
				if(ans > 1) sub = 1;
			}
			else if(t3 > 1){
				x1 = (x1 * fast(2, t3-1))%MOD;
				if(ans > 1) sub = 1;
			}	
			else{
				x1 = 0;
				if(ans > 1) sub = 1;
			}
			
			long long x2 = 1;
			if(t2 > 0 and t3 > 0){
				x2 = (x2 * fast(2, t2-1+t3-1))%MOD;
				ok = true;
			}
			else x2 = 0;
	
			ans = (ans * (x1+x2)%MOD)%MOD;	
			ans = (ans - sub + MOD)%MOD;	
			
		}
		
		printf("%lld\n", ans);
		
		
	}
	
	return 0;
}

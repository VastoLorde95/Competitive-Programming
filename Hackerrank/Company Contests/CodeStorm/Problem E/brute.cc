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
int dp[N], cnt[N][4];
int a[N];
int d[10];

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
		else if((res&8) > 0){
			dp[i] = 4;
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
		else if(res == 4){
			dp[i] = 8;	// second player decides the outcome
		}
	}	
	for(int i = 1; i < N; i++){
		for(int j = 0; j < 4; j++){
			cnt[i][j] = cnt[i-1][j] + (dp[i] == (1<<j));
		}
	}
	
	sd(t);
	while(t--){
		sd2(n,m);
		set<int> s;
		int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
		for(int i = 0; i < m; i++){
			sd(a[i]);
			s.insert(a[i]);
			s1 += (dp[a[i]] == 1), s2 += (dp[a[i]] == 2), s3 += (dp[a[i]] == 4), s4 += (dp[a[i]] == 8);
		}
		
		vector<int> v;
		for(int i = 1; i <= n; i++){
			if(!s.count(i)){
				v.pb(i);
			}
		}
		int l = v.size(), up = (1ll<<l);
		long long ans = 0;
		for(int i = 1; i < up; i++){
			int t1 = s1, t2 = s2, t3 = s3, t4 = s4;
			for(int j = 0; j < l; j++){
				if((i&(1ll<<j)) > 0){
					t1 += (dp[v[j]] == 1), t2 += (dp[v[j]] == 2), t3 += (dp[v[j]] == 4), t4 += (dp[v[j]] == 8);
				}
			}
			
			if(t2%2 == 1){
				if(t3%2 == 1){
					ans++;
				}
			}
			else{
				if(t3%2 == 0){
					ans++;
				}
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

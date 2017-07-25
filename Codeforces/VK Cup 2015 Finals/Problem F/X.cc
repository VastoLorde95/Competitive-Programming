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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 1001000;
int l[N], dp[N], cnt[N], res, mxv, n;

int main(){
	sd(n);
	int x, y;
	for(int i = 0; i < n; i++){
		sd(x);
		cnt[x]++;
		mxv = max(mxv, x);
	}
	for(int i = 2; i <= mxv; i++){
		if(l[i] == 0){
			l[i] = i;
			for(int j = i; j <= mxv/i; j++){
				if(l[i*j] == 0) l[i*j] = i;
			}
		}	
	}
	res = dp[1] = cnt[1]; l[1] = 1;
	for(int i = 2; i <= mxv; i++){
		dp[i] = dp[1], x = i, y = l[i];
		while(x != 1){
			y = l[x];
			while(x%y ==0) x /= y;
			dp[i] = max(dp[i], dp[i/y]);
			tr4("yo",i,i/y,dp[i/y]);
		}
		dp[i] += cnt[i];
		tr3(i,dp[i],cnt[i]);
		res = max(res, dp[i]);
	}
	tr(res);
	return 0;
}

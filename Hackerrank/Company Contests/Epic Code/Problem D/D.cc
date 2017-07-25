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

int n;
long long a[3001], dp[3001], cur, mx, inf = 1e17;
long long v[3001], v2[3000];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	mx = -inf;
	
	for(int i = 0; i < n; i++) v2[i] = v[i] = -inf;
	
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			cur = a[i]*a[j];
			mx = max(mx, max(cur, v[j+1]+cur));
			
			v2[j] = max(cur, v[j+1]+cur);
		}
		for(int i = 0; i < n; i++) v[i] = v2[i];
	}
	
	for(int i = 0; i < n; i++) mx = max(mx, v[i]);
	tr(mx);
	
	return 0;
}

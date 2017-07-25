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

int a[100], n, m, cur, mn = 100000, mx = 0, ans;
vector<int> o;

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		sd(a[i]);	
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	
	for(int i = 1; i < m; i++) cur += abs(a[i]-a[i-1]);
	
	tr2("Originally", cur);
	ans = cur;
	
	for(int i = 0; i < m; i++) o.pb(a[i]);
	
	for(int i = 0; i < m; i++){
		for(int j = mn; j <= mx; j++){
			vector<int> nn(o);			
			for(int k = 0; k < m; k++){
				if(nn[k] == o[i]) nn[k] = j;
			}
			
			int newcost = 0;
			for(int k = 1; k < m; k++){
				newcost += abs(nn[k]-nn[k-1]);
			}
			
			tr4("Changed",o[i],j,newcost);
			ans = min(ans, newcost);
		}
	}
	
	tr(ans);
	return 0;
}

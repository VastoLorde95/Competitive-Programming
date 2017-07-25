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

long long n, m, a[100100];
long long tot, cur, s1, s2, ans;

vector<long long> v[100100];

int main(){	_
	cin >> n >> m;
	for(long long i = 0; i < m; i++){
		cin >> a[i];
	}
	
	if(m == 1){
		cout << 0 << endl; return 0;
	}
	
	for(long long i = 1; i < m; i++){
		tot += abs(a[i]-a[i-1]);
	}
	
	ans = tot;

	if(a[1] != a[0]) v[a[0]].pb(a[1]);
	if(a[m-2] != a[m-1]) v[a[m-1]].pb(a[m-2]);
	
	for(long long i = 1; i < m-1; i++){
		if(a[i-1] != a[i]) v[a[i]].pb(a[i-1]);
		if(a[i+1] != a[i]) v[a[i]].pb(a[i+1]);
	}
	
	for(long long i = 1; i <= n; i++){
		if(v[i].size() > 0){
			
			sort(v[i].begin(), v[i].end());
			cur = 0, s1 = 0, s2 = 0;
			
			foreach(it, v[i]){
				cur += abs(i - (*it));
				s2 += *it;
			}
			
			long long sz = v[i].size();
			
			for(long long j = 0; j < sz; j++){
				s1 += v[i][j];
				s2 -= v[i][j];
				
				ans = min(ans, tot-cur+ (s2 - ((sz-j-1)*v[i][j])) + ((v[i][j]*(j+1)) - s1));
				
//				tr3(i,j,ans);
			}		
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

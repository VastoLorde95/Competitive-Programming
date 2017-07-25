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

long long n, r, avg;
vector<pair<long long, long long> > x;
long long a, b;
long long tot, target, cost;

int main(){ _	
	cin >> n >> r >> avg;
	
	target = avg*n;
	
	
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		tot += a;
		x.pb(mp(b,a));
	}
	
	if(tot >= target){
		cout << 0 << endl;
		return 0;
	}
	
	sort(x.begin(), x.end());
	
	
	for(int i = 0; i < n; i++){
		if((r-x[i].se)+tot > target){
			cost += (target-tot)*x[i].fi;
			tot = target;
			break;
		}
		else{
			tot += (r-x[i].se);
			cost += (r-x[i].se)*x[i].fi;
		}
	}
	
	cout << cost << "\n";
	
	return 0;
}

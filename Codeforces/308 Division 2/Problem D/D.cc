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

long long n;
long long ans;
vector<pair<int, int> > pts;

map<long double, int> m;

int main(){
	cin >> n;
	ans = 0;
	
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		pts.pb(mp(x,y));
	}
	
//	sort(pts.begin(), pts.end());	
		
	for(int i = 0; i < n; i++){
		m.clear();
		long long inf = 0;
		for(int j = i+1; j < n; j++){
			if(pts[i].fi == pts[j].fi) inf++;
			else{
//				tr3((double)(pts[i].se - pts[j].se)/(double)(pts[i].fi-pts[j].fi), i, j);
				m[(long double)(pts[i].se - pts[j].se)/(long double)(pts[i].fi-pts[j].fi)]++;
			}
		}		
		long long cnt = n-i-1;
		
		ans += (cnt*(cnt-1))/2;
		
		foreach(it, m){
			if(it->se > 1){
				ans -= (it->se * (it->se -1))/2;
			}
		}
		
		if(inf > 1) ans -= (inf*(inf-1))/2;
	}
	
	cout << ans << endl;
	return 0;
}

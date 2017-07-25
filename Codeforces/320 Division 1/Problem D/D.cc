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

int n, m;
string s;
vector<pair<int,int> > v;

long long ans = 0;

int main( ){ _
	cin >> n >> m;
	cin >> s;
	int l = s.length();
	int cur = 1, x = 1;
	for(int i = 1; i < l; i++){
		if(s[i] == s[i-1]){
			cur++;
			x++;
		}
		else{
			v.pb(mp(cur,x));
			cur = 1, x = 1;
		}
	}
	if(cur > 0){
		v.pb(mp(cur,x));
	}
	
	int sz = v.size();
	for(int i = 0; i < sz; i++){
		ans += ((m-1)*v[i].se) + ((m-1) * (l-v[i].se)) - (sz-1);
//		tot += v[i].se;
	}
	
	tr(ans);
	
	return 0;
}

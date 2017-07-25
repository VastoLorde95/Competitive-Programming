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

typedef long long ll;
typedef pair<ll, ll> pll;

int h, q, ii, ans, n;
ll l, r, inf = 1LL<<60;
vector<pll> y, no, d, nxt;
set<pll> v;
set<pll>::iterator it;

int main(){ _
	cin >> h >> q;
	for(int i = 0; i < q; i++){
		cin >> ii >> l >> r >> ans;
		l <<= (h-ii);
		while(ii < h) r <<= 1, r += 1, ii++;
		
		if(ans) y.pb(mp(l,r)); else no.pb(mp(l,r));		
	}
	
	sort(y.begin(), y.end());
	sort(no.begin(), no.end());
	
	l = 1LL<<(h-1), r = (1LL<<h)-1;
	
	n = y.size();
	
	for(int i = 0; i < n; i++){
		if(y[i].fi > r or y[i].se < l){
			puts("Game cheated!"); return 0;
		}
		l = max(l, y[i].fi), r = min(r, y[i].se);
	}
	
	v.insert(mp(l,r));
	
	n = no.size();
	
	for(int i = 0; i < n and !v.empty(); i++){
		it = v.upper_bound(mp(no[i].se, inf));
		if(it == v.begin()) continue;
		it--;
		
		d.clear(), nxt.clear();
		while(it->se >= no[i].fi){
			d.pb(*it);
			if(it->se > no[i].se and it->fi >= no[i].fi)
				nxt.pb(mp(no[i].se+1, it->se));
			else if(it->fi < no[i].fi and it->se <= no[i].se)
				nxt.pb(mp(it->fi, no[i].fi-1));
			else if(it->fi < no[i].fi and it->se > no[i].se){
				nxt.pb(mp(it->fi, no[i].fi-1));
				nxt.pb(mp(no[i].se+1, it->se));
			}
			
			if(it == v.begin()) break;
			it--;
		}
		
		foreach(it, d) v.erase(*it);
		foreach(it, nxt) v.insert(*it);
	}
	
	if(v.empty()) puts("Game cheated!");
	else if(v.size() == 1){
		pll p = *v.begin();
		if(p.fi == p.se) cout << p.fi << "\n"; else puts("Data not sufficient!");
	}
	else puts("Data not sufficient!");
	
	return 0;
}

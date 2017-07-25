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

long long n, m;
long long res[200100];
long long l, r, a, up[200100], down[200100];
vector<pair<long long, long long> > is;
set<pair<long long, long long> > b;
set<pair<long long, long long> >::iterator it2;
vector<pair<long long, long long> > inter;

bool cmp(const pair<long long, long long> &p1, const pair<long long, long long> &p2){
	return up[p1.se] < up[p2.se];
}

int main(){ _
	cin >> n >> m;
	for(long long i = 0; i < n; i++){
		cin >> l >> r;
		is.pb(mp(l,r));
	}
	for(long long i = 0; i < m; i++){
		cin >> a;
		b.insert(mp(a,i+1));
	}

	for(long long i = 1; i < n; i++){
		down[i] = is[i].fi - is[i-1].se;
		up[i] = is[i].se - is[i-1].fi;
		
		inter.pb(mp(up[i]-down[i],i));
		
	}
	
	sort(inter.begin(), inter.end(), cmp);
	
	foreach(it, inter){
	
//		tr2(it->fi, it->se);
	
		long long id = it->se;
		long long x = up[id], y = down[id];
		it2 = b.lower_bound(mp(y,0));
		
		if(it2 == b.end()){
			cout << "No\n"; return 0;
		}
		if(it2->fi > up[id]){
			cout << "No\n"; return 0;
		}
		
		res[id] = it2->se;
		b.erase(it2);
	}
	
	cout << "Yes\n";
	for(long long i = 1; i < n; i++){
		cout << res[i] << " ";
	}
	cout << "\n";
	
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <unordered_map>
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

int n, m, a[1001000], l[1001000], r[1001000];
int s[1001000], tp;
unordered_map<int, ll> cnt;
vector<pair<int,ll> > gcnt, lcnt;
vector<pair<int, ll> > tmp;
vector<pair<int, ll> >::iterator it;
ll tmpp, INF = 1LL<<60;


int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	l[0] = -1;
	s[0] = 0; tp = 0;
	for(int i = 1; i < n; i++){
		while(tp >= 0 and a[i] > a[s[tp]]) tp--;
		if(tp >= 0)
			l[i] = s[tp];
		else
			l[i] = -1;
		s[++tp] = i;
	}
	
	r[n-1] = n;
	s[0] = n-1; tp = 0;
	for(int i = n-2; i >= 0; i--){
		while(tp >= 0 and a[i] >= a[s[tp]]) tp--;
		if(tp >= 0)
			r[i] = s[tp];
		else
			r[i] = n;
		s[++tp] = i;
	}
	
	for(int i = 0; i < n; i++){
		cnt[a[i]] += (ll) (r[i] - i) * (i - l[i]);
	}
	
	foreach(itt, cnt){
		tmp.pb(*itt);
	}
	
	sort(tmp.begin(), tmp.end());
	
	int sz = tmp.size();
	
	lcnt.pb(mp(tmp[0].fi, tmp[0].se));
	for(int i = 1; i < sz; i++){
		lcnt.pb(mp(tmp[i].fi, lcnt[i-1].se + tmp[i].se));
	}
	
	gcnt.pb(mp(tmp[sz-1].fi, tmp[sz-1].se));
	for(int i = sz-2; i >= 0; i--){
		gcnt.pb(mp(tmp[i].fi, gcnt[sz-i-2].se + tmp[i].se));
	}
	
	reverse(gcnt.begin(), gcnt.end());
	
	char c, d;
	int x;
	while(m--){
		scanf(" %c%d %c", &c, &x, &d);
		
		if(c == '='){
				tmpp = cnt[x];
		}
		else if(c == '<'){
				it = lower_bound(lcnt.begin(), lcnt.end(), mp(x, -1LL));
				if(it == lcnt.begin()){
					tmpp = 0;
				}
				else{
					it--;
					tmpp = it->se;
				}
		}
		else{
				it = upper_bound(gcnt.begin(), gcnt.end(), mp(x,INF));
				if(it == gcnt.end()){
					tmpp = 0;
				}
				else{
					tmpp = it->se;
				}
		}
		
		if((tmpp&1) == 0){
			if(d == 'D')
				printf("C");
			else
				printf("D");
		}
		else{
			printf("%c", d);
		}
	}
		
	puts("");	
	
	return 0;
}

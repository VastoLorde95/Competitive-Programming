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

int n, m, s, t, v[100100], cnt1[100100], cnt2[100100];
ll d1[100100], d2[100100], d3[100100], len[100100], thres;
vector<pair<int, int> > g[100100], rg[100100];
vector<pair<int, int> > roads;
bool ok[100100];

void sp1(){
	memset(v, 0, sizeof v);
	priority_queue<pair<ll, int> > q;
	q.push(mp(0LL, s));
	while(!q.empty()){
		int cur = q.top().se;
		ok[cur] = true;
		ll dd = -q.top().fi;
		q.pop();
		if(v[cur]) continue;
		
		d1[cur] = dd;
		v[cur] = 1;
		
		foreach(it, g[cur]){
			ll dis = d1[cur];
			if(!v[it->fi]){
				q.push(mp(-1LL*(dis + it->se), it->fi));
			}
		}
	}
	
	return;
}

void sp2(){
	memset(v, 0, sizeof v);
	priority_queue<pair<ll, int> > q;
	q.push(mp(0LL, t));
	while(!q.empty()){
		int cur = q.top().se;
		ll dd = -q.top().fi;
		q.pop();
		if(v[cur]) continue;
		
		d2[cur] = dd;
		v[cur] = 1;
		
		foreach(it, rg[cur]){
			ll dis = d2[cur];
			if(!v[it->fi]){
				q.push(mp(-1LL*(dis + it->se), it->fi));
			}
		}
	}
	return;
}

void sp3(){
	memset(v, 0, sizeof v);
	priority_queue<pair<ll, int> > q;
	q.push(mp(0LL, s));
	while(!q.empty()){
		int cur = q.top().se;
		ll dd = -q.top().fi;
		q.pop();
		if(v[cur]) continue;
		
		d3[cur] = dd;
		v[cur] = 1;
		
		foreach(it, g[cur]){
			ll dis = d3[cur];
			if(!v[it->fi]){
				q.push(mp(-1LL*(dis + it->se), it->fi));
			}
			if(dis+(long long) it->se == d1[it->fi] and d1[cur] + d2[it->fi] + (long long)it->se == thres) cnt1[cur]++, cnt2[it->fi]++;
		} 
	}
	return;
}

int main(){
	sd2(n,m); sd2(s,t);
	for(int i = 0; i < m; i++){
		int a, b, l; sd3(a,b,l);
		g[a].pb(mp(b,l));
		rg[b].pb(mp(a,l));
		roads.pb(mp(a,b));
		len[i] = l;
	}
	
	for(int i = 1; i <= n; i++){
		ok[i] = false;
	}
	
	sp1();
	sp2();
	thres = d1[t];
	sp3();
	
	for(int i = 0; i < m; i++){
		if(!ok[roads[i].fi] or !ok[roads[i].se] or !ok[t]){
			printf("NO\n");
			continue;
		}
		if(cnt1[roads[i].fi] == 1 and cnt2[roads[i].se] == 1 and d1[roads[i].fi] + d2[roads[i].se] + len[i] == thres){
			printf("YES\n");
		}
		else if(len[i] -(d1[roads[i].fi] + d2[roads[i].se] + len[i] - (thres - 1LL)) > 0 and (d1[roads[i].fi] + d2[roads[i].se] + len[i] - (thres - 1LL)) > 0){
			printf("CAN %I64d\n", (d1[roads[i].fi] + d2[roads[i].se] + len[i] - thres + 1LL));
		}
		else{
			printf("NO\n");
		}
	}
	
	return 0;
}

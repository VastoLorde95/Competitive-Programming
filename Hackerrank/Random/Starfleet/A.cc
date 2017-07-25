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

int n, q, v, x, y, yu, yd, t, fr;

int cnt1, cnt2;

set<int> cy, cf;
map<int, int> fy, ff;
vector<pair<int, pair<int, int> > > qr, fighters;
vector<int> f[200100];
int root, counter[200100], res[35000], cur;

bool comp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
	int a = p1.fi/root, b = p2.fi/root;
	if(a == b){
		if(p1.se.fi == p2.se.fi) return p1.fi < p2.fi;
		return p1.se.fi < p2.se.fi;
	}
	else return a < b;
}

map<int,int> gett;

void add(int indx){
	foreach(it, f[indx]){
		gett[counter[*it]]--;
		if(gett[counter[*it]] == 0) gett.erase(counter[*it]);
		++counter[*it];
		gett[counter[*it]]++;
	}
	return;
}
void remove(int indx){
	foreach(it, f[indx]){
		gett[counter[*it]]--;
		if(gett[counter[*it]] == 0) gett.erase(counter[*it]);
		--counter[*it];
		gett[counter[*it]]++;
	}
	return;
}

int main(){
	sd3(n,q,v);
	for(int i = 0; i < n; i++){
		sd3(x,y,fr);
		cy.insert(y);
		cf.insert(fr);
		fighters.pb(mp(x,mp(y,fr)));
	}	
	
	int mn = 1e9, mx = -1e9;
	
	for(int i = 0; i < q; i++){
		sd3(yu,yd,t);
		qr.pb(mp(yd,mp(yu,i)));
	}
	
	foreach(it, cy){
		fy[*it] = cnt1++;
	}
	
	foreach(it, cf){
		ff[*it] = cnt2++;
	}
	
	for(int i = 0; i < n; i++){
		fighters[i].se.fi = fy[fighters[i].se.fi];
		fighters[i].se.se = ff[fighters[i].se.se];
		counter[fighters[i].se.se]++;
		f[fighters[i].se.fi].pb(fighters[i].se.se);
	}
	
	map<int, int>::iterator it;
	
	int tomb = cnt1+1000;
	
	cy.clear();
	cf.clear();
	
	for(int i = 0; i < q; i++){
		it = fy.lower_bound(qr[i].fi);
		if(it == fy.end())
			qr[i].fi = tomb;
		else
			qr[i].fi = it->se;
		it = fy.upper_bound(qr[i].se.fi);
		it--;
		qr[i].se.fi = it->se;
	}	
	
	root = int(sqrt(cnt1));

	sort(qr.begin(), qr.end(), comp);
	
	foreach(it, ff){
		gett[counter[it->se]]++;
	}
	
	int l = 0, r = cnt1-1;
	for(int i = 0; i < q; i++){
		int ll = qr[i].fi, rr = qr[i].se.fi;
		
		if(ll > rr){
			res[qr[i].se.se] = 0; continue;
		}
		
		while(l < ll) remove(l++);
		while(l > ll) add(--l);
		while(r < rr) add(++r);
		while(r > rr) remove(r--);
		res[qr[i].se.se] = gett.rbegin()->fi;
		
	}
	
	for(int i = 0; i < q; i++){
		printf("%d\n", res[i]);
	}
	
	return 0;
}

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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int N = 100100;

typedef pair<int,int> pii;

int n;
//pair<pii,pii> s[N];

set<int> compr;
int cnt;
map<int, int> f;

map<int, vector<pii> > row;
map<int, vector<pii> > col;
map<int, vector<pair<int, pii> > > e;

long long ans;

const int MAXN = 4*N;
long long tree[MAXN]; // Careful, indexing begins from 1.

long long query(int idx){
    long long sum = 0;
    while(idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx < MAXN){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

bool comp(const pii &p1, const pii &p2){
	if(p1.fi == p2.fi) return p1.se > p2.se;
	return p1.fi < p2.fi;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2; sd2(x1,y1); sd2(x2,y2);
		if(x1 == x2){// column
			if(y1 > y2) swap(y1,y2);
			col[x1].pb(mp(y1,y2));
		}
		else{// row
			if(x1 > x2) swap(x1,x2);
			row[y1].pb(mp(x1,x2));
		}
		compr.insert(x1);
		compr.insert(x2);
		compr.insert(y1);
		compr.insert(y2);
	}
	
	foreach(it, compr){
		f[*it] = ++cnt;
	}
	
	foreach(it, row){
		vector<pii> &v1 = it->se;
		vector<pii> v2;
		sort(v1.begin(), v1.end(), comp);
		
		pii cur = v1[0];
		for(int i = 1; i < v1.size(); i++){
			if(v1[i].fi > cur.se){
				v2.pb(cur);
				cur = v1[i];
			}
			else{
				cur.se = max(cur.se, v1[i].se);
			}
		}
		v2.pb(cur);
		it->se = v2;
		
		foreach(seg, v2){
//			tr3(it->fi, seg->fi, seg->se);
			ans += 1ll*(seg->se-seg->fi+1);
			e[seg->fi].pb(mp(1,mp(it->fi, -1)));
			e[seg->se+1].pb(mp(2,mp(it->fi, -1)));
		}
	}
	
//	tr(ans);
	
	foreach(it, col){
		vector<pii> &v1 = it->se;
		vector<pii> v2;
		sort(v1.begin(), v1.end(), comp);
		
//		foreach(seg, v1){
//			tr3(seg->fi, seg->se, it->fi);
//		}
		
		pii cur = v1[0];
		for(int i = 1; i < v1.size(); i++){
			if(v1[i].fi > cur.se){
				v2.pb(cur);
				cur = v1[i];
			}
			else{
				cur.se = max(cur.se, v1[i].se);
			}
		}
		v2.pb(cur);
		it->se = v2;
		
		foreach(seg, v2){
			e[it->fi].pb(mp(3,mp(seg->fi, seg->se)));
		}
	}
	foreach(it, e){
		vector<pair<int, pii> > &v = it->se;
		foreach(event, v){
			if(event->fi == 1){
//				tr3("adding row", it->fi, event->se.fi);
				update(f[event->se.fi], 1);
			}
			else if(event->fi == 2){
//				tr3("removing row", it->fi, event->se.fi);
				update(f[event->se.fi], -1);
			}
			else{
				long long b = event->se.se, a = event->se.fi;
				long long len = b - a + 1;
				len -= query(f[b])-query(f[a]-1);
//				tr4("column",a,b,len);
				ans += len;
			}
		}
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}

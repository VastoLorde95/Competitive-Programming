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

typedef long long ll;

const int N = 100000;

ll x, k;
vector<ll> d, res;
int steps = 0;

void go(int indx, ll step){
	++steps;
	if(res.size() == N) return;
	if(indx == 0){
		res.pb(1); return;
	}
	if(step == 0){
		res.pb(d[indx]); return;
	}
	
	for(int i = 0; i <= indx and res.size() < N; i++){
		if(d[indx]%d[i] == 0){
			go(i, step-1);
		}
	}
}

int main(){ _
	cin >> x >> k;
	if(x == 1){
		cout << 1 << endl; return 0;
	}
	if(k > N){
		for(int i = 0; i < N; i++) cout << "1 ";
		cout << endl; return 0;
	}

	for(ll i = 1; i*i <= x; i++){
		if(x%i == 0){
			d.pb(i);
			if(i*i != x) d.pb(x/i);
		}
	}
	
	sort(d.begin(), d.end());
	
	go(d.size()-1, k);		
	
	foreach(it, res){
		cout << *it << ' ';
	}
	cout << endl;
	
	tr(steps);
	
	return 0;
}

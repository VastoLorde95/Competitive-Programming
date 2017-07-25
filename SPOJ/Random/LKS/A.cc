#include <bits/stdc++.h>

#define sd2(x,y) scanf("%d%d",&x,&y)

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

const int M = 500, INF = 1e9;

int mx, n, k, sumv[M], sumw[M];

bool cmp(const pii &p1, const pii &p2){
	return (ll) p1.se * p2.fi > (ll) p1.fi * p2.se;
}

vector<pii> t;
inline int getBound(int x, int lim){
	int cur = 0, ben = 0;
	for(int i = x; i < n; i++)
		if(cur + t[i].fi <= lim) cur += t[i].fi, ben += t[i].se;
		else return ben + (1ll * t[i].se * (lim-cur)) / t[i].fi;
	return ben;
}

void branchAndBound(int x, int curb, int curw){
	if(x == n){
		mx = max(mx, curb);
		return;
	}
	
	if(sumw[x] + curw <= k){
		mx = max(mx, sumv[x] + curb);
		return;
	}
	
	int ub1 = (k - curw - t[x].fi >= 0)? curb + t[x].se + getBound(x+1, k - curw - t[x].fi) : -INF;
	int ub2 = curb + getBound(x+1, k - curw);
	
	if(ub1 <= mx and ub2 <= mx) return;
	
	if(ub1 > ub2){
		branchAndBound(x+1, curb + t[x].se, curw + t[x].fi);
		if(ub2 <= mx) return;
		branchAndBound(x+1, curb, curw);
	}
	else{
		branchAndBound(x+1, curb, curw);
		if(ub1 <= mx) return;
		branchAndBound(x+1, curb + t[x].se, curw + t[x].fi);
	}
	return;
}

int main(){
	sd2(k,n);
	
	t.resize(n);
	for(int i = 0; i < n; i++) sd2(t[i].se,t[i].fi);
	
	sort(t.begin(), t.end(), cmp);
	
	for(int i = 0; i < n; i++) sumv[i] = t[i].se, sumw[i] = t[i].fi;
	t.clear();
	
	for(int i = n-2; i >= 0; i--) sumv[i] += sumv[i+1], sumw[i] += sumw[i+1];
	
	branchAndBound(0, 0, 0);
	
	printf("%d", mx);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, m, a, l, b[200100], oo = (1e9) + 1, lft, rgt, s;
vector<pii> p;
vector<pii>::iterator it;

bool ok(){
	if(rgt == lft){
		s++;
		if(s == 2) return true;
	}
	else s = 0;
	return false;
}

int solve(){
	lft = rgt = a, s = 0;
	while(true){
		it = upper_bound(p.begin(), p.end(), make_pair(b[lft]+l, oo)); it--;
		rgt = it->second, l -= it->first - b[lft];

		if(ok() or l == 0) return rgt;

		it = lower_bound(p.begin(), p.end(), make_pair(b[rgt]-l, -oo));
		lft = it->second, l -= b[rgt] - it->first;

		long long d = 2LL * (long long) (b[rgt] - b[lft]);
		if(d) l %= d;
		
		if(ok() or l == 0) return lft;
	}


int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d", b+i); p.push_back(make_pair(b[i],i));
	}
	
	sort(p.begin(), p.end());

	while(m--){
		scanf("%d%d",&a,&l);
		printf("%d\n", solve());
	}
	return 0;
}

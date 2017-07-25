#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int getHeight(int x){
	int h = 0;
	for(; x; x >>= 1) h++;
	return h;
}

void solve(){
	int n, u, v;
	
	cin >> n >> u >> v;
	
	int h1 = getHeight(u);
	int h2 = getHeight(v);
	
	if(h1 < h2){
		swap(h1, h2), swap(u, v);
	}
	
	int p1 = 0, p2 = 0, i = 0, j = 0;
	
	while(u != v){
		if(u&1) p1 |= 1 << i;
		u >>= 1, h1--, i++;
		
		if(h1 < h2){
			if(v&1) p2 |= 1 << j;
			v >>= 1, h2--, j++;
		}
	}
	
	int ans = min((n-p1) / (1 << i), (n-p2) / (1 << j));
	cout << ans << '\n';
}

int main(){ _
	int q; cin >> q;
	while(q--) solve();
	return 0;
}

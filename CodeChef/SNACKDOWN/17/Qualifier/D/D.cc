#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

typedef long long ll;

const int N = 100100;

ll l[N];
ll sum[N];

void solve(){
	int n, q;
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++) cin >> l[i];
	
	sort(l+1, l+n+1);
	
	for(int i = 1; i <= n; i++) sum[i] = l[i];
	
	for(int i = 2; i <= n; i++) sum[i] += sum[i-1];
	
	while(q--){
		int k;
		cin >> k;
		
		int pos = lower_bound(l, l+n+1, k) - l;
		
		if(pos == 1){
			cout << n << '\n';
			continue;
		}
		
		int lo = 0, hi = pos - 1, mid;
		while(lo + 1 < hi){
			mid = (lo + hi) / 2;
			
			ll req = (ll) (pos - mid - 1) * (ll) k;
			ll have = sum[pos-1] - sum[mid];
			ll need = req - have;
			
			if(need > mid) lo = mid;
			else hi = mid;
		}
		
		cout << n - hi << '\n';
	}
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 100100;

int n;
ll a[N];
ll dp[N];

ll p[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	ll s1 = a[1];
	ll s2 = a[1];
	
	ll last = s1;
	for(int i = 2; i <= n; i++){
		s2 = (((s2 + p[i-2]) % MOD) * a[i]) % MOD;
		last = (s1 + s2) % MOD;
		s1 = (s1 + last) % MOD;
	}
	
	cout << last << endl;
	
}

int main(){ _
	p[0] = 1;
	for(int i = 1; i < N; i++){
		p[i] = p[i-1] * 2 % MOD;
	}

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;

int n;
ll a[100100];
map<ll, int> cnt;

int main(){ _
	cin >> n;
	
	int ans = n-1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
		ans = min(ans, n - ++cnt[a[i]]);
	}
	
	cout << ans << endl;
	
	return 0;
}

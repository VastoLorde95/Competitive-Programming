// K-Periodic Array
#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n, k, a[N], cnt1[N], cnt2[N], ans;

int main(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 1) cnt1[i%k]++; else cnt2[i%k]++;
	}
	
	for(int i = 0; i < k; i++) ans += min(cnt1[i], cnt2[i]);
	
	cout << ans << endl;
	
	return 0;
}

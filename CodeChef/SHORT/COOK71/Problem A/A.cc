#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 1;

int cnt[N];

void solve(){
	int n;
	cin >> n;
	
	fill(cnt, cnt+N, 0);
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}

	int mx = 0;	
	for(int i = N-1; i >= 0; i--) if(cnt[i] >= 4) mx = max(mx, i*i);
	
	for(int i = N-1; i >= 0; i--)
		for(int j = i-1; j >= 0; j--) if(cnt[i] > 1 and cnt[j] > 1) mx = max(mx, i*j);
	
	if(mx == 0) mx = -1;
	
	cout << mx << endl;
	
}

int main(){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

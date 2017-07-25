// Sereja and Suffixes
#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

int n, m, a[N], ans[N];
int h[N];

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int cnt = 0;
	for(int i = n-1; i >= 0; i--){
//		s.insert(a[i]);
		if(!h[a[i]]) cnt++;
		h[a[i]] = 1;
		ans[i] = cnt;
	}
	
	int l;
	for(int i = 0; i < m; i++){
		cin >> l;
		cout << ans[l-1] << endl;
	}
	
	return 0;
}

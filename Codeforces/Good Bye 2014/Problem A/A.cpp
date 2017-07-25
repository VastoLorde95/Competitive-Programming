#include <bits/stdc++.h>
using namespace std;	

int n, t, a[30001], cur = 1;

int main(){
	cin >> n >> t;
	
	for(int i = 1; i < n; i++) cin >> a[i];
	
	while(cur < t) cur += a[cur];
	
	if(cur == t) puts("YES");
	else puts("NO");
	
	return 0;
}

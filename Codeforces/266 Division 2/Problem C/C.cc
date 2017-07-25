// Number of Ways
#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

int n;
long long a[N], sum[N], val, cnt, res;

int main(){
	cin >> n;
	cin >> a[0];
	
	sum[0] = a[0];
	
	for(int i = 1; i < n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	
	if(sum[n-1]%3 != 0){
		cout << 0 << endl;
		return 0;
	}
	
	val = sum[n-1]/3;
	
	for(int i = 0; i < n-1; i++){
		if(sum[i] == val){
			if(val == 0) res += cnt;	
			cnt++;
		}
		else if(sum[i] == 2*val) res += cnt;
	}
	
	cout << res << endl;
	
	return 0;
}

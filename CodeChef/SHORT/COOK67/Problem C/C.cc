#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

typedef long long ll;

const int N = 300100;

ll x[N];
ll y[N];

ll sumlx[N], sumrx[N];
ll sumly[N], sumry[N];

string s;

int main(){ _
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	
	sort(x, x+n);
	sort(y, y+n);

	for(int i = 0; i < n; i++){
		sumlx[i] = sumrx[i] = x[i];
		sumly[i] = sumry[i] = y[i];	
	}
	
	for(int i = 1; i < n; i++) sumlx[i] += sumlx[i-1], sumly[i] += sumly[i-1];
	for(int i = n-2; i >= 0; i--) sumrx[i] += sumrx[i+1], sumry[i] += sumry[i+1];

	cin >> s;
	
	ll x0 = 0, y0 = 0;
	for(int i = 0; i < m; i++){
		if(s[i] == 'D') y0--;
		else if(s[i] == 'U') y0++;
		else if(s[i] == 'L') x0--;
		else x0++;
		
		int p1 = lower_bound(x, x+n, x0) - x;
		int p2 = lower_bound(y, y+n, y0) - y;
		
		ll d1 = (sumrx[p1] - x0 * (n-p1)) + ((p1-1 >= 0)? (x0 * p1 - sumlx[p1-1]) : 0);
		ll d2 = (sumry[p2] - y0 * (n-p2)) + ((p2-1 >= 0)? (y0 * p2 - sumly[p2-1]) : 0);
		
		cout << d1 + d2 << '\n';
	}
	
	return 0;
}

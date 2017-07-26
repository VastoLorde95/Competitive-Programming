#include <bits/stdc++.h>
using namespace std;

/*
1245375689
1997333137
1636616323
100123456789
101234567897
101111111111
1000000000000037
1011001110001111
70000006660000007
*/

typedef long long ll;

struct RollingHash{
	vector<ll> pwr, hsh;
	ll A, M;
	int n;
	
	RollingHash(string &s, ll _A, ll _M){
		n = s.length();
		pwr.resize(n+1); hsh.resize(n+1);
		
		A = _A, M = _M;
		
		pwr[0] = 1;
		for(int i = 1; i <= n; i++) pwr[i] = pwr[i-1] * A % M;
		
		hsh[0] = s[0] % M;
		for(int i = 1; i < n; i++){
			hsh[i] = (hsh[i] * A % M) + s[i]; if(hsh[i] >= M) hsh[i] -= M;
		}
	}
	
	ll getHash(int x, int y){
		assert(x >= 0 and x < n and y >= 0 and y <= n);
		return (hsh[y] + M - ((x-1 >= 0)? hsh[x-1] * pwr[y-x+1] % M : 0)) % M;
	}
};

int main(){
	
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef int64_t q;
q a, b, d, B, f=10;
q s(q x, q l, q p){
	if(p > x) return 0;
	B = (x / p) % 10;
	return (p / f * l * B) + (p * (d < B)) + ((x % p + 1)*(d == B)) + s(x, l+1, p*f);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> a >> b;
		q res = 0;
		for(d = 1; d < f; d++) res += (s(b, 0, 1) - s(a-1, 0, 1)) * d;
		cout << res << endl;
	}
	return 0;
}

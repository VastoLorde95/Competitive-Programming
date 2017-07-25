#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	if(a * b == c * d or a * c == b * d or a * d == b * c) puts("Possible"); else puts("Impossible");
	
	return 0;
}

#include <bits/stdc++.h>
#define sd(x) scanf("%d",&x)
#define pb push_back
using namespace std;
int main(){
	int n, d; sd2(n,d);
	vector<int> v(n);
	for(int i = 0; i < n; i++) sd(v[i]);
	for(int i = 0; i < d; i++) v.pb(v[i]);
	for(int i = d; i < n+d; i++) printf("%d ", v[i]);
	puts("");
	return 0;
}

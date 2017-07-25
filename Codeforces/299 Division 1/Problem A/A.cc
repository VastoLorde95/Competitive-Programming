#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;

long long a, b, n, l, t, m, r, fnd, cur, f, mx = 1000000000000LL;

vector<long long> v, s;

int main(){
	cin >> a >> b >> n;
	
	v.pb(a);
	s.pb(a);
	
	cur = 0;
	
	for(int i = 1; i < 2000000; i++){
		v.pb(v[i-1] + b);
		s.pb(s[i-1] + v[i]);
	}
	
	while(n--){
		cin >> l >> t >> m;
		
		if(l == 1) cur = 0;
		else cur = s[l-2];
		fnd = cur+(m*t);
		
		//cout<< cur << " " << fnd << endl;
		
		if(t < v[l-1]){
			cout << -1 << "\n";
			continue;
		}
		
		vector<long long>::iterator it = upper_bound(s.begin(), s.end(), fnd);
		vector<long long>::iterator it2 = upper_bound(v.begin(), v.end(), t);
		
		
		long long res = min(it - s.begin(), it2 - v.begin());
		
		cout << res << endl;
		
		
	}
	return 0;
}

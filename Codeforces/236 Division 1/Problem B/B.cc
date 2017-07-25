#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, a[6000], gcd[6000], bad;
set<int> b;
vector<int> primes;

bool good(int num){
	int sz = primes.size(), tot = 0;
	for(int i = 0; i < sz and primes[i] <= num; i++){
//		tr3("#",i,num);
		int cnt = 0;
		while(num%primes[i] == 0){
			cnt++;
			num /= primes[i];
		}
		if(b.count(primes[i])) tot -= cnt;
		else tot += cnt;
	}
	if(num > 1){
		if(b.count(num)) tot--; else tot++;
		
	}
	if(tot < 0) return true;
	return false;
}

int main(){
	primes.pb(2);
	for(int i = 3; i < 33000; i += 2){
		bool ok = true;
		foreach(it, primes){
			if(i%(*it) == 0){
				ok = false;
				break;
			}
		}
		if(ok) primes.pb(i);
	}		
	
	sd2(n,m);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	for(int i = 0; i < m; i++){
		sd(bad); b.insert(bad);
	}
	
	gcd[0] = a[0];
	for(int i = 1; i < n; i++){
		gcd[i] = __gcd(a[i], gcd[i-1]);
//		tr2(i, gcd[i]);
	}
	
	int i = 0;
	while(i < n and gcd[i] > 1) i++;
	i--;
	
//	tr(i);
	
	while(i >= 0){
		while(i >= 0 and gcd[i] == 1) i--;
		if(i < 0) break;
		
		if(good(gcd[i])){
//			tr3(i,gcd[i], "is good");
			for(int j = 0; j <= i; j++){
				a[j] /= gcd[i];
				gcd[j] /= gcd[i];
			}
			
//			for(int j = 0; j < n; j++){
//				cout << a[j] << " ";
//		
//			}
//			cout << endl;
		}
		else i--;
	}
	
	int ans = 0, sz = primes.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < primes.size() and primes[j] <= a[i]; j++){
			int cnt = 0;
			while(a[i]%primes[j] == 0){
				cnt++;
				a[i] /= primes[j];
			}
			if(b.count(primes[j])) ans -= cnt; else ans += cnt;
		}
		if(a[i] > 1){
			if(b.count(a[i])) ans--; else ans++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

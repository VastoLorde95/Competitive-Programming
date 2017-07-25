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

const int N = 10000001;
int sieve[N], primes[N], pcnt;

void getSieve(){
	for(int i = 2; i <= N; i++){
		if(sieve[i] == 0){
			sieve[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= sieve[i] and i*primes[j] <= N; j++) sieve[i*primes[j]] = primes[j];
	}
	return;
}

bool ispal(int num){
	int rev = 0;
	int tmp = num;
	while(tmp){
		rev *= 10;
		rev += tmp%10;
		tmp /= 10;
	}
	return rev == num;
}

set<int> pp;
map<long double, int> ans;

int main(){
	int p = 0, q = 0;
	int c1 = 0, c2 = 0;
	cin >> p >> q;
	getSieve();
	
	long double f = (long double) p/q;
//	tr(f);
	for(int i = 1; i <= 2000000; i++){
		if(ispal(i)) c1++;
		if(sieve[i] == i) c2++;			
		ans[(long double) c2/c1] = i;
	}
	
	int mx = 0;
	foreach(it, ans){
		if(it->fi > f) break;
		mx = max(mx, it->se);		
	}
	cout << mx << "\n";
	
	
	
	return 0;
}

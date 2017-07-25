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

int n;
vector<int> primes;
set<int> q;

int main(){
	sd(n);
	if(n == 1){
		cout << 0 << "\n";
		return 0;
	}
	
	primes.pb(2);
	for(int i = 3; i <= n; i++){
		bool ok = true;
		foreach(it, primes){
			if(i%(*it) == 0) ok = false;
		}
		if(ok) primes.pb(i);
	}
	
	foreach(it, primes){
		int cur = *it;
		while(cur <= n){
			q.insert(cur);
			cur *= *it;
		}
	}
	
	tr(q.size());
	foreach(it, q){
		cout << *it << " ";
	}
	cout << "\n";
	
	return 0;
}

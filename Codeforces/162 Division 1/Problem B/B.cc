#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, a[100100], pos[100100], l[100100], mx = 1;

const int N = 1000001;
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

int main(){
	getSieve();
	
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		vector<int> up;
		while(a[i] > 1){
//			tr4(i, a[i], sieve[a[i]], l[i]);
			l[i] = max(l[i], l[pos[sieve[a[i]]]]+1);
			up.pb(sieve[a[i]]);
			a[i] /= sieve[a[i]];
		}
		
		for(int j = 0; j < up.size(); j++){
			pos[up[j]] = i;
		}

//		tr2("exit",l[i]);
		
		mx = max(mx,l[i]);
	}
	
	tr(mx);
	
	return 0;
}

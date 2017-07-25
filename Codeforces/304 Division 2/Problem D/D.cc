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

const int N = 5001001;
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

int t, a, b, tmp;
int sum[N];

int main(){ _
	getSieve();
	
	sum[1] = 0;
	
	for(int i = 2; i < N; i++){
		tmp = i;
		sum[i] = sum[i-1];
		while(sieve[tmp] != 0){
			sum[i]++;
			tmp /= sieve[tmp];
		}
	}
	
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << sum[a] - sum[b] << "\n";
	}
	
	return 0;
}

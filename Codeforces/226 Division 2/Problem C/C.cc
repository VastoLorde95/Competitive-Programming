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

using namespace std;

int n, m, x, cnt[10000001], sum[10000001], primes[10000001], l, r, N = 10000000;
	
int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd(x);
		cnt[x]++;
	}
	
	for(int i = 2; i <= N; i++){
		if(primes[i] == 0){
			primes[i] = i;
			if(i <= N/i){
				for(int j = i*i; j <= N; j += i){
					primes[j] = i;
				}
			}
		}
	}
	
	//cout << "dipshit" << endl;
	
	for(int i = N; i >= 2; i--){
		if(cnt[i] > 0){
			sum[primes[i]] += cnt[i];
			int j = i, k = primes[i];
			while(j%k == 0) j /= k;
			cnt[j] += cnt[i];	// dp, we get the count of the remaining primes from the smaller numbers below
		}
	}
	
	//cout << "dipshit" << endl;
	
	for(int i = 1; i <= N; i++){
		sum[i] += sum[i-1];		// we have the answer for [1, N]. We store the answer as partial sums. For numbers that are not primes,
		// sum[n] = sum[p] where p is the largest primes lesser than n
	}
	
	sd(m);
	
	for(int i = 0; i < m; i++){
		sd2(l, r);
		r = min(r, N);
		l = min(l, N+1);	// N+1 since we are going to do l-1
		printf("%d\n", sum[r] - sum[l-1]);
	}
	
	
	return 0;
}

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

using namespace std;

int t, n, m;
vector<pair<int, int> > primes;
long long sum = 1;

void compute(int i, int num){
	if(i == primes.size())
		return;
	int tmp = num;
	compute(i+1, num);
	for(int j = 0; j < primes[i].se; j++){
		tmp *= primes[i].fi;
		sum += tmp;
		compute(i+1, tmp);
	}
}

int main(){
	sd(t);
	while(t--){
		sd(n);
		primes.clear();
		
		m = n;
		sum = 1;
		
		
		for(int i = 2; i*i <= m; i++){
			if(m%i == 0){
				int cnt = 0;
				while(m%i == 0){
					m /= i;
					cnt++;
				}
				primes.push_back(make_pair(i, cnt));
			}
		}
		if(m > 1){
			primes.push_back(make_pair(m, 1));
		}		
		
		//for(int i = 0; i < primes.size(); i++){
		//	cout<< primes[i].fi << " " << primes[i].se << endl;
		//}
		
		compute(0, 1);
		
		if(n == 1) sum = 1;
		
		printf("%lld\n",sum);
		
	}
	return 0;
}

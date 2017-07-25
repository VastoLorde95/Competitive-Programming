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

int t, a, b, c, d, e, f, g, h, flag, tmp, cnt, res;
map<int, int> p; // primes and their powers
vector<int> primes;
vector<int> del;
void precompute(int x, int y){
	tmp = x;
	for(int i = 2; i*i <= x; i++){
		if(tmp%i == 0){
			cnt = 0;
			while(tmp%i == 0){
				tmp /= i;
				cnt++;
			}
			p[i] += (cnt*y);
		}
	}
	
	if(tmp > 1) p[tmp] += y;
}

void factorize(int x){
	//cout << "here " << x << endl;
	for(int i = 0; primes[i] <= x; i++){
		if(x%primes[i] == 0){
			cnt = 0;
			while(x%primes[i] == 0){
				x /= primes[i];
				cnt++;
			}
			//cout << "we divided " << primes[i] << " " << cnt << endl;
			
			p[primes[i]] += cnt;
		}
	}
	
	if(x > 1){
		p[x]++;
	}
}

int main(){
	sd(t);
	
	primes.push_back(2);
	for(int i = 3; i <= 1415; i += 2){
		flag = 1;
		for(int j = 0; j < primes.size(); j++){
			if(i%primes[j] == 0){
				flag = 0;
				break;
			}
		}
		
		if(flag) primes.push_back(i);
	}
	
	
	while(t--){
		sd2(a,b);
		sd2(c,d);
		sd2(e,f);
		sd2(g,h);
		
		p.clear();
		
		precompute(a,b);
		precompute(c,d);
		precompute(e,f);
		precompute(g,h);
		
		res = 0;
		
		while(p.size() > 0){
			for(map<int, int>::iterator it = p.begin(); it != p.end(); it++){
				it->second--;
				
				factorize((it->first)-1);
				
			}
			
			del.clear();
			
			for(map<int, int>::iterator it = p.begin(); it != p.end(); it++){
				if(it->second == 0)
					del.push_back(it->first);
			}
			
			for(int i = 0; i < del.size(); i++){
				p.erase(del[i]);
			}
			
			res++;
		}
		
		cout << res << endl;
		
		
		
		
	}
	return 0;
}

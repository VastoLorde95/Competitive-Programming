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

using namespace std;

long long n, m, MOD = 1000000007, res, a, b, c, d, temp;
vector<vector<long long> > t;
vector<long long> x;
map<long long, long long> ways;	//no of ways to reach it->first = level
map<pair<long long, long long>, long long> spec_v;	//no of ways to reach vertex m of level x
map<long long, long long>::iterator it;
int k;


long long exp(long long x, long long y){
	long long ret = 1;
	while(y > 0){
		if(y&1){
			ret = (ret*x)%MOD;
		}
		x = (x*x)%MOD;
		y >>= 1;
	}
	return ret;
}


int main(){
	scanf("%lld%lld%d",&n, &m, &k);
	
	res = exp(m, n);
	
	for(int i = 0; i < k; i++){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d); 
		x.clear(); x.push_back(c); x.push_back(a); x.push_back(d); x.push_back(b);
		t.push_back(x);
	}
	
	sort(t.begin(), t.end());
	
	if(k > 0){
		temp = exp(m, t[0][1] - 1); 	
		ways[t[0][0]] = temp;
		spec_v[make_pair(t[0][2], t[0][0])] = temp;
				
		for(int i = 1; i < k; i++){
			long long term1 = exp(m, t[i][1]-1);
			long long term2;
			if(spec_v.find(make_pair(t[i][3], t[i][1])) != spec_v.end()){
				term2 = spec_v[make_pair(t[i][3], t[i][1])];
			}
			else{
				it = ways.lower_bound(t[i][1]);
				if(it != ways.begin()){ //some way exists to reach with at least one special edges 
					it--;		
					term2 = it->second;
					term2 = (term2 * exp(m, t[i][1] - (it->first) - 1))%MOD;
				}
				else{	//currently there is no way to reach u, l1 with at least one special edge
					term2 = 0;
				}
			}
			long long term3;	//no of ways to reach v, l2 with at least one special edge not using u, l1 -> v, l2
			it = ways.lower_bound(t[i][0]);
			if(it != ways.begin()){
				it--;
				term3 = it->second;
				term3 = (term3 * exp(m, t[i][0] - (it->first) - 1))%MOD;
			}
			else{
				// there is no way to reach v, l2 withput using our current special edge
				term3 = 0;
			}
		
			if(ways.find(t[i][0]) != ways.end()){
				ways[t[i][0]] =  (ways[t[i][0]] + (term1 + term2)%MOD)%MOD;
			}
			else{
				if(t[i][0] == (n+1)){
					ways[t[i][0]] = ((term1 + term2)%MOD + term3)%MOD;
				}
				else{
					ways[t[i][0]] = ((term1 + term2)%MOD + (term3*m)%MOD)%MOD;
				}
			}
		
			if(spec_v.find(make_pair(t[i][2], t[i][0])) != spec_v.end()){
				spec_v[make_pair(t[i][2], t[i][0])] = (spec_v[make_pair(t[i][2], t[i][0])] + (term1 + term2)%MOD)%MOD;
			}
			else{
				spec_v[make_pair(t[i][2], t[i][0])] = ((term1 + term2)%MOD + term3)%MOD;
			}
			
		
		}
	}
	if(!ways.empty()){
		it = ways.end();
		it--;
		res = (res + ((it->second) * exp(m, n - (it->first)))%MOD)%MOD;
	}
	cout<<res<<endl;
	
	return 0;
}

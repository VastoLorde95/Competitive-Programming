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

vector<long long> lucky;
long long num, l, r, cur, prev,	 res;

int main(){ _
	cin >> l >> r;
	for(int i = 0; i < 11; i++){
		for(int mask = 0; mask < (1<<i); mask++){
			num = 0;
			for(int j = 0; j < i; j++){
				num *= 10;
				if((mask&(1<<j)) > 0){
					num += 4;
				}
				else{
					num += 7;
				}	
			}
			lucky.pb(num);
		}
	}
	
	sort(lucky.begin(), lucky.end());
	
	
	prev = l;
	
	vector<long long>::iterator it = lower_bound(lucky.begin(), lucky.end(), l);
	cur = *it;
	if(r > cur)
		res = cur * (cur-l+1);
	else
		res = cur * (r-l+1);
	it++;
	
	prev = cur;
	
	if(r > cur){
		while(it != lucky.end()){
			cur = *it;
		
			if(cur < r){
				res = res + cur*(cur-prev);
				prev = cur;
			}
		
			if(cur >= r){
				res += cur*(r-prev);
				break;
			}
		
			it++;
		}
	}
	cout << res << endl;
	
	return 0;
}

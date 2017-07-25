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

int n, k, d;
vector<vector<int> > nums;

vector<int> base_k(int x){
	vector<int> ret;
	
	if(k == 1){
		for(int i = 1; i <= x; i++){
			ret.pb(0);
		}
		
		while(ret.size() < d) ret.pb(0);
		
		return ret;
	}
	
	while(x > 0){
		ret.pb(x%k);
		x /= k;
	}
	
	while(ret.size() < d) ret.pb(0);
	
	return ret;
}

int main(){

	sd3(n,k,d);
	
	for(int i = 0; i < n; i++){
		nums.pb(base_k(i));
	}
	
	for(int i = 0; i < n; i++){
		if(nums[i].size() > d){
			printf("-1\n");
			return 0;
		}
		for(int j = i+1; j < n; j++){
			if(nums[i] == nums[j]){
				printf("-1\n");
				return 0;
			}
		}
	}	
	
	
	for(int i = 0; i < d; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", nums[j][i]+1);
		}
		printf("\n");	
	}
	return 0;
}

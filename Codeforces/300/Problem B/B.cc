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

vector<int> nums, res;
int p[10], n, num, dp[1000001], prev[1000001];

int main(){

	p[0] = 1;
	for(int i = 1; i < 10; i++) p[i] = p[i-1]*10;
	
	for(int i = 1; i < (1<<10); i++){
		num = 0;
		for(int j = 0; j < 10; j++){
			if( (i&(1<<j)) > 0){
				num += p[j];
			}
		}
		nums.push_back(num);
	}
	
	sort(nums.begin(),  nums.end());
	
	sd(n);
	
	for(int i = 1; i <= 1000000; i++){
		dp[i] = i;
		prev[i] = 1;
	}
	
	for(int i = 1; nums[i] <= 1000000; i++){
		dp[nums[i]] = 1;
		prev[nums[i]] = nums[i];
		for(int j = nums[i]+1; j <= 1000000; j++){
			if((dp[j-nums[i]]+1) < dp[j]){
				prev[j] = nums[i];
				dp[j] = dp[j-nums[i]]+1;
			}
		}
	}
	
	for(int i = n; i > 0; ){
		res.pb(prev[i]);
		i -= prev[i];
	}
	
	/*int start = 0;
	
	while(nums[start] <= n){
		start++;
	}	
	
	start--;
	
	while(n > 0){
		
		if(start > 0 and nums[start-1]+nums[start-1] == n){
			res.pb(nums[start-1]);
			res.pb(nums[start-1]);
			n = 0;
			break;
		}
		
		n -= nums[start];
		
		res.push_back(nums[start]);
		
		while(start >= 0 and nums[start] > n){
			start--;
		}
	}*/
	
	printf("%d\n",(int)res.size());
	
	for(int i = 0; i < res.size(); i++){
		printf("%d ", res[i]);
	}
	
	return 0;
}

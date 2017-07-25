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

int n, cnt, num;
vector<int> nums;
int p[10];

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
	
	int i = 0;
	while(i < nums.size() and nums[i] <= n) cnt++, i++;
	
	cout << cnt << endl;
	
	return 0;
}

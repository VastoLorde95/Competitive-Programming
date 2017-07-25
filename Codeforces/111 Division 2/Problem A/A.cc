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

int n, coins[100], sum[100], cur, cnt;

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>coins[i];
	}
	sort(coins, coins+n);
	sum[0] = coins[0];
	for(int i = 1; i < n; i++){
		sum[i] = sum[i-1] + coins[i];
	}
	
	int i = n;
	
	while(cur <= sum[i-1]){
		cnt++;
		cur += coins[i-1];
		i--;
	}
	
	cout<< cnt <<endl;
	
	
	return 0;
}

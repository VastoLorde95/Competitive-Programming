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

int s, k;
long long num[1001], sum[1001];
vector<long long> res;
int main(){
	cin>> s >> k;
	num[0] = 1;
	sum[0] = 1;
	
	int i = 0;
	while(num[i] < s){
		num[i+1] = sum[i] - ( (i-k >= 0)? sum[i-k]:0 );
		sum[i+1] = sum[i] + num[i+1];
		//cout<< i << " " << num[i+1] << " " << sum[i+1] << " " << sum[i-k] << endl;
		i++;
	}
	
	for(i; i >= 0 and s > 0; i--){
		if(s >= num[i]){
			s -= num[i];
			res.push_back(num[i]);
		}
	}
	
	if(res.size() == 1){
		res.push_back(0);
	}
	
	cout<< res.size() << endl;
	for(i = 0; i < res.size(); i++){
		cout<< res[i] << " ";
	}
	
	return 0;
}

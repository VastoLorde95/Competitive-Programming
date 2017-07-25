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

int sum, limit, ones, hi;
vector<int> res;
int main(){
	sd2(sum,limit);
	
	for(int i = 1; sum > 0 and i <= limit; i <<= 1){
		for(int j = i; sum > 0 and j <= limit; j += (i*2)){
			if((sum&i) > 0 or j + (i*2) <= limit){
				sum -= i;
				res.push_back(j);
			}
		}
	}
	
	//cout<< sum << " " << res.size() << endl;
	
	if(sum != 0){
		printf("-1\n");
	}
	else{
		printf("%d\n",(int)res.size());
		for(int i = 0; i < res.size(); i++){
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	return 0;
}

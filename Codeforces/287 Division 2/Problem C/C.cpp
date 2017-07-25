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

long long h, n, pow2[55], ext, ans, dir, cur;

int main(){
	long long two = 2;
	pow2[0] = 1;
	ans = 0;
	for(int i = 1; i <= 54; i++){
		pow2[i] = pow2[i-1] * two;
	}
	cin>>h>>n;
	
	ext = pow2[h] + n - 1;
	ans = 0, dir = 0;
	for(long long i = h-1; i >= 0; i--){
		if((ext&(long long)(1LL<<i)) > 0){	//right
			if(dir == 0){
				ans += (pow2[i+1]);
				dir = 0;
			}
			else{
				ans++;
				dir = 1 - dir;
			}
		}
		else{//left
			if(dir == 0){
				ans++;
				dir = 1 - dir;
			}
			else{
				ans += (pow2[i+1]);
				dir = 1;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}

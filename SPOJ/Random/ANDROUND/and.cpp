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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	long long t, n, num[30000], k, result;
	cin>>t;
	while(t--){
		scanf("%lld %lld",&n, &k);
		//sd2(n,k);
		for(int i = 0; i < n; i++){
			scanf("%lld",&num[i]);
		}
		result = num[0];
		if(k > n/2){
			for(int i = 0; i < n; i++){
				result &= num[i];
			}
			for(int i = 0; i < n; i++){
				printf("%lld ",result);
			}
			printf("\n");
		}
		else{
			for(int i = 0; i < 31; i++){
				for(int j = 0; j < n; j++){
					if((num[j]&(1<<i)) == 0){
						//cout<<i<<" "<<num[j]<<" "<<j<<endl;
						for(int q = 1; q <= k; q++){
							num[(j+q)%n] = num[(j+q)%n] & (~(1<<i));
							num[(n+j-q)%n] = num[(n+j-q)%n] & (~(1<<i));
						}
						j = j + k;
					}
				}
			}
			for(int i = 0; i < n; i++){
				printf("%lld ",num[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

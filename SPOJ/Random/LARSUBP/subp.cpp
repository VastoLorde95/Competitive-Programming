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
	int t, temp, cas = 1;
	char s[10001];
	long long MOD = 1000000007, ends_with[10], sum;
	sd(t);
	while(cas <= t){
		scanf("%s",s);
		sum = 0;
		
		for(int i = 0; i < 10; i++)
			ends_with[i] = 0;

		int i = 0;
		while(s[i] != '\0'){
			temp = s[i] - '0';
			ends_with[temp] = (ends_with[temp] + 1) % MOD;
			for(int j = 0; j < temp; j++){
				ends_with[temp] += ends_with[j] % MOD;
			}
			i++;
		}
		
		sum += (ends_with[0] + ends_with[1] + ends_with[2] + ends_with[3] + ends_with[4] + ends_with[5] + ends_with[6] + ends_with[7] + ends_with[8] + ends_with[9])%MOD;
			
		printf("Case %d: %lld\n",cas,sum);
		cas++;
	}
	return 0;
}

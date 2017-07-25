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
	int t, n, num[101], sum[100001], integers[100001], l, temp;
	long long ans;
	sd(t);
	while(t--){
		sd(n);
		for(int i = 0; i <= 100000; i++)
			sum[i] = 0;
		for(int i = 0; i < n; i++){
			sd(num[i]);
		}
		integers[0] = 0;		//Those integers which are sums of subsets
		integers[1] = num[0];
		l = 2, ans = num[0];
		sum[integers[0]] = 1;	//Those integers which are sums of subsets and have already been cosidered.
		sum[integers[1]] = 1;
		for(int i = 1; i < n; i++){
			temp = l;
			for(int j = 0; j < l; j++){			// For all those sums that alrady exist, add the ith element, if it is not set then it is a new integer.
				if(sum[integers[j] + num[i]] == 0){
					integers[temp] = integers[j] + num[i];
					sum[integers[j] + num[i]] = 1;
					ans += integers[temp];
					temp++;
				}
			}
			l = temp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


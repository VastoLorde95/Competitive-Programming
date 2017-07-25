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
	int t, temp, ans;
	map<int,long long> count;
	long long n, max;	
	sd(t);
	while(t--){
		count.clear();
		max = 0;
		scanf("%lld",&n);
		for(long long i = 0; i < n; i++){
			sd(temp);
			if(count.find(temp) == count.end())
				count[temp] = 1;
			else{
				count[temp]++;
				if(count[temp] > max){
					max = count[temp];
					ans = temp;					
				}
			}
		}
		if(max > n/2){
			printf("YES %d\n",ans);
		}
		else
			printf("NO\n");
		
	}
	return 0;
}

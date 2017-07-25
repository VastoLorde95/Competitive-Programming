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
	int t, n, r;
	long long sum;
	char name[30];
	pair<int,int> ranks[100000];
	sd(t);
	while(t--){
		sd(n);
		sum = 0;
		for(int i = 0; i < n ; i++){
			scanf("%s %d",name,&r);
			ranks[i] = make_pair(r,i+1);
		}
		sort(ranks, ranks+n);
		for(int i = 0; i < n; i++){
			//cout<<ranks[i].first<<" "<<ranks[i].second<<endl;
			sum += abs((i + 1) - ranks[i].first);
		}
		printf("%lld\n",sum);
	}
	return 0;
}

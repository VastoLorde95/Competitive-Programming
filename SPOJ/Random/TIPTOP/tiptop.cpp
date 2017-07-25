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
#define sllu(x) scanf("%llu",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int t, i = 1;
	unsigned long long n, root;
	sd(t);
	while(i <= t){
		scanf("%llu",&n);
		root = sqrt(n);
		if(root*root == n or (root-1)*(root-1) == n or (root+1)*(root+1) == n)
			printf("Case %d: Yes\n",i);
		else
			printf("Case %d: No\n",i);
		i++;
	}
	return 0;
}

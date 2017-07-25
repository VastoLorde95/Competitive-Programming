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

int main()
{
	int t, a[100],n,flag;
	long long result, MOD = 1000000007;
	sd(t);
	while(t--){
		sd(n);
		for(int i=0;i<n;i++) sd(a[i]);
		
		sort(a,a+n);
		result=1,flag=1;
		for(int i=n-1;i>=0;i--){
			if(a[i]-i<=0){
				flag=0;
				break;
			}
			result=(result*(a[i]-i))%MOD;
		}
		if(!flag)
			printf("0\n");
		else
			printf("%lld\n",result);
	}
	printf("KILL BATMAN\n");
	return 0;
}

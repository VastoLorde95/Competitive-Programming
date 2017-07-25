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

int main(){
	int t, cnt;
	long long n, s, sum, diff, i, x;
	sd(t);
	while(t--){
		scanf("%lld%lld",&n,&s);
		sum = (n*(n+1))/2;
		if(  sum == s){
			cout<< 0 <<endl;
			continue;
		}
		cnt = 0; x = n;
		while(s != sum){
			diff = sum - s;
			i = 1;
			while(x-i > diff){
				i++;
			}
			s += x-i;
			x--;
			cnt++;
		}
		
		cout<< cnt <<endl;
	}
	return 0;
}

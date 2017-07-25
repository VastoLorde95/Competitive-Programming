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

int n, x, cnt[1002], mn = 10000, a, b, c;

int main(){
	sd2(n,x);
	for(int i = 0; i < n; i++){
		sd2(a,b);
		if(a > b)
			swap(a,b);
		cnt[a]++;
		cnt[b+1]--;
	}
	
	for(int i = 0; i <= 1000; i++){
		c += cnt[i];
		if(c == n){
			mn = min(mn, abs(i-x));
		}		
	}
	
	if(mn == 10000) mn = -1;
	
	cout << mn << endl;
	
	return 0;
}

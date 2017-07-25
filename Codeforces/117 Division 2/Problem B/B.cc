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

int d, n, day[2000], cnt, cur;

int main(){
	sd(d);
	sd(n);
	for(int i = 0; i < n; i++){
		sd(day[i]);
	}
	
	cur = day[0];
	
	for(int i = 1; i < n; i++){
		if(cur == d){
			cur = day[i];
		}
		else{
			cnt += (d - cur);
			cur = day[i];
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}

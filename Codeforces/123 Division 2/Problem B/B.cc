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

int ball[100001], n, m, next = -1;

int main(){
	sd2(n,m);
	int cur = (m+1)/2;	
	if(m%2 == 0) next = 1;
	for(int i = 1; i <= n; i++){
		ball[i] = cur;
		cur += next;
		if(next > 0) next = (-next -1);
		else next = (-next+1);
		if(cur < 1 or cur > m){
			cur = (m+1)/2;
			if(m%2 == 0) next = 1;
			else next = -1;
		}
	}
	for(int i = 1; i <= n; i++){
		cout<< ball[i] << endl;
	}
	return 0;
}

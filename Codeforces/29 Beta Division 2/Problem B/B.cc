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

int l, d, v, g, r, t[10000], cur, cnt;

int main(){
	
	cin >> l >> d >> v >> g >> r;
	t[0] = 1;
	for(int i = 1; i <= 10000; i++){
		if(cur == 0){
			t[i] = 1;
			cnt++;
			if(cnt == g){
				cnt = 0;
				cur = 1 - cur;
			}
		}
		else{
			t[i] = 2;
			cnt++;
			if(cnt == r){
				cnt = 0;
				cur = 1 - cur;
			}
		}
	}
	
	//for(int i = 0; i <= l; i++){
	//	cout<< t[i] << endl;
	//}
	
	int timme = floor((double)d/(double)v)+1;
	
	//cout << timme << endl;
	
	if(t[timme] == 1){
		printf("%.7lf\n",(double)l/(double)v);
	}
	
	else{
		while(t[timme] == 2) timme++;
		timme--;
		printf("%.7lf\n",timme + (double)(l-d)/(double)v);
	}
	
	
	
	return 0;
}

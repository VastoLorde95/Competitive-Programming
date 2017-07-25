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

int n, h[1000], mx, cnt, flag = 1, flag2, prev; // 1 means decreasing

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(h[i]);
	}
	
	cnt = 1;
	mx = 1;
	
	for(int i = 1; i < n; i++){
		if(flag == 1){
			if(h[i] < h[i-1]){
				flag2 = 0;
				cnt++;
			}
			else if(h[i] == h[i-1] and flag2 == 1){
				cnt++;
				prev++;
			}
			else if(h[i] == h[i-1] and flag2 == 0){
				cnt++;
				flag2 = 1;
				prev = 2;
			}
			else{
				mx = max(mx, cnt);
				if(flag2 == 1)
					cnt = prev+1;
				else
					cnt = 2;
				flag = 0;
			}
		}
		else{
			if(h[i] >= h[i-1]) cnt++;
			else{
				cnt++;
				mx = max(mx, cnt);
				flag = 1;
			}
			
		}
	}
	
	mx = max(mx, cnt);
	
	printf("%d\n",mx);
	
	return 0;
}

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

int n, t, s, cnt, mx, b[100000], j;

int main(){
	sd2(n, t);
	for(int i = 0; i < n; i++){
		sd(b[i]);
	}
	
	
	for(int i = 0; i < n; i++){
		if(b[i] <= t){
			if(s + b[i] <= t){
				s += b[i];
				cnt++;
				mx = max(mx, cnt);
			}
			else{
				while( j < i and s+b[i] > t){
					s -= b[j];
					j++;
					cnt--;
				}	
				
				s += b[i];
				cnt++;
				mx = max(mx, cnt);
			}
		}
		else{
			s = 0;
			j = i+1;
			cnt = 0;
		}
	}
	
	printf("%d\n",mx);
	
	return 0;
}

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

int t, s, c, k;
long long res, temp;

int main(){
	sd(t);
	while(t--){
		sd3(s,c,k);
		if(c == 0){
			if(k > s){
				printf("0\n");
			}
			else{
				res = 3, temp = 2, s--;
				while(s >= k){
					res += temp;
					temp <<= 1;
					s--;
				}
				printf("%lld\n",res);
			}
		}
		else if(s == 0){
			if(k > 1){
				printf("0\n");
			}
			else{
				printf("%lld\n",(1LL<<(c+1))-2);
			}
		}
		else{
			//s >= 1 and c >= 1
			if(k > s){
				printf("0\n");
			}
			else{
				s--;
				if(k == 1){
					if(s <= c-1){
						printf("%lld\n",(1LL<<(c+1))+1);
					}
					else{
						printf("%lld\n",(1LL<<(c+1))+1 + ((1LL<<(s+1)) - (1LL<<(c+1))));
					}
				}
				else{
					//the cosines can't do anything on their own now
					if(c < s){
						int i = s + 1;
						res = 3, temp = 2; //0, pi, 2*pi
						while(i >= k and c > 0){
							res += temp;
							i--;
							c--;
							temp <<= 1;
						}
						//now either no more pts are avaialble or c is zero
						if(i < k){
							printf("%lld\n",res);
						}
						else{
							i--;
							while(i >= k){
								res += temp;
								i--;
								temp <<= 1;
							}
							printf("%lld\n",res);
						}
					}
					else{
						int i = s + 1;
						res = 3, temp = 2; //0, pi, 2*pi
						while(i >= k){
							res += temp;
							i--;
							temp <<= 1;
						}
						printf("%lld\n",res);
					}
				}
					
			}
		}
	}
	return 0;
}

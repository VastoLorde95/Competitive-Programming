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

int main(){
	int primes[200], l = 1, flag;
	primes[0] = 2;
	for(int i = 3; i < 1000; i+=2){
		flag = 1;
		for(int j = 0; j < l; j++){
			if(i%primes[j] == 0){
				flag = 0;
				j = l;
			}
		}
		if(flag){
			primes[l++] = i;
		}
	}
	return 0;
}

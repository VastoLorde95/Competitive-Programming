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
	int b, i = 1, s, routes[100000], start, end, max, niceness, t1, t2, length, length_temp;
	sd(b);
	while(i <= b){
		sd(s);
		s--;
		for(int j = 0; j < s; j++){
			sd(routes[j]);
		}
		niceness = 0, max = 0, start = 0, end = 0, t1 = 1, t2 = 2, length = 0, length_temp = 0;
		for(int j = 0; j < s; j ++){
			niceness += routes[j];
			if(niceness > max){
				max = niceness;
				t2 = j + 2;
				start = t1;
				end = t2;
				length_temp++;
				length = length_temp;
			}
			else if(niceness == max and t2-t1 > length and niceness > 0){
				t2 = j + 2;
				end = t2;
				start = t1;
				length_temp++;
				length = length_temp;
			}
			else if(niceness >= 0){
				t2++;
				length_temp++;
			}
			else{
				niceness = 0;
				t1 = j + 2;
				t2 = j + 3;
				length_temp = 0;
			}
		}
		if(length == 0){
			printf("Route %d has no nice parts\n",i);
		}
		else{
			printf("The nicest part of route %d is between stops %d and %d\n",i,start,end);
		}
		i++;
	}
	return 0;
}

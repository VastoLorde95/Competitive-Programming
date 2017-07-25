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
	int t, n, r, id, sub;
	set<int> stud[10001];
	sd(t);
	while(t--){
		for(int i = 0; i <= 10000; i++){
			stud[i].clear();
		}
		sd2(n,r);
		int flag = 0;
		for(int i = 0; i < r; i++){
			sd2(id,sub);
			if(flag == 0)
				if(stud[id].find(sub) == stud[id].end()){
					stud[id].insert(sub);
				}
			else{
				flag = 1;
			}
		}
		if(flag == 0)
			printf("possible\n");
		else
			printf("impossible\n");
		
	}
	return 0;
}

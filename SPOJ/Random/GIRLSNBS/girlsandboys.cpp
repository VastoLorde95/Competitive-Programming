#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

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
	int g, b;
	sd2(g,b);
	while(g!= -1 and b != -1){
		if( g == 0 or b == 0)
			cout<<max(b,g)<<endl;
		else if( g == b)
			cout<<1<<endl;
		else{
			int m1 = min(b,g);
			int m2 = max(b,g);
			if(m2%(m1+1) == 0)
				cout<<m2/(m1+1)<<endl;
			else
				cout<<m2/(m1+1) + 1<<endl;
		}
		sd2(g,b);
	}
	return 0;
	}

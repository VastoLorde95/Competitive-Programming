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

int x;

int main(){
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			cin>> x;
			if(x == 1){
				cout<< abs(i-3) + abs(j-3) << endl;
				return 0;
			}
		}
	}
	return 0;
}

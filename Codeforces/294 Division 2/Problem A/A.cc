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

int a, b;
char c;

int main(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			scanf(" %c",&c);
			if(c == 'Q') a += 9;
			else if(c == 'R') a += 5;
			else if(c == 'B') a += 3;
			else if(c == 'N') a += 3;
			else if(c == 'P') a += 1;
			else if(c == 'q') b += 9;
			else if(c == 'r') b += 5;
			else if(c == 'b') b += 3;
			else if(c == 'n') b += 3;
			else if(c == 'p') b += 1;
		}
	}
	
	if(a > b) cout<<"White\n";
	else if(a < b) cout<<"Black\n";
	else cout<<"Draw\n";
	return 0;
}

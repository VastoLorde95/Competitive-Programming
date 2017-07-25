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

long long w, h, x, y, res, tmp;

int main(){
	cin >> w >> h;
	x = w/2;
	y = h/2;
	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= y; j++){
			tmp = (w-i-i+1) * (h-j-j+1);
			if(tmp > 0)
				res += tmp;
		}
	}
	
	cout << res << endl;
	
	return 0;
}

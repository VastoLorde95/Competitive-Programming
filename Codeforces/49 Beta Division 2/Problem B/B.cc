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

long long h, w, tmp, h_max, w_max;

int main(){
	
	cin >> w >> h;	
	
	for(long long i = 1; i <= w; i <<= 1){	// w is a power of 2
		tmp = min(h, (long long)(i*1.25));
		if(tmp < 0.8*i)	// this means that we have reached an upper limit
			continue;
		else if(i*tmp > h_max*w_max or (i*tmp == h_max*w_max and i > h_max)){	// if the answers are equal we want to maximize the height
			h_max = i;
			w_max = tmp;
		}
					
	}
	
	for(long long i = 1; i <= h; i <<= 1){	// h is a power of 2
		tmp = min(w,(long long)(i*1.25));
		if(tmp < 0.8*i)
			continue;
		else if(i*tmp > h_max*w_max or (i*tmp == h_max*w_max and tmp > h_max)){
			h_max = tmp;
			w_max = i;
		}					
	}
	
	cout<< h_max << " " << w_max << endl;
	
	return 0;
}

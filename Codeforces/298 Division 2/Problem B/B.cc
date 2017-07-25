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

int v1, v2, t, d, res, v;

int main(){
	sd2(v1,v2);
	sd2(t,d);
	 v = v1;
	 for(int i = 1; i < t; i++){
	 	res += v;
	 	
	 	if( (int)(ceil( ((double)(v+1-v2)/(double)(t-(i+1))) )) <= d ){
	 		int cnt = 0;
	 		while(cnt < d and ((int)(ceil((double)(v+1-v2)/(double)(t-(i+1))) )) <= d)
	 			v++, cnt++;
	 	}
	 	else if( (int)(ceil( ((double)(v-v2)/(double)(t-(i+1))) )) <= d )
	 		continue;
	 	else{
	 		while( (int)(ceil( ((double)(v-v2)/(double)(t-(i+1))) )) > d and v >= v2 )
	 			v--;	
	 	}
	 }
	 
	 res += v2;
	 
	 cout << res << endl;
	
	
	return 0;
}

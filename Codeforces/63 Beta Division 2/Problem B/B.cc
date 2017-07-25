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

int n, m, p[101], l, r, t, c, s[101], res;

int main(){
	sd2(n,m);
	
	for(int i = 0; i < 101; i++){
		s[i] = 10000000;
	}
	
	
	for(int i = 0; i < m; i++){
		sd2(l,r); sd2(t,c);
		for(int j = l; j <= r; j++){
			if( t < s[j]){
				s[j] = t;
				p[j] = c;
			}
		}
	}
	
	for(int i = 1; i < 101; i++){
		res += p[i];
		//cout<< i << " " << p[i] << endl;
	}
	
	cout<< res << endl;
	return 0;
}

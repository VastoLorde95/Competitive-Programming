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

int m[3][3], s1, s2, s3, x;

int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			sd(m[i][j]);
		}
	}
	
	s1 = m[0][0] + m[0][1] + m[0][2];
	s2 = m[1][0] + m[1][1] + m[1][2];
	s3 = m[2][0] + m[2][1] + m[2][2];
	
	m[0][0] = (s1+s2+s3)/2 - s1;
	m[1][1] = (s1+s2+s3)/2 - s2;
	m[2][2] = (s1+s2+s3)/2 - s3;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

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

int t, len, mat[5][5], val[100000];
string s, l;
long long x, tmp;

int main(){
	mat[1][1] = 1;
	mat[1][2] = 2;
	mat[1][3] = 3;
	mat[1][4] = 4;
	
	mat[2][1] = 2;
	mat[2][2] = -1;
	mat[2][3] = 4;
	mat[2][4] = -3;
	
	mat[3][1] = 3;
	mat[3][2] = -4;
	mat[3][3] = -1;
	mat[3][4] = 2;
	
	mat[4][1] = 4; 
	mat[4][2] = 3;
	mat[4][3] = -2;
	mat[4][4] = -1;
	
	cin>>t;
	for(int T = 1; T <= t; T++){
		cin >> len >> x;
		cin>>l;
		
		s = "";
		
		tmp = x;
		
		x = min(x, 16);
		
		for(int i = 0; i < x; i++){
			s += l;
		}
		
		len = s.length();
		
		val[0] = (s[0] - 'g');
		
		for(int i = 1; i < len; i++){
			val[i] = (val[i-1]/abs(val[i-1]))*(mat[abs(val[i-1])][s[i]-'g']);
		}
		
		if(val[len-1] != -1){
			printf("Case #%d: NO\n",T);
			continue;
		}
		
		
		
		int flag = 0;
		for(int i = 0; i < len; i++){
			if(val[i] == 2) flag = 1;
			else if(val[i] == 4 and flag == 1){
				printf("Case #%d: YES\n",T);
				flag = 3;
				break;
			}
		}
		
		if(flag != 3)
			printf("Case #%d: NO\n",T);
	}
	
	return 0;
}

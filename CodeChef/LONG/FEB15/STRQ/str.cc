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

long long dp[4][4][1000001], cnt[4][1000001];
int a, b, c, d, l, q, le, ri, a1, a2;
string s;
char x, y;

int main(){
	for(int i = 0; i < 4; i++){
		cnt[i][0] = 0;
		for(int j = 0; j < 4; j++){
			dp[i][j][0] = 0;
		}
	}
	a = b = c = d = 0;
	cin>> s;
	l = s.length();
	for(int i = 1; i <= l; i++){
		if(s[i-1] == 'c'){
			dp[0][1][i] = dp[0][1][i-1] + b;
			dp[0][2][i] = dp[0][2][i-1] + c;
			dp[0][3][i] = dp[0][3][i-1] + d;
			a++;
			
			dp[1][0][i] = dp[1][0][i-1];
			dp[1][2][i] = dp[1][2][i-1];
			dp[1][3][i] = dp[1][3][i-1];
			
			dp[2][0][i] = dp[2][0][i-1];
			dp[2][1][i] = dp[2][1][i-1];
			dp[2][3][i] = dp[2][3][i-1];
			
			dp[3][0][i] = dp[3][0][i-1];
			dp[3][1][i] = dp[3][1][i-1];
			dp[3][2][i] = dp[3][2][i-1];
			
		}
		else if(s[i-1] == 'h'){
			dp[1][0][i] = dp[1][0][i-1] + a;
			dp[1][2][i] = dp[1][2][i-1] + c;
			dp[1][3][i] = dp[1][3][i-1] + d;
			b++;
			
			dp[0][1][i] = dp[0][1][i-1];
			dp[0][2][i] = dp[0][2][i-1];
			dp[0][3][i] = dp[0][3][i-1];
			
			dp[2][0][i] = dp[2][0][i-1];
			dp[2][1][i] = dp[2][1][i-1];
			dp[2][3][i] = dp[2][3][i-1];
			
			dp[3][0][i] = dp[3][0][i-1];
			dp[3][1][i] = dp[3][1][i-1];
			dp[3][2][i] = dp[3][2][i-1];
		}
		else if(s[i-1] == 'e'){
			dp[2][0][i] = dp[2][0][i-1] + a;
			dp[2][1][i] = dp[2][1][i-1] + b;
			dp[2][3][i] = dp[2][3][i-1] + d;
			c++;
			dp[0][1][i] = dp[0][1][i-1];
			dp[0][2][i] = dp[0][2][i-1];
			dp[0][3][i] = dp[0][3][i-1];
			
			dp[1][0][i] = dp[1][0][i-1];
			dp[1][2][i] = dp[1][2][i-1];
			dp[1][3][i] = dp[1][3][i-1];
			
			dp[3][0][i] = dp[3][0][i-1];
			dp[3][1][i] = dp[3][1][i-1];
			dp[3][2][i] = dp[3][2][i-1];
		}
		else{
			dp[3][0][i] = dp[3][0][i-1] + a;
			dp[3][1][i] = dp[3][1][i-1] + b;
			dp[3][2][i] = dp[3][2][i-1] + c;
			d++;			
			
			dp[0][1][i] = dp[0][1][i-1];
			dp[0][2][i] = dp[0][2][i-1];
			dp[0][3][i] = dp[0][3][i-1];
			
			dp[1][0][i] = dp[1][0][i-1];
			dp[1][2][i] = dp[1][2][i-1];
			dp[1][3][i] = dp[1][3][i-1];
			
			dp[2][0][i] = dp[2][0][i-1];
			dp[2][1][i] = dp[2][1][i-1];
			dp[2][3][i] = dp[2][3][i-1];
		}
		
		cnt[0][i] = a;
		cnt[1][i] = b;
		cnt[2][i] = c;
		cnt[3][i] = d;
	}
	
	sd(q);
	while(q--){
		scanf(" %c %c %d %d", &x, &y, &le, &ri);
		if(x == 'c')
			a1 = 0;
		else if(x == 'h')
			a1 = 1;
		else if(x == 'e')
			a1 = 2;
		else if(x == 'f')
			a1 = 3;
		
		if(y == 'c')
			a2 = 0;
		else if(y == 'h')
			a2 = 1;
		else if(y == 'e')
			a2 = 2;
		else if(y == 'f')
			a2 = 3;
			
		//cout<< a1 << " " << a2 << " " << le << " " << ri << endl;
		//cout<<dp[a2][a1][ri]<<" "<< dp[a2][a1][le-1]<<endl;
		printf("%lld\n", dp[a2][a1][ri] - dp[a2][a1][le] - ((cnt[a2][ri] - cnt[a2][le]) * (cnt[a1][le-1])) );
	}
	return 0;
}

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

int t, n, cnt, jump, l;
string s;

int main(){
	sd(t);
	while(t--){
		cin>>s;
		l = s.length();
		sd(n);
		cnt = 0;
		jump = 0;
		for(int i = 0; i < l; i++){
			if( s[i] == 'T') jump += 2;
			else ++jump;
		}
		
		for(int i = 1; i <= 12*n; i++){
			int cur = i;
			while(cur+jump <= 12*n){
				cnt++;
				cur += jump;
			}
		}
		
		printf("%d\n",cnt);
	}
	return 0;
}

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

int t, n, cnt, res;
string s;

int main(){
	cin>>t;
	for(int j = 1; j <= t; j++){
		cin >> n;
		cin >> s;
		
		cnt = res = 0;
		
		for(int i = 0; i < n+1; i++){
			if(i <= cnt){
				cnt += (s[i]-'0');
			}
			else{
				res += (i-cnt);
				cnt = i + (s[i]-'0');
			}
		}
		
		cout <<"Case #"<< j << ": "<< res << "\n";
		
	}
	return 0;
}

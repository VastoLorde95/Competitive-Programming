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

int n, cnt[4], mx;
long long num, ans, MOD = 1000000007;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>> n;
	cin>> s;
	for(int i = 0; i < n; i++){
		if(s[i] == 'A')
			cnt[0]++;
		else if(s[i] == 'C')
			cnt[1]++;
		else if(s[i] == 'G')
			cnt[2]++;
		else
			cnt[3]++;
	}
	
	for(int i = 0; i < 4; i++){
		mx = max(mx, cnt[i]);
	}
	
	for(int i = 0; i < 4; i++){
		if(cnt[i] == mx)
			num++;	
	}
	
	ans = 1;
	
	for(int i = 0; i < n; i++){
		ans = (ans*num)%MOD;
	}
	
	cout<< ans <<endl;
	return 0;
}

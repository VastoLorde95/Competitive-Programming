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

int n, m, cnt1[26], cnt2[26], res;
string s, t;

int main(){
	cin>>s;
	cin>>t;
	
	
	n = s.length();
	m = t.length();
	
	for(int i = 0; i < n; i++){
		cnt1[s[i]-'a']++;
	}
	
	for(int i = 0; i < m; i++){
		cnt2[t[i]-'a']++;
	}
	
	for(int i = 0; i < 26; i++){
		if(cnt1[i] == 0 and cnt2[i] != 0){
			printf("-1\n");
			return 0;
		}
		if(cnt1[i] >= cnt2[i]){
			res += cnt2[i];
		}
		else{
			res += cnt1[i];
		}
	}
	
	printf("%d\n",res);
	
	return 0;
}

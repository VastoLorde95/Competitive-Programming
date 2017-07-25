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

string s;
int k, w[26], val, l, mx;

int main(){
	cin>>s>>k;
	l = s.length();
	for(int i = 0; i < 26; i++){
		cin>>w[i];
		mx = max(mx, w[i]);
	}
	
	for(int i = 0; i < l; i++){
		val += (i+1)*w[s[i]-'a'];
	}
	
	for(int i = 0; i < k; i++){
		val += (l+i+1)*mx;
	}
	
	cout<< val <<endl;
	return 0;
}

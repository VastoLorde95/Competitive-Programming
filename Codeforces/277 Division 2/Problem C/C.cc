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

int n, p, mid, cost, l, r;
string s;

int main(){
	sd2(n,p);
	cin>>s;
	p--;
	
	mid = n/2, l = n, r = -1;
	
	if(p >= n/2){
		string tmp = "";
		for(int i = n-1; i >= 0; i--){
			tmp += s[i];
		}
		s = tmp;	
		p = n-p-1;
	}
	
	for(int i = 0; i < mid; i++){
		if(s[i] != s[n-i-1]){
			cost += min(abs(s[i] - s[n-i-1]), 26 - abs(s[i] - s[n-i-1]));
			l = min(l, i);
			r = max(r, i);
		}
	}
	
	if(l == n){
		cout << 0 << endl;
	}
	else{
		cout << (r-l) + cost + min(abs(p-l),abs(p-r)) << endl;
	}
	
	return 0;
}

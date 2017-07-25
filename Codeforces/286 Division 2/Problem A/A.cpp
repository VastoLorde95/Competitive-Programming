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

int main(){
	string s, flag = 0;
	char c;
	cin>>s;
	int l = s.length(), i = 0, j = l-1;
	while(i < j){
		if(s[i] != s[j] and flag == 0){
			if(s[i+1] == s[j]){
				c = s[i]; flag = 1;
			}
			else if(s[j-1] == s[i]){
				c = s[j];
				flag = 1;		
			}
		}
	}
	return 0;
}

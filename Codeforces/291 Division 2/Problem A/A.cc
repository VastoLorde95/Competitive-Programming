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
	string x, res = "", ans = "";
	cin>>x;
	int l = x.length();
	if(x[0] == '9') res += '9';
	else{
		if((x[0] - '0') >= 5){
			res += (char) ('0' + ('9' - x[0]));
		}
		else{
			res += x[0];
		}
	}
	
	for(int i = 1; i < l; i++){
		if((x[i] - '0') >= 5){
			res += (char) ('0' + ('9' - x[i]));
		}
		else{
			res += x[i];
		}
	}
	
	cout<<res<<endl;
	
	return 0;
}

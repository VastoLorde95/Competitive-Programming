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

int n, m;

int main(){
	cin >> n >> m;
	if(min(n,m)%2 == 0){
		cout<<"Malvika\n";
	}
	else{
		cout<<"Akshat\n";
	}
	return 0;
}

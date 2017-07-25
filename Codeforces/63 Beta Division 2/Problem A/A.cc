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

int j, x, y, z, n;

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>j;
		x += j;
		cin>>j;
		y += j;
		cin>>j;
		z += j;
	}
	
	if(x == y and y == z and x == 0){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	return 0;
}

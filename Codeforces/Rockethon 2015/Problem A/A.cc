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
	int n1, n2, k1, k2;
	cin>>n1>>n2>>k1>>k2;
	if(n1 <= n2){
		cout<<"Second"<<endl;
	}
	else{
		cout<<"First"<<endl;
	}
	return 0;
}

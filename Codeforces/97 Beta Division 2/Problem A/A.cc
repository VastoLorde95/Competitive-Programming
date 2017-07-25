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

int n, x, res[100];

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>x;
		res[x-1] = i;
	}
	
	for(int i = 0; i < n ; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}

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

int n, m, s, x[100];

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		sd(x[i]);
	}
	
	sort(x, x+n);
	
	if(x[0] >= 0){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i = 0; i < m; i++){
		if(x[i] < 0){
			s -= x[i];
		}	
		else{
			break;
		}	
	}
	
	cout<< s <<endl;
	
	return 0;
}

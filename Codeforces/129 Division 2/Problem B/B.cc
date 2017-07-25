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

int n, s, e;
long long cnt, a[100000];

int main(){
	cin>> n;
	for(int i = 0; i < n; i++){
		cin>> a[i];
	}
	
	if(n == 1){
		cout<< 0 << endl;
		return 0;
	}
	
	for(int i = 1; i < n; i++){
		if(a[i] < a[i-1]){
			cnt += (a[i-1] - a[i]);
		}
	}
	
	cout<< cnt <<endl;
	
	
	
	return 0;
}

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

long long n, h[100001], a[100001], x, y;
long long c1[100001], c2[100001];
int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>h[i]>>a[i];
		c1[h[i]]++;
		c2[a[i]]++;
	}
	
	for(int i = 0; i < n; i++){
		cout<< n-1 + c1[a[i]] << " " <<n - 1 - c1[a[i]] <<endl;
	}
	
	
	return 0;
}

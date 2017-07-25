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

string s;
int m, l, x;
int a[200002], sum[2000002];

int main(){
	cin>>s;
	l = s.length();
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>x;
		a[x] += 1;
		a[l-x+1] -= 1;
	}
	
	sum[1] = a[1];	

	for(int i = 2; i <= l; i++){
		sum[i] = sum[i-1] + a[i];
	}
	
	for(int i = 1; i <=(l/2); i++){
		if(sum[i]&1 != 0){
			swap(s[i-1], s[l-(i-1)-1]);
		}
	}
	
	cout<< s << endl;
	return 0;
}

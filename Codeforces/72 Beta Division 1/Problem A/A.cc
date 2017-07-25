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

long long n, res, cnt, a, prev;

int main(){
	cin>>n;
	cin>>a;
	prev = a;
	cnt = 1;
	
	for(int i = 1; i < n; i++){
		cin>>a;
		if(a == prev){
			cnt++;
		}
		else{
			prev = a;
			res += ((cnt)*(cnt+1))/2;
			cnt = 1;
		}
	}
	
	res += ((cnt)*(cnt+1))/2;
	
	cout << res << endl;
	
	return 0;
}

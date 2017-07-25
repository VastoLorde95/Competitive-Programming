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

int n;
long long A, d[200000], s, x, y;

int main(){
	cin>>n;
	cin>>A;
	for(int i = 0; i < n; i++){
		cin>>d[i];
		s += d[i];
	} 
	
	for(int i = 0; i < n; i++){
		x = (A - s + d[i])-1;
		x = max(x, 0LL);
		
		y = (A - n + 2);
		
		if(y > d[i])
			cout << x << " ";
		else{
			cout << x+(d[i]-y+1) << " ";
		}
		
	}
	
	return 0;
}

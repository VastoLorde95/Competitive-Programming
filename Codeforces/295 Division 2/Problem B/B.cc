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
	int n, m, cnt = 0, cnt2 = 0;
	cin>>n>>m;
	
	while(m > n){
		if(m&1) m++, cnt++;
		m /= 2;
		cnt++;
	}
	
	cout<< cnt + n-m <<endl;
	
	return 0;
}

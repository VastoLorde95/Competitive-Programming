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

long long a, b, s;

int main(){
	cin >> a >> b >> s;
	if( s >= (abs(a)+abs(b)) and (s - (abs(a)+abs(b)))%2 == 0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

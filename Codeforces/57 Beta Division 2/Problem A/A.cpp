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
	string a, b, c = "";
	cin>> a >> b;
	int l = a.length();
	for(int i = 0; i < l; i++){
		if(a[i] != b[i]) c += '1';
		else c += '0';
	}
	cout<< c << endl;
	
	return 0;
}

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

int n, a[100], b[100];

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b, b+n, greater<int>());
	
	int l = 0, h = 0;
	
	for(int i = 0; i < n; i++){
		if(a[i] == b[0]) break;
		l++;
	}
	
	for(int i = n-1; i >= 0; i--){
		if(a[i] == b[n-1]) break;
		h++;
	}
	
	if(n == 1){
		cout<<0<<endl;
	}
	else if(n == 2){
		cout<<l<<endl;
	}
	else if(l > (n-h-1))
		cout<< (l+h)-1 <<endl;
	else
		cout<< l+h << endl;
	
	return 0;
}

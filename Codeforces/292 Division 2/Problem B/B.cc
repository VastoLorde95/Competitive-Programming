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

int n, m, b, g, found[101], boy[101], girl[101], temp, x, y;

int main(){
	cin>> n >> m;
	
	cin>>b;
	for(int i = 0; i < b; i++){
		cin>>temp;
		boy[temp] = 1;
	}
	
	cin>>g;
	
	for(int i = 0; i < g; i++){
		cin>>temp;
		girl[temp] = 1;
	}	
	int l = n*m*10;
	x = 0, y = 0;
	for(int i = 0; i < l; i++){
		if(boy[x] == 1 or girl[y] == 1){
			boy[x] = girl[y] = 1;
		}
		
		x = (x + 1)%n;
		y = (y + 1)%m;
		
	}	
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		if(boy[i] == 1) cnt++;
	}
	
	for(int i = 0; i < m; i++){
		if(girl[i] == 1) cnt++;
	}
	
	//cout<<cnt<<endl;
	
	if(cnt == n + m) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	
	return 0;
}

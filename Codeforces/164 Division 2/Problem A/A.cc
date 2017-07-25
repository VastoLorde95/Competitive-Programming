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

int n, h[30], a[30], cnt;

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>h[i]>>a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j == i)
				 continue;
			else{
				if(h[i] == a[j]) cnt++;
			}
		}
	}
	
	cout<< cnt << endl;
	
	return 0;
}

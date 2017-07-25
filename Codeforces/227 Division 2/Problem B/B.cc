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

int n, m, a[3000], b[3000], cnt, j;

int main(){
	sd2(n,m);
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	for(int i = 0; i < m; i++){
		sd(b[i]);
	}
	
	for(int i = 0; i < n; i++){
		while(j < m and a[i] > b[j]){
			//cout<<a[i]<<" "<<b[j]<<endl;
			j++;
		}
		
		//cout<<i<<" "<<j<<endl;
		
		if(j == m){
			cout<< n-i << endl;
			return 0;
		}
		j++;
	}
	
	cout<< 0 << endl;
	return 0;
}

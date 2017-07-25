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

int n, a[1001], l, r, prev, cur, flag;

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}	
	for(int i = 1; i <= n; i++){
		if(a[i] != i){
			l = r = i;
			int val = a[i]-1;
			i++;
			while(i <= n and a[i] == val){
				r = i;
				i++;
				val--;
			}
			
			for(int j = l; j <= r; j++){
				a[j] = j;
			}
			
			for(int j = 1; j <= n; j++){
				if(a[j] != j){
					cout<<"0 0\n";
					return 0;
				}
			}
			
			i = n+1;
		}
	}

	if(l == 0){
		cout<<"0 0\n";
	}
	else{
		cout<<l<<" "<<r<< endl;
	}
	
	return 0;
}

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

int n, k, cnt[101], a, res;

int main(){
	sd2(n,k);
	for(int i = 0; i < n; i++){
		sd(a);
		cnt[a]++;
	}
	
	while(cnt[k] != n){
		for(int i = k-1; i >= 1; i--){
			if(cnt[i] > 0){
				cnt[i+1]++;
				cnt[i]--;
			}
		}
		res++;
	}
	
	cout<< res << endl;
	
	return 0;
}

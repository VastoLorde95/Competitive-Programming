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

int n, k, cur, res[100000];

int main(){
	sd2(n,k);
	
	for(int i = 0; i < n; i++){
		res[i] = i+1;
	}
	
	if(k == 0){
		cout<<n<<" ";
		for(int i = 1; i <= n-1; i++)
			cout<<i<<" ";
		return 0;
	}
	
	if(k == n){
		printf("-1\n");
		return 0;
	}
	
	if(n == 2){
		cout<<"1 2"<<endl;
		return 0;
	}
	cur = n-1;
	
	int i = 2;
	
	while(i < n and cur >= k+2){	
		swap(res[i], res[i-1]);
		i += 2;
		cur -= 2;
	}
	
	if(cur == k+1){
		swap(res[i], res[0]);
	}
	
	for(int i = 0; i < n; i++){
		cout<<res[i]<<" ";
	}
	
	return 0;
}

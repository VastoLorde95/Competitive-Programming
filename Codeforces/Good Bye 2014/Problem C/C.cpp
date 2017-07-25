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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;	

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, w[501], sum[1001], last[501], ans = 0, b[1001], found[1001];
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>w[i];
	
	sum[0] = 0;
		
	for(int i = 1; i <= m; i++){
		cin>>b[i];
		if(last[b[i]] == 0){
			memset(found, 0, sizeof found);
			for(int j = 1; j < i; j++){
				if(found[b[j]] == 0){
					ans += w[b[j]];
					found[b[j]] = 1;
				}
			}
			last[b[i]] = i;
		}
		else{		
			memset(found, 0, sizeof found);	
			for(int j = last[b[i]] + 1; j < i; j++){
				if(found[b[j]] == 0){
					ans += w[b[j]];
					found[b[j]] = 1;
				}
			}
			last[b[i]] = i;
		}
		//cout<<b<<" "<<sum[i]<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

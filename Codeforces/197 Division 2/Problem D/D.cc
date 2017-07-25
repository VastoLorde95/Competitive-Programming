#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, a[20][1<<18], id, p, b;

int main(){
	sd2(n,m);
	for(int i = 0; i < (1<<n); i++){
		sd(a[n][i]);
	}
	
	for(int i = n-1; i >= 0; i--){
		id = 1-id;
		if(id){
			for(int j = 0; j < (1<<i); j++){
				a[i][j] = a[i+1][j*2] | a[i+1][j*2 + 1];
			}
		}
		else{
			for(int j = 0; j < (1<<i); j++){
				a[i][j] = a[i+1][j*2] ^ a[i+1][j*2 + 1];
			}
		}
	}
	
	while(m--){
		sd2(p,b);
		p--;
		a[n][p] = b;
		id = 0;
		for(int i = n-1; i >= 0; i--){
			p /= 2;
			id = 1-id;
			if(id){
				a[i][p] = a[i+1][2*p] | a[i+1][2*p + 1];
			}
			else{
				a[i][p] = a[i+1][2*p] ^ a[i+1][2*p + 1];
			}
		}
		
		printf("%d\n", a[0][0]);
		
	}
	
	return 0;
}

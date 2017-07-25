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

const int LOGN = 20;
int n, m[1<<LOGN][LOGN], g[1<<LOGN][LOGN], a[1<<LOGN], k[1<<LOGN];

void sparseTable(){
	
	for(int i = 0; i < n; i++){ // base case
		m[i][0] = a[i];
		g[i][0] = a[i];
	}
	
	for(int j = 1; j < LOGN; j++){
		for(int i = 0; (i+(1<<j)-1) < n; i++){
			m[i][j] = min(m[i][j-1], m[i+(1<<(j-1))][j-1]);	// recurrence
			g[i][j] = __gcd(g[i][j-1], g[i+(1<<(j-1))][j-1]);
		}
	}
	
	k[2] = 1;
	for(int i = 3; i <= n; i++){
		k[i] = k[i-1] + ((i&(i-1)) == 0);
	}
	
	return;
}

int rmq(int x, int y){
	int l = y-x+1;
	return min(m[x][k[l]], m[y-(1<<k[l])+1][k[l]]);			// k = floor(log(x));
}

int rgcd(int x, int y){
	int l = y-x+1;
	return __gcd(g[x][k[l]], g[y-(1<<k[l])+1][k[l]]);
}

bool check(int l){
	for(int i = 0; i <= n-l; i++){
		if(rmq(i,i+l-1) == rgcd(i,i+l-1)) return true;
	}
	return false;
}

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	sparseTable();
	
	int lo = 1, hi = n+1, mid;
	
	while(lo+1 < hi){
		mid = (lo+hi)/2;
		if(check(mid)){
			lo = mid;
		}
		else{
			hi = mid;
		}
	}
	
	vector<int> res;
	
	for(int i = 0; i <= n-lo; i++){
		if(rmq(i,i+lo-1) == rgcd(i,i+lo-1)){
			res.pb(i+1);
		}
	}
	
	printf("%d %d\n", (int) res.size(), lo-1);	
	
	for(int i = 0; i < res.size(); i++){
		printf("%d ", res[i]);
	}	
	printf("\n");	
	return 0;
}

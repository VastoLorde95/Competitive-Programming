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

int n, r[101][101], c[101];
vector<int> res;
int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sd(r[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		int good = 1;
		for(int j = 1; j <= n; j++){
			if(r[i][j] == 1 or r[i][j] == 3) good = 0;
		}
		if(good) res.pb(i);
	}
	
	tr(res.size());
	if(res.size()){
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	}
	
	return 0;
}

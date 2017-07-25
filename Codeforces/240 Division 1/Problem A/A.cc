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

using namespace std;

int n, k, tmp, sum;
vector<int> res;

int main(){
	sd2(n,k);	
	
	if(n == 1){
		if(k > 0){
			cout << -1 << endl;
		}
		else
			cout << 1 << endl;	
		return 0;
	}
	
	if(k < n/2){
		cout << -1 << endl;
		return 0;
	}
	
	int tmp = k - (n/2 - 1);
	
	res.pb(tmp); 
	res.pb(2*tmp);
	
	int i = 1;
	while(res.size() < n){
		if(i == tmp or i == tmp*2 or i+1 == tmp or i+1 == 2*tmp){
			i += 2;
			continue;
		}
		
		res.pb(i);
		res.pb(i+1);
		
		i += 2;
	}
	
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}

	return 0;
}

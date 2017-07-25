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

using namespace std;

int n, k, m, cnt[3000];
vector<int> res;
int main(){
	sd3(n,m,k);
	
	for(int i = 1; i <= n+m; i++){
		while(cnt[i] < k or cnt[i+1] == 0){
			for(int j = i; j < i+n; j++){
				cnt[j]++;
			}
			res.pb(i);
		}
	}	
	
	printf("%d\n", (int) res.size());
	for(vector<int>::iterator it = res.begin(); it != res.end(); it++){
		printf("%d ", *it);
	}
	

	return 0;
}

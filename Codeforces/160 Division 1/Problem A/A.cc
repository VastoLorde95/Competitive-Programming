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

int n, m, a[100000], q[100000], cost, cnt = 0;

int main(){
	sd(m);
	for(int i = 0; i < m; i++) sd(q[i]);
	sd(n);
	for(int i = 0; i < n; i++) sd(a[i]);
	
	sort(q, q+m);
	sort(a, a+n, greater<int>());
	
	for(int i = 0; i < n; i++){
		if(cnt == q[0]){
			cnt++;
			continue;
		}
		if(cnt == q[0]+1){
			cnt = 0;
			continue;
		}
		
//		cout << i << " " << a[i] << endl;
		cost += a[i];
		cnt++;
	}
	
	printf("%d\n", cost);
	
	return 0;
}

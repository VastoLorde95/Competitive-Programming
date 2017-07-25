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

int n, t, cur = 2;
long long a, sum, val, k, num[200001], d[200001];

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t == 1){
			cin >> a >> k;
			sum += a*k;
			d[a] += k;
		}
		else if(t == 2){
			cin >> k;
			sum += k;
			num[cur] = k;
			d[cur] = 0;
			cur++;
		}
		else{
			cur--;
			sum -= (num[cur]+d[cur]);
			d[cur-1] += d[cur];
		}
		
		printf("%.17lf\n", (double)(sum)/(cur-1));
		
	}
	
	return 0;
}

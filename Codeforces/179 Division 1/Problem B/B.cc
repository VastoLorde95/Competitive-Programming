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

int n, x[501];
long long w[501][501], p[501][501], sum;
vector<long long> res;

int main(){ _
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> w[i][j];
			p[i][j] = w[i][j];
		}
	}
	
	for(int i = n; i >= 1; i--) cin >> x[i];
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				p[x[i]][x[j]] = min(p[x[i]][x[j]], p[x[i]][x[k]] + p[x[k]][x[j]]);
			}
		}
		
		sum = 0;
		
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= k; j++){
				sum += p[x[i]][x[j]];
			}
		}
		
		res.pb(sum);
	}
	
	for(int i = n-1; i >= 0; i--){
		cout << res[i] << " ";
	}	
	
	cout << endl;
		
	return 0;
}


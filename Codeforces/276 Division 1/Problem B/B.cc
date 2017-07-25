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

int n, ans, a[200001], p[2000001], mx;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		mx = max(mx,a[i]);
	}
	
	sort(a, a+n);
	
	for(int i = a[0]+1, j = 0; i <= 2*mx; i++){
		while(j < n and a[j] < i) j++;
		j--;
		p[i] = a[j];
	}
	
	for(int i = 0; i < n; i++){
		if(i > 0 and a[i] == a[i-1]) continue;
		for(int j = 2*a[i]; j <= 2*mx; j += a[i]){
			ans = max(ans, p[j]%a[i]);
		}
	}
	
	tr(ans);
	
	return 0;
}

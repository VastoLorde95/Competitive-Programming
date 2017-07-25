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

int n, a[100001], cnt[100001], mx, nn;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		nn = max(nn, a[i]);
	}
	
	for(int i = 0; i <= n/2; i++){
		if(a[i]-i > 0) cnt[a[i]-i]++;
		if(i < n-i-1)
			if(a[n-i-1]-i > 0) cnt[a[n-i-1]-i]++;
	}
	
	for(int i = 0; i <= nn; i++){
		mx = max(mx, cnt[i]);
//		tr2(i, cnt[i]);
	}
	
	printf("%d\n", n-mx);
	
	return 0;
}

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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, h;
pair<int, int> a[100000];
int res[100000];

int main(){
	sd2(n,h);
	
	if(n == 2){
		cout << "0\n1 1\n";
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		sd(a[i].fi);
		a[i].se = i;
	}
	
	sort(a, a+n);
	
	int ans = a[n-1].fi+a[n-2].fi-a[1].fi-a[0].fi;
	
	int mn = min(a[0].fi+a[1].fi+h, a[1].fi+a[2].fi);
	int mx = max(a[n-1].fi+a[n-2].fi,a[n-1].fi+a[0].fi+h);
	
	if(mx-mn < ans){
		cout << mx-mn << endl;
		res[a[0].se] = 1;
		for(int i = 0; i < n; i++){
			if(i != a[0].se) res[i] = 2;
		}
	}
	else{
		cout << ans << endl;
		for(int i = 0; i < n; i++) res[i] = 2;
	}

	for(int i = 0; i < n; i++){
		printf("%d ", res[i]);
	}
	printf("\n");
	
	return 0;
}

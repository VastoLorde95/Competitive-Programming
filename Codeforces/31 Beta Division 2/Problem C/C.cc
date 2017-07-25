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
#include <locale>

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

int n, t[1001001], s[1001001], x, y, mx, l = 1000000000, r = 0;
vector<pair<int, int> > seg;
vector<int> res;

int main(){
	sd(n);
	
	if(n == 1){
		puts("1");
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		sd2(x,y);
		seg.pb(mp(x,y));
		t[x]++;
		t[y]--;
		mx = max(mx, y);
	}
	
	for(int i = 1; i <= mx; i++){
		s[i] = s[i-1] + t[i];
		if(s[i] > 2){
			puts("0");
			return 0;
		}
	}
	
	int cnt = 0;
	
	for(int i = 1; i <= mx; i++){
		if(s[i] == 2){
			l = min(l,i);
			r = max(r,i);
		}
	}
	
	if(l > r){
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) printf("%d ", i);
		printf("\n");
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		if(seg[i].fi <= l and seg[i].se > r){
			cnt++;
			res.pb(i+1);
		}
	}
	
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) printf("%d ", res[i]);
	printf("\n");
	
	
	return 0;
}

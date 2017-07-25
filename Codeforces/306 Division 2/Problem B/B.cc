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

int n, l, r, x, cnt;
int c[15];

int main(){
	sd2(n,l); sd2(r,x);
	if(n == 1){
		printf("0\n"); return 0;
	}
	
	for(int i = 0; i < n; i++){
		sd(c[i]);
	}
	
	for(int i = 0; i < (1<<n); i++){
		int len = 0, tot = 0, mn = 1000000, mx = 0;
		for(int j = 0; j < n; j++){
			if((i&(1<<j)) > 0){
				len++;
				tot += c[j];
				mn = min(mn, c[j]);
				mx = max(mx, c[j]);
			}
		}
		if(len < 2) continue;
		
		if(tot >= l and tot <= r and mx-mn >= x) cnt++;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}

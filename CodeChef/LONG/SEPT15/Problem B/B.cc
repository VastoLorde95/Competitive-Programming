#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int t, n, m, x, y, cnt;
vector<int> a;

int main(){
	sd(t);
	while(t--){
		a.clear();
		sd2(n,m);
		cnt = 0;
		for(int i = 0; i < m; i++){
			sd(x);
			a.pb(x);
		}
		sort(a.begin(), a.end());
		
		int cur = 0;
		
		
		if(a.size() == 1){
			printf("0\n");
			continue;
		}
		else if(a.size() == 2){
			printf("1\n");
			continue;
		}
		
		while(((int)a.size())-cur >= 2){
			a[cur]--;
			if(a[cur] == 0) cur++;
			
			x = a.back(); a.pop_back();
			y = a.back(); a.pop_back();
			
			a.pb(x+y+1);
			cnt++;
		}
		
		printf("%d\n", cnt);
		
	}
	return 0;
}

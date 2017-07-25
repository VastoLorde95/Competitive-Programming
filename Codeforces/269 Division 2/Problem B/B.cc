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

int n;
pair<int, int> h[2001];
set<int> d;

int res[2001][3];
int v[2001][3];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int x;
		sd(h[i].fi); h[i].se = i+1;
		
		d.insert(h[i].fi);
	}
	
	if(n-d.size() <= 1){
		puts("NO"); return 0;
	}
	
	puts("YES");
	
	sort(h, h+n);
	
	for(int i = 0; i < n; i++){
		res[i][0] = h[i].se;
		v[i][0] = h[i].fi;
		
		res[i][1] = h[i].se;
		v[i][1] = h[i].fi;
		
		res[i][2] = h[i].se;
		v[i][2] = h[i].fi;
	}
	
	int i = 1;	
	for(i = 1; i < n; i++){
		if(v[i][1] == v[i-1][1]){
			swap(res[i][1], res[i-1][1]);
			break;
		}
	}
	i++;
	for(; i < n; i++){
		if(v[i][2] == v[i-1][2]){
			swap(res[i][2], res[i-1][2]);
			break;
		}
	}
	
	for(int j = 0; j < 3; j++){
		for(int i = 0; i < n; i++){
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

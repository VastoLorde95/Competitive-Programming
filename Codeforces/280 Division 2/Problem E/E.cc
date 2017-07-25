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

int n, m, dx, dy;
int v1[1000001], v2[1000001];
vector<pair<int, int> > trees;



int main(){
	sd2(n,m); sd2(dx,dy);

	
	int cur = 0;	
	for(int i = 0; i < n; i++){
		v1[cur] = i;
		cur = (cur+dx)%n;
	}
	
	cur = 0;
	for(int i = 0; i < n; i++){
		v2[cur] = i;
		cur = (cur+dy)%n;
	}
	
	
	map<int, int > cnt;
	
	for(int i = 0; i < m; i++){
		int x, y; sd2(x,y);
		
//		tr4(v1[x], v2[y], v2[y]-v1[x], n-v1[x]+v2[y]);
		
		if(v2[y] >= v1[x])
			cnt[v2[y]-v1[x]]++;
		else
			cnt[n-v1[x]+v2[y]]++;
		trees.pb(mp(x,y));
	}
	
	int mx = 0, ind;
	foreach(it, cnt){
		if(it->se > mx){
			mx = (it->se);
			ind = it->fi;
		}
	}
	
//	tr2("This is",ind);
	
	for(int i = 0; i < m; i++){
		int x, y, val;
		x = trees[i].fi, y = trees[i].se;
		
		if(v2[y] >= v1[x])
			val = v2[y]-v1[x];
		else
			val = n-v1[x]+v2[y];
		if(val == ind){
			printf("%d %d\n", x, y);
			return 0;
		}	
	}
	
	return 0;
}

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

int n, a[200001], b[200001], cur, res[200001];
set<int> ids;
set<int> as, bs;

map<int, int> aa, bb;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd2(a[i], b[i]);
		bb[a[i]] = b[i];
		aa[b[i]] = a[i];
		
		if(a[i] == 0) res[2] = b[i];
		
		as.insert(a[i]);
		bs.insert(b[i]);
		
		ids.insert(a[i]);
		ids.insert(b[i]);
	}
	
	foreach(it, ids){
		if(as.count(*it) and !bs.count(*it)){
			res[1] = *it;
			break;
		}
	}
	
	for(int i = 3; i <= n; i++){
		res[i] = bb[res[i-2]];
	}
	
	for(int i = 1; i <= n; i++){
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}

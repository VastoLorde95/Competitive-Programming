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

int n, t[5000], mn = 100000;
vector<int> a, b, c;


int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(t[i]);
		if(t[i] == 1) a.pb(i+1);
		else if(t[i] == 2) b.pb(i+1);
		else c.pb(i+1);
	}
	
	tr(min(min(a.size(), b.size()), c.size()));
	
	for(int i =0, j = 0, k = 0; i < a.size() and j < b.size() and k < c.size(); i++, j++, k++){
		printf("%d %d %d\n", a[i], b[j], c[k]);
	}
	
	return 0;
}

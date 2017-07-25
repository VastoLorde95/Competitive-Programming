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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

typedef pair<int,int> pii;

const int N = 100100;

int n, q, root;

vector<pii> s[N], e[N];
int a[N], b[N], x[N], y[N];
vector<int> queries;

bool comp(const int &i, const int &j){
	int u = a[i]/root, v = a[j]/root;
	if(u == v) return b[i]/root == b[j]/root;
	return u < v;
}

int main(){
	sd2(n,q);
	root = int(sqrt(n))+1;
	
	for(int i = 0; i < n; i++){
		int xx, yy; sd2(xx,yy);
		s[xx].pb(i);
		e[yy].pb(i);
	}
	
	for(int i = 0; i < q; i++){
		sd2(a[i], b[i]); sd2(x[i], y[i]);
		queries.pb(i);
	}
		
	sort(queries.begin(), queries.end(), comp);
	
	for(int i = 0; i < q; i++){
		int id = queries[i];
		
	}
	
	return 0;
}

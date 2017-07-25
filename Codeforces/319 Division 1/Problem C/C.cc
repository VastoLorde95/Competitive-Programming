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
#define foreach(it, v1) for(LET(it, v1.begin()); it != v1.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v1,w,x,y,z) cout<<v1<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v1,w,x,y,z) cout<<u<<" "<<v1<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef pair<int,int> pii;

const int BLOCK = 1000;

int n;
vector<pair<pii,int> > v;

bool cmp(const pair<pii,int> &p1, const pair<pii,int> &p2){
	if(p1.fi.fi/BLOCK == p2.fi.fi/BLOCK){
		if((p1.fi.fi/BLOCK)%2 == 0) return p1.fi.se < p2.fi.se;
		return p2.fi.se < p1.fi.se;
	}
	return p1.fi.fi/BLOCK < p2.fi.fi/BLOCK;
}


int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int x, y; sd2(x,y);
		v.pb(mp(mp(x,y),i+1));
	}
	
	sort(v.begin(), v.end(), cmp);
	
	foreach(it, v) printf("%d ", it->se); printf("\n");
	return 0;
}

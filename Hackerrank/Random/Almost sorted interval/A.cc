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

const int MAXN = 1001000;
int tree[MAXN];
int n, a[1001000], l[1001000], r[1001000];
long long ans;

vector<int> lazy[1001000];

int query(int idx){
    int sum = 0;
    while(idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx < MAXN){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);	
	}
	
	stack<int> s;
	s.push(1);
	l[1] = 0;
	for(int i = 2; i <= n; i++){
		while(!s.empty() and a[s.top()] < a[i]) s.pop();
		if(s.empty()) l[i] = 0;
		else l[i] = s.top();
		s.push(i);
	}
	
	while(!s.empty()) s.pop();
	
	r[n] = n+1;
	s.push(n);
	
	for(int i = n-1; i >= 1; i--){
		while(!s.empty() and a[s.top()] > a[i]) s.pop();
		if(s.empty()) r[i] = n+1;
		else r[i] = s.top();
		s.push(i);
	}
	
	for(int i = n; i >= 1; i--){
		foreach(it, lazy[i]) update(*it+1, -1);
		update(i+1, 1);
		lazy[l[i]].pb(i);
		
		ans += query(r[i]+1) - query(i);
	}
		
	printf("%lld\n", ans);
		
	return 0;
}

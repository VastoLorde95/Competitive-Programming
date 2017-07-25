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

const int MAXN = 1<<19;

int n, a[MAXN], cnt = 1;
set<int> comp;
map<int, int> cord;
long long tree[MAXN];

long long ans, cur, k;


long long query(int idx){
    long long sum = 0;
    while(idx > 0){
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
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		sd(a[i]);
		comp.insert(a[i]);
	}
	
	foreach(it, comp){	
		cord[*it] = cnt;
		cnt++;
	}
	
	for(int i = 0; i < n; i++) a[i] = cord[a[i]];

	if(k == 0){
		cout << (long long) (((long long) n * 1LL * (n+1)) / 2LL) << "\n";
		return 0;
	}
	
	update(a[0], 1);
	
	int s = 0, e = 0;
	while(s < n){
		while(e < n and cur < k){
			e++;
			if(e == n) break;
			
			update(a[e], 1);
			cur += 1LL * ((long long) (e-s+1) - (long long) query(a[e]));
		}
		
		if(cur < k) break;
		
		ans += ((long long) n-e);		
		
		cur -= ((long long) query(a[s]-1));
		update(a[s], -1);
		s++;
	}
	cout << ans << "\n";	
		
	return 0;
}

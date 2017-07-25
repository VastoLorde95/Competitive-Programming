#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <unordered_map>
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

const int N = 10001;

int n;
int a[N];
int cnt[N+N];
int cnt2[100000001];
vector<int> v;

long long c1, c2, c3;

int main(){
	sd(n);
	int mx = 0;
	for(int i = 0; i < n; i++){
		sd(a[i]);
		cnt[a[i]]++;
		v.pb(a[i]*a[i]);
		cnt2[v[i]]++;
		mx = max(mx, v[i]);
	}
	
	for(int i = 1; i <= mx; i++){
		cnt2[i] += cnt2[i-1];
	}
	
	
	
	for(int i = 1; i <= 10000; i++) cnt[i] += cnt[i-1];
	
	int t1, t2, t3, t4, acute, right, tot, l1, l2;
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(v[i]+v[j] <= mx)
				right = cnt2[v[i] + v[j]] - cnt2[v[i]+v[j]-1];
			else
				right = 0;
			
			t3 = min(mx,v[i]+v[j]-1);
			
			l1 = cnt2[t3] - j - 1;
			acute = l1;
			
			t1 = a[i]+a[j]-1;
			t1 = min(t1, 10000);
			tot = cnt[t1] - cnt[a[j]] - (acute+right);
			
			c1 += acute;
			c2 += right;
			c3 += tot;
		}
	}
	
	printf("%lld %lld %lld\n", c1,c2,c3);
	
	return 0;
}

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

typedef long long ll;

const int LOGN = 20;
const int N = 1<<LOGN;

int n, m, q, a[N];
ll cnt[LOGN+1][2], tot;

int type[LOGN+1];

void mergesort(int i, int j, int lvl){
	if(lvl == 0) return;
	int mid = (i+j)/2;
	
	mergesort(i,mid,lvl-1);
	mergesort(mid,j,lvl-1);
	
	vector<int> tmp;
	int p1 = i, p2 = mid;
	while(p1 < mid and p2 < j){
		if(a[p1] <= a[p2]){
			tmp.pb(a[p1++]);
		}
		else{
			cnt[lvl][0] += mid-p1;
			tmp.pb(a[p2++]);			
		}
	}
	
	while(p1 < mid){
		tmp.pb(a[p1++]);
	}
	while(p2 < j){
		tmp.pb(a[p2++]);
	}
	
	p1 = i, p2 = mid;
	while(p1 < mid and p2 < j){
		if(a[p2] <= a[p1]){
			p2++;
		}
		else{
			cnt[lvl][1] += j-p2;
			p1++;
		}
	}
	
	foreach(it, tmp){
		a[i++] = *it;
	}
	
	tmp.clear();
	
	return;
}

int main(){
	sd(n);
	
	int up = 1<<n;
	for(int i = 0; i < up; i++){
		sd(a[i]);
	}
	
	mergesort(0, up, n);

	sd(m);
	while(m--){
		sd(q);
		for(int i = q; i >= 0; i--){
			type[i] ^= 1;
		}
		
		tot = 0;		
		for(int i = 0; i <= n; i++){
			tot += cnt[i][type[i]];
		}

		printf("%I64d\n", tot);
	}

	return 0;
}

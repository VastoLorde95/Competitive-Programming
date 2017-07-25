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
long long k, tot, a[100100];
 
int main(){ _
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		tot += a[i];
	}
	
	if(tot < k){
		puts("-1"); return 0;
	}
	if(tot == k){
		return 0;
	}
	
	long long lo = 0, hi = 1e9 + 1, mid;
	while(lo+1 < hi){
		mid = (lo+hi)/2;
		tot = 0;
		for(int i = 0; i < n; i++) tot += min(mid, a[i]);
		if(tot > k) hi = mid;
		else lo = mid;
	}
	
	for(int i = 0; i < n; i++){
		k -= min(a[i],lo);
		a[i] -= lo;
	}
	
//	tr2(lo,k);
	
	int start = -1;
	for(int i = 0; i < n; i++){
		if(a[i] > 0 and k > 0){
			a[i]--;
			k--;
			start = i;
		}
	}
	
	for(int i = start+1; i < n; i++){
		if(a[i] > 0) cout << i+1 << " ";
	}
	
	for(int i = 0; i <= start; i++){
		if(a[i] > 0) cout << i+1 << " ";
	}
	
	cout << endl;
	return 0;
}

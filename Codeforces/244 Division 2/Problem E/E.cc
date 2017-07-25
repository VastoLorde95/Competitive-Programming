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

int n, m, x[1001000];
long long ans;

long long f(int pos){
	int i = 0, j;
	long long ret = 0;
	while(i < n and x[i] <= pos){
		int tmp = m;
		ret += abs(x[i] - pos);
		while(i < n and x[i] <= pos and tmp--) i++;
	}
	if(i == n) return ret;
	j = i;
	i = n-1;
	while(i >= j and x[i] > pos){
		int tmp = m;
		ret += abs(x[i]-pos);
		while(i >= j and x[i] > pos and tmp--) 	i--;
	}
	return ret;
}

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		sd(x[i]);
	}
	
	int lo = -1e9, hi = 1e9, mid1, mid2;
	long long v1, v2;
	
	while(lo < hi){
		mid1 = lo + (hi-lo)/3;
		mid2 = hi - (hi-lo)/3;
		
		v1 = f(mid1);
		v2 = f(mid2);
		
		if(v1 < v2)
			hi = mid2-1;
		else if(v1 > v2)
			lo = mid1+1;
		else
			hi = mid2, lo = mid1+1;
	}
	
	cout << min(v1,v2)*2LL << "\n";	
	
	return 0;
}

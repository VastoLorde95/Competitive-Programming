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
int n, a[100100];

long long f(long long v){
	long long ret = 0;
	for(int i = 0; i < n; i++){
		ret += (long long) abs(a[i]-v)* (long long) abs(a[i]-v) *(long long) abs(a[i]-v);
	}
	return ret;
}


int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	int lo = 0, hi = 10000, m1, m2;
	for(int i = 0; i < 100; i++){
		m1 = lo + (hi-lo)/3;
		m2 = hi - (hi-lo)/3;
		long long v1 = f(m1);
		long long v2 = f(m2);
		if(v1 < v2) hi = m2-1;
		else if(v1 > v2) lo = m1+1;
		else lo = m1, hi = m2;
	}
	
	long long mn = 1e18;
	int val = -1;
	// I did this just in case I get a range of values
	for(int i = lo; i <= hi; i++){
		if(f(i) < mn){
			val = i;
			mn = f(i);
		}
	}
	
	tr(val);
	
	return 0;
}

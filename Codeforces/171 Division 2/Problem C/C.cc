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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, m, a[100000], up[100000], down[100001], l, r, cur, prev, state, s;
vector<pair<int, int> > ladders;

int main(){
	sd2(n,m);
	
	for(int i = 0; i < n; i++) sd(a[i]);
	
	for(int i = 0; i < n; i++){
		int j = i+1;
		while(j < n and a[j] >= a[j-1]) j++;
		
		j--;
		
		for(int k = i; k <= j; k++) up[k] = j;
		
		i = j;
	}
	
	for(int i = 0; i < n; i++){
		int j = i+1;
		while(j < n and a[j] <= a[j-1]) j++;
		
		j--;
		
		for(int k = i; k <= j; k++) down[k] = j;
		
		i = j;
	}
	
	for(int i = 0; i < m; i++){
		sd2(l,r); l--, r--;
		if(down[up[l]] >= r) puts("Yes");
		else puts("No");
	}
	
	return 0;
}

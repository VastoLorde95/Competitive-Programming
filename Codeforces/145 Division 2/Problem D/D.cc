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

int n, d, m, k, f[101], x, u[101], ff[101], res[101], mn[101], mx[101];
string t[101];


int main(){ __
	sd2(m,k);
	
	for(int i = 1; i <= k; i++){
		sd(x);
		f[x] = 1;
	}
	
	sd(n);
	
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		sd(d);
		for(int j = 0; j < d; j++){
			sd(x);
			if(x == 0) u[i]++;
			else if(f[x]) ff[i]++;
		}
		
		if(m-(d-u[i])-(k-ff[i]) >= u[i]) mn[i]= ff[i];
		else mn[i] = ff[i] + u[i] - (m-(d-u[i])-(k-ff[i]));
		
//		tr4(d,k,u[i],ff[i]);
		
		mx[i] = ff[i] + min(u[i], k-ff[i]);
		
//		tr3(i,mn[i],mx[i]);
		
	}
	
	for(int i = 1; i <= n; i++){
		
		bool ok = true;
		
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			
			if(mn[i] < mx[j]){
				ok = false;
				break;
			}
		}
		
		if(ok) res[i] = 0;
		else{
			ok = true;
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
			
				if(mx[i] < mn[j]){
					ok = false;
					break;
				}
			}
			
			if(ok) res[i] = 2;
			else res[i] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << res[i] << endl;
	}	
	return 0;
}

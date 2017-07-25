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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int t, n, x, c1, c2;
int cnt[100100];
map<int, int> vals;

bool check(){
	
	int mx = 0, mn = 1e6;
	
	for(int i = 1; i <= n; i++){
		mx = max(mx, cnt[i]);
		mn = min(mn, cnt[i]);
	}
	
	if(cnt[n-1] != mn and cnt[n-1] != mx and cnt[n] != mn and cnt[n] != mx) return true;
	return false;
}

int main(){
	sd(t);
	while(t--){
		sd(n);
		
		if(n == 3){
			puts("none");
			continue;
		}
		
		for(int i = 1; i <= n; i++) cnt[i] = 0;
		for(int i = 1; i <= n-2; i++){
			sd(x);
			cnt[x]++;
		}
		for(int i = 1; i <= n-2; i++){
			sd(x);
			cnt[x]++;
		} 
		
		vals.clear();
		
		for(int i = 1; i <= n; i++){
			vals[cnt[i]]++;
		}
		
		int ind, mx=-1;
		
		for(int i = 1; i <= n-2; i++){
			if(cnt[i] > mx){
				mx = cnt[i];
				ind = i;
			}	
		}		
		
		cnt[ind]++;
		cnt[ind]++;
		
		int ind2;
		mx = -1;
		
		for(int i = 1; i <= n-2; i++){
			if(i != ind and cnt[i] > mx){
				mx = cnt[i];
				ind2 = i;
			}
		}
		
		cnt[ind2]++;
		cnt[ind2]++;
		
		if(check()){
			puts("both");
			cout << ind1 << " " << ind2 << endl;
			cout << ind1 << " " << ind2 << endl;
			continue;
		}
		
	}
	return 0;
}

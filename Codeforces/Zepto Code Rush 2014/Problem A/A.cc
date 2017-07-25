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

int n, x, h, t, m, u1[2001], u2[2001];
vector<pair<int, int> > a, b;
bool ok = false;

int eat(int ind){
	int cnt = 0, jump = x;
	
	memset(u1, 0, sizeof u1);
	memset(u2, 0, sizeof u2);
	
	while(true){
		ind = 1-ind;
		if(ind == 0){
			int mx = 0, indx = -1;
			for(int i = 0; i < a.size(); i++){
				if(u1[i] == 0 and a[i].fi <= jump and a[i].se > mx){
					mx = a[i].se;
					indx = i;
				}
			}
			if(indx == -1) break;
			
			jump += mx;
			u1[indx] = 1;
			cnt++;
		}
		else{
			int mx = 0, indx = -1;
			for(int i = 0; i < b.size(); i++){
				if(u2[i] == 0 and b[i].fi <= jump and b[i].se > mx){
					mx = b[i].se;
					indx = i;
				}
			}
			if(indx == -1) break;
			jump += mx;
			u2[indx] = 1;
			cnt++;
		}
	}
	return cnt;
}

int main(){
	sd2(n,x);
	for(int i = 0; i < n; i++){
		sd3(t,h,m);
		if(t == 0) a.pb(mp(h, m)); else b.pb(mp(h, m));
		if(h <= x) ok = true;
	} 

	if(a.size() == 0 or b.size() == 0){
		if(ok)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	
	cout << max(eat(0), eat(1)) << endl;
	
	
	return 0;
}

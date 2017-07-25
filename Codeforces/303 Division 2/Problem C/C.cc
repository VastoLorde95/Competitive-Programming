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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, h, x;
vector<pair<int, int> > t;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd2(x,h);
		t.pb(mp(x,h));
	}
	
	int cnt = 1;
	int fwd = 0;
	
	for(int i = 1; i < n-1; i++){
		if(fwd == 0){
			if(t[i-1].fi < t[i].fi - t[i].se){
				cnt++;
				fwd = 0;
//				tr2(1,i);
			}
			else if(t[i].fi + t[i].se < t[i+1].fi){
				cnt++;
				fwd = 1;
//				tr2(2,i);
			}
			else{
				fwd = 0;
			}
		}
		else{
			if(t[i-1].fi + t[i-1].se < t[i].fi - t[i].se){
				cnt++;
				fwd = 0;
//				tr2(3,i);
//				tr3("this", t[i-1].fi+t[i-1].se, t[i].fi - t[i].se);
			}
			else if(t[i].fi + t[i].se < t[i+1].fi){
				cnt++;
				fwd = 1;
//				tr2(4,i);
			}
			else{
				fwd = 0;
			}
		}
	}
	
	if(n > 1) cnt++;

	tr(cnt);
			
	return 0;
}

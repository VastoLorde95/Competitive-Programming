#include <bits/stdc++.h>

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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

typedef long long ll;

const int LOGN = 17;
const int N = 1<<LOGN;

int n, m, a[N];
set<int> id[LOGN];
ll tot;

int main(){ _
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < LOGN; j++){
			if((a[i]&(1<<j)) == 0){
				id[j].insert(i);	
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < LOGN; j++){
			if((a[i]&(1<<j)) > 0){
				set<int>::iterator it = id[j].upper_bound(i);
				if(it == id[j].end()){
					tot += (1ll<<j)*(n-i);
				}
				else{
					tot += (1ll<<j)*(*it-i);
				}
			}			
		}
	}

	int p, v;
	while(m--){
		cin >> p >> v;
		p--;
		for(int j = 0; j < LOGN; j++){
			if((a[p]&(1<<j)) > 0){
				set<int>::iterator it = id[j].upper_bound(p);
				int r = (it == id[j].end())? n : *it;
				int l = (it == id[j].begin())? 0 : *(--it)+1;
				
				long long del = r-l;
				tot -= (1ll<<j)*((del*(del+1))/2);
				del = r-p-1;
				tot += (1ll<<j)*((del*(del+1))/2);
				del = p-l;
				tot += (1ll<<j)*((del*(del+1))/2);
			}
			else{
				id[j].erase(p);
			}
		}
		
		a[p] = v;
		for(int j = 0; j < LOGN; j++){
			if((a[p]&(1<<j)) > 0){
				set<int>::iterator it = id[j].upper_bound(p);
				int r = (it == id[j].end())? n : *it;
				int l = (it == id[j].begin())? 0 : *(--it)+1;
				
				long long del = r-l;
				tot += (1ll<<j)*((del*(del+1))/2);
				del = r-p-1;
				tot -= (1ll<<j)*((del*(del+1))/2);
				del = p-l;
				tot -= (1ll<<j)*((del*(del+1))/2);
			}
			else{
				id[j].insert(p);
			}
		}
		
		cout << tot << '\n';
		
	}

	return 0;
}

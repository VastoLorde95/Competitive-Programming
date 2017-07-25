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

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

long long n, a, b, ans;
vector<int> x;

void go(vector<int> v, int id, long long cost){
	if(id == n){
		vector<int> vv;
		
		int g = v[0];
		for(int i = 1; i < n; i++){
			g = __gcd(g, v[i]);
		}
		
		if(g > 1) ans = min(ans, cost);
		
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				vv.clear();
				for(int k = 0; k < n; k++){
					if(k < i or k > j){
						vv.pb(v[k]);
					}
				}
				
				if(vv.empty()) continue;
				
				int g = vv[0];
				for(int k = 1; k < vv.size(); k++){
					g = __gcd(g, vv[k]);
				}
				
				if(g > 1){
					ans = min(ans, cost + a*(j-i+1));
				}
			}
		}		
				
		return;	
	}
	
	v.pb(x[id]);
	go(v, id+1, cost);
	v.pop_back();
	v.pb(x[id]+1);
	go(v, id+1, cost+b);
	v.pop_back();
	v.pb(x[id]-1);
	go(v, id+1, cost+b);
}

int main(){ _
	cin >> n >> a >> b;
	x.resize(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	
	ans = (1ll<<62);
	
	vector<int> tmp;
	go(tmp, 0, 0);
	
	cout << ans << endl;
	
	return 0;
}

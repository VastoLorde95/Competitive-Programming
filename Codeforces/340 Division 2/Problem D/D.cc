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

vector<pair<int,int> > v1, v2;

int main(){
	for(int i = 0; i < 3; i++){
		int x, y;
		sd2(x,y);
		v1.pb(mp(x,y));
		v2.pb(mp(y,x));
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int res = 3;
	
	if(v1[0].fi == v1[1].fi and v1[1].fi == v1[2].fi) res = 1;
	if(v2[0].fi == v2[1].fi and v2[1].fi == v2[2].fi) res = 1;

	
	if(v1[0].fi == v1[1].fi and (v1[2].se <= v1[0].se or v1[2].se >= v1[1].se)){
		res = min(res, 2);
	}
	if(v1[1].fi == v1[2].fi and (v1[0].se <= v1[1].se or v1[0].se >= v1[2].se)){
		res = min(res, 2);
	}
	
	v1 = v2;
	
	if(v1[0].fi == v1[1].fi and (v1[2].se <= v1[0].se or v1[2].se >= v1[1].se)){
		res = min(res, 2);
	}
	if(v1[1].fi == v1[2].fi and (v1[0].se <= v1[1].se or v1[0].se >= v1[2].se)){
		res = min(res, 2);
	}
	
	cout << res << endl;
	
	return 0;
}

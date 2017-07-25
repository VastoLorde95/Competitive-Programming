#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;

int n, k;

ll ans[N];

pii p[N];

map<int, set<pii> > h, v;

int main(){
	sd2(n,k);
	
	for(int i = 1; i <= n; i++){
		sd2(p[i].fi, p[i].se);
		h[p[i].fi].insert(mp(1,i));
		h[p[i].fi+k].insert(mp(-1,i));
	}

	int prevx = h.begin()->fi;
	foreach(it, h){
		vector<pii> e;
		foreach(jt, it->se) e.pb(*jt);
		
		int sz = e.size();		
		for(int i = 0; i < sz; i++){
			int t = e[i].fi, j = e[i].se;
			if(t == -1){
				v[p[j].se].erase(mp(1,j));
				v[p[j].se+k].erase(mp(-1,j));
			}
			else{
				v[p[j].se].insert(mp(1,j));
				v[p[j].se+k].insert(mp(-1,j));
			}
		}
		
		if(v.empty()) continue;
		
		int prevy = v.begin()->fi;
		int cnt = 0;
		
	}
	
	return 0;
}

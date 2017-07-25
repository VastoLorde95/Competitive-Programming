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
typedef pair<ll,ll> pii;

map<pii, ll> cost;

int hgt(ll x){
	int mx = 0;
	for(int i = 0; i <= 60; i++){
		if((x&(1ll<<i))) mx = i;
	}
	return mx+1;
}

int main(){ _
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int t; ll u, v;
		cin >> t >> u >> v;
		if(t == 1){
			ll w; cin >> w;
			int h1 = hgt(u);
			int h2 = hgt(v);
			if(h1 < h2){
				swap(u,v);
				swap(h1,h2);
			}
			
			ll p;
			while(h1 > h2){
				p = u/2;
				cost[mp(u,p)] += w;
				u = p;
				h1--;
			}
			
			while(u != v){
				ll p1 = u/2;
				cost[mp(u,p1)] += w;
				ll p2 = v/2;
				cost[mp(v,p2)] += w;
				
				u = p1;
				v = p2;
			}
		}
		else{
			int h1 = hgt(u);
			int h2 = hgt(v);
			if(h1 < h2){
				swap(u,v);
				swap(h1,h2);
			}
			
			ll tot = 0;
			ll p;
			while(h1 > h2){
				p = u/2;
				tot += cost[mp(u,p)];
				u = p;
				h1--;
			}
			
			while(u != v){
				ll p1 = u/2;
				tot += cost[mp(u,p1)];
				ll p2 = v/2;
				tot += cost[mp(v,p2)];
				
				u = p1;
				v = p2;
			}
			
			cout << tot << '\n';
			
		}
	}
	return 0;
}

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
const long double eps = 1e-9;
const long double R = 0.707106781186547476064377794840287157537358051492365;
const long double S = -R;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int N = 100100;
const ll INF = 3e18;

struct point{
	ll x, y, z;
};

struct inequality{
	pair<ll, ll> a, b, c, s;
};

point p[N];
int n;

point getSolution(inequality &e){
	point ret = {INF,INF,INF};
	if(e.a.fi > e.a.se or e.b.fi > e.b.se or e.c.fi > e.c.se or e.s.fi > e.s.se) return ret;
	if(e.a.fi + e.b.fi + e.c.fi > e.s.se or e.a.se + e.b.se + e.c.se < e.s.fi) return ret;
	
	ret.x = e.a.fi;
	ret.y = e.b.fi;
	ret.z = e.c.fi;
	
	ll del = max(0ll, e.s.fi - (e.a.fi + e.b.fi + e.c.fi));
	
	ll t;
	
	t = min(del, e.a.se - e.a.fi);
	ret.x += t;
	del   -= t;
	t = min(del, e.b.se - e.b.fi);
	ret.y += t;
	del   -= t;
	t = min(del, e.c.se - e.c.fi);
	ret.z += t;
	del   -= t;
	
	return ret;
}

void updateBounds(pair<ll,ll> &p1, pair<ll, ll> &p2){
	p1.fi = max(p1.fi, p2.fi);
	p1.se = min(p1.se, p2.se);
}

void update(inequality &e, inequality &t){
	updateBounds(e.a, t.a);
	updateBounds(e.b, t.b);
	updateBounds(e.c, t.c);
	updateBounds(e.s, t.s);
}

ll div(ll x){
	return (x-(x&1))/2;
}

point check(ll val){
	inequality e;
	e.a = e.b = e.c = e.s = mp(-INF, INF);
	
	inequality t;
	for(int i = 0; i < n; i++){
		t.s = mp( p[i].x + p[i].y + p[i].z - val,  p[i].x + p[i].y + p[i].z + val);
		t.a = mp(-p[i].x + p[i].y + p[i].z - val, -p[i].x + p[i].y + p[i].z + val);
		t.b = mp( p[i].x - p[i].y + p[i].z - val,  p[i].x - p[i].y + p[i].z + val);
		t.c = mp( p[i].x + p[i].y - p[i].z - val,  p[i].x + p[i].y - p[i].z + val);
		
		update(e, t);
	}
	
	point ans = {INF, INF, INF};
	
	
	for(int i = 0; i < 2; i++){
		t = e;
		
		t.a.fi = div(t.a.fi - i + 1);
		t.b.fi = div(t.b.fi - i + 1);
		t.c.fi = div(t.c.fi - i + 1);
		t.s.fi = div(t.s.fi - 3*i + 1);
		
		t.a.se = div(t.a.se - i);
		t.b.se = div(t.b.se - i);
		t.c.se = div(t.c.se - i);
		t.s.se = div(t.s.se - 3*i);
		
		ans = getSolution(t);
		if(ans.x != INF){
			point ret;
			ret.x = ans.y + ans.z + i;
			ret.y = ans.x + ans.z + i;
			ret.z = ans.x + ans.y + i;
			return ret;
		}
	}
	
	return ans;
}

void solve(){
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%I64d%I64d%I64d", &p[i].x, &p[i].y, &p[i].z);
	}
	
	ll lo = -1, mid, hi = INF;
	while(lo + 1 < hi){
		mid = lo + (hi-lo) / 2;
		if(check(mid).x != INF) hi = mid;
		else lo = mid;
	}
	
	point ans = check(hi);
	
	printf("%I64d %I64d %I64d\n", ans.x, ans.y, ans.z);
}

int main(){
	int t;
	sd(t);
	while(t--){
		solve();
	}
	return 0;
}

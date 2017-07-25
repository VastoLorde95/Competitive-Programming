#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef long long ll;

const ll MAXN = 200001;

// x left x right cnt left cnt right
ll tree1[MAXN], tree2[MAXN], tree3[MAXN], tree4[MAXN];

ll t, n, MOD = 1E9 + 7, sorted_index[MAXN];
ll ans;
vector<pair<ll, ll> > x;
vector<pair<ll, ll> > p;

ll query1(ll idx){
    ll sum = 0;
    while(idx){
        sum += tree1[idx];
        sum %= MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void update1(ll idx, ll val){
    while(idx < MAXN){
        tree1[idx] += val;
        tree1[idx] %= MOD;
        idx += (idx & -idx);
    }
}

ll query2(ll idx){
    ll sum = 0;
    while(idx){
        sum += tree2[idx];
        sum %= MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void update2(ll idx, ll val){
    while(idx < MAXN){
        tree2[idx] += val;
        tree2[idx] %= MOD;
        idx += (idx & -idx);
    }
}

ll query3(ll idx){
    ll sum = 0;
    while(idx){
        sum += tree3[idx];
        sum %= MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void update3(ll idx, ll val){
    while(idx < MAXN){
        tree3[idx] += val;
        tree3[idx] %= MOD;
        idx += (idx & -idx);
    }
}

ll query4(ll idx){
    ll sum = 0;
    while(idx){
        sum += tree4[idx];
        sum %= MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void update4(ll idx, ll val){
    while(idx < MAXN){
        tree4[idx] += val;
        tree4[idx] %= MOD;
        idx += (idx & -idx);
    }
}

int main(){
	sd(t);
	while(t--){
		memset(tree1, 0, sizeof tree1);
		memset(tree2, 0, sizeof tree2);
		memset(tree3, 0, sizeof tree3);
		memset(tree4, 0, sizeof tree4);
		memset(sorted_index, 0, sizeof sorted_index);
		
		sd(n);
		p.clear();
		x.clear();
		
		ans = 0;
		
		ll mx = 0;
		for(ll i = 0; i < n; i++){
			ll cord; sd(cord);
			x.pb(mp(cord,i));
			mx = max(mx, cord);
		}
		
		sort(x.begin(), x.end());
		
		for(ll i = 0; i < n; i++){
			sorted_index[x[i].se] = i;
		}
		
		for(ll i = 0; i < n; i++){
			update1(i+1, x[i].fi);
			update2(n-i, mx - x[i].fi);
			
			update3(i+1, 1);
			update4(n-i, 1);
		}
		
		for(ll i = 0; i < n; i++){
			ll val; sd(val);
			p.pb(mp(val, i));
		}
		
		sort(p.begin(), p.end(), greater<pair<ll, ll> >());
		
		foreach(it, p){
			ll cnt = it->fi, i = sorted_index[it->se];
			ll tmp;
			
			tmp = (query1(n) - query1(i+1) + MOD)%MOD;
			tmp = (tmp + MOD - (((query3(n) - query3(i+1))*(ll)x[i].fi)%MOD))%MOD;
			
			ans = (ans + (tmp*cnt)%MOD)%MOD;
			
			update1(i+1, -x[i].fi);
			update3(i+1, -1);
			
			tmp = (query2(n) - query2(n-i) + MOD)%MOD;
			tmp = (tmp + MOD - ((query4(n) - query4(n-i))*(ll)(mx - x[i].fi))%MOD)%MOD;
			
			ans = (ans + (tmp*cnt)%MOD)%MOD;
			
			update2(n-i, -(mx-x[i].fi));
			update4(n-i, -1);
		}

		printf("%lld\n", ans);
	}
	return 0;
}

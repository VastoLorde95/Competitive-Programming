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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

typedef long long ll;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
long long l = v.size(); for(long long i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const ll N = 500100;

ll n, h, w, inf = 1ll<<60;
string s;
map<ll, ll> lx, ly;
ll MOD = 1e9 + 7;
vector<ll> m;

int main(){ _
	cin >> n >> h >> w;
	cin >> s;
	
	ll t1 = -inf, t2 = inf, t3 = -inf, t4 = inf;	

	ll x = 0, y = 0;
	lx[0] = 0, ly[0] = 0;
	for(ll i = 1; i <= n; i++){
		if(s[i-1] == 'U') x--;
		else if(s[i-1] == 'D') x++;
		else if(s[i-1] == 'L') y--;
		else if(s[i-1] == 'R') y++;
		
		if(!lx.count(x)) lx[x] = i;
		if(!ly.count(y)) ly[y] = i;
		
		t1 = max(t1,x), t2 = min(t2,x), t3 = max(t3,y), t4 = min(t4,y);
	}
	
	if(x == 0 and y == 0 and t1 < h and t2 > -h and t3 < w and t4 > -w){
		puts("-1");
		return 0;
	}
	
	ll v1, v2, mn, free = 0;
	for(int i = 1; i <= w; i++){
		mn = inf;
		if(t3 >= w-i+1){
			mn = min(mn, ly[w-i+1]);
		}
		if(t4 <= -i){
			mn = min(mn, ly[-i]);
		}
		
		if(mn == inf){
			if(y > 0 and t3 > 0){
				v1 = (w-i+1 - t3 + y-1)/y;
				v2 = w-i+1 - v1*y;
				
				assert(v2 >= 0);
	
				if(ly.count(v2)) mn = min(mn, n*v1 + ly[v2]);
			}
			else if(y < 0 and t4 < 0){
				v1 = -(i + t4 + abs(y) - 1)/y;
				v2 = i - v1*abs(y);
		
				assert(v2 >= 0);
		
				if(ly.count(-v2)) mn = min(mn, n*v1 + ly[-v2]);
			}
		}
		
		if(mn == inf){
			free++;
			continue;
		}

		m.pb(mn%MOD);
	}
	
	sort(m.begin(), m.end());
	vector<ll> cm(m);
	for(int i = 1; i < cm.size(); i++) cm[i] = (cm[i] + cm[i-1])%MOD;
	
	ll ans = 0;
	for(int i = 1; i <= h; i++){
		mn = inf;
		
		if(t1 >= h-i+1){
			mn = min(mn, lx[h-i+1]);
		}
		
		if(t2 <= -i){
			mn = min(mn, lx[-i]);
		}

		if(mn == inf){
			if(x > 0 and t1 > 0){
				v1 = (h-i+1 - t1 + x-1)/x;
				v2 = h-i+1 - v1*x;
				
				assert(v2 >= 0);
			
				if(lx.count(v2)) mn = min(mn, n*v1 + lx[v2]);
			}
			else if(x < 0 and t2 < 0){
				v1 = -(i + t2 + abs(x) - 1)/x;
				v2 = i - v1*abs(x);
		
				assert(v2 >= 0);
		
				if(lx.count(-v2)) mn = min(mn, n*v1 + lx[-v2]);
			}
		}
		
		int id = upper_bound(m.begin(), m.end(), mn) - m.begin();
	
		if(id > 0){
			ans += cm[id-1];
			ans %= MOD;
		}
				
		if(mn != inf){
			ans += ((free + (ll)(cm.size())-id) * mn)%MOD;
			ans %= MOD;
		}
		
		if(mn == inf and free > 0){
			puts("-1"); return 0;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

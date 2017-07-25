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

const int N = 200100;
const int M = 5;
const ll INF = (1LL << 60);

ll t[N], top[M];
vector<int> ppl[M];

ll n, k, b, c;

ll getmod(ll x){
	return ((x % M) + M) % M;
}

ll getdist(ll x, ll y){
	if(M * c <= b) return c * (y - x);
	return (b * ((y - x) / M)) + (c * ((y - x) % M));
}

int main(){ _
	cin >> n >> k >> b >> c;
	
	for(int i = 0; i < n; i++) cin >> t[i];
	
	sort(t, t+n);
	
	ll total, ans = INF;
	
	for(int rem = 0; rem < M; rem++){
		
		for(int i = 0; i < M; i++) ppl[i].clear();
		for(int i = 0; i < M; i++) top[i] = 0;
		for(int i = 0; i < k; i++) ppl[getmod(t[i])].pb(t[i]);

		ll val = t[k-1], prev;
		while(getmod(val) != rem) val++;
		
		total = 0;
		for(int i = 0; i < M; i++) foreach(person, ppl[i]) total += getdist(*person, val);
		
		ans = min(ans, total);
		
		for(int i = k; i < n; i++){
			prev = val;
			val = t[i];
			while(getmod(val) != rem) val++;
			
			total += getdist(prev, val) * k;
			
			int id = -1;
			ll mx = getdist(t[i], val);
			for(int j = 0; j < M; j++){
				if(top[j] == ppl[j].size()) continue;
				
				ll d = getdist(ppl[j][top[j]], val);
				if(d > mx) mx = d, id = j;
			}
						
			if(id != -1){
				total -= getdist(ppl[id][top[id]++], val);
				total += getdist(t[i], val);
				ppl[getmod(t[i])].pb(t[i]);
			}
			
			ans = min(ans, total);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

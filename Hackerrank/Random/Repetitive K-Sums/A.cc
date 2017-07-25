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

const int N = 100100;

int n, k;
vector<ll> res;
map<ll, int> cnt;

void go(ll val, int id, int tot){
	if(id == 0 and tot != k) return;
	if(id == 0 and tot == k){
		if(--cnt[val] == 0) cnt.erase(val);
		return;
	}
	
	int rem = k-tot;
	ll x = res[id-1];
	for(int i = 0; i <= rem; i++){
		go(val + x * i, id - 1, tot + i);
	}
}

string line;

void solve(){
	cin >> n >> k;
	getline(cin, line);
	
	istringstream iss(line);	
	
	res.clear();
	cnt.clear();
	
	ll si;
	while(iss >> si) cnt[si]++;
	
	if(n == 1){
		printf("%lld\n", (cnt.begin()->fi)/k);
		return;
	}
	
	ll prev = cnt.begin()->fi / k;
	cnt[prev*k]--;
	if(cnt[prev*k] == 0) cnt.erase(prev*k);
	res.pb(prev);
	
	while(!cnt.empty()){
		ll x = (cnt.begin()->fi - prev*(k-1));
		res.pb(x);
		
		int l = res.size();
		for(int i = 1; i <= k; i++) go(x * i, l - 1, i);
	}
	
	for(int i = 0; i < n; i++) printf("%lld ", res[i]); puts("");
	
}

int main(){ _
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

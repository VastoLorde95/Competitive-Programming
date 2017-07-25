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
const ll MOD = 1e9 + 7;

vector<int> v;


void solve(){
	int n, m; ll x, y;
	cin >> n >> m >> x >> y;
	x--, y--;
	v.clear();
	for(int i = 0; i < n; i++){
		int val; sd(val);
		v.pb(val);
	}
	
	for(int i = 0; i < m; i++){
		vector<int> q;
		q.pb(v[0]);
		for(int j = 1; j < v.size(); j++){
			q.pb(q.back() + v[j] % MOD);
			q.pb(v[j]);
		}
		v = q;
	}
	
	ll ans = 0;
	for(int i = x; i <= y; i++){
		ans = ans + v[i] % MOD;
	}
	
	cout << ans << endl;
	
	
}

int main(){
	int t;
	sd(t);
	while(t--)
		solve();
	return 0;
}

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

bool check(ll x, ll y, ll a, ll b){
	if(x < 0 or y < 0) return false;
	if(a + b != x*y) return false;
	
	if(a%x == 0 and b%x == 0) return true;
	if(a%y == 0 and b%y == 0) return true;
	return false;
}

void solve(){
	ll r, c, m, k, j;
	cin >> r >> c >> m >> k >> j;
	
	if(m+k != (r*c) - j){
		cout << "No\n";
		return;
	}
	
	if(m%r == 0){
		ll h = m/r;
		if(check(r, c-h, k, j)){
			cout << "Yes\n";
			return;
		}
	}
	
	if(j%r == 0){
		ll h = j/r;
		if(check(r, c-h, m, k)){
			cout << "Yes\n";
			return;
		}
	}
	
	if(k%r == 0){
		ll h = k/r;
		if(check(r, c-h, m, j)){
			cout << "Yes\n";
			return;
		}
	}
	
	if(m%c == 0){
		ll h = m/c;
		if(check(r-h, c, k, j)){
			cout << "Yes\n";
			return;
		}
	}
	
	if(j%c == 0){
		ll h = j/c;
		if(check(r-h, c, m, k)){
			cout << "Yes\n";
			return;
		}
	}
	
	if(k%c == 0){
		ll h = k/c;
		if(check(r-h, c, m, j)){
			cout << "Yes\n";
			return;
		}
	}
	
	cout << "No\n";
	
}

int main(){ _
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

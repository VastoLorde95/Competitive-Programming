#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

ll a00, a01, a10, a11;

ll get(ll v){
	ll lo = 0, hi = v+10, mid;
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		ll val = (mid * (mid-1)) / 2;
		if(val <= v) lo = mid; else hi = mid;
	}
	return lo;
}

bool solve(ll c0, ll c1, bool verbose){
	if((c0 * (c0-1))/2 != a00 or (c1 * (c1-1))/2 != a11 or c0 * c1 != a10 + a01){
		if(verbose) cout << "Impossible" << endl;
		return 0;
	}
	
	string ans;
	for(int i = 0; i < c0; i++) ans += '0';
	for(int i = 0; i < c1; i++) ans += '1';
	
	int n = c0 + c1;
	ll x = c0 * c1, y = 0;
	
	int j = 0;
	for(int i = c0; i < n and x > a01; i++){
		while(x - (i-j) < a01) j++;
		x -= i-j;
		y += i-j;
		swap(ans[i], ans[j]);
		j++;
	}
	
	if(verbose) cout << ans << endl;
	return 1;
}

int main(){ _
	cin >> a00 >> a01 >> a10 >> a11;
	
	if(a00 + a01 + a10 + a11 == 0){
		cout << 0 << endl;
		return 0;
	}
	if(a00 + a01 + a10 + a11 == 1){
		if(a00) cout << "00" << endl;
		if(a01) cout << "01" << endl;
		if(a10) cout << "10" << endl;
		if(a11) cout << "11" << endl;
		return 0;
	}
	
	ll c0 = get(a00);
	ll c1 = get(a11);
	
	if(a00 == 0 and a11 > 0){
		if(solve(0, c1, 0)) solve(0, c1, 1);
		else if(solve(1, c1, 0)) solve(1, c1, 1);
		else cout << "Impossible" << endl;
		return 0;
	}
	else if(a00 > 0 and a11 == 0){
		if(solve(c0, 0, 0)) solve(c0, 0, 1);
		else if(solve(c0, 1, 0)) solve(c0, 1, 1);
		else cout << "Impossible" << endl;
		return 0;
	}
	else if(a00 == 0 and a11 == 0){
		if(solve(0, 0, 0)) solve(0, 0, 1);
		else if(solve(1, 1, 0)) solve(1, 1, 1);
		else if(solve(1, 0, 0)) solve(1, 0, 1);
		else if(solve(0, 1, 0)) solve(0, 1, 1);
		else cout << "Impossible" << endl;
		return 0;
	}
	
	solve(c0, c1, 1);
	
	return 0;
}

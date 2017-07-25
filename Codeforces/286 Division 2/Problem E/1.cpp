#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int n, m, k, p;
ll h[100010], a[100010];
ll l[100010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> k >> p;
	rep(i,n) cin >> h[i] >> a[i];
	rep(i,n){
		l[i] = h[i] + a[i] * m;
	}
	ll lo = 0, hi = 2e13;
	while(lo + 1 < hi){
		ll mi = (lo + hi) / 2;
		bool ok = 1;
		ll total = 0;
		rep(i,n){
			total += max(0LL, (l[i] - mi + p - 1) / p);
		}
		if(total > m * k){
			ok = 0;
		}else{
			int t[10010] = {};
			rep(i,n) if(l[i] > mi){
				for(ll target = (l[i] - mi) % p == 0 ? p : (l[i] - mi) % p; target <= l[i] - mi; target += p){
					if(target - h[i] <= 0){
						t[0]++;
					}else if(target - h[i] > a[i] * (m-1)){
						ok = 0;
						goto end;
					}else{
						t[(target - h[i] + a[i] - 1) / a[i]]++;
					}
				}
			}
			int rest = 0;
			rep(i,m){
				rest += t[i];
				rest = max(0, rest - k);
			}
			ok = rest == 0;
		}
		end:;
		(ok ? hi : lo) = mi;
	}
	cout << hi << endl;
}


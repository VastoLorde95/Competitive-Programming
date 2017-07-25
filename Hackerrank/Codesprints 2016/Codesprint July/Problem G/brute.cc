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

const int N = 5010;

ll w[N], x[N];
ll cost[N][N];

int main(){ _
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> x[i] >> w[i];
	}

	ll best = 1ll << 60;	
	for(int i = 0; i < 1ll<<n; i++){
		if(__builtin_popcount(i) != k) continue;
		
		ll tot = 0;
		for(int j = 0; j < n; j++){
			ll cur = 1ll << 60;
			for(int r = 0; r < n; r++){
				if((i&(1ll<<r)) > 0){
					cur = min(cur, w[j] * abs(x[r] - x[j]));
				}
			}
			tot += cur;
		}
		if(tot < best) best = tot;
	}
	
	tr(best);
	
	return 0;
}

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

int n, m;
ll h[N];
ll p[N];

bool f(ll x){
	for(int i = 1, j = 1; i <= n; i++){
		if(p[j] < h[i]){
			ll d = h[i] - p[j];
			
			if(d > x) return false;
			
			ll r1 = x - d * 2;
			ll r2 = (x - d) / 2;
			
			int j1 = j, j2 = j;
			
			while(j1 <= m and p[j1] <= h[i] + r1) j1++;
			while(j2 <= m and p[j2] <= h[i] + r2) j2++;
			
			j = max(j1, j2);
			if(j > m) return true;
		}
		else{
			while(j <= m and p[j] <= h[i] + x) j++;
			if(j > m) return true;
		}
	}
	return false;
}

int main(){ _
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> p[i];
	}
	
	ll lo = -1, hi = 1e11, mid;
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(f(mid)) hi = mid;
		else lo = mid;
	}
	
	tr(hi);
		
	return 0;
}

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

const int N = 500100;
const int INF = 1e9;

int n, a, b, T;
string s;

int t[N];

int solve(){
	for(int i = 1; i < n; i++) t[i] = INF;
	
	t[0] = 1 + ((s[0] == 'w')? b : 0);
	
	if(t[0] > T) return 0;
	
	int last = 0;
	for(int i = 1; i < n; i++){
		t[i] = t[i-1] + a + 1 + ((s[i] == 'w')? b : 0);
		if(t[i] > T) break;
		last = i;
	}
	
	int ans = 1 + last;
	
	int cur = 0;
	for(int i = n-1; i > 0; i--){
		if(s[i] == 'w') cur += a + b + 1; else cur += a + 1;
		
		if(cur + t[0] > T) break;
		
		int l = 1 + (n - i), lo = 0, hi = i, mid;
		while(lo + 1 < hi){
			mid = (lo + hi) >> 1;
			int cost = cur + a * (n - i) + t[mid];
			
			if(cost <= T) lo = mid; else hi = mid;
		}
		
		ans = max(ans, l + lo);
	}
	
	return ans;
}

int main(){ _
	cin >> n >> a >> b >> T >> s;

	int ans = solve();
	for(int i = 1, j = n-1; i < j; i++, j--) swap(s[i], s[j]);
	ans = max(ans, solve());
	
	cout << ans << endl;
	
	return 0;
}

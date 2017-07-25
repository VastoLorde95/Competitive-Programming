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

const long double PI = 3.1415926535897932384626433832795;

const int N = 5001;

ll dp[N][N];
ll cnt[N];

int a, b, c, d;

int main(){
	cin >> a >> b >> c >> d;
	
	vector<int> v = {a,b,c,d};
	sort(v.begin(), v.end());
	a = v[0];
	b = v[1];
	c = v[2];
	d = v[3];
	
	ll tot = 0;
	for(int i = 1; i <= c; i++){
		for(int j = i; j <= d; j++){
			dp[i][i^j]++;
			tot++;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = N-2; j > 0; j--){
			dp[j][i] += dp[j+1][i];
		}
	}
	
	for(int i = 1; i < N; i++){
		for(int j = 0; j < N; j++){
			cnt[i] += dp[i][j];
		}
	}
	
	
	ll ans = 0;
	for(int i = 1; i <= a; i++){
		for(int j = i; j <= b; j++){
			int x = i ^ j;
			ans += (cnt[j] - dp[j][x]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

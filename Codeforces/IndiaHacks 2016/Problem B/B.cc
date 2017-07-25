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

const int N = 100;
const int M = 6;
const int Q = 200;

ll dp[N][M];

int n, q;
string x[Q], y[Q];

int main(){ _
	cin >> n >> q;
	
	for(int i = 1; i <= q; i++)
		cin >> x[i] >> y[i];
	
	dp[1][0] = 1;	
	
	for(int i = 1; i < n; i++)
		for(int j = 0; j < M; j++)
			for(int k = 1; k <= q; k++)
				if(y[k][0] - 'a' == j)
					dp[i+1][x[k][0] - 'a'] += dp[i][j];

	ll ans = 0;
	for(int i = 0; i < M; i++) ans += dp[n][i];
	
	cout << ans << endl;
	
	return 0;
}

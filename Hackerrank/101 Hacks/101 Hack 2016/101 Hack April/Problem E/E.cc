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

const ll N = 100100;
const int inf = 1e9;

ll n, k;

ll dp[N];

int len[N];
ll cnt[N];

vector<int> v;
vector<pair<pair<int, ll>, int> > tbl[N];

int main(){ _
	cin >> n >> k;
	
	int x, mx = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.pb(x);
		
		mx = max(mx, x);
	}

	for(int i = 0; i < n; i++) v[i] = mx - v[i];

	reverse(v.begin(), v.end());

	dp[0] = 1;
	
	int lis = 0;
	
	vector<int> d(n+1, inf);
	for(int i = 0; i < n; i++){
		int pos = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
		d[pos] = v[i];
		
		len[n-i-1] = pos + 1;
		cnt[n-i-1] = dp[pos];
		
		dp[pos+1] += dp[pos];
		if(dp[pos+1] > k) dp[pos+1] = k;
		
		lis = max(lis, pos+1);	
	}
	
	if(dp[lis] < k){
		cout << -1 << endl;
		return 0;
	}
	
	reverse(v.begin(), v.end());
	
	for(int i = 0; i < n; i++) v[i] = mx - v[i];

	for(int i = 0; i < n; i++){
		tbl[len[i]].pb(mp(mp(v[i], cnt[i]), i));
	}
	
	int up = 0;
	
	vector<int> answer;
	
	for(int i = lis; i > 0; i--){
		sort(tbl[i].begin(), tbl[i].end());
		
		ll cur = 0, ncur;
		for(int j = 0; j < tbl[i].size(); j++){
			if(tbl[i][j].se < up) continue;
			if(!answer.empty() and answer.back() >= tbl[i][j].fi.fi) continue;
			
			ncur = cur + tbl[i][j].fi.se;
			if(ncur >= k){
				answer.pb(tbl[i][j].fi.fi);
				k -= cur;
				up = tbl[i][j].se;
				break;
			}
			cur = ncur;
		}
	}

	for(int i = lis; i > 0; i--){
		tr(meta, i, tbl[i]);
	}

	tr(answer);
	
	return 0;
}

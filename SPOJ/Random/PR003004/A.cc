#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

vector<int> itov(ll x){
	if(!x) return {0};
	vector<int> v;
	
	while(x){
		v.pb(x%10);
		x /= 10;
	}
	
	reverse(v.begin(), v.end());
	
	return v;
}

const int N = 20;

ll sum[N][2];
ll cnt[N][2];

ll get(vector<int> v, bool flag){
	int n = v.size();
	
	memset(sum, 0, sizeof sum);
	memset(cnt, 0, sizeof cnt);
	
	cnt[0][1] = 1;

	for(int i = 0; i < n; i++){
		for(int eq = 0; eq < 2; eq++){
			ll c = cnt[i][eq];
			ll s = sum[i][eq];
			if(!c) continue;
			
			int mnd = (eq)? v[i] : 9;
			
			for(int nd = 0; nd <= mnd; nd++){
				int neq = (eq and nd == v[i]);
				sum[i+1][neq] += s + c * nd;
				cnt[i+1][neq] += c;
			}
		}
	}
	
	ll ret = sum[n][0] + ((flag)? sum[n][1] : 0);
	
	return ret;
}

void solve(){
	ll a, b;
	cin >> a >> b;
	
	vector<int> A = itov(a);
	vector<int> B = itov(b);
	
	cout << get(B,1) - get(A,0) << endl;
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

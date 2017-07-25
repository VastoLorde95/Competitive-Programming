#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;

const int N = 1001000;

ll inf = (1ll<<60);

int n;
ll a, b, ans = inf; 

int arr[N];

ll dp[N][3];

void solve(int prime){
	bool ok = false;
	for(int i = 1; i <= n; i++){
		for(int j = -1; j <= 1; j++) if((arr[i]+j)%prime == 0) ok = true;			
	}
	if(!ok) return;
	
	for(int i = -1; i <= 1; i++){
		int num = arr[1]+i;
		if(num%prime == 0) ok = true;
	}
	if(!ok) return;
	
	dp[1][0] = (arr[1]%prime == 0)? 0 : b;
	dp[1][1] = inf;
	dp[1][2] = dp[1][0];
	
	for(int i = 2; i <= n; i++){
		dp[i][0] = dp[i][1] = dp[i][2] = inf;
		for(int j = -1; j <= 1; j++){
			int num = arr[i]+j;
			if(num%prime == 0){
				if(j == 0){
					dp[i][0] = min(dp[i][0], dp[i-1][0]);
					dp[i][2] = min(dp[i][2], min(dp[i-1][1], dp[i-1][2]));
				}
				else{
					dp[i][0] = min(dp[i][0], dp[i-1][0] + b);
					dp[i][2] = min(dp[i][2], min(dp[i-1][1], dp[i-1][2]) + b);
				}	
			}
		}
		dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][1]) + a);
	}
	
	ans = min(ans, min(dp[n][0], min(dp[n][1], dp[n][2])));
	return;
}

int main(){ _
	cin >> n >> a >> b;
	
	for(int i = 1; i <= n; i++) cin >> arr[i];
	
	set<int> p;
	for(int i = -1; i <= 1; i++){
		int num = arr[1]+i;
		
		for(int j = 2; j*j <= num; j++){
			if(num%j == 0){
				p.insert(j);
				while(num%j == 0) num /= j;
			}
		}
		if(num > 1) p.insert(num);
	}	
	foreach(it, p) solve(*it);
	
	reverse(arr+1, arr+1+n);

	p.clear();	
	for(int i = -1; i <= 1; i++){
		int num = arr[1]+i;
		
		for(int j = 2; j*j <= num; j++){
			if(num%j == 0){
				p.insert(j);
				while(num%j == 0) num /= j;
			}
		}
		if(num > 1) p.insert(num);
	}	
	foreach(it, p) solve(*it);
	
	cout << ans << endl;

	return 0;
}


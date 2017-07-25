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

long long n, k;
long long a[1000];
long long dp[1000], MOD = 1e9 + 9;

int main(){ _
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	long long res = 0;
	for(int i = 0; i < n; i++){
		long long p = 1;
		long long sum = 0;
		for(int j = i; j >= 0; j--){
			p = (p*a[j])%k;
			if(p == 0){
				sum += (j-1 >= 0)? dp[j-1] : 1;
			}
			if(sum >= MOD) sum -= MOD;
		}
		dp[i] = sum;
	}

	cout << dp[n-1] << endl;
	
	return 0;
}

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

const int N = 20;

int n, k;
double p[N], ans[N];
double dp[1 << N];
double eps = 1e-9;

int main(){ _
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}	
	
	if(n == k){
		for(int i = 0; i < n; i++){
			if(p[i] != 0){
				cout << 1 << ' ';
			}
			else
				cout << 0 << ' ';
		}
		cout << endl;
		return 0;
	}

	int up = 1 << n;
	for(int i = 0; i < up; i++){
		double tot = 0;
		
		for(int j = 0; j < n; j++){
			if(i&(1<<j)) tot += p[j];
		}
		
		if(tot == 1) tot = 0;
		dp[i] = 1.0 / (1.0 - tot);
	}
	
	for(int j = 0; j < n; j++){
		for(int i = 0; i < up; i++){
			if(i&(1<<j)){
				dp[i] -= dp[i^(1<<j)];
			}
		}	
	}

	for(int i = 0; i < up; i++){
		if(__builtin_popcount(i) >= k) continue;
		for(int j = 0; j < n; j++){
			if((i&(1<<j)) == 0) ans[j] += p[j] * dp[i];
		}		
	}

	cout << fixed << setprecision(15);
	
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	
	return 0;
}

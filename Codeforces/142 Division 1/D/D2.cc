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

const int INF = 1e9;
const int N = 5010;

int n;
int h[N];
int dp[N][N];

int main(){ _
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = INF;
		}
	}
	
	int tmp = 0;
	for(int i = 1; i <= n; i++){
		tmp += h[i];
		dp[i][1] = tmp;		
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i-1; j >= 1; j--){
			dp[i][j] = min(dp[i][j], dp[i][j+1]);
		}
		
		int tot = 0;
		for(int j = i+1; j <= n; j++){
			tot += h[j];
		}
		
		int k = i;
		for(int j = n; j > i; j--){
			while(k > 0 and dp[i][k] > tot){
				k--;
			}
			
			if(k == 0) break;
			dp[j][k+1] = min(dp[j][k+1], tot);
			tot -= h[j];
		}
	}
	
	int ans = n;
	while(ans >= 1 and dp[n][ans] == INF) ans--;
	cout << n - ans << endl;
	
	return 0;
}

// any answer with k merges cannot be worse than an answer with k-1 merges. Thus we just need to find the largest k. We never need the smaller values of k!

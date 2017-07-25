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

const int N = 1010;
const int M = 11;

int a[N];
int dp[N][1 << M];
int s[N];
int l[N];
int p[N];
int last[N];

map<int, int> id;

void pre(){
	for(int i = 2; i < N; i++){
		p[i] = 1;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				p[i] = 0;
				break;
			}
		}
	}
	
	int tid = 0;
	for(int i = 2; i <= 31; i++){
		if(p[i]){
			id[i] = tid++;
		}
	}
	
	for(int i = 2; i < N; i++){
		if(!p[i]) continue;
		for(int j = i; j < N; j += i){
			l[j] = i;
			if(i <= 31) s[j] |= (1 << id[i]);
		}
	}
}

bool cmp(const int &i, const int &j){
	return l[i] > l[j];
}

void solve(){
	int n;
	cin >> n;
	
	for(int i = 0; i < N; i++){
		last[i] = -1;
	}
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n, cmp);
	
	for(int i = 0; i < (1<<M); i++){
		if(s[a[0]]&i){
			dp[0][i] = 0;
		}
		else{
			dp[0][i] = 1;
		}	
	}

	last[l[a[0]]] = 0;
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < (1 << M); j++){
			if(s[a[i]]&j)
				dp[i][j] = dp[i-1][j];
			else{
				if(l[a[i]] > 31){
					if(last[l[a[i]]] == -1) dp[i][j] = max(dp[i-1][j], 1 + dp[i-1][j | s[a[i]]]);
					else dp[i][j] = max(dp[i-1][j], 1 + ((last[l[a[i]]] == 0)? 0 : dp[last[l[a[i]]]-1][j | s[a[i]]]));
				}
				else{
					dp[i][j] = max(dp[i-1][j], 1 + dp[i-1][j | s[a[i]]]);
				}
			}
		}
		
		if(last[l[a[i]]] == -1)
			last[l[a[i]]] = i;
	}
	
	cout << dp[n-1][0] << endl;
	
}

int main(){ _
	pre();

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

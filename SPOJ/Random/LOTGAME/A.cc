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

const int N = 31;

ll dp[N][2][2][2];

vector<int> bin(int x){
	vector<int> ret;
	while(x){
		ret.pb(x%2);
		x /= 2;
	}
	return ret;
}

void pad(vector<int> &v, int l){
	while(v.size() < l) v.pb(0);
	reverse(v.begin(), v.end());
}

void solve(){
	int a, b, k;
	cin >> a >> b >> k;
	
	vector<int> A = bin(a);
	vector<int> B = bin(b);
	vector<int> K = bin(k);
	
	int mx = max(A.size(), max(B.size(), K.size()));
	pad(A, mx);
	pad(B, mx);
	pad(K, mx);
	
	int n = mx;
	
	memset(dp, 0, sizeof dp);
	
	dp[0][1][1][1] = 1;
	for(int i = 0; i < n; i++){
		for(int ek = 0; ek < 2; ek++){
			for(int ea = 0; ea < 2; ea++){
				for(int eb = 0; eb < 2; eb++){
					ll val = dp[i][ek][ea][eb];
					if(!val) continue;
					
					int mdK = (ek)? K[i] : 1;
					int mdA = (ea)? A[i] : 1;
					int mdB = (eb)? B[i] : 1;
					
					for(int x = 0; x <= mdK; x++){
						for(int y = 0; y <= mdA; y++){
							for(int z = 0; z <= mdB; z++){
								if((y&z) != x) continue;
								int neqk = (ek and x == K[i]);
								int neqa = (ea and y == A[i]);
								int neqb = (eb and z == B[i]);
														
								dp[i+1][neqk][neqa][neqb] += val;			
							}
						}
					}
				}
			}
		}		
	}
	
	ll res = dp[n][0][0][0];
	cout << res << endl;
}

int main(){ _
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();	
	}
	return 0;
}

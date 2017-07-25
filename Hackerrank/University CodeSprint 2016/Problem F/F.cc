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

const int N = 50;
const int S = 200;
const int K = 2000;

unordered_map<int, vector<int> > dp[N+1][S+1];
//unordered_map<int, vector<int> > dp[S+1][K+1];

int main(){ _

//	int cnt = 0;
		
	for(int i = 0; i <= S; i++){
		dp[1][i][0].pb(i);
//		++cnt;
	}

	for(int s = 0; s <= S; s++){
		for(int x = 0; x <= s-x; x++){
			dp[2][s][s-x-x].pb(x);
		}
	}

	int v, up;
	for(int x = S; x >= 0; x--){
		for(int i = 3; i <= N; i++){
			for(int s = x*i; s <= S; s++){
				if(dp[i-1][s-x].empty()) continue;
								
				v = s - x*i;
				up = min((s - i*x) * (i-1), K);
				
				for(int k = v; k <= up; k++){
					if(dp[i-1][s-x].count(k-v)){
						dp[i][s][k].pb(x);
//						++cnt;
					}
				}
			}
		}		
	}	
	
//	tr(cnt);
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int n, s, k;
		cin >> n >> s >> k;
	
		if(dp[n][s][k].empty()){
			cout << -1 << endl;
			continue;
		}
		
		vector<int> res;
		while(n){
			if(res.empty()){
				int j = dp[n][s][k].back();
			
				cout << j << ' ';
				res.pb(j);
				k -= s - n * j;
				s -= j;
			}
			else{
				int j;
				for(int r = (int)(dp[n][s][k].size()) - 1; r >= 0; r--){
					if(res.back() <= dp[n][s][k][r]){
						j = dp[n][s][k][r];
						break;
					}
				}
				
				cout << j << ' ';
				res.pb(j);
				k -= s - n * j;
				s -= j;
			}
			n--;
		}
		
		cout << endl;
		
	}
	
	return 0;
}

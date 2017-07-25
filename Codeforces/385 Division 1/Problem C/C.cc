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

const int N = 16;

char c[N];
int r[N];
int b[N];
int dp1[1<<N][N];
int dp2[1<<N][N][2];

const int INF = 1e9;

int main(){
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> c[i] >> r[i] >> b[i];
	}	

	for(int i = 0; i < 1<<n; i++){
		dp1[i] = INF;
	}
	
	for(int mask = 1; mask < (1<<n); mask++){
		int rr = 0, bb = 0;
		int tr = 0, tb = 0;
		for(int j = 0; j < n; j++){
			if(mask&(1<<j)){
				if(c[j] == 'R') rr++;
				else bb++;
				
				tr += r[j];
				tb += b[j];
			}
		}
		
		for(int j = 0; j < n; j++){
			if(mask&(1<<j)){

				int x = r[j] - dp2[mask^(1<<j)].fi - (rr-(c[j] == 'R'));
				int y = b[j] - dp2[mask^(1<<j)].se - (bb-(c[j] != 'R'));

				x = max(x, 0);
				y = max(y, 0);

				int ot = max(r[j], b[j]);
				int bt = max(max(r[j]-x-(rr-1), b[j]-y-(bb-1)),0);

//				if(mask == 7){
//					tr(j, x, y, ot, bt, rr, bb);
//				}
				
				dp[mask] = max(dp[mask], dp[mask^(1<<j)] + max(x, y));
				dp2[mask] = 
			}
		}
	}
		
	return 0;
}

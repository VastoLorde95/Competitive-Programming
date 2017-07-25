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

const int MOD = 1e9 + 7;

const int N = 55;
const int M = 17;

int dp[N][M][M][M];

void add(int &x, int y){
	x += y;
	if(x >= MOD) x -= MOD;
}

void sub(int &x, int y){
	x -= y;
	if(x < 0) x += MOD;
}

void pre(){
	dp[0][0][0][0] = 1;
	for(int i = 0; i < 52; i++){
		for(int x = 0; x < M; x++){
			for(int y = 0; y < M; y++){
				for(int z = 0; z < M; z++){
					int val = dp[i][x][y][z];
					if(!val) continue;
					
					for(int d = 0; d < 10; d++){
						int nx = x + (d == 3);
						int ny = y + (d == 6);
						int nz = z + (d == 9);
						
						if(nx > 16 or ny > 16 or nz > 16) continue;
						
						add(dp[i+1][nx][ny][nz], val);
					}
				}
			}
		}
	}
}

vector<int> digits(string &x){
	vector<int> ret;
	
	for(char c : x) ret.pb(c - '0');
	return ret;
}

int get(string &s){
	vector<int> v = digits(s);
	
	int n = v.size();
	
	int c3 = 0, c6 = 0, c9 = 0;
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		for(int d = 0; d < v[i]; d++){
			int nx = c3 + (d == 3);
			int ny = c6 + (d == 6);
			int nz = c9 + (d == 9);
			
			for(int j = max(max(1,nx), max(ny,nz)); j < M; j++){
				add(ans, dp[n-i-1][j-nx][j-ny][j-nz]);
			}
		}
		
		c3 += (v[i] == 3);
		c6 += (v[i] == 6);
		c9 += (v[i] == 9);
	}
	
	if(c3 == c6 and c6 == c9 and c3 > 0) add(ans, 1);
	
	return ans;
}

void solve(){
	string a, b;
	cin >> a >> b;
	
	int x = 0, y = 0, z = 0;
	for(char c : a) if(c == '3') x++; else if(c == '6') y++; else if(c == '9') z++;
	
	int flag = (x == y) and (y == z) and (x > 0);	
	
	cout << (get(b) - get(a) + flag + MOD) % MOD << endl;
}

int main(){ _
	pre();
	
	int t;
	cin >> t;
	
	while(t--) solve();
	
	return 0;
}

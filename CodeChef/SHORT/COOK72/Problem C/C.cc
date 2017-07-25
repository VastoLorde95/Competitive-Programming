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

const long double PI = 3.1415926535897932384626433832795;

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

int g[N][N];
int v[N][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'U', 'D', 'L', 'R'};

string ans;

int n, m;

bool check(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m and g[x][y] != 0) return true;
	return false;
}

int delx, dely;

void dfs(int x, int y, string s){
	if(v[x][y]) return;
	v[x][y] = 1;
	
	string t = s;
	reverse(t.begin(), t.end());
	
	ans += t;
	
	for(int i = 0; i < n; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(check(nx, ny)){
			dfs(nx, ny, s + dir[i]);
		}
	}
}

int main(){
	cin >> n >> m;

	int sx, sy;	
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] != '*'){
				g[i][j+1] = (s[j] == '.')? 1 : 2;
				if(g[i][j+1] == 2){
					sx = i, sy = j+1;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == 1){
				dfs(i, j);
			}
		}
	}
	
	return 0;
}

#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const int N = 510;

int n;
ll g[N][N];


int main(){ _
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}

	int r, c;	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> g[i][j];
			if(!g[i][j]){
				r = i, c = j;
			}
		}
	}	
	
	int x;
	if(r == 1) x = r + 1; else x = r - 1;
		
	ll val = 0;
	for(int i = 1; i <= n; i++){
		val += g[x][i];
	}
	
	ll tot = 0;
	for(int i = 1; i <= n; i++){
		tot += g[r][i];
	}
	
	g[r][c] = val - tot;
	
	if(g[r][c] <= 0){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		ll sum = 0;
		for(int j = 1; j <= n; j++){
			sum += g[i][j];
		}
		if(sum != val){
			cout << -1 << endl;
			return 0;
		}
	}
	
	for(int j = 1; j <= n; j++){
		ll sum = 0;
		for(int i =1; i <= n; i++){
			sum += g[i][j];
		}
		if(sum != val){
			cout << -1 << endl;
			return 0;
		}
	}
	
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		sum += g[i][i];
	}
	
	if(sum != val){
		cout << -1 << endl;
		return 0;
	}

	sum = 0;
	for(int i = 1; i <= n; i++){
		sum += g[i][n-i+1];
	}
	
	if(sum != val){
		cout << -1 << endl;
		return 0;
	}
	
	cout << g[r][c] << endl;
	
	return 0;
}

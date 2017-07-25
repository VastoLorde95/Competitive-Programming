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

const int N = 256;

int a[N][N];

void solve(){
	int n; sd(n);
	int m = n * 2;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			sd(a[i][j]);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans += max(max(a[i][j], a[m-1-i][j]), max(a[i][m-1-j], a[m-1-i][m-1-j]));
		}
	}
	
	tr(ans);
	
	
}

int main(){
	int q; sd(q);
	while(q--) solve();
	return 0;
}

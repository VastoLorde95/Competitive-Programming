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

const int N = 101;

int n, m, q;
int ma[N][N];

void rowshift(int x){
	int v = ma[x][1];
	for(int i = 1; i < m; i++){
		ma[x][i] = ma[x][i+1];
	}
	ma[x][m] = v;
}
void colshift(int x){
	int v = ma[1][x];
	for(int i = 1; i < n; i++){
		ma[i][x] = ma[i+1][x];
	}
	ma[n][x] = v;
}

void revrow(int x){
	int v = ma[x][m];
	for(int i = m; i > 1; i--){
		ma[x][i] = ma[x][i-1];
	}
	ma[x][1] = v;
}
void revcol(int x){
	int v = ma[n][x];
	for(int i = n; i > 1; i--){
		ma[i][x] = ma[i-1][x];
	}
	ma[1][x] = v;
}

vector<pii> qr;

int main(){
	sd3(n,m,q);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ma[i][j] = 1;
		}
	}
	
	for(int i = 0; i < q; i++){
		int t; sd(t);
		if(t == 1){
			int r; sd(r);
			rowshift(r);
			qr.pb(mp(t,r));
		}
		else if(t == 2){
			int r; sd(r);
			colshift(r);
			qr.pb(mp(t,r));
		}
		else{
			int x, y, k; sd3(x,y,k);
			ma[x][y] = k;
		}
	}
	
	reverse(qr.begin(), qr.end());
	
	foreach(it, qr){
		if(it->fi == 1){
			revrow(it->se);
		}
		else{
			revcol(it->se);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", ma[i][j]);
		}
		puts("");
	}
	
	return 0;
}

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

const int N = 1002;

const int MAX_X = N, MAX_Y = N;
int tree[MAX_X][MAX_Y];

void update(int x, int y, int val){
    int yy;
    while (x < MAX_X){
        yy = y;
        while(yy < MAX_Y){
			tree[x][yy] += val;
			yy += (yy & -yy);
		}
        x += (x & -x); 
    }
}

int query(int x, int y){
    int yy, sum = 0;
    while (x){
        yy = y;
        while(yy){
			sum += tree[x][yy];
			yy -= (yy & -yy);
		}
        x -= (x & -x); 
    }
    return sum;
}

int n;
int m[N][N];

set<int> s;
map<int, int> f;
int cnt;

vector<pii> pos[N*N];

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sd(m[i][j]);
			s.insert(m[i][j]);
		}
	}
	
	foreach(it, s){
		f[*it] = cnt++;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			m[i][j] = f[m[i][j]];
			pos[m[i][j]].pb(mp(i,j));
		}
	}
	
	ll ans = 0;

	for(int x = cnt-1; x >= 0; x--){	
		for(int i = 0; i < pos[x].size(); i++){
			int a = pos[x][i].fi, b = pos[x][i].se;
			ans += query(a, b);
		}
		for(int i = 0; i < pos[x].size(); i++){
			int a = pos[x][i].fi, b = pos[x][i].se;
			update(a, b, 1);
		}
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}

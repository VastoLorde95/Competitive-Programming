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
const int INF = 1e9;

int g[N][N];
int h[N];

int ans = INF;

int cnt[N];

int w, p, b;

void solve(int m){
	fill(cnt, cnt+N, 0);
	
	int ret = 0;
	for(int i = 0; i < w; i++){
		if((m&(1<<i))){
			ret++;
			for(int j = 0; j < p; j++){
				cnt[j] += g[i][j];
			}
		}
	}
	
	for(int j = 0; j < p; j++){
		cnt[j] -= h[j];
	}
	
	for(int i = 0; i < p; i++){
		if(cnt[i] < 0) return;
	}
	
	ans = min(ans, ret);
}

int main(){
	sd3(w,b,p);
	
	for(int i = 0; i < w; i++){
		for(int j = 0; j < p; j++){
			sd(g[i][j]);
		}
	}
	
	for(int i = 0; i < b; i++){
		for(int j = 0; j < p; j++){
			sd(h[j]);
		}
		ans = INF;
		for(int m = 0; m < (1<<w); m++){
			solve(m);
		}
		if(ans == INF) cout << -1 << endl; else cout << ans << endl;
	}
	
	
	return 0;
}

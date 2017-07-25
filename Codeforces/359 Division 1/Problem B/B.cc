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

const int N = 300100;

int n, q;
vector<int> g[N];
int c[N];
int s[N];
int pr[N];
int mx[N];

void dfs(int cur){
	s[cur] = 1;
	foreach(it, g[cur]){
		dfs(*it);
		s[cur] += s[*it];
		
		mx[cur] = max(mx[cur], s[*it]);
	}
	
	if(s[cur] == 1){
		c[cur] = cur;
		return;
	}
	
	foreach(it, g[cur]){
		int x = c[*it];
		
		bool ok = false;
		while(true){
			if(mx[x] <= s[cur]/2 and s[cur] - s[x] <= s[cur]/2){
				c[cur] = x;
				ok = true;
				break;
			}
			if(x == cur) break;
			x = pr[x];
		}
		
		if(ok) break;
	}
}

int main(){
	sd2(n,q);
	for(int i = 2; i <= n; i++){
		int p; sd(p);
		g[p].pb(i);
		pr[i] = p;
	}
	
	dfs(1);
	
	for(int i = 1; i <= q; i++){
		int v; sd(v);
		printf("%d\n", c[v]);
	}
	
	return 0;
}

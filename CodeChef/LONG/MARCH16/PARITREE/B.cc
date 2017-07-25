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

const int N = 100100;
const int MOD = 1e9 + 7;

int p[N], rnk[N], size[N], enemy[N];
int po[N];

void create(int x){
	p[x] = x;
	rnk[x] = 0;
	enemy[x] = -x;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	
	if(rnk[px] > rnk[py]) p[py] = px;
	else p[px] = py;
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}

int n, q;

void init(){
	sd2(n,q);
	for(int i = 1; i <= n; i++) create(i);
}

int solve(){
	init();
	
	int u, v, x;
	for(int i = 1; i < n; i++) sd2(u,v);
	
	int flag = 0, cnt = n-1;
	for(int i = 0; i < q; i++){
		sd3(u,v,x);
		u = find(u), v = find(v);
		if(!x){
			if(u == v) continue;
			if(enemy[u] == v){
				flag = 1; continue;
			}
			int a = enemy[u], b = enemy[v];
			merge(u,v);
			
			u = find(u);
			if(a < 0 and b < 0) enemy[u] = -u;
			else if(a < 0) enemy[u] = b, enemy[b] = u;	
			else if(b < 0) enemy[u] = a, enemy[a] = u;
			else{
				merge(a,b);
				a = find(a);
				enemy[u] = a, enemy[a] = u;
			}
			
			cnt--;
		}
		else{
			if(u == v){
				flag = 1; continue;
			}
			if(enemy[u] == v) continue;
			int a = enemy[u], b = enemy[v];
			
			if(a > 0) merge(a, v);
			if(b > 0) merge(b, u);
			u = find(u), v = find(v);
			enemy[u] = v, enemy[v] = u;
			
			cnt--;
		}
	}
	
	return (flag == 1)? 0 : po[cnt];
}

int main(){
	po[0] = 1;
	for(int i = 1; i < N; i++){
		po[i] = po[i-1] << 1;
		if(po[i] >= MOD) po[i] -= MOD;
	}

	int t; sd(t);
	while(t--) printf("%d\n", solve());
	return 0;
}

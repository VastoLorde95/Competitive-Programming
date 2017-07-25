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
#define __ freopen("out.in","r",stdin);freopen("out.out","w",stdout);

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

const int N = 310;
const double eps = 1e-6;

int p[N], rnk[N], size[N];

void create(int x){
	p[x] = x, rnk[x] = 0;
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

int n;
double x[N], y[N], r[N];

double dist(double x1, double y1, double x2, double y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

double dot(double x1, double y1, double x2, double y2){
	return x1*x2 + y1*y2;
}

double cross(double x1, double y1, double x2, double y2){
	return x1*y2 - y1*x2;
}

vector<int> g[N];
int vis[N];

bool dfs(int x, int y, vector<int> &v){
	if(x == y){
		vis[y] = 1;
		v.pb(y);
		return true;		
	}
	vis[x] = 1;
	
	for(int &z : g[x]){
		if(vis[z]) continue;
		
		if(dfs(z, y, v)){
			v.pb(x);
			return true;
		}
	}
	
	return false;
}

double getAngle(double x1, double y1, double x2, double y2){
	return atan2(cross(x1,y1,x2,y2), dot(x1,y1,x2,y2));
}

int main(){ 
#ifdef ONLINE_JUDGE	
	__
#endif
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%lf%lf%lf", x+i, y+i, r+i);
		create(i);
	}
	
	double x1, y1, r1;
	scanf("%lf%lf%lf", &x1, &y1, &r1);
	
	for(int i = 0; i < n; i++){
		x[i] -= x1, y[i] -= y1, r[i] += r1;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			double d = dist(x[i], y[i], x[j], y[j]);
			
			if(d >= (r[i]+r[j]) * (r[i]+r[j])) continue;

			int pi = find(i), pj = find(j);			
			
			if(pi != pj){
				merge(pi, pj);
				g[i].pb(j);
				g[j].pb(i);
				continue;
			}
			
			vector<int> path;
			fill(vis, vis+n, 0);
			
			dfs(i, j, path);
			reverse(path.begin(), path.end());
			path.pb(path[0]);
			
			double ang = 0;
			for(int i = 0; i+1 < path.size(); i++){
				ang += getAngle(x[path[i]], y[path[i]], x[path[i+1]], y[path[i+1]]);
			}
			
			if(fabs(fabs(ang) - PI*2) < eps){
				puts("NO");
				return 0;
			}
		}
	}

	puts("YES");
	
	return 0;
}

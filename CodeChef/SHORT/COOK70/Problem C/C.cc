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

const int N = 400100;
int p[N], rnk[N];

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

int r, c, w;

set<pair<pii, pii> > edges;
map<pii, int> indx;

vector<pii> points;

int getindx(pii p1, bool flag = true){
	if(p1.fi == 0 or p1.fi == r or p1.se == 0 or p1.se == c) p1 = mp(0,0);
	if(indx.count(p1)) return indx[p1];
	
	if(flag){
		if(p1 != mp(0,0)) points.pb(p1);
		return indx[p1] = points.size();
	}
	else return -1;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
	edges.clear();
	indx.clear();
	points.clear();
	
	sd3(r,c,w);
	
	indx[mp(0,0)] = 0;
	
	for(int i = 0; i <= 2*w; i++){
		create(i);
	}
	
	int ans = 2;
	
	for(int i = 1; i <= w; i++){
		int x1, y1, x2, y2;
		sd2(x1,y1); sd2(x2,y2);
		pii p1, p2;
		if(x1 == x2){
			p1 = mp(x1-1, y1);
			p2 = mp(x1, y1);			
		}
		else{
			p1 = mp(x1, y1-1);
			p2 = mp(x1, y1);
		}
		
		edges.insert(mp(p1, p2));
		edges.insert(mp(p2, p1));
		
		int x = getindx(p1);
		int y = getindx(p2);
		
		x = find(x), y = find(y);
		
		if(x == y){
			ans = 0;
		}
		else merge(x, y);
	}
	
	if(ans == 0){
		printf("0\n"); return;
	}
	
	if(r == 1 or c == 1){
		if(r*c == 1){
			printf("Chefland is doomed\n");
		}
		else{
			printf("1\n");
		}
		return;
	}
	
	foreach(it, points){
		int x = it->fi, y = it->se;
		int xid = find(getindx(*it, false));
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			int yid = getindx(mp(nx, ny), false);
			
			if(yid == -1) continue;
			
			yid = find(yid);
			if(!edges.count(mp(*it, mp(nx,ny))) and xid == yid) ans = 1;
		}
	}
	
	printf("%d\n", ans);
}

int main(){
	int t; sd(t);
	while(t--) solve();
}

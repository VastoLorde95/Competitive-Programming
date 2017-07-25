#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const int N = 100100;

int n, m, k;
set<pair<pii, int> > d1[2*N], d2[2*N];
ll ans[N];

set<pair<pii, int> > vis;

void update(int &x, int &y, int &d, int &nx, int &ny, int &nd, ll &t){
	if(d == 1){
		int dx = n-x;
		int dy = m-y;	
		if(dx < dy){
			nx = n, ny = y + dx, nd = 4;
		}
		else if(dx > dy){
			nx = x + dy, ny = m, nd = 2;
		}
		else{
			nx = n, ny = m, dy = 0;
		}
		t += min(dx, dy);
	}
	else if(d == 2){
		int dx = n-x;
		int dy = y;	
		if(dx < dy){
			nx = n, ny = y - dx, nd = 3;
		}
		else if(dx > dy){
			nx = x + dy, ny = 0, nd = 1;
		}
		else{
			nx = n, ny = 0, dy = 0;
		}
		t += min(dx, dy);
	}
	else if(d == 3){
		int dx = x;
		int dy = y;	
		if(dx < dy){
			nx = 0, ny = y - dx, nd = 2;
		}
		else if(dx > dy){
			nx = x - dy, ny = 0, nd = 4;
		}
		else{
			nx = 0, ny = 0, dy = 0;
		}
		t += min(dx, dy);
	}
	else if(d == 4){
		int dx = 0;
		int dy = m-y;	
		if(dx < dy){
			nx = 0, ny = y - dx, nd = 1;
		}
		else if(dx > dy){
			nx = x + dy, ny = m, nd = 3;
		}
		else{
			nx = 0, ny = m, dy = 0;
		}
		t += min(dx, dy);
	}
}

int main(){ _
	cin >> n >> m >> k;
	
	for(int i = 0; i < k; i++){
		int x, y; cin >> x >> y;
		d1[y+x].insert(mp(mp(x,y),i));
		d2[y-x].insert(mp(mp(x,y),i));
		ans[i] = -1;
	}
	
	bool start = true;
	int x = 0, y = 0, d = 1;
	ll t = 0;
	while(!vis.count(mp(mp(x,y),d))){
		if((x == 0 or x == n) and (y == 0 or y == m) and !start) break;
		start = false;
		vis.insert(mp(mp(x,y),d));
		
		int nx, ny, nd;
		
		if(d == 1 or d == 3){
			int val = y-x;
			while(!d2[val].empty()){
				auto p = *d2[val].begin();
				int xx = p.fi.fi, yy = p.fi.se, id = p.se;
				
				tr(p);
				
				d2[val].erase(p);
				d1[yy+xx].erase(p);
				
				int del = min(abs(xx-x), abs(yy-y));
				
				ans[id] = t + del;
			}
		}
		else{
			int val = y+x;
			while(!d1[val].empty()){
				auto p = *d1[val].begin();
				int xx = p.fi.fi, yy = p.fi.se, id = p.se;
				
				tr(p);
				
				d1[val].erase(p);
				d2[yy-xx].erase(p);
				
				int del = min(abs(xx-x), abs(yy-y));
				
				ans[id] = t + del;
			}
		}
		
		update(x, y, d, nx, ny, nd, t);
		
		x = nx, y = ny, d = nd;		
		tr(x, y, d);
	}
	
	for(int i = 0; i < k; i++){
		cout << ans[i] << '\n';
	}
		
	return 0;
}

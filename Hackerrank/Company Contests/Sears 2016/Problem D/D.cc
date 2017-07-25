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
int root;

int a[N];
int active[N];
int ans[N];

vector<pair<pii, int> > q;

bool cmp(const pair<pii, int> &p1, const pair<pii, int> &p2){
	int x = p1.fi.fi / root;
	int y = p2.fi.fi / root;
	if(x == y) return p1.fi.se < p2.fi.se;
	return x < y;
}

int cnt;
int n, m;

void add(int x){
	if(n == 1){
		active[x] = 1, cnt++;
	}
	else if(x == 1){
		active[x] = 1;
		if(x+1 <= n and active[x+1] == 0) cnt++;
	}
	else if(x == n){
		active[x] = 1;
		if(x-1 > 0 and !active[x-1]) cnt++;
	}
	else{
		active[x] = 1;
		if(active[x-1] and active[x+1]) cnt--;
		else if(!active[x-1] and !active[x+1]) cnt++;
	}
}

void rmv(int x){
	if(n == 1){
		active[x] = 0, cnt--;
	}
	else if(x == 1){
		active[x] = 0;
		if(x+1 <= n and !active[x+1]) cnt--;
	}
	else if(x == n){
		active[x] = 0;
		if(x-1 > 0 and !active[x-1]) cnt--;
	}
	else{
		active[x] = 0;
		if(active[x-1] and active[x+1]) cnt++;
		else if(!active[x-1] and !active[x+1]) cnt--;
	}
}

int main(){
	sd2(n, m);
	root = sqrt(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		sd2(u,v);
		u--, v--;
		q.pb(mp(mp(u,v),i));
	}
	
	sort(q.begin(), q.end(), cmp);
	
	for(int i = q[0].fi.fi; i <= q[0].fi.se; i++){
		add(a[i]);
	}
	
	int l = q[0].fi.fi, r = q[0].fi.se;
	
//	tr(q);
	
	for(int i = 0; i < m; i++){
		int xx = q[i].fi.fi, yy = q[i].fi.se;
		while(l > xx) add(a[--l]);
		while(r < yy) add(a[++r]);
		while(l < xx) rmv(a[l++]);
		while(r > yy) rmv(a[r--]);
		
//		tr(i, l, r, cnt);
//		for(int i = 1; i <= n; i++){
//			tr(i, active[i]);
//		}
		
		ans[q[i].se] = cnt;
	}
	
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
		
	return 0;
}

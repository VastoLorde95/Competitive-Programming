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

const int N = 200200;

const int MAXN = N;
int tree[MAXN];

int query(int idx, int sum = 0){
    for(; idx; idx -= (idx & -idx)) sum += tree[idx];
    return sum;
}

void update(int idx, int val){
    for(; idx < MAXN; idx += (idx & -idx)) tree[idx] += val;
}

int n, m;
int p[N];
int pos[N];
vector<int> segments[N];

int ans[N];

vector<pii> q[N];

int main(){ _
	cin	>> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		pos[p[i]] = i;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			int x = min(pos[i], pos[j]);
			int y = max(pos[i], pos[j]);
			
			segments[y].pb(x);			
		}
	}
	
	for(int i = 1; i <= m; i++){
		int l, r;
		cin >> l >> r;
		q[r].pb(mp(l,i));
	}
	
	for(int i = 1; i <= n; i++){
		for(int x :  segments[i]){
			update(x, 1);
		}
		
		for(pii p : q[i]){
			ans[p.se] = query(i) - query(p.fi-1);
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}

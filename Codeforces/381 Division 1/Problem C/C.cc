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

const int N = 300100;
const ll INF = 1ll << 60;

const int MAXN = N;

ll tree[MAXN]; // Careful, indexing begins from 1.

ll get(int idx, ll sum = 0){
	idx++;
    for(; idx; idx -= (idx & -idx)) sum += tree[idx];
    return sum;
}

void update(int idx, ll val){
	idx++;
    for(; idx < MAXN; idx += (idx & -idx)) tree[idx] += val;
}

int n, m;
ll a[N];

int main(){ _
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[0] = INF;
	a[n+1] = INF;
	
	set<int> f;
	set<int> b;
	
	for(int i = 1; i <= n; i++){
		if(a[i] <= a[i-1]) f.insert(i-1);
	}
	
	for(int i = n; i >= 1; i--){
		if(a[i] <= a[i+1]) b.insert(i+1);
	}
	
	for(int i = 0; i <= n+1; i++){
		update(i, a[i]);
		update(i+1, -a[i]);
	}
	
	int mx = 1;
	
	foreach(it, f){
		auto jt = b.upper_bound(*it+1);
		if(jt != b.end()){
			mx = max(mx, *jt - *it - 1);
		}
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		int l, r, d;
		cin >> l >> r >> d;
		
		update(l, d);
		update(r+1, -d);
		
		auto it = f.lower_bound(l);
		if(it != f.begin()){
			it--;
			if(*it == l-1 and get(*it) < get(l)){
				f.erase(it);
			}
		}
		
		if(get(r) >= get(r+1)){
			f.insert(r);
		}
		
		auto jt = b.upper_bound(r);
		if(jt != b.end()){
			if(*jt == r+1 and get(r) > get(*jt)){
				b.erase(jt);
			}
		}
		
		if(get(l) >= get(l-1)){
			b.insert(l);
		}
		
		
		foreach(it, f){
			tr(*it);
		}
		foreach(it, b){
			tr(*it);
		}
		
		{
			auto x = f.lower_bound(l);
			int ii;
			if(x == f.begin()){
				ii = l-1;
			}
			else{
				x--;
				ii = *x;
			}

			auto y = b.upper_bound(l);
			
			int jj = (y == b.end())? l+1 : *y;
			
			tr(l, r, ii, jj);
			
			mx = max(mx, jj-ii-1);
		}
		
		{
		
			auto y = b.upper_bound(r);
			int jj = (y == b.end())? r+1 : *y;


			auto x = f.lower_bound(r);
			int ii;
			if(x == f.begin()){
				ii = r	 -1;
			}
			else{
				x--;
				ii = *x;
			}
//			int ii = (x == f.begin())? jj-1 : *x;
			
			tr(l, r, ii, jj);
						
			mx = max(mx, jj-ii-1);
		}
		
		cout << mx << '\n';
	}
	
	return 0;
}

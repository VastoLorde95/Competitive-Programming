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

const int N = 1010;

bitset<N> rows[N];
int a[N][N];
int n, m;

bool f(int x){
	for(int i = 1; i <= n; i++){
		rows[i].reset();
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] >= x) rows[i].set(j);
		}
	}
	
	bitset<N> tmp;
	for(int i = 1; i <= n; i++){
		if(rows[i].count() <= 1) continue;
		for(int j = i+1; j <= n; j++){
			tmp = rows[i] & rows[j];
			if(tmp.count() > 1) return true;
		}
	}
	
	return false;
}

int main(){ _
	cin >> n >> m;
	
	set<int> d;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			d.insert(a[i][j]);
		}
	}
	
	vector<int> vals;
	foreach(it, d) vals.pb(*it);

	int lo = 0, hi = vals.size(), mid;
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		if(f(vals[mid])) lo = mid;
		else hi = mid;
	}
	
	cout << vals[lo] << endl;
	
	return 0;
}

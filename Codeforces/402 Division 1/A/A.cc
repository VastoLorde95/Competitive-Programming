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

const int N = 200100;

int a[N];
int bad[N];

int n, m;
string p, t;


bool f(int x){
	for(int i = 0; i < m; i++){
		bad[i] = 0;
	}
	
	for(int i = 1; i <= x; i++){
		bad[a[i]] = 1;
	}
	
	int j = 0;
	for(int i = 0; i < m and j < n; i++){
		if(bad[i]) continue;
		if(t[i] == p[j]){
			j++;
		}
	}	
	
	return j == n;
	
}

int main(){ _
	cin >> t >> p;
	
	n = p.length();
	m = t.length();
	
	for(int i = 1; i <= m; i++){
		cin >> a[i];
		a[i]--;
	}
	
	int lo = 0;
	int hi = m;
	int mid;
	
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(f(mid)) lo = mid;
		else hi = mid;
	}
	
	cout << lo << endl;
	
	return 0;
}

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
const int INF = 2000000000;

int n;
int a[N];
int d[N];

void solve(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	if(n <= 3){
		int mn = 1e9;
		for(int i = 0; i < n; i++) mn = min(mn, a[i]);
		printf("%d\n", mn);
		return;
	}
	
	map<int, int> f;
	
	for(int i = 1; i < n; i++){
		d[i] = a[i] - a[i-1];
		f[d[i]]++;
	}

	int val = INF;
	
	int del = a[1] - a[0];
	if(--f[del] == 0) f.erase(del);
	if(f.size() == 1) val = a[0];
	f[del]++;
	
	del = a[n-1] - a[n-2];
	if(--f[del] == 0) f.erase(del);
	if(f.size() == 1) val = min(val, a[n-1]);
	f[del]++;
	
	for(int i = 1; i < n-1; i++){
		del = a[i] - a[i-1];
		if(--f[del] == 0) f.erase(del);
		
		del = a[i+1] - a[i];
		if(--f[del] == 0) f.erase(del);
		
		f[a[i+1] - a[i-1]]++;
		
		if(f.size() == 1) val = min(val, a[i]);
		
		del = a[i] - a[i-1];
		f[del]++;
		del = a[i+1] - a[i];
		f[del]++;
		if(--f[a[i+1] - a[i-1]] == 0) f.erase(a[i+1] - a[i-1]);
	}
	
	if(val == INF) val = -1;
	
	printf("%d\n", val);
}

int main(){
	int t; sd(t);
	while(t--) solve();
	return 0;
}

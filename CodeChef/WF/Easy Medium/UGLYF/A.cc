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

const int M = 26;

vector<int> v[M];

void solve(){
	string a, b;
	cin >> a >> b;
	
	int n = a.length();
	int m = b.length();
	
	for(int i = 0; i < M; i++){
		v[i].clear();
	}
	
	for(int i = 0; i < m; i++){
		v[b[i]-'A'].pb(i);
	}
	
	int mn = 1e9;

	for(int x = 0; x < n; x++){
		int c = a[x] - 'A';
		if(v[c].empty()) continue;
		
		set<int> dis;
		dis.insert(x);
		dis.insert(n-x-1);
		dis.insert(x+m-n);
		dis.insert(m-x-1);
		
		vector<int> p;
		foreach(it, dis) p.pb(*it);

		dis.clear();

		dis.insert(v[c][0]);
		dis.insert(v[c].back());
	
		for(int i = 0; i < p.size(); i++){
			auto it = lower_bound(v[c].begin(), v[c].end(), p[i]);
			
			if(it != v[c].end()) dis.insert(*it);
			if(it != v[c].begin()){
				it--;
				dis.insert(*it);
			}	
		}
		
		foreach(it, dis){
			int y = *it;
			int val = abs(x-y) + abs(x+y-n+1) + abs(x+m-n-y) + abs(x-m+y+1);
			if(val < mn) mn = val;
		}
	}
	
	cout << mn << endl;
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

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

// biconnected => cycles exist
// if cycle contains a chord then the chord is an irrelevant edge
// => graph cannot contain chords
// additional vertices can be added by connecting them to the original cycle with two non-adjacent nodes
// every additional vertex added is always a part of at least two cycles. => Adding a third edge to this node will create a chord
// thus we cannot have more than 2 * n - 4 edges

void solve(){
	int n, m;
	cin >> n >> m;
	if(n == m){
		for(int i = 1; i < n; i++){
			cout<< i << ' ' << i+1 << endl;
		}
		cout << n << ' ' << 1 << endl;
		return;
	}
	if(m < n or m > 2 * n - 4){
		cout << -1 << ' ' << -1 << endl;
		return;
	}
	
	int sz = -1;
	for(int i = 4; i <= n; i++){
		if((n - i) * 2 == m - i){
			sz = i;
		}
	}
	
	if(sz == -1){	
		cout << -1 <<  ' ' << -1 << endl;
		return;
	}
	
	for(int i = 1; i < sz; i++){
		cout << i << ' ' << i+1 << endl;
	}
	cout << sz << ' ' << 1 << endl;
	
	for(int i = sz+1; i <= n; i++){
		cout << i << ' ' << 1 << endl;
		cout << i << ' ' << 3 << endl;	
	}
	
	return;
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

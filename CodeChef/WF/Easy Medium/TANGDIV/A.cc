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

void solve(){
	int n, k, p;
	sd3(n,k,p);
	
	vector<pii> a, b;

	for(int i = 0; i < k; i++){
		int l, r;
		sd2(l,r);
		a.pb(mp(l,r));
	}
	
	for(int i = 0; i < p; i++){
		int l, r;
		sd2(l,r);
		b.pb(mp(l,r));
	}
	
	if(p > k){
		printf("No\n");
		return;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());	

	set<pii> div;
	for(int i = 1; i < k; i++){
		div.insert(mp(a[i-1].se, a[i].fi));
	}	
	div.insert(mp(a[k-1].se, a[0].fi));
	
	bool flag = true;
	
	for(int i = 1; i < p; i++){
		if(!div.count(mp(b[i-1].se, b[i].fi))) flag = false;
	}
	
	if(!div.count(mp(b[p-1].se, b[0].fi))) flag = false;
	
	printf("%s\n", (flag)? "Yes" : "No");
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}

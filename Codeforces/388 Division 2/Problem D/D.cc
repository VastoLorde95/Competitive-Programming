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

vector<int> b[N];
set<pii> mx;

int main(){ _
	int n;
	cin >> n; 

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		b[x].pb(y);
	}
	
	for(int i = 1; i <= n; i++){
		if(!b[i].empty()){
			mx.insert(mp(b[i].back(), i));
		}
	}

	int q;
	cin >> q;
	
	while(q--){
		int k;
		cin >> k;
		
		vector<int> v;
		for(int i = 0; i < k; i++){
			int l; cin >> l;
			
			if(!b[l].empty()){
				v.pb(l);
				mx.erase(mp(b[l].back(), l));
			}
		}
		
		if(mx.empty()){
			cout << "0 0" << endl;
		}
		else if(mx.size() == 1){
			int it = mx.begin()->se;
			cout << it << ' ' << b[it][0]  << endl;
		}
		else{
			auto it = mx.rbegin();
			auto jt = it;
			jt++;
			
			auto kt = upper_bound(b[it->se].begin(), b[it->se].end(), jt->fi);
			
			cout << it->se << ' ' << *kt << endl;
		}
		
		for(auto &i : v){
			mx.insert(mp(b[i].back(), i));
		}
		
	}
	
	return 0;
}

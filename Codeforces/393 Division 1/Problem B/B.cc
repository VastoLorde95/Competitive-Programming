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

ll t[N];
ll p[N];
multiset<pair<ll, ll> > s;
map<ll, ll> cur;
int n;

int main(){ _
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> t[i];
		
		while(!s.empty() and s.begin()->fi <= t[i]){
			if(--cur[s.begin()->se] == 0) cur.erase(s.begin()->se);
			s.erase(s.begin());
		}
		
		ll prev = (i == 0)? 0 : p[i-1];
		
		s.insert(mp(t[i]+1, prev+20));
		s.insert(mp(t[i]+90, prev+50));
		s.insert(mp(t[i]+1440, prev+120));
		
		cur[prev+20]++;
		cur[prev+50]++;
		cur[prev+120]++;
	
		p[i] = cur.begin()->fi;
		
		if(i == 0) cout << p[i] << endl;
		else cout << p[i] - p[i-1] << endl;
	}
	
	return 0;
}

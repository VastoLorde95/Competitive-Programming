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

int n, m;
string s;
set<int> val;
vector<pair<char, pii> > v;

bool cmp(const pair<char, pii> &p1, const pair<char, pii> &p2){
	if(p1.fi != p2.fi) return p1.fi < p2.fi;
	return (p1.se.se-p1.se.fi) < (p2.se.se - p2.se.fi);
}

int main(){ _
	cin >> m >> s;
	n = s.length();

	for(int i = 0; i < n; i++){
		int mx = min(n-m+1, i);
		int mn = max(0, i-m+1);
		
		v.pb(mp(s[i], mp(mn, mx)));
	}
	
	for(int i = 0; i+m-1 < n; i++){
		val.insert(i);
	}
	
	sort(v.begin(), v.end(), cmp);

	queue<char> q;
	
	string res;
	
	int k = 0;
	while(!val.empty()){
		char c = v[k].fi;
		int mn = v[k].se.fi, mx = v[k].se.se;
		k++;		
				
		auto it = val.lower_bound(mn);
		if(it == val.end()){
			q.push(c);
			continue;
		}
		if(*it > mx){
			q.push(c);
			continue;
		}
		
		while(!q.empty() and q.front() < c){
			res += q.front();
			q.pop();
		}
		
		while(it != val.end() and *it <= mx){
			val.erase(it);
			it = val.lower_bound(mn);
		}
		
		res += c;
	}
	
	cout << res << endl;

	return 0;
}

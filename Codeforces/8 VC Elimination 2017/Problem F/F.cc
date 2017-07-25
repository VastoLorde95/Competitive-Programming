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

const int N = 1001000;

int n, k;
int p[N];
int v[N];

vector<vector<int> > c;

int main(){ _
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			int x = i;
			
			vector<int> cc;
			while(!v[x]){
				cc.pb(x);
				v[x] = 1;
				x = p[x];
			}
			
			c.pb(cc);
		}
	}
	
	
//	int mn = 0;
//	int tot = k;
//	int id = 0;
//	while(tot > 0 and id < c.size()){
//		if(tot >= c[id].size()){
//			mn += c[id].size();
//			tot -= c[id].size();
//		}
//		else{
//			mn += tot + 1;
//			tot = 0;
//		}
//		id++;
//	}
	
	int sz = 0;
	foreach(it, c) sz = max(sz, (int) (*it).size());
	
	int mn = k + 1;
	
	const long unsigned int szz = sz;
	
	bitset<100> b;
	
////////////////////////////////	
	int mx = 0;
	int tot = k;
	for(int i = 0; i < c.size() and tot > 0; i++){
		if(c[i].size() % 2 == 0){
			if(c[i].size() / 2 <= tot){
				tot -= c[i].size() / 2;
				mx += c[i].size();
			}
			else{
				mx += tot * 2;
				tot = 0;
				break;
			}
		}
	}
	
	for(int i = 0; i < c.size() and tot > 0; i++){
		if(c[i].size() % 2 == 1){
			if((c[i].size() / 2) + 1 <= tot){
				tot -= c[i].size() / 2;
				tot--;
				mx += c[i].size();
			}
			else{
				mx += tot * 2;
				tot = 0;
				break;
			}
		}
	}
	
	cout << mn << ' ' << mx << endl;
	
	return 0;
}

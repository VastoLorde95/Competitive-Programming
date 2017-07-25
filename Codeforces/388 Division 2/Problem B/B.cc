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

int main(){
	int x[3];
	int y[3];

	for(int i = 0; i < 3; i++){
		cin >>  x[i] >> y[i];
	}

	set<pii> res;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
		
			int vx = x[i] - x[j];
			int vy = y[i] - y[j];
		
			for(int k = 0; k < 3; k++){
				if(k == i or k == j) continue;
			
				int nx = x[k] + vx;
				int ny = y[k] + vy;
			
				// now the opposite sides are (x[i], y[i], x[j], y[j]) and (x[k], y[k], nx, ny)
				// the other set of opposite sides are (x[i], y[i], nx, ny) and (x[j], y[j], x[k], y[k])
			
				// now use any test to check for parallelogram
				if(x[i] - nx == x[j] - x[k] and y[i] - ny == y[j] - y[k]){
					// this is ok
					res.insert(mp(nx,ny));
				}
				else if(x[i] - x[k] == x[j] - nx and y[i] - y[k] == y[j] - ny){
					// this is ok
					res.insert(mp(nx,ny));
				}				
			}
		}
	}
	
	cout << res.size() << endl;
	foreach(it, res){
		cout << it->fi << ' ' << it->se << endl;
	}
	
	return 0;
}

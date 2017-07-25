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

const int N = 30;

int t[N];
int n;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

map<int, map<int, int> > m;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	
	int x = 0, y = 0, id = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < t[i]; j++){
			x += dx[id];
			y += dy[id];
		}
		id = (id + 1) % 8;
	}
	
	for(int i = n-1; i >= 0; i--){
		id = (id + 7) % 8;
		for(int j = 0; j < t[i]; j++){
			m[x][y] = 1;
			x -= dx[id];
			y -= dy[id];	
		}
		
		if(i > 0){
			if((i-1)%2 == 0){
				// flip 180
				if(id == 7 or id == 3){
					// flip about x
					map<int, map<int, int> > mm;
					for(auto &it : m){
						for(auto &jt : it.se){
							mm[it.fi][y - (jt.fi - y)] = 1;
						}
					}
					
					for(auto &it : mm){
						for(auto &jt : it.se){
							m[it.fi][jt.fi] = 1;
						}
					}
				}
				else if(id == 5 or id == 1){
					// flip about y
					map<int, map<int, int> > mm;
					for(auto &it : m){
						for(auto &jt : it.se){
							mm[x  - (it.fi - x)][jt.fi] = 1;
						}
					}
					
					for(auto &it : mm){
						for(auto &jt : it.se){
							m[it.fi][jt.fi] = 1;
						}
					}
				}
			}
			else{
				// flip 90
				map<int, map<int, int> > mm;

				for(auto &it : m){
					for(auto &jt : it.se){
						int dx = it.fi - x;
						int dy = jt.fi - y;
					
						dx *= -1;
						dy *= -1;
					
						mm[x - dy][y + dx] = 1;
					}
				}
				
				for(auto &it : mm){
					for(auto &jt : it.se){
						m[it.fi][jt.fi] = 1;
					}
				}
			}
		}
	}
	
	assert(x == 0 and y == 0);
		
	int tot = 0;

	for(auto it : m){
		tot += it.se.size();
	}
	
	cout << tot << endl;
	
	return 0;
}

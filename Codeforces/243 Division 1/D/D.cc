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
const int M = 330;

unordered_set<int> p[N];
vector<int> pts[N];

int main(){
	for(int i = 0; i < N; i++){
		p[i].reserve(1024);
		p[i].max_load_factor(0.25);
	}
	
	int n;
	sd(n);
	
	for(int i = 0; i < n; i++){
		int x, y;
		sd2(x,y);
		
		p[x].insert(y);
		pts[x].pb(y);
	}
	
	for(int i = 0; i < N; i++){
		sort(pts[i].begin(), pts[i].end());
	}
	
	vector<int> heavy;
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(pts[i].size() <= M){
			for(int x = 0; x < pts[i].size(); x++){
				for(int y = x+1; y < pts[i].size(); y++){
					int dis = pts[i][y] - pts[i][x];
					
					if(i-dis >= 0 and pts[i-dis].size() > M and p[i-dis].count(pts[i][x]) and p[i-dis].count(pts[i][x]+dis)) ans++;
					if(i + dis < N and p[i+dis].count(pts[i][x]) and p[i+dis].count(pts[i][y])) ans++;
				}				
			}
		}
		else{
			heavy.pb(i);
		}
	}
	
	for(int i = 0; i < heavy.size(); i++){
		int A = heavy[i];
		for(int j = i+1; j < heavy.size(); j++){
			int B = heavy[j];
			int dis = B - A;
			
			assert(dis >= 0);
			
			for(int x = 0; x < pts[A].size(); x++){
				B = pts[A][x];
				if(B + dis >= N or A + dis >= N) continue;
				if(p[A].count(B+dis) and p[A+dis].count(B) and p[A+dis].count(B+dis)) ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

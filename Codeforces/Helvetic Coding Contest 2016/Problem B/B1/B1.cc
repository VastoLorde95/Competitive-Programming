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

const int N = 60;

int n;
char g[N][N];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		scanf("%s", g[i]);
	}
	
	int minx = n+1, maxx = -1, miny = n+1, maxy = -1;

	int tmp = 0;
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(g[i][j] == '1'){
				minx = min(minx, i);
				maxx = max(maxx, i);
				
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
			tmp |= g[i][j] - '0';
			
			if(g[i][j] != '0') cnt++;
		}
	}	
	
	if(tmp == 4){
		puts("Yes");
	}
	
	if(g[minx][miny] != '1' or g[minx][maxy] != '1' or g[maxx][miny] != '1' or g[maxx][maxy] != '1'){
		puts("No");
		return 0;
	}

	bool ok = true;
	for(int i = minx+1; i < maxx; i++){
		if(g[i][miny] != '2' or g[i][maxy] != '2') ok = false;
	}
	
	for(int j = miny+1; j < maxy; j++){
		if(g[minx][j] != '2' or g[maxx][j] != '2') ok = false;
	}
	
	for(int i = minx+1; i < maxx; i++){
		for(int j = miny+1; j < maxy; j++){
			if(g[i][j] != '4') ok = false;
		}
	}	
	
	int cnt2 = (maxx-minx+1) * (maxy-miny+1);
	if(cnt2 != cnt) ok = false;
	
	if(ok) puts("Yes"); else puts("No");
	
	return 0;
}

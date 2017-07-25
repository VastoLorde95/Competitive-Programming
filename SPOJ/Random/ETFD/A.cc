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

const int N = 1000001;
const int K = 21;

int p[N];
int phi[N];
int dep[N];
int s[K][N];


int main(){
	for(int i = 1; i < N; i++) phi[i] = i;
	
	for(int i = 2; i < N; i++){
		if(p[i]) continue;
		
		for(int j = i; j < N; j += i){
			p[j] = 1;
			phi[j] -= phi[j] / i;
		}
	}
	
	dep[1] = 0;
	for(int i = 2; i < N; i++){
		dep[i] = dep[phi[i]]+1;
	}
	
	for(int i = 1; i < N; i++){
		s[dep[i]][i] = 1;
	}
	
	for(int i = 0; i < K; i++){
		for(int j = 1; j < N; j++){
			s[i][j] += s[i][j-1];
		}
	}
	
	int t;
	sd(t);
	while(t--){
		int m, n, k;
		sd3(m,n,k);
		printf("%d\n", s[k][n] - s[k][m-1]);
	}
	
	return 0;
}

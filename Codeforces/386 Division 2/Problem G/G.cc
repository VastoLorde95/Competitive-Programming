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

int n, t, k;
int p[N];
int a[N];
int out[N];

vector<int> l[N];

int main(){
	sd3(n,t,k);

	p[1] = -1;
	l[0].pb(1);
	
	int cnt = 2;
	for(int i = 1; i <= t; i++){
		sd(a[i]);
		for(int j = 0; j < a[i]; j++){
			l[i].pb(cnt++);
		}
	}
	
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < l[i].size(); j++){
			p[l[i][j]] = l[i-1][0];
			out[l[i-1][0]]++;
		}
	}
	
	int leaves = 0;
	
	for(int i = 1; i <= n; i++){
		if(out[i] == 0) leaves++;
	}
	
	if(leaves < k){
		printf("-1\n");
		return 0;
	}
	
	if(leaves > k){
		for(int i = t; i > 1 and leaves > k; i--){
			int x = 1, y = 1;
			while(x < l[i].size() and y < l[i-1].size() and leaves > k){
				p[l[i][x]] = l[i-1][y];
				x++;
				y++;
				leaves--;
			}
		}
	}
	
	if(leaves != k){
		printf("-1\n");
		return 0;
	}
	
	printf("%d\n", n);
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < l[i].size(); j++){
			printf("%d %d\n", l[i][j], p[l[i][j]]);
		}
	}
	
	return 0;
}

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

const int LOGN = 18;
const int N = 1 << LOGN;

int n;
int p[LOGN][N], l[N];

int LCA(int x, int y){
	if(l[x] < l[y]) swap(x,y);
	
	int tmp = 1;
	while((1<<tmp) <= l[x]) tmp++;
	tmp--;
	
	for(int i = tmp; i >= 0; i--) 
		if(l[x] - (1<<i) >= l[y]) x = p[i][x];
	
	if(x == y) return y;
	
	for(int i = tmp; i >= 0; i--)
		if(p[i][x] > 0 and p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];

	return p[0][x];
}

int main(){	
	sd(n);
	
	int x; sd(x);
	l[x] = 1;
	
	printf("1 ");
	
	int u = 1, v = 2;
	
	int mx = 1;
	
	for(int i = 3; i <= n; i++){
		sd(x);
		l[i] = l[x] + 1;
		p[0][i] = x;
		
		for(int j = 1; j < LOGN; j++){
			p[j][i] = p[j-1][p[j-1][i]];
		}
		
		int l1 = LCA(i, u);
		int len1 = l[i] - l[l1] + l[u] - l[l1];	

		int l2 = LCA(i, v);
		int len2 = l[i] - l[l2] + l[v] - l[l2];
		
		
		if(len1 > len2 and len1 > mx){
			mx = len1;
			v = i;
		}
		else if(len2 >= len1 and len2 > mx){
			mx = len2;
			u = i;
		}	
		
		printf("%d ", mx);
	}
	printf("\n");
			
	return 0;
}	

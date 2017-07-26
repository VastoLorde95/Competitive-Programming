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

const int MAX_POW = 17, N = 1 << MAX_POW;

int n, q, jumpTable[MAX_POW][1<<MAX_POW], depth[1<<MAX_POW];;
vector<int> adjacencyList[N];

int lowestCommonAncestor(int x, int y){
	if(depth[x] < depth[y]) swap(x,y);
	
	int dd = 1;
	while((1 << dd) <= depth[x]) dd++; dd--;
	
	for(int i = dd; i >= 0; i--) if(depth[x] - (1 << i) >= depth[y]) x = jumpTable[i][x];
	
	if(x == y) return y;
	
	for(int i = dd; i >= 0; i--)
		if(jumpTable[i][x] > 0 and jumpTable[i][x] != jumpTable[i][y])
			x = jumpTable[i][x], y = jumpTable[i][y];

	return jumpTable[0][x];
}

void makeJumpTable(){
	for(int K = 1; K < MAX_POW; K++) for(int j = 1; j <= n; j++) jumpTable[K][j] = jumpTable[K-1][jumpTable[K-1][j]];
}

void dfs(int x, int prev){
	jumpTable[0][x] = prev;
	
	for(auto &y : adjacencyList[x]){
		depth[y] = depth[x] + 1;		
		dfs(y, x);
	}
}

int main(){
	sd2(n,q);
	for(int i = 2; i <= n; i++){
		int x;
		sd(x);
		adjacencyList[x].pb(i);
	}
	
	dfs(1, 1);

	makeJumpTable();

	while(q--){
		int k;
		sd(k);
		
		if(k == 1){
			int y; sd(y);
			printf("%d\n", y);
			continue;
		}	
		
		int xx, yy; sd2(xx,yy);
		
		int zz = lowestCommonAncestor(xx, yy);
		for(int i = 2; i < k; i++){
			sd(xx);
			zz = lowestCommonAncestor(xx, zz);
		}
		printf("%d\n", zz);
	}
	
	return 0;
}

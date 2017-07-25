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

const int N = 1 << 18;
const int M = 5;
const int INF = 1e8;

struct node{
	int mcost[M][M];
	
	node(){
		for(int i = 0; i < M; i++){
			mcost[i][i] = 0;
			for(int j = i+1; j < M; j++){
				mcost[i][j] = INF;
			}
		}
	}
	
	void assign(char d){
		if(d == '2'){
			mcost[0][0] = 1;
			mcost[0][1] = 0;
		}
		else if(d == '0'){
			mcost[1][1] = 1;
			mcost[1][2] = 0;
		}
		else if(d == '1'){
			mcost[2][2] = 1;
			mcost[2][3] = 0;
		}
		else if(d == '7'){
			mcost[3][3] = 1;
			mcost[3][4] = 0;
		}
		else if(d == '6'){
			mcost[3][3] = 1;
			mcost[4][4] = 1;
		}
	}

	void combine(node &left, node &right){
		for(int i = 0; i < M; i++){
			for(int j = i; j < M; j++){
				mcost[i][j] = min(left.mcost[i][i] + right.mcost[i][j], left.mcost[i][j] + right.mcost[j][j]);
				for(int k = i+1; k < j; k++){
					mcost[i][j] = min(mcost[i][j], left.mcost[i][k] + right.mcost[k][j]);
				}
			}
		}
	}
};

int n, q;
string s;
node tree[2*N];

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(s[l]);
		return;
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	 
	tree[id].combine(tree[left], tree[right]);
	
	return;
}

node query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return node();
	if(x <= l && r <= y) return tree[id];
	
	int left = id<<1, right = left+1, mid = (l+r) >> 1;

	node lft = query(x, y, left, l, mid), rgt = query(x, y, right, mid, r);
	node ret = node();
	ret.combine(lft, rgt);

	return ret;
}

int main(){ _
	cin >> n >> q;
	cin >> s;
	
	build();

	int a, b;	
	while(q--){
		cin >> a >> b;
		a--, b--;
		
		node ans = query(a, b+1);
		if(ans.mcost[0][M-1] >= INF) cout << -1 << '\n';
		else cout << ans.mcost[0][M-1] << '\n';
	}
	
	return 0;
}

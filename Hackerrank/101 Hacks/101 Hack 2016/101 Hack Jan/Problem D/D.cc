#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 500100, LOGN = 20;

int n, q;
int a[N], up[N], down[N];
int jump[N][LOGN];

int tree[N], tree2[N];

int dfs(int cur, int step){
	if(step == 0){
		if(tree[cur] > 0) return tree[cur];
		if(up[cur] == n+1){
			return tree[cur] = cur;
		}
		return tree[cur] = dfs(up[cur], 1);
	}
	else{
		if(tree2[cur] > 0) return tree2[cur];
		if(down[cur] == n+1){
			return tree2[cur] = cur;
		}
		return tree2[cur] = dfs(down[cur], 0);
	}
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	up[n+1] = down[n+1] = n+1;
	
	stack<int> s;
	up[n] = n+1;
	s.push(n);
	for(int i = n-1; i > 0; i--){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		if(s.empty()){
			up[i] = n+1;
		}
		else{
			up[i] = s.top();
		}
		s.push(i);
	}

	while(!s.empty()) s.pop();
	
	down[n] = n+1;
	s.push(n);
	for(int i = n-1; i > 0; i--){
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(s.empty()){
			down[i] = n+1;
		}
		else{
			down[i] = s.top();
		}
		s.push(i);
	}
	
	for(int i = 1; i <= n; i++){
		if(tree2[i] == 0){
			dfs(i, 1);
		}
	}
	
	for(int i = 1; i <= n; i++) jump[i][0] = up[down[i]];
	for(int i = 0; i < LOGN; i++) jump[n+1][i] = n+1;
	
	for(int i = 1; i < LOGN; i++){
		for(int j = 1; j <= n; j++){
			jump[j][i] = jump[jump[j][i-1]][i-1];
//			tr(i,j,jump[i][j]);
		}
	}
	
	sd(q);
	int x, y;
	while(q--){
		sd2(x,y);
		if(tree2[x] == tree2[y]){
			printf("1\n");
		}
		else{
//			tr(x,y);
			for(int i = LOGN-1; i >= 0; i--){
				if(jump[x][i] < y){
					x = jump[x][i];
				}
			}
//			tr(x,y);
			if(down[x] == y) printf("1\n");
			else printf("0\n");
		}
	}
	
	
	return 0;
}

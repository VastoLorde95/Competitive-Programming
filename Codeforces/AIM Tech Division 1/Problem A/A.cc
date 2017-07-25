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

const int N = 501;

int n, m;

int e[N][N];
int f[N][N];

char s[N];
int used[N];

bool ok(char x, char y){
	if(x == 'b' or y == 'b') return true;
	if(x == 'a' and y == 'c') return false;
	if(x == 'c' and y == 'a') return false;
	return true;
}

int main(){
	sd2(n,m);

	int u, v;
	for(int i = 0; i < m; i++){
		sd2(u,v);
		e[u][v] = e[v][u] = 1;
	}	
	
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++) cnt += e[i][j];
		
		if(cnt == n-1){
			used[i] = 1;
			s[i] = 'b';
		}
	}

	for(int i = 1; i <= n; i++){
		if(used[i]) continue;
		
		s[i] = 'a';
		used[i] = 1;
		for(int j = 1; j <= n; j++){
			if(!used[j] and e[i][j] == 1){
				used[j] = 1;
				s[j] = 'a';
			}
		}
		break;
	}
	
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			s[i] = 'c';
			used[i] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			
			if(ok(s[i], s[j])) f[i][j] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(e[i][j] != f[i][j]){
				puts("No");
				return 0;
			}
		}
	}
	
	puts("Yes");
	for(int i = 1; i <= n; i++) printf("%c", s[i]); puts("");
	
	return 0;
}

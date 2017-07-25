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

const int N = 1010;

int n;
int pos[N], a[N];
int brkpt[N];

vector<pair<int,int> > solution;

vector<int> res;

bool solve(vector<int> &v, int d){
	if(v == res) return true;
	if(d == 3) return false;
	
	vector<int> positions;
	for(int i = 0; i < n; i++){
		if(brkpt[v[i]]) positions.pb(i);
	}
	
	int m = positions.size(), x, y;
		
	vector<int> tmp;
	for(int i = 0; i < m; i++){
		x = positions[i];
		for(int j = i+1; j < m; j++){
			y = positions[j];
			tmp = v;

			for(int a = x, b = y; a < b; a++, b--) swap(tmp[a], tmp[b]);
			
			if(solve(tmp, d+1)){
				solution.pb(mp(x,y));
				return true;
			}
		}
	}
	
	return false;
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		pos[a[i]] = i;
	}
	
	brkpt[1] = brkpt[n] = 1;
	for(int i = 1; i < n; i++){
		if(abs(pos[i] - pos[i+1]) != 1){
			brkpt[i] = brkpt[i+1] = 1;
		}
	}
	
	vector<int> v;
	for(int i = 1; i <= n; i++){
		v.pb(i);
	}

	for(int i = 1; i <= n; i++){
		res.pb(a[i]);
	}
	
	solve(v,0);
	
	printf("%d\n", (int) solution.size());
	reverse(solution.begin(), solution.end());
	foreach(it, solution){
		printf("%d %d\n", it->fi+1, it->se+1);
	}
	
	return 0;
}

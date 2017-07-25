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

typedef pair<int,int> pii;

const int N = 2000;

int n;
vector<pair<pii,pii> > v;

set<int> comp1, comp2;
map<int,int> f1, f2;
int if1[N], if2[N], cnt1, cnt2;

int g[N][N];
int ok[N][N];

void dfs(int x, int y){
	if(x < 0 or x >= cnt1 or y < 0 or y >= cnt2 or g[x][y] == 1 or ok[x][y] == 1) return;
	ok[x][y] = 1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}

int main(){
	int x = 0, y = 0;
	char c; int d;
	
	
	sd(n);
	for(int i = 0; i < n; i++){
		scanf(" %c %d", &c, &d);
		if(c == 'L'){
			v.pb(mp(mp(x-d,y), mp(x+1,y+1)));
			x -= d;
		}
		else if(c == 'R'){
			v.pb(mp(mp(x,y), mp(x+d+1,y+1)));
			x += d;
		}
		else if(c == 'U'){
			v.pb(mp(mp(x,y), mp(x+1,y+d+1)));
			y += d;
		}
		else{
			v.pb(mp(mp(x,y-d), mp(x+1,y+1)));
			y -= d;
		}
	}
	
	foreach(it, v){
		int x1 = it->fi.fi, y1 = it->fi.se, x2 = it->se.fi, y2 = it->se.se;
		comp1.insert(x1);
		comp1.insert(x2);
		comp2.insert(y1);
		comp2.insert(y2);
	}
	
	foreach(it, comp1){
		f1[*it] = cnt1;
		if1[cnt1++] = *it;
	}

	foreach(it, comp2){
		f2[*it] = cnt2;
		if2[cnt2++] = *it;
	}
	
	foreach(it, v){
		int x1 = f1[it->fi.fi], y1 = f2[it->fi.se], x2 = f1[it->se.fi], y2 = f2[it->se.se];
		for(int i = x1; i < x2; i++) for(int j = y1; j < y2; j++) g[i][j] = 1;
	}	
	
	for(int i = 0; i < cnt1; i++){
		for(int j = 0; j < cnt2; j++){
			if(i == 0 or i == cnt1-1 or j == 0 or j == cnt2-1) dfs(i,j);
		}
	}
	
	cnt1--;
	cnt2--;
	
	long long res = 0;
	for(int i = 0; i < cnt1; i++){
		for(int j = 0; j < cnt2; j++){
			if(ok[i][j]) continue;
			long long dx = if1[i+1]-if1[i];
			long long dy = if2[j+1]-if2[j];
			res += dx*dy;
		}
	}
	
	cout << res << endl;
	
	return 0;
}

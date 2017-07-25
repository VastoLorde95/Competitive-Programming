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

const int N = 15;

inline pair<pii, pii> mm(int x1, int y1, int x2, int y2){
	return mp(mp(x1,y1), mp(x2,y2));
}

int n, m;
int g[N][N];

void check(vector<pair<pii, pii> > moves){
//	tr("$$$$$$$$");
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << g[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	tr("$$$$$$$$");
	
	for(auto P : moves){
		int a = P.fi.fi, b = P.fi.se;
		int p = P.se.fi, q = P.se.se;
		
		assert(1 <= a and a <= n);
		assert(1 <= p and p <= n);
		assert(1 <= b and b <= m);
		assert(1 <= q and q <= m);
		
//		tr("$$$$$$$$");
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= m; j++){
//				cout << g[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		tr("$$$$$$$$");
//		tr(P);
		
		assert(g[a][b] == 1);
		assert(g[p][q] == 0);
		if(abs(a-p) == 1 or abs(b-q) == 1){
			assert(abs(a-p) == 0 or abs(b-q) == 0);
			swap(g[a][b], g[p][q]);
		}
		else{
			if(a == p){
				assert(abs(b-q) == 2 and g[a][(b+q)/2] == 1);
				g[a][b] = 0;
				g[p][q] = 1;
				g[a][(b+q)/2] = 0;
			}
			else{
				assert(abs(a-p) == 2 and g[(a+p)/2][b] == 1);
				g[a][b] = 0;
				g[p][q] = 1;
				g[(a+p)/2][b] = 0;
			}
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cnt += g[i][j];
		}
	}
	
	assert(cnt == 1);
}

void doit(vector<pair<pii, pii> > &moves){
	if(m == 1){
		for(int i = 3; i <= n; i++){
			moves.pb(mm(i,1,i-2,1));
			moves.pb(mm(i-2,1,i-1,1));
			moves.pb(mm(i-1,1,i,1));
		}
		return;
	}
	
	for(int j = 1; j <= m; j++){
		if(j < m){
			moves.pb(mm(3,j,1,j));
			moves.pb(mm(1,j,2,j));
			moves.pb(mm(1,j+1,1,j));
			moves.pb(mm(1,j,3,j));
			
			for(int i = 4; i <= n; i++){
				moves.pb(mm(i,j,i-2,j));
				moves.pb(mm(i-2,j,i-1,j));
				moves.pb(mm(i-1,j,i,j));
			}
		}
		else{
			for(int i = 3; i <= n; i++){
				moves.pb(mm(i,j,i-2,j));
				if(i < n){
					moves.pb(mm(i-2,j,i-1,j));
					moves.pb(mm(i-1,j,i,j));
				}
			}
		}
	}
	
	if(m > 2){	// clear the last row
		for(int j = m-2; j >= 1; j--){
			moves.pb(mm(n,j,n,j+2));
			moves.pb(mm(n,j+2,n,j+1));
			moves.pb(mm(n,j+1,n,j));
		}
		moves.pb(mm(n-2, m, n-1, m));
		moves.pb(mm(n-1, m, n, m));
		for(int j = m; j > 2; j--){
			moves.pb(mm(n,j,n,j-1));
		}
		moves.pb(mm(n,1,n,3));
	}
	else{
		moves.pb(mm(n-2,m,n-1,m));
		moves.pb(mm(n-1,m,n-1,m-1));
		moves.pb(mm(n,1,n-2,1));
	}
	
	
}

void solve(){
	cin >> n >> m;
	
	int xx, yy;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == '.'){
				xx = i+1, yy = j+1;
			}
			
			g[i+1][j+1] = (s[j] == '*');
		}
	}
	
	if(n == 1 and m == 1){
		cout << -1 << endl;
		return;
	}
	
	if((n == 1 and m == 2) or (n == 2 and m == 1)){
		cout << 0 << endl;
		return;
	}
	
	if(n == 2 and m == 2){
		cout << -1 << endl;
		return;
	}

		
	bool trans = false;
	if(n < m){ // make the longer dimension the rows and take transpose later
		swap(n, m);
		swap(xx, yy);
		trans = true;
	}
	
	vector<pair<pii, pii> > moves;
	while(xx != 1 or yy != 1){
		if(xx > 1){
			moves.pb(mp(mp(xx-1, yy), mp(xx,yy)));
			xx--;
		}
		else if(yy > 1){
			moves.pb(mp(mp(xx, yy-1), mp(xx,yy)));
			yy--;
		}
	}
	
	doit(moves);
	
	assert(moves.size() <= 5000);
	
	cout << moves.size() << endl;
	for(pair<pii, pii> &p : moves){
		if(!trans){
			cout << p.fi.fi << ' ' << p.fi.se << ' ' << p.se.fi << ' ' << p.se.se << endl;
		}
		else{
			cout << p.fi.se << ' ' << p.fi.fi << ' ' << p.se.se << ' ' << p.se.fi << endl;
			swap(p.fi.se, p.fi.fi);
			swap(p.se.se, p.se.fi);
		}
	}

	if(trans) swap(n,m);
	check(moves);
	
}

int main(){ _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

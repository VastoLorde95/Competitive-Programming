#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const ll B = 31;
const ll P = 2e9 + 7;
const int N = 610;

int n;
string g[2];
unordered_set<string> s;

string loopLeft(int x, int y){
	int i = x, j = y;
	string h;
	
	while(j >= 0){
		h += g[i][j];
		j--;
	}
	
	j = 0;
	i ^= 1;
	while(j <= y){
		h += g[i][j];
		j++;
	}
	return h;
}

string loopRight(int x, int y){
	int i = x, j = y;
	string h;
	
	while(j < n){
		h += g[i][j];
		j++;
	}
	
	j = n-1;
	i ^= 1;
	while(j >= y){
		h += g[i][j];
		j--;
	}
	return h;
}

void doit(){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			if(j == 0){
				s.insert(loopRight(i,j));
			}
			
			string h = loopLeft(i,j);
		
			int ni = i^1;
			int nj = j+1;

			while(nj < n){				
				s.insert(h+loopRight(ni,nj));
				h += g[ni][nj];
				ni ^= 1;
				h += g[ni][nj];
				nj++;
			}
		}
	}
}

void solve(){
	s.clear();
	cin >> n >> g[0] >> g[1];
	
	doit();
	reverse(g[0].begin(), g[0].end());
	reverse(g[1].begin(), g[1].end());
	doit();
	
	cout << s.size() << endl;
}

int main(){
	int p;
	cin >> p;
	while(p--) solve();
	return 0;
}

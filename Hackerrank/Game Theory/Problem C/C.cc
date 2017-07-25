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

int g[16][16];

int dx[4] = {-2,-2,1,-1};
int dy[4] = {1,-1,-2,-2};

bool good(int x, int y){
	if(x >= 1 and x <= 15 and y >= 1 and y <= 15) return true;
	return false;
}

int main(){
	
	g[1][1] = 0;
	for(int i = 3; i <= 30; i++){
		for(int x = 1; x <= 15; x++){
			int y = i-x;
			if(!good(x,y)) continue;
			
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				if(!good(nx,ny)) continue;
				g[x][y] |= (1-g[nx][ny]);
			}
		}
	}		
		
	int t;
	sd(t);
	while(t--){
		int x, y;
		sd2(x,y);
		if(g[x][y]) puts("First"); else puts("Second");
	}

	return 0;
}

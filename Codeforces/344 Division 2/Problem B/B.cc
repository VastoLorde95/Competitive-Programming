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

const int N = 5010;

int n, m, k;
pii row[N], col[N];

int main(){
	sd3(n,m,k);
	
	for(int i = 1; i <= n; i++){
		row[i] = mp(0,0);
	}
	for(int i = 1; i <= m; i++){
		col[i] = mp(0,0);
	}
	
	int type, x, y;
	int t = 1;
	while(k--){
		sd3(type, x, y);
		if(type == 1){
			row[x] = mp(y,t++);
		}
		if(type == 2){
			col[x] = mp(y,t++);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(row[i].se < col[j].se) printf("%d ", col[j].fi); else printf("%d ", row[i].fi);
		}
		printf("\n");
	}
	
	return 0;
}

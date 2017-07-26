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

void good(){
	puts("POSSIBLE");
}

void bad(){
	puts("IMPOSSIBLE");
}

int mt[60][60];

void solve(){
	int n; ll m;
	scanf("%d%lld", &n, &m);
	
	if(n == 2){
		if(m > 1){
			bad();
		}
		else{
			good();
			puts("01");
			puts("00");
		}
		return;
	}
	
	if(m > (1ll << (n-2))){
		bad();
		return;
	}
	
	memset(mt, 0, sizeof mt);
	
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j < n; j++){
			mt[i][j] = 1;
		}
	}
	
	mt[1][n] = 1;
	m--;
	for(int i = 2; i < n; i++){
		int j = i-2;
		if((m&(1ll<<j)) > 0){
			mt[i][n] = 1;
		}
	}
	
	good();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d", mt[i][j]);
		}
		puts("");
	}	
	return;
}

int main(){
	int t; sd(t);
	for(int T = 1; T <= t; T++){
		printf("Case #%d: ", T);
		solve();
	}
	return 0;
}

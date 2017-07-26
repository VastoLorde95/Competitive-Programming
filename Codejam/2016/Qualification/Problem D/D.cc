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

int main(){
	int t; sd(t);
	for(int T = 1; T <= t; T++){
		int k, c, s; sd3(k,c,s);
		printf("Case #%d: ", T);
		if(s == k){
			for(int i = 1; i <= s; i++) printf("%d ", i);
			printf("\n");
			continue;
		}

		if(c == 1){
			printf("IMPOSSIBLE\n");
			continue;			
		}
		
		if(s < (k+1)/2){
			printf("IMPOSSIBLE\n");
			continue;
		}
		
		ll num = 1;
		for(int i = 1; i < c; i++) num *= k;
		
		ll r = k/2;
		
		for(ll i = 1; i <= r; i++){
			printf("%lld ", num * 2ll * (i-1) + 2ll * i);
		}
		
		if(k % 2){
			printf("%lld", (ll) k);
		}
		printf("\n");
	}
	return 0;	
}

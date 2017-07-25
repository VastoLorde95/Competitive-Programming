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

const int N = 1001000;

int p[N], phi[N];
ll ans[N];

int main(){
	for(int i = 1; i < N; i++) phi[i] = i;
	for(int i = 2; i < N; i++) p[i] = 1;
	
	for(int i = 2; i < N; i++){
		if(!p[i]) continue;
		for(int j = i; j < N; j += i){
			p[j] = 0;
			phi[j] -= phi[j] / i;
		}
	}

	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i){
			ans[j] += 1ll * i * phi[i];
		}
	}
	
	for(int i = 1; i < N; i++){
		ans[i] /= 2;
		ans[i] *= i;
	}
	
	int t; sd(t);
	while(t--){
		int x; sd(x);
		printf("%lld\n", ans[x] + x);
	}

	return 0;
}

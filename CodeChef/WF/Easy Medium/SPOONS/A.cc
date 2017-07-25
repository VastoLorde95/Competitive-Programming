#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULLLL);cout.tie(NULLLL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LLINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

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

ll vals[63] = {2, 3, 6, 10, 20, 35, 70, 126, 252, 462, 924, 1716, 3432, 6435, 12870, 24310, 48620, 92378, 184756, 352716LL, 705432LL, 1352078LL, 2704156LL, 5200300LL, 10400600LL, 20058300LL, 40116600LL, 77558760LL, 155117520LL, 300540195LL, 601080390LL, 1166803110LL, 2333606220LL, 4537567650LL, 9075135300LL, 17672631900LL, 35345263800LL, 68923264410LL, 137846528820LL, 269128937220LL, 538257874440LL, 1052049481860LL, 2104098963720LL, 4116715363800LL, 8233430727600LL, 16123801841550LL, 32247603683100LL, 63205303218876LL, 126410606437752LL, 247959266474052LL, 495918532948104LL, 973469712824056LL, 1946939425648112LL, 3824345300380220LL, 7648690600760440LL, 15033633249770520LL, 30067266499541040LL, 59132290782430712LL, 118264581564861424LL, 232714176627630544LL, 465428353255261088LL, 916312070471295267LL, 1832624140942590534LL};

void solve(){
	ll n;
	scanf("%lld", &n);
	
	printf("%d\n", (int) (2 + (lower_bound(vals, vals+63, n) - vals)));
}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}

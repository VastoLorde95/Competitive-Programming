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

typedef long long ll;
typedef pair<int,int> pii;

const int M = (1<<27);
const ll MOD = (1ll<<32);

int q;
ll s, a, b, sum;
short h[M];

int main(){
	sd(q);
	sd3(s,a,b);

	int tmp, x, y;
	while(q--){
		tmp = s >> 1;
		
		x = tmp >> 27;
		y = (tmp&(M-1));

		if(s&1){
			if(((h[y]>>x)&1) == 0){
				h[y] ^= (1<<x);
				sum += tmp;
			}
		}
		else{
			if(((h[y]>>x)&1) > 0){
				h[y] ^= (1<<x);
				sum -= tmp;
			}
		}
		
		s = (s*a + b)%MOD;
	}
	printf("%lld\n", sum);
	
	return 0;
}

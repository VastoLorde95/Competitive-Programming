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

const int N = 1001000;
const ll MOD = 1e9 + 7;

int n;
int h[N];

void add(ll &x, ll v){
	x += v;
	if(x >= MOD) x -= MOD;
}

int main(){
	sd(n);
	
	bool nonzero = false;
	for(int i = 0; i < n; i++){
		sd(h[i]); h[i]--;
		if(h[i]) nonzero = true;
	}
	
	if(!nonzero){
		puts("0"); return 0;
	}
	
	ll ways = 0, t1 = 0;
	
	for(int i = 0; i < n; i++){
		if(!h[i]){
			t1 = 0; continue;
		}
		
		add(ways, h[i]);
		if(i > 0 and h[i] > h[i-1]) add(ways, (t1 * h[i-1]) % MOD);
		if(i > 0 and h[i] <= h[i-1]) add(ways, (t1 * h[i]) % MOD);
		
		if(i + 1 < n){
			if(h[i+1] > h[i]){
				t1 = ((t1 + 1) * h[i]) % MOD;
			}
			else{
				t1 = t1 = ((t1 + 1) * h[i+1]) % MOD;
			}
		}
	}
	
	cout << ways << endl;
	
	
	return 0;
}

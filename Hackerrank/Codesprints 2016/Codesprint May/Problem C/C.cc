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
 
#define K 100005
#define M 1000000007
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define F first
#define S second
#define sl(n) scanf("%lld",&n);
#define D(x) cout<<x<<" "; 
#define PB push_back
#define MP make_pair
#define gcd __gcd
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PI> VPI;
typedef vector<PL> VPL;
 
ll poww(ll x, ll y)
{
//	cout<<" x "<<x<<" y "<<y<<endl;
	if(x==1) return 1ll;
	if(y==1) return x;
	ll ans = poww(x,y/2);
	ans *= ans;
	if(ans>= M) ans %= M;
	if(y&1) return (ans*x)%M;
	else return ans;
}
 
 
void solve(int n, int k, int st)
{
	//cout<<" n "<<n<<" k "<<k<<" st "<<st<<endl;
	if(n>= 4*k)
	{
		for(int i=0; i<k;i++) cout<<st+k+i<<" ";
		for(int i=0; i<k;i++) cout<<st+i<<" ";
		solve(n-2*k,k,st+2*k);
	}
	else if(4*k - n >= k)
	{
		for(int i=k; i<n;i++) cout<<st+i<<" ";
		for(int i=0; i<k;i++) cout<<st+i<<" ";
	}
	else
	{
		for(int i=0;i<k;i++) cout<<st+k+i<<" ";
		for(int i=0;i<(n-3*k);i++) cout<<st+i<<" ";
		for(int i=0;i<k;i++) cout<<st+n-k+i<<" ";
		for(int i=0;i<(4*k-n);i++) cout<<st+k-(4*k-n)+i<<" ";
		for(int i=0;i<k - (4*k-n); i++) cout<<2*k+ st+i<<" ";
	}
}
 
 
int main()
{
	int t;
	sd(t);
	while(t--)
	{
		int n,k;
		sd(n); sd(k);
		if(n/2 < k) cout<<-1<<endl;
		else if(k==0)
		{
			fo(i,n) cout<<i+1<<" ";
			cout<<endl;
		}
		else
		{
			solve(n,k,1);
			cout<<endl;
		}
	}
}
 

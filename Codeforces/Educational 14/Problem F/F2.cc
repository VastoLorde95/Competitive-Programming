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

const int N = 3000002;

int n, m;
int a[N];
ll b[N];

ll ans[N];

vector<int> v[N];
vector<int> q[N];

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		int x; sd(x);
		a[x]++;
	}
	
	b[N-1] = a[N-1];
	for(int i = N-2; i >= 0; i--){
		b[i] = a[i];
		b[i] += b[i+1];
	}
	
	ll tot = 0;
	for(int i = 1; i < N; i++){
		if(a[i]){
			ll z = 1;
			ll y = a[i];
			tot += ((z <= y)? b[z]-1 : b[z]) * y;
		}
	}
	
	int mx = 0;
	sd(m);
	for(int i = 1; i <= m; i++){
		int p; sd(p);
		q[p].pb(i);
		mx = max(mx, p);
	}
	
	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i){
			if(a[i]) v[j].pb(i);
		}
	}
	
	int cur = 1;
	for(int i = 1; i <= mx; i++){
		for(int j = 0; j < q[i].size(); j++){
			int x = i, id = q[i][j], y, z;
			while(cur < x){
				for(int r = 0; r < v[cur].size(); r++){
					y = v[cur][r];
				
					z = cur/y;
					tot -= ((z <= y)? b[z]-1 : b[z]) * a[y];
				
					z++;
					tot += ((z <= y)? b[z]-1 : b[z]) * a[y];
				}
				cur++;
			}
		
			ans[id] = tot;
		}
	}
	
	for(int i = 1; i <= m; i++){
		printf("%I64d\n", ans[i]);
	}
	return 0;
}

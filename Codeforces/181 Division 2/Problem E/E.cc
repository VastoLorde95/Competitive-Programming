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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 10000001;
int lp[N], primes[N], pcnt;

void getSieve(){
	for(int i = 2; i <= N; i++){
		if(lp[i] == 0){
			lp[i] = i; primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= lp[i] and i*primes[j] <= N; j++) lp[i*primes[j]] = primes[j];
	}
	return;
}

typedef long long ll;

const int M = 1000100;
int k, a, cnt[N], mx;
ll cp[N];

int f(ll val){
	ll p, d, tot;
	for(int i = 0; i < pcnt and primes[i] <= val; i++){
		d = p = primes[i], tot = 0;
		while(d <= val and tot < cp[p]){
			tot += val/d;
			d *= p;
		}	
		if(tot < cp[p]) return 0;
	}
	return 1;
}

int main(){
	getSieve();
	sd(k);
	for(int i = 1; i <= k; i++){
		sd(a);
		mx = max(mx, a);
		cnt[1]++; cnt[a+1]--;
	}
	
	int p, num;
	for(int i = 1; i <= mx; i++){
		cnt[i] += cnt[i-1];
		num = i;
		while(num > 1){
			p = lp[num];
			while(lp[num] == p){
				cp[p] += cnt[i];
				num /= p;
			}
		}
	}
	
	ll lo = mx, hi = (1LL<<45), mid;
	while(lo < hi){
		mid = (lo+hi)>>1;
		if(f(mid)) hi = mid;
		else lo = mid+1;
	}
	
	printf("%I64d\n", hi);
	
	return 0;
}

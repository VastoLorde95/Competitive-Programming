#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>

#define For(i,a,b) for(register int (i)=(a);(i)<=(b);(i)++)
#define FOR(i,a) For(i,1,a)
#define Ford(i,a,b) for(register int (i)=(a);(i)>=(b);(i)--)
#define Rep(i,a,b) for(register int (i)=(a);(i)<(b);(i)++)
#define REP(i,a) Rep(i,0,a)
#define type(x) __typeof(x.begin())
#define foreach(it,x) for(__typeof(x.begin()) it = x.begin() ; it!=x.end() ; it++ )

#define NEW(x,n) (x*)calloc(n,sizeof(x))
#define fill(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define compress(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
#define two(x) (1LL<<(x))
#define fi first
#define se second
#define gcd __gcd
#define pb push_back
#define mp make_pair

#ifdef KAZAR
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
	#define dbg(x) cerr<<#x<<":"<<(x)<<endl
	#define dg(x) cerr<<#x<<":"<<(x)<<' '
#else
    #define eprintf(...) 0
	#define dbg(x) 0
	#define dg(x) 0
#endif

using namespace std;

typedef long long Lint;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 1e9+5143;
const Lint Linf = 1e18+5413;
const double eps = 1e-15;
const double pi = acos(-1);

template<class T> inline void umax(T &a,T b){if(a<b) a = b ; }
template<class T> inline void umin(T &a,T b){if(a>b) a = b ; }
template<class T> inline T abs(T a){return a>0 ? a : -a;}
template<class T> inline T lcm(T a,T b){
	return a/gcd(a,b)*b;
}

inline int read(){
	int res = 0LL ;int neg ;
	while(1){
		char ch = getchar();
		if(ch>='0' && ch<='9' || ch=='-'){
			if(ch=='-') neg = -1;
			else neg = 1 , res = ch-'0';
			break;
		}
	}
	while(1){
		char ch = getchar();
		if(ch>='0' && ch<='9') res*=10 , res+=ch-'0';
		else break;
	}
	return res*neg;
}

const int N = 492717;
const int SQ = 300;

ii a[N];
int f[N];
vi valsx , vals;
vi occurance[N];
vii ask[N];
vi huges;
int ans[N];
int q;
vi here[N];

void get_damn_input(){

    int n = read();
    q = read();
    read();

    FOR(i,n){
        read();
        a[i].fi = read();
        a[i].se = read();
        valsx.pb(a[i].fi);
    }

    compress(valsx);

    FOR(i,n){
        a[i].fi = lower_bound(all(valsx),a[i].fi) - valsx.begin() + 1;
    }

    sort(a + 1,a + 1 + n);

    FOR(i,n){
        vals.pb(a[i].se);
    }

    compress(vals);

    FOR(i,n){
        f[i] = lower_bound(all(vals),a[i].se) - vals.begin() + 1;
        assert(f[i] < N);
        occurance[f[i]].pb(a[i].fi);
        assert(a[i].fi < N);
        here[a[i].fi].pb(f[i]);
    }

    REP(i,N) compress(here[i]);

    REP(i,vals.size() + 5){
        sort(all(occurance[i]));
        if(occurance[i].size() > SQ){
            huges.pb(i);
        }
    }

    FOR(i,q){
        int r = upper_bound(all(valsx),read()) - valsx.begin();
        int l = lower_bound(all(valsx),read()) - valsx.begin() + 1;
        read();
        ask[r].pb(ii(l,i));
    }

}

int kd[N * 10];

void put(int k,int b,int e,int x,int val){
    assert(k < N * 10);
    if(b > x || e < x) return;
    if(b == e){
        assert(val > 0);
        umax(kd[k],val);
        return;
    }
    put(k + k,b,(b+e)/2,x,val);
    put(k + k + 1,(b+e)/2 + 1,e,x,val);
    kd[k] = max(kd[k + k],kd[k + k + 1]);
}

int get(int k,int b,int e,int x1,int x2){
    assert(k < N * 10);
    if(b > x2 || e < x1) return 0;
    if(b >= x1 && e <= x2) return kd[k];
    return max(get(k + k,b,(b+e)/2,x1,x2),get(k + k + 1,(b+e)/2+1,e,x1,x2));
}

void insert(int idx,int where){
    assert(idx < N);
    if(occurance[idx].size() > SQ) return;
    int cur = 0;
    Ford(i,occurance[idx].size() - 1,0){
        if(occurance[idx][i] <= where){
            put(1,1,N,occurance[idx][i],++cur);
        }
    }
}

int main(){
    get_damn_input();

    REP(i,N){
        assert(i < N);
        foreach(it,here[i]){
            insert(*it,i);
        }
        int r = i;
        foreach(it,ask[r]){
            int l = it->fi;
            int res = get(1,1,N,l,r);
            foreach(huge,huges){
                umax(res,int(upper_bound(all(occurance[*huge]),r) - lower_bound(all(occurance[*huge]),l)) );
            }
            ans[it->se] = res;
        }
    }

    FOR(i,q) printf("%d\n",ans[i]);

    return 0;
}


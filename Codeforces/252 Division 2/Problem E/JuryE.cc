#undef NDEBUG
#ifdef gridnevvvit
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
                  
#include <functional>
#include <limits>
#include <numeric>
#include <complex>

#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>   

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline li nextInt64() { li x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

li x;
int k;
int pl;


const int N = 402;
const int MAGIC = 9;


ld d[2][(1 << MAGIC)][2][N];

inline bool read() {
 	return (cin >> x >> k >> pl);
}
              
inline void solve() {                    
	ld p = ld(pl) / 100;

	int SPMASK = (1 << MAGIC) - 1;

	li pmask = x & li(SPMASK);
    li plast = (x & li(1 << MAGIC)) > 0;
    li pcnt = 0;
    
    x >>= MAGIC;
    
    if (x == 0)
   		pcnt = 200;
    else {
    	while (true) {
    	 	int bit = x & 1ll;

    	 	if (bit == plast)
    	 		pcnt++;
    	 	else
    	 		break;

    	 	x >>= 1;
    	}
    }

    d[0][pmask][plast][pcnt] = 1.0;
 	
                 
    forn(it, k) {
		int i = it & 1;
		int nxt = i ^ 1;

		forn(mask, (1 << MAGIC)) {
		 	forn(last, 2) {
		 	 	forn(cnt, N) {
		 	 	 	d[nxt][mask][last][cnt] = 0.0;
		 	 	}
		 	}
		}

	 	forn(mask, (1 << MAGIC)) {
			forn(last, 2) {
				forn(cnt, N) {
					ld dv = d[i][mask][last][cnt];

					//doubling
                	{
                		int nmask = (mask << 1) & SPMASK;
                		int nlast = (mask & (1 << (MAGIC - 1))) > 0;
                		int ncnt = cnt;

                		if (last == nlast)
                			ncnt++;
                		else
                			ncnt = 1;
                    	
                        d[nxt][nmask][nlast][ncnt] += dv * p;

                    }

                    //adding
                    {
                     	int nmask = mask + 1;

                     	if (nmask != (1 << MAGIC)) {
                     		d[nxt][nmask][last][cnt] += dv * (1.0 - p);
                     	} else {
                     		if (last == 1)
                     			d[nxt][0][0][cnt] += dv * (1.0 - p);
                     		else
                     			d[nxt][0][1][1] += dv * (1.0 - p);
                        }
                    }
                }	
			}
	 	}
	}            

	ld answer = 0;

	k = k & 1;

	forn(nmask, (1 << MAGIC)){
	 	forn(last, 2) {
	 	 	forn(cnt, N) {
	 	 		int counter = 0;

	 	 		int mask = nmask;

	 	 		if (mask != 0) {
	 	 		
	 	 			while (mask % 2 == 0)
	 	 				counter += 1, mask /= 2;
	 	 					
	 	 		} else {
	 	 			counter = MAGIC;
	 	 			if (last == 0)
	 	 				counter += cnt;
	 	 		}	
	 	 		
	 	 		ld dv = d[k][nmask][last][cnt];

	 	 		answer += ld(counter) * ld(d[k][nmask][last][cnt]);
	 	 	}
	 	}
	}

	cout << fixed << setprecision(13) << answer << endl;
}

int main() 
{

	srand(time(NULL));

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	assert(read());
	solve();

} 

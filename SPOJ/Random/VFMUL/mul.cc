#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<complex>

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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

typedef complex<long double> base;

long long nn;
char a[1000000], b[1000000];
long double PI = 2 * acos(0.0L);
long long BASE = 100000;

long long rev (long long num, long long lg_n) {
	long long res = 0;
	for (long long i=0; i<lg_n; ++i)
		if (num & (1<<i))
			res |= 1<<(lg_n-1-i);
	return res;
}
 
void fft (vector<base> & a, bool invert) {
	long long n = (long long) a.size();
	long long lg_n = 0;
	while ((1 << lg_n) < n)  ++lg_n;
 
	for (long long i=0; i<n; ++i)
		if (i < rev(i,lg_n))
			swap (a[i], a[rev(i,lg_n)]);
 
	for (long long len=2; len<=n; len<<=1) {
		long double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (long long i=0; i<n; i+=len) {
			base w (1);
			for (long long j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (long long i=0; i<n; ++i)
			a[i] /= n;
}

void multiply (const vector<long long> & a, const vector<long long> & b, vector<long long> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
 	long long carry = 0;
	res.resize (n);
	for(size_t i = 0; i < n; ++i) res[i] = (long long) (fa[i].real() + 0.5);
	
//	foreach(it, res) cout << *it << " "; cout << endl;
	
	for(size_t i = 0; i < n; ++i){
		carry += res[i];
		res[i] = carry%BASE;
		carry /= BASE;
	}
}

vector<long long> n1, n2, r;

long long l1, l2;

int main(){
	scanf("%lld",&nn);
	while(nn--){
		scanf("%s %s", a, b);
		n1.clear(), n2.clear(), r.clear();
		
		l1 = strlen(a), l2 = strlen(b);
		
		for(long long i = l1-1; i >= 0; i -= 5){
			long long x = 0;
			for(long long j = max(0LL,i-5+1); j <= i; j++){
				x = (x*10) + (long long)(a[j]-'0');
			}
			n1.pb(x);
		}
		
//		foreach(it, n1) cout << *it << " "; cout << endl;
		
		for(long long i = l2-1; i >= 0; i -= 5){
			long long x = 0;
			for(long long j = max(0LL,i-5+1); j <= i; j++){
				x = (x*10) + (long long)(b[j]-'0');
			}
			n2.pb(x);
		}
//		foreach(it, n2) cout << *it << " "; cout << endl;
		
		multiply(n1, n2, r);
		
//		foreach(it, r) cout << *it << " "; cout << endl;
		
		long long i = r.size()-1;
		while(i > 0 and r[i] == 0) i--;
		printf("%lld", r[i]);
		for(i--; i >= 0; i--) printf("%.*lld", 5, r[i]); printf("\n");
	}
	return 0;
}

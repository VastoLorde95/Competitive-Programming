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

typedef complex<double> base;

int n, m, k;
char s[200100], t[200100];

int d[1<<18], res[1<<18];
vector<int> a, b;
double PI = 3.14159265358979323846f;
 
int rev (int num, int lg_n) {
	int res = 0;
	for (int i=0; i<lg_n; ++i)
		if (num & (1<<i))
			res |= 1<<(lg_n-1-i);
	return res;
}
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	int lg_n = 0;
	while ((1 << lg_n) < n)  ++lg_n;
 
	for (int i=0; i<n; ++i)
		if (i < rev(i,lg_n))
			swap (a[i], a[rev(i,lg_n)]);
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

int multiply (vector<int> & a, vector<int> & b) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	for (size_t i=0; i<n; ++i)
		res[i] += int (fa[i].real() + 0.5);
	return n;
}

void get(char c){
	memset(d, 0, sizeof d);
	
	a.clear(), b.clear();
	
	for(int  i = 0; i < m; i++){
		if(t[i] == c) b.pb(1); else b.pb(0);
	}
	
	reverse(b.begin(), b.end());	
	
	for(int i = 0; i < n; i++){
		if(s[i] == c) d[max(0, i-k+1)]++, d[min(n, i+k+1)+1]--;	
	}
	for(int i = 1; i <= n; i++){
		d[i] += d[i-1];
		if(d[i] > 0) a.pb(1); else a.pb(0);
	}
	
}


int main(){
	sd3(n,m,k);
	scanf("%s %s",s,t);
	
	get('A');
	int sz = multiply(a, b);
	
	get('T');
	multiply(a, b);
	
	get('C');
	multiply(a, b);
	
	get('G');
	multiply(a, b);
	
	int ans = 0;
	
	for(int i = 0; i < sz; i++) if(res[i] == m) ans++;
	
	printf("%d\n", ans);
	return 0;
}

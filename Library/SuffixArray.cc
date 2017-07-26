#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;

struct SuffixArray {
	int sa[N], lcp[N], n;
	int w[N], rnk[N], tb[N]; // buffer
	string s;
	
	SuffixArray(string &str){
		s = str;
		n = s.length();
		
		int m = 128;
		int *x = rnk, *y = tb, *z;
		
		x[n] = 0;
		for(int i = 0; i < n; i++) x[i] = s[i], y[i] = i;
			
		sort(x, y, m);
		for(int k = 1, p = 1; p < n; k *= 2, m = p) {
			p = 0;
			for(int i = n-k; i < n; i++) y[p++] = i;
			for(int i = 0; i < n; i++) {
				if(sa[i] >= k)
					y[p++] = sa[i] - k;
			}
			
			sort(x, y, m);
			z = x, x = y, y = z;
			
			x[sa[0]] = 0;
			p = 1;
			
			for(int i = 1; i < n; i++) x[sa[i]] = cmp(y, sa[i-1], sa[i], k) ? p-1 : p++;
		}
		
		// lcp
		for(int i = 0; i < n; i++)  rnk[sa[i]] = i;
		
		for(int i = 0, k = 0; i < n; i++, k ? k-- : 0){
			if(rnk[i] == n-1){
				k = 0;
				continue;
			}
			int j = sa[rnk[i]+1];
			while(i + k < n and j + k < n and s[i+k] == s[j+k]) k++;
			lcp[rnk[i]] = k;
		}

	}
	
	void sort(int *x, int *y, int m) { // radix sort
		for(int i = 0; i < m; i++) w[i] = 0;
		for(int i = 0; i < n; i++) w[x[y[i]]]++;
		for(int i = 1; i < m; i++) w[i] += w[i-1];
		for(int i = n-1; i >= 0; i--) sa[--w[x[y[i]]]] = y[i];
	}
	
	bool cmp(int *r, int a, int b, int l) {
		if(r[a] == r[b]) {
			if(a+l >= n || b+l >= n) return false;
			return r[a+l] == r[b+l];
		}
		return false;
	}
};

int main(){
	return 0;
}

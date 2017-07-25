#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

const int N = 200100;

ll b = 101;
ll p = 1024383257;
ll h[N], pwr[N];

int n;
char s[N];

void precompute(){
	pwr[0] = 1;
	for(int i = 1; i < n; i++) pwr[i] = pwr[i-1] * b % p;
	
	h[0] = s[0];
	for(int i = 1; i < n; i++) h[i] = (h[i-1] * b + s[i]) % p;
}
 
ll getHash(int i, int j){
	ll v1 = h[j] - ((i-1 >= 0)? (h[i-1] * pwr[j-i+1] % p) : 0);
	if(v1 < 0) v1 += p;
	return v1;
}

ll h2;
int longestCommonPrefix(int i, int j, int k, int l){
	int lo = 0, hi = min(n - k + 2, l+1), mid;
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		h2 = getHash(j, j + mid - 1);
		if(getHash(i, i + mid - 1) == h2 and h2 == getHash(k, k + mid - 1)) lo = mid;
		else hi = mid;
	}
	
	return lo;
}

int longestCommonSuffix(int i, int j, int k, int l){
	int lo = 0, hi = min(i + 2, l+1), mid;
	while(lo + 1 < hi){
		mid = (lo + hi) >> 1;
		h2 = getHash(j - mid + 1, j);
		if(getHash(i - mid + 1, i) == h2 and h2 == getHash(k - mid + 1, k)) lo = mid;
		else hi = mid;
	}
	return lo;
}

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	precompute();
	
	ll ans1 = 0, ans2 = 0;

	int limit = n / 3;	
	for(int l = 1; l <= limit; l++){
		for(int i = 0; i < n-2*l; i += l){
			int j = i + l, k = j + l;
			
			int x = longestCommonPrefix(i,j,k,l+1);
			int y = longestCommonSuffix(i,j,k,l);
			int a =  min(x,l) + y  - l;
			
			if(a <= 0) continue;
			
			if(x > l) ans1 += a;
			else{
				ans1 += a-1;
				ans2++;
			}
		}
	}
	
	printf("%lld %lld\n", ans2, ans1);
	
	return 0;
}

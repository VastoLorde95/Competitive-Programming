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

int get(int n, int k){
	if(n == k){
		return 0;
	}
	int a1, a2, b1, b2, c1, c2;
	if(k % n == 0){
		a1 = a2 = 0;
		b1 = k / n, b2 = n-1;
		c1 = (k / n) - 1, c2 = 1;
	}
	else{
		a1 = (k / n) + 1, a2 = k % n;
		b1 = (k / n), b2 = n-1 - a2;
		c1 = (k / n) - 1, c2 = 1;
	}
	
	int ret = 0;
	ret += a2 * ((a1 + 1) / 2);
	ret += b2 * ((b1 + 1) / 2);
	ret += c2 * ((c1 + 1) / 2);
	return ret;
}

void solve(){
	int n, s;
	cin >> n >> s;
	
	vector<int> res;
	for(int i = 1; i <= s; i++){
		int cnt = get(i,s);
		if(cnt < n) res.pb(i);
	}
	
	printf("%d\n", (int) res.size());
	foreach(it, res) printf("%d ", *it);
	puts("");
}

int main(){ _
	int t; cin >> t;
	while(t--) solve();	
	return 0;
}

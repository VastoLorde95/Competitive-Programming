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

const int LOGN = 18;
const int N = 1 << LOGN;

int n;
int sp1[LOGN][N];
int sp2[LOGN][N];
int k[N], o[N];
int a[N], b[N];

void sparseTable(){
	for(int i = 0; i < n; i++){
		sp1[0][i] = a[i], sp2[0][i] = b[i];
	}
	
	for(int j = 1; j < LOGN; j++){
		for(int i = 0; (i+(1<<j)-1) < n; i++){
			sp1[j][i] = max(sp1[j-1][i], sp1[j-1][i+(1<<(j-1))]);
			sp2[j][i] = min(sp2[j-1][i], sp2[j-1][i+(1<<(j-1))]);
		}
	}
	
	for(int i = 2; i < n; i++){
		k[i] = k[i-1] + ((i&(i-1)) == 0);
		o[i] = (k[i] == k[i-1])? o[i-1] : (o[i-1] << 1)+1;
	}
}

int mx(int x, int y){
	int l = y-x+1;
	return max(sp1[k[l]][x], sp1[k[l]][y-o[l]]);
}

int mn(int x, int y){
	int l = y-x+1;
	return min(sp2[k[l]][x], sp2[k[l]][y-o[l]]);
}

int getLeft(int x){
	int lo = x-1, hi = n-1, mid;
	while(lo+1 < hi){
		mid = (lo + hi) >> 1;
		if(mx(x,mid) >= mn(x,mid)) hi = mid; else lo = mid;
	}
	if(mx(x,hi) != mn(x,hi)) hi = -1;
	return hi;
}

int getRight(int x, int y){
	int lo = y, hi = n, mid;
	while(lo+1 < hi){
		mid = (lo + hi) >> 1;
		if(mx(x,mid) == mn(x,mid)) lo = mid; else hi = mid;
	}
	return lo;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(a[i]);
	for(int i = 0; i < n; i++) sd(b[i]);
	
	sparseTable();
	
	ll ans = 0;
	int x;
	for(int i = 0; i < n; i++){
		if(a[i] > b[i]) continue;
		if((x = getLeft(i)) == -1) continue;
		ans += getRight(i, x)-x+1;
	}
	
	printf("%I64d\n", ans);

	return 0;
}

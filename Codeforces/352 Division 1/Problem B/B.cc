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

const int N = 500100;

int n, k;
int a[N];

int main(){
	sd2(n,k);
	
	for(int i = 0; i < n; i++) sd(a[i]);
	
	sort(a, a+n);

	int prev = a[0], tmp = k, j = 0;
	for(int i = 1; i < n; i++){
		ll v = (ll) (a[i] - prev) * i;
		if(v <= tmp){
			tmp -= v;
			prev = a[i];
			j = i;
		}
	}
	
	int dh = tmp / (j + 1), rem = tmp % (j + 1);
	for(int i = 0; i <= j; i++){
		a[i] = prev + dh;
		if(i < rem) a[i]++;
	}
	
	for(int i = 0; i < n; i++) a[i] = -a[i];
	
	sort(a, a+n);
	
	prev = a[0], tmp = k, j = 0;
	for(int i = 1; i < n; i++){
		ll v = (ll) (a[i] - prev) * i;
		if(v <= tmp){
			tmp -= v;
			prev = a[i];
			j = i;
		}
	}
	
	dh = tmp / (j + 1), rem = tmp % (j + 1);
	for(int i = 0; i <= j; i++){
		a[i] = prev + dh;
		if(i < rem) a[i]++;
	}
	
	for(int i = 0; i < n; i++) a[i] = -a[i];
	
	sort(a, a+n);
	
	printf("%d\n", a[n-1] - a[0]);
	
	return 0;
}

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

const long double PI = 3.1415926535897932384626433832795;

const int N = 101;

int n;

ll get(ll val){
	ll cur = 0, jump = 1;
	int num = 1;
	while(cur < val){
		if(num == 0) jump *= 3;
		else if(num == 1){
			if(jump != 1) jump *= 2;
		}
		else if(num == 2) jump *= 2;
		cur += jump;
		num++;
		if(num == 4) num = 0;
	}
	if(--num < 0) num = 3;
	return num;
}


ll a[N];

void solve(){
	sd(n);
	for(int i = 0; i < n; i++) scanf("%lld", a+i);
	
	ll res = 0;
	for(int i = 0; i < n; i++) res ^= get(a[i]);
	
	if(res) puts("Henry"); else puts("Derek");
}

int main(){
	int t; sd(t);
	while(t--) solve();
	return 0;
}

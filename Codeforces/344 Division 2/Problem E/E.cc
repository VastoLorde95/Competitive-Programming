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

const int N = 200100;

struct line{
	ll m, c;
	ll get(ll x){
		return m*x + c;
	}
};

line st[N];

struct convexHull{
	int top;
	
	bool smallerIntercept(const line &l1, const line &l2, const line &l3){
		return (l3.c - l1.c) * (l1.m - l2.m) <= (l2.c - l1.c) * (l1.m - l3.m);
	}
	
	convexHull() : top(0) {	}
	
	void insert(ll m, ll c){
		line l = {m, c};
		
		while(top > 1 and smallerIntercept(st[top-2], st[top-1], l)) --top;
		st[top++] = l;
		
		return;
	}
	
	ll query(ll x){
		int lo = 0, hi = top-1, mid;
		
		while(lo+1 <= hi){
			mid = (lo + hi) >> 1;
			if(st[mid].get(x) <= st[mid+1].get(x)) lo = mid+1; else hi = mid;
		}
		
		return st[lo].get(x);
	}
};

int n;
ll a[N], sum[N], total;

int main(){ _
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
		total += a[i] * i;
	}
	
	ll ans = total;	
		
	convexHull hull = *(new convexHull());
	for(int i = 1; i <= n; i++){
		hull.insert(i, -sum[i-1]);
		ans = max(ans, total + hull.query(a[i]) + sum[i-1] - a[i] * i);
	}
	
	hull = *(new convexHull());
	for(int i = n; i >= 1; i--){
		hull.insert(-i, -sum[i]);
		ans = max(ans, total + hull.query(-a[i]) + sum[i] - a[i] * i);
	}
	
	cout << ans << '\n';
		
	return 0;
}

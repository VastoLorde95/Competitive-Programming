#include <bits/stdc++.h>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 100100;
const int M = 1<<21;
const int SQRT = 320;

struct query{
	int l, r, id;
	int operator<(const query &q) const{
		if(l/SQRT != q.l/SQRT)
			return l/SQRT < q.l/SQRT;
		
		return r < q.r;	
	}
};

int n, m, k;
int a[N], s[N];
long long res[N], ans;
int cnt[M];
query q[N];

void add(int x){
	ans += cnt[s[x]^k];
	cnt[s[x]]++;
}

void remove(int x){
	cnt[s[x]]--;
	ans -= cnt[s[x]^k];
}

void add2(int x){
	x--;
	ans += cnt[s[x]^k];
	cnt[s[x]]++;
}

void remove2(int x){
	x--;
	cnt[s[x]]--;
	ans -= cnt[s[x]^k];
}

int main(){
	sd3(n,m,k);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	
	s[1] = a[1];
	for(int i = 2; i <= n; i++){
		s[i] = s[i-1]^a[i];
	}
	
	int l, r;
	for(int i = 0; i < m; i++){
		sd2(l,r);
		q[i] = {l,r,i};
	}
	
	sort(q, q+m);
	
	l = q[0].l+1, r = q[0].l-1;
	for(int i = 0; i < m; i++){
		int ll = q[i].l, rr = q[i].r;
		while(l < ll) remove2(l++);
		while(l > ll) add2(--l);
		while(r < rr) add(++r);
		while(r > rr) remove(r--);
		res[q[i].id] = ans;
	}
	
	for(int i = 0; i < m; i++){
		printf("%I64d\n", res[i]);
	}
	
	
	return 0;
}

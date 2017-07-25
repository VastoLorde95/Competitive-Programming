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

const int LOGN = 17;
const int N = 100100;
const int Q = 5010;

struct seg{
	int l, r, mx;
	double p, dp[Q];
};

bool comp(const seg &s1, const seg &s2){
	if(s1.l == s2.l) return s1.r > s2.r;
	return s1.l < s2.l;
}

int n, q;

seg s[Q];
int a[N];

vector<int> g[Q];

int sp[LOGN][N], k[N], o[N];

void sparseTable(){
	
	for(int i = 1; i <= n; i++) sp[0][i] = a[i];
	
	for(int j = 1; j < LOGN; j++)
		for(int i = 1; (i+(1<<j)-1) <= n; i++)
			sp[j][i] = max(sp[j-1][i], sp[j-1][i+(1<<(j-1))]);
	
	for(int i = 2; i <= n; i++){
		k[i] = k[i-1] + ((i&(i-1)) == 0);
		if(k[i] == k[i-1]) o[i] = o[i-1];
		else o[i] = ((o[i-1]+1)<<1)-1;
	}
	
	return;
}

int rmq(int x, int y){
	int l = y-x+1;
	return max(sp[k[l]][x], sp[k[l]][y-o[l]]);
}

int mx;

void compute(int cur){
	if(g[cur].size() == 0){
		s[cur].dp[0] = 1.0f - s[cur].p;
		for(int i = 1; i <= q; i++) s[cur].dp[i] = 1;
		return;
	}
	
	foreach(it, g[cur]) compute(*it);
	
	double p1, p2;
	for(int i = 0; i <= q; i++){
		p1 = s[cur].p, p2 = 1.0f - s[cur].p;
		foreach(it, g[cur]){
			int j = s[cur].mx - s[*it].mx + i;
			if(j-1 >= 0)
				p1 *= s[*it].dp[min(q,j-1)];
			p2 *= s[*it].dp[min(q,j)];
		}
		if(i == 0) p1 = 0;
		s[cur].dp[i] = p1 + p2;
	}
}

int main(){
	sd2(n,q);
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		mx = max(mx, a[i]);
	}
	
	for(int i = 1; i <= q; i++){
		int l, r; double p;
		scanf("%d%d%lf", &s[i].l, &s[i].r, &s[i].p);
	}

	s[0].l = 0, s[0].r = n+1, s[0].p = 0, s[0].mx = mx;

	sort(s+1, s+q+1, comp);

	stack<int> st;
	st.push(0);
	for(int i = 1; i <= q; i++){
		while(!st.empty() and s[st.top()].r < s[i].l) st.pop();
		g[st.top()].pb(i);
		st.push(i);
	}
	
	sparseTable();
	
	for(int i = 1; i <= q; i++) s[i].mx = rmq(s[i].l, s[i].r);
	
	compute(0);

	double res = s[0].dp[0] * mx;
	for(int i = 1; i <= q; i++) res += (s[0].dp[i] - s[0].dp[i-1]) * (mx+i);
	
	printf("%.11lf\n", res);
	
	return 0;
}

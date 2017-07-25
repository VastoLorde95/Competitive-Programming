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

const int LOGN = 20;
const int N = 1 << (LOGN);

int n, K;
int v[N], c[N], k[N], o[N];
int maxv[LOGN][N];
int minc[LOGN][N];

void sparseTable(){
	for(int j = 1; j < LOGN; j++){
		int up = 1 << j;
		for(int i = 1; (i+up-1) <= n; i++){
			maxv[j][i] = max(maxv[j - 1][i], maxv[j - 1][i + (1 << (j - 1))]);
			minc[j][i] = min(minc[j - 1][i], minc[j - 1][i + (1 << (j - 1))]);
		}
	}
	
	for(int i = 2; i <= n; i++){
		k[i] = k[i-1] + ((i&(i-1)) == 0);
		if(k[i] == k[i-1]) o[i] = o[i-1];
		else o[i] = ((o[i-1]+1)<<1)-1;
	}
	
	return;
}

int maxVisitors(int x, int y){
	int l = y-x+1;
	return max(maxv[k[l]][x], maxv[k[l]][y-o[l]]);
}

int minRevenue(int x, int y){
	int l = y-x+1;
	return min(minc[k[l]][x], minc[k[l]][y-o[l]]);
}

vector<int> p;

int get(int x, int y){
	if(y < x or y > n) return 0;
	int v1 = maxVisitors(x,y);
	int v2 = minRevenue(x,y);
	return min(v1,v2);
}

int main(){
	sd2(n,K);
	
	for(int i = 1; i <= n; i++){
		sd(v[i]);
		v[i] *= 100;
		maxv[0][i] = v[i];
	}
	
	for(int i = 1; i <= n; i++){
		sd(c[i]);
		minc[0][i] = c[i];
	}

	sparseTable();

	for(int i = 1; i <= n; i++){
		if(c[i] <= v[i]){
			p.pb(c[i]);
			continue;
		}
		
		int lo = i, hi = n+1, mid;
		while(lo+1 < hi){
			mid = (lo + hi) >> 1;
			int x = maxVisitors(i, mid);
			int y = minRevenue(i, mid);
			
			if(x < y) lo = mid;
			else hi = mid;
		}
		
		p.pb(max(get(i,lo),get(i,hi)));
		
	}
	
	sort(p.begin(), p.end());
	
	double ans = 0, prob = (double) K / (double) n;
	for(int i = 0; i+K-1 < n; i++){
		if(i == 0){
			ans += prob * p[i];
		}
		else{
			prob *= n-i-K+1;
			prob /= n-i;
			ans += prob * p[i];
		}
	}

	printf("%.11lf\n", ans);
	
	return 0;
}

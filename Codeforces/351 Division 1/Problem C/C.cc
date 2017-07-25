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

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 200100;
const int K = 51;
const ld INF = 1e18;

struct line{
	ld m, c;
	ld get(ld x){
		return m*x + c;
	}
};

// can be used only when queries are in incrasing order of x co-ordinate
line st[N];
ld pos[N];
int top, ptr;
struct convexHull{
	
	double x_intersection(const line &l1, const line &l2){ // Careful! if slopes are equal, then this is not defined!
		assert(l1.m != l2.m);
		return ((double)(l2.c-l1.c))/(l1.m-l2.m);
	}
	
	convexHull(){
		top = ptr = 0;
	}
	
	void insert(ld m, ld c){
		line l = {m, c};
		ld x;
		
		while(top > 1){	// if there are two lines in the hull before insertion of this line, try to improve the hull 
			x = x_intersection(st[top-2], l);
			if(x > pos[top-1]) break;
			--top;
		}
		
		st[top++] = l;
		if(top > 1) // if there is more than one line in the hull after insertion of the current line
			pos[top-1] = x_intersection(st[top-1], st[top-2]);
		return;
	}
	
	ld query(ld x){
		while(ptr < top-1 and pos[ptr+1] <= x) ptr++; // find the line whose range straddles point x
		return st[ptr].get(x);
	}
};

int n, k;
int t[N];

ll sum[N];
ld score[N];
ld inv[N];

ld dp[N][K];

int main(){
	sd2(n,k);
	
	for(int i = 1; i <= n; i++){
		sd(t[i]);
	}

	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + t[i];
		inv[i] = inv[i-1] + (ld) 1.0 / t[i];
		score[i] = score[i-1] + (ld) sum[i] / (ld) t[i];
	}
	
	convexHull hull;
	
	for(int i = 1; i <= n; i++){
		dp[i][1] = score[i];
	}
	
	
	
	for(int j = 2; j <= k; j++){
		convexHull hull = *(new convexHull());
		
		for(int i = 1; i <= n; i++){
			if(i >= j){
				dp[i][j] = score[i] + hull.query(inv[i]);
			}
			else{
				dp[i][j] = INF;
			}
			
			hull.insert(-sum[i], dp[i][j-1] - score[i] + inv[i] * sum[i]);
		}
	}
	
	printf("%.11lf\n", (double) dp[n][k]);
		
	
	return 0;
}

#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int N = 100010;
const ull base = 31;

ull pwr[N];

int n, k;

char s[N];
ull h1[N], h2[N];

#define getHash1(x,y) ((h1[(y)+1])-((h1[(x)])*(pwr[(y)-(x)+1])))
#define getHash2(x,y) ((h2[(x)+1])-((h2[(y)+2])*(pwr[(y)-(x)+1])))

void preprocess(){
	h1[0] = 0; for(int i = 1; i <= n; i++) h1[i] = h1[i-1] * base + s[i-1];
	h2[n+1] = 0; for(int i = n; i > 0; i--) h2[i] = h2[i+1] * base + s[i-1];
}

ll ans;
void odd(){
	for(int i = 0; i < n; i++){
		int lo = 1, hi = min(i+1, n-i) + 1, mid;
		while(lo + 1 < hi){
			mid = (lo + hi) >> 1;
			if(getHash1(i, i+mid-1) == getHash2(i-mid+1, i)) lo = mid;
			else hi = mid;
		}
		
		int x = i - lo + 1, y = i + lo - 1;
		
		for(int j = 1; j <= k; j++){
			if(x-1 < 0 or y+1 >= n) break;
			x--, y++;
						
			int tx = x - 1, ty = y + 1;
			
			if(tx < 0 or ty >= n) break;
			
			int lo = 0, hi = min(tx+1, n-y) + 1 , mid;
			
			while(lo + 1 < hi){
				mid = (lo + hi) >> 1;
				if(getHash1(ty, ty+mid-1) == getHash2(tx-mid+1, tx)) lo = mid;
				else hi = mid;
			}
			
			x = tx - lo + 1, y = ty + lo - 1;
		}
		
		ll tmp = (y - x + 2) >> 1;
		ans += tmp * tmp;
	}
}

void even(){
	for(int i = 1; i < n; i++){
		int lo = 0, hi = min(i, n-i) + 1, mid;
		while(lo + 1 < hi){
			mid = (lo + hi) >> 1;
			if(getHash1(i, i+mid-1) == getHash2(i-mid, i-1)) lo = mid;
			else hi = mid;
		}
		
		int x = i - lo , y = i + lo - 1;
		
		for(int j = 1; j <= k; j++){
			if(x-1 < 0 or y+1 >= n) break;
			x--, y++;
		
			int tx = x - 1, ty = y + 1;
			
			if(tx < 0 or ty >= n) break;
			
			int lo = 0, hi = min(tx+1, n-y) + 1 , mid;
			
			while(lo + 1 < hi){
				mid = (lo + hi) >> 1;
				if(getHash1(ty, ty+mid-1) == getHash2(tx-mid+1, tx)) lo = mid;
				else hi = mid;
			}
			
			x = tx - lo + 1, y = ty + lo - 1;
		}
		
		ll tmp = (y - x + 1) >> 1;
		ans += tmp * (tmp + 1);
	}
}

void solve(){
	scanf("%d%d%s", &n, &k, s);
	
	preprocess();
	
	ans = 0;
	
	odd();
	even();
	
	printf("%lld\n", ans);
}

int main(){
	pwr[0] = 1;
	for(int i = 1; i < N; i++) pwr[i] = pwr[i-1] * base;
	
	int t; sd(t);
	while(t--) solve();
	return 0;
}

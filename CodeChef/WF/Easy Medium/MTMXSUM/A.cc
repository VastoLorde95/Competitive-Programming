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

const int MOD = 1e9 + 7;
const int N = 100100;

int a[N];
int b[N];

int dp1[N];
int dp2[N];

int l1[N], l2[N];
int r1[N], r2[N];

int n;

vector<pii> events[N];

void add(int &x, int y){
	x += y;
	if(x >= MOD) x -= MOD;
}

void sub(int &x, int y){
	x -= y;
	if(x < 0) x += MOD;
}

void get(int a[], int L[], int R[], int dp[]){
	stack<int> s;
	
	L[1] = 0;
	s.push(1);
	
	for(int i = 2; i <= n; i++){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		if(!s.empty()) L[i] = s.top();
		else L[i] = 0;
		s.push(i);
	}
	
	while(!s.empty()) s.pop();
	
	R[n] = n+1;
	s.push(n);
	
	for(int i = n-1; i > 0; i--){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		if(!s.empty()) R[i] = s.top();
		else R[i] = n+1;
		s.push(i);
	}
	
	for(int i = 1; i <= n; i++){
		events[i].clear();
	}
	
	for(int i = 1; i <= n; i++){
		int x = i - L[i];
		int y = R[i] - i;
		int len = x + y - 1;
		
		int mn = min(x, y);
		int mx = max(x, y);
		
		events[len].pb(mp(i, 0));
		events[mx-1].pb(mp(i, 1));
		events[mn-1].pb(mp(i, 2));
	}
	
	int s1 = 0, s2 = 0, s3 = 0;
	int sum = 0;
	
	for(int k = n; k >= 1; k--){
		for(pii &p : events[k]){
			int id = p.fi, t = p.se;
			
			if(t == 0){
				add(s1, a[id]);
			}
			else if(t == 1){
				sub(s1, a[id]);
				add(s2, a[id]);
			}
			else{
				sub(s2, a[id]);
				add(s3, a[id]);
			}
		}
		
		add(sum, s1);
		sub(sum, s3);
		
		dp[k] = sum;
	}	
}

int main(){
	sd(n);
	
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		a[i] += i;
	}	
	
	for(int i = 1; i <= n; i++){
		sd(b[i]);
		b[i] += i;
	}

	get(a, l1, r1, dp1);
	get(b, l2, r2, dp2);
	
	for(int i = 1; i <= n; i++)
		printf("%lld ", (1ll * dp1[i] * dp2[i]) % MOD);
	
	printf("\n");
	
	return 0;
}

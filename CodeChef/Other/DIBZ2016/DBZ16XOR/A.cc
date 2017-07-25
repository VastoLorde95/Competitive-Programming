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
const int M = 20;

int n, a[N];
int cnt[N][M];

int l[N], r[N];

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		for(int j = 0; j < M; j++){
			cnt[i][j] = cnt[i-1][j];
			if((a[i]&(1<<j)) > 0) cnt[i][j]++;
		}
	}
	
	stack<int> s;
	s.push(1);	
	
	l[1] = 0;
	
	for(int i = 2; i <= n; i++){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		
		if(s.empty()) l[i] = 0;
		else l[i] = s.top();
		s.push(i);	
	}
	
	while(!s.empty()) s.pop();
	
	s.push(n);
	r[n] = n+1;
	
	for(int i = n-1; i > 0; i--){
		while(!s.empty() and a[s.top()] < a[i]) s.pop();
		if(s.empty()) r[i] = n+1;
		else r[i] = s.top();
		s.push(i);
	}
	
	long long ans = 0;
	for(long long i = 1; i <= n; i++){
		long long x = l[i], y = r[i], t1, t2;
		
		if(y-1-x == 1) continue;
		
		
		
		for(int j = 0; j < M; j++){
			if((a[i]&(1<<j)) > 0){
				t1 = cnt[y-1][j] - cnt[i][j];
				t2 = cnt[i-1][j] - cnt[x][j];
				
				ans += t1*t2*(1ll<<j);
				ans += (y-1-i-t1)*(i-1-x-t2)*(1ll<<j);
				
				ans += t1*(1ll<<j);
				ans += t2*(1ll<<j);
				
			}
			else{
				t1 = cnt[y-1][j] - cnt[i][j];
				t2 = cnt[i-1][j] - cnt[x][j];
				
				ans += t1*(i-1-x-t2)*(1ll<<j);
				ans += (y-1-i-t1)*t2*(1ll<<j);
				
				ans += t1*(1ll<<j);
				ans += t2*(1ll<<j);
			}
		}
	}

	printf("%lld\n", ans);
	
	return 0;
}

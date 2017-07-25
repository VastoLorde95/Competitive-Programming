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

const long double PI = 3.1415926535897932384626433832795;

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

const int N = 101;

int n, k;

int a[N];
int cnt[N];
int len[N];

int main(){
	int t;
	sd(t);
	for(int tt = 1; tt <= t; tt++){
		printf("Case %d\n", tt);
		
		fill(cnt, cnt+N, 0);
		fill(len, len+N, 0);
		
		sd2(n,k);
	
		assert(1 <= n and n <= 100);
	
		for(int i = 1; i <= n; i++){
			sd(a[i]);
		}
	
		set<int> s;
		for(int i = 1; i <= n; i++){
			s.insert(a[i]);
		}
	
		assert(s.size() == n);
	
		cnt[0] = 1;
	
		int lis = 0;
		for(int i = 1; i <= n; i++){
			int mx = 0;
			for(int j = 1; j < i; j++){
				if(a[j] < a[i]){
					mx = max(mx, len[j]);
				}
			}
			len[i] = mx + 1;
			lis = max(lis, len[i]);
		
			if(len[i] == 1){
				cnt[i] = 1;
				continue;
			}
		
			for(int j = 1; j < i; j++){
				if(len[j] == mx and a[j] < a[i]){
					cnt[i] += cnt[j];
				}
			}
		}
	
	
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(len[i] == lis){
				ans += cnt[i];
			}
		}
	
		assert(ans == k);
	}
	
	return 0;
}

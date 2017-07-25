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

const int N = 100100;
const int M = 26;

char s[N];
int k;

int cnt[M];

void solve(){
	scanf("%s %d", s, &k);
	int l = strlen(s);
	
	fill(cnt, cnt+M, 0);
	
	for(int i = 0; i < l; i++){
		cnt[s[i]-'a']++;	
	}
	
	int mx = 0;
	for(int i = 0; i < M; i++){
		mx = max(mx, cnt[i]);
	}
	
	if(mx <= k){
		printf("0\n");
		return;
	}
	
	int ans = 1e9;
	for(int i = mx; i >= k; i--){
		int tot = 0;
		for(int j = 0; j < M; j++){
			if(cnt[j] > i) tot += cnt[j] - i;
			if(cnt[j] < i - k) tot += cnt[j];
		}
		ans = min(ans, tot);
	}
	
	printf("%d\n", ans);
	
}

int main(){
	int t; sd(t);
	while(t--) solve();	
	return 0;
}

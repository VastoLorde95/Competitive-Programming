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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

typedef long long ll;

const int N = 5100;

// z[i] = the length of the longest substring of 's' starting at index 'i' which is at the same time a prefix of the string 's'
int z[N][N];

void build_z(string s, int id){// l, r are the invariant variables => [l,r] is the maximum interval such that s[l,r] is a prefix substring
	int len = s.length(), l = 0, r = 0, k;
	z[id][0] = len;
	
	for(int i = 1; i < len; i++){
		if(r < i){				// make a new interval l,r and find the substring starting at i which is a prefix substring
			l = r = i; 
			while(r < len and s[r-l] == s[r]) r++;
			z[id][i] = r-l; r--;
		}
		else{					// try to expand the current interval by observing the value of z[k]
			k = i-l;
			if(z[id][k] < r-i+1){		// can't be more than z[k] since s[i..R] matches with s[k...z[k]]
				z[id][i] = z[id][k];
			}
			else{				// we can expand the current r since z[k] allows us to do so
				l = i;
				while(r < len and s[r-l] == s[r]) r++;
				z[id][i] = r-l; r--;
			}
		}
	}
	return;	
}

int n;
string s;
ll MOD = 1e9 + 7, dp[N][N], sum[N][N];

int main(){ _
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < n; i++) build_z(s.substr(i, n-i), i);
	
	if(s[0] != '0') dp[0][1] = 1;
	
	for(int j = 1; j < n; j++){
		for(int i = 1; i <= n; i++){
			sum[j-1][i] = sum[j-1][i-1] + dp[j-1][i];
			if(sum[j-1][i] >= MOD) sum[j-1][i] -= MOD;
		}
	
		if(s[j] != '0'){
			if(s[j-1] != '0' and s[j-1] < s[j])
				dp[j][1] = dp[j-1][1];
			else
				dp[j][1] = 0;
		}
		else{
			dp[j][1] = 0;
		}
	
		for(int i = 2; j-i+1 >= 0; i++){
			if(s[j-i+1] == '0'){
				dp[j][i] = 0; continue;
			}
			if(j-i+1 == 0){
				dp[j][i] = 1; continue;
			}
			
			ll t1 = sum[j-i][i-1];
			if(j-i-i+1 < 0){
				dp[j][i] = t1; continue;
			}
			
			if(s[j-i-i+1] == '0'){
				dp[j][i] = t1; continue;
			}
			
			if(z[j-i-i+1][i] >= i){
				dp[j][i] = t1; continue;
			}

			if(s[j-i-i+1 + z[j-i-i+1][i]] < s[j-i+1 + z[j-i-i+1][i]]){
				t1 = (t1 + dp[j-i][i]) %MOD;
			}
			
			dp[j][i] = t1;
		}
	}
	
	long long res = 0;
	for(int i = 1; i <= n; i++){
		res += dp[n-1][i];
		res %= MOD;
	}
	
	cout << res << endl;
	
	return 0;
}

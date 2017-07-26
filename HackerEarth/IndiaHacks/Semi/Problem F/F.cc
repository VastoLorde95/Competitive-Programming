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

typedef long long ll;
typedef pair<int,int> pii;

long long n, m, p, x;
string s;

void solve(){
	cin >> n >> m >> p >> x;
	cin >> s;
	
	string t = s;
	
	n--;
	
	while(n > 0){
		long long tmp = 1;
		while(tmp <= n) tmp *= 2;
		tmp /= 2;
		
		n -= tmp;
		
		for(long long j = 0; j < m; j++){
			long long k = (j - (tmp*p)%m + m)%m;
			t[j] = (char) ('0' + (s[j]-'0')^(s[k]-'0')^x);
		}
		
		s = t;	
	
	}

	cout << s << endl;
	
}

int main(){ _
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

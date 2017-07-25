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

const int N = 100;
const ll MOD = 1e9 + 7;

ll cnt[100];

vector<int> d;

ll ans;

int main(){ _
	for(int i = 0; i < 64; i++){
		d.pb(i);
	}
	
	for(int i = 0; i < 64; i++){
		for(int j = 0; j < 64; j++){
			cnt[d[i]&d[j]]++;
		}
	}
	
	string s;
	cin >> s;
	
	ans = 1;
	for(int i = 0; i < s.length(); i++){
		if('0' <= s[i] and s[i] <= '9'){
			ans = ans * cnt[s[i]-'0'] % MOD;
		}
		else if('A' <= s[i] and s[i] <= 'Z'){
			ans = ans * cnt[s[i] - 'A' + 10] % MOD;
		}
		else if('a' <= s[i] and s[i] <= 'z')
			ans = ans * cnt[s[i] - 'a' + 36] % MOD;
		else if(s[i] == '-')
			ans = ans * cnt[62] % MOD;
		else
			ans = ans * cnt[63] % MOD;
		
	}
	tr(ans);
	
	return 0;
}

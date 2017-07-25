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

ll b[2] = {31, 29};
ll p[2] = {(ll)1e9 + 7, (ll) 1e9 + 9};
ll h1[2], h2[2];
ll pw[2];

int n;
string s, t;

int r[255];

int main(){ _
	cin >> n; n--;
	cin >> s >> t;
	
	r['N'] = 'S', r['S'] = 'N', r['E'] = 'W', r['W'] = 'E';
	
	pw[0] = pw[1] = 1;
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 2; j++){
			h1[j] = (h1[j] + (pw[j] * s[i])) % p[j];
			h2[j] = ((h2[j] * b[j])  + r[t[i]]) % p[j];
			pw[j] = pw[j] * b[j] % p[j];
		}
		
		if(h1[0] == h2[0] and h1[1] == h2[1]){
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	
	return 0;
}

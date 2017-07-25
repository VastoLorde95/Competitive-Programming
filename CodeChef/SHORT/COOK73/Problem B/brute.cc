#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
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

void solve(){
	int n; cin >> n;
	int c[n];
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}	
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		v.pb(i);
	}
	
	ll ans = 0;
	
	do{
		bool ok = true;
		for(int i = 0; i < n; i++){
			int len = 0;
			for(int j = i+1; ;j++){
				if(j == n or v[j] > v[i]){
					len = j - i - 1;
					break;
				}
			}
			if(len != c[i]){
				 ok = false;
				 break;
			}
		}
		
		if(ok) ans++;
		
	}while(next_permutation(v.begin(), v.end()));
	
	cout << ans << endl;
}

int main(){ _
	int t; cin >> t; while(t--) solve();
	return 0;
}

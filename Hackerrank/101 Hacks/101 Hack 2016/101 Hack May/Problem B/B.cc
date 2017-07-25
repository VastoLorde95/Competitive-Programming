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

const int N = 3100;

int n;
ll a[N];

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 30; i >= 0; i--){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if((a[j] & (1ll << i)) > 0) cnt++;
		}
		if(cnt == 0 or cnt == n) continue;
		
		vector<ll> v1;
		vector<ll> v2;	
		
		for(int j = 0; j < n; j++){
			if((a[j] & (1ll << i)) > 0) v1.pb(a[j]);
			else v2.pb(a[j]);
		}
		
		ll mx = 1ll << 50;
		foreach(it1, v1){
			foreach(it2, v2){
				mx = min(mx, *it1 ^ *it2);
			}
		}
		
		cout << mx << endl;
		return 0;
	}	
	
	cout << 0 << endl;
	
	return 0;
}

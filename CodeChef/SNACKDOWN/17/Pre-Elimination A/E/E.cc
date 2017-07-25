#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<math.h>
#include<cstdlib>
#include<map>
#include<utility>
#include<stack>
#include<fstream>
#include<set>
#include<queue>
#include<iomanip>

using namespace std;

#define ll long long int
#define ld long double

const ll inf = 100000000000005;
const ll mod = 1e9+7;

#define cincout ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define me(a,i) memset(a,i,sizeof(a))
#define mp make_pair
#define VLL vector <ll>
#define PLL pair <ll,ll>
#define VLD vector <ld>
#define pb push_back
#define sortv(v) sort(v.begin(),v.end())
#define sortvd(v) sort(v.begin(),v.end(),greater<int>())
#define printv(n,v) for(int i=0;i<n;i++)  {cout<<v[i]<<" ";}
#define vin(v,n,a) for(int i=0;i<n;i++)	{v.pb(a);cin>>v[i];}
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FORFE(i,a,b) for (int i = (a); i <= (b); i++)
#define FORDE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORF(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (a); i > (b); i--)

vector<pair<ll,ll> > ver,hor;

ll n,k,m,hx,hy,tx,ty,ans=0;

void solve(vector<pair<ll,ll> > po){
	ll cur = ((n-k)/2)+1, en = cur+k-1, mx=-1;
	
	for(int i = 0; i < po.size(); i++){
//		cout << cur << ' ' << po[i].first << ' ' << po[i].second << ' ' << ans << endl;
		
		if(po[i].first <= cur && po[i].second >= cur)
			mx = max(mx, po[i].second);
		else if(po[i].first > cur && mx == -1){
			ans = -1;
			return;
		}
		else if(po[i].first > cur){
			cur = mx + 1;
			mx = -1;
			ans++;
			i--;	
			if(cur > en)
				break;		
		}
	}
	if(cur <= en && mx < en)
		ans=-1;
	else if(cur <= en && mx >= en)
		ans++;
		
//	cout << ans << endl;
}
	
int main() { cincout;
	int t;
	cin >> t;
	while(t--) {
		ans = 0;
		ver.clear();
		hor.clear();
		
		cin >> n >> k >> m;
		
		for(int i = 0; i < m; i++){
			cin >> hx >> hy >> tx >> ty;
			if(hx == tx){
				if(hy > ty) swap(hy, ty);
				hor.pb(mp(hy,ty));
				ver.pb(mp(hx,hx));
			}
			if(hy == ty){
				hor.pb(mp(hy,hy));
				if(hx > tx) swap(hx, tx);
				ver.pb(mp(hx,tx));
			}
		}
		
		sortv(hor);
		sortv(ver);
		
		solve(hor);
		if(ans == -1)
			cout << -1 << endl;
		else{
			solve(ver);
			cout << ans << endl;
		}
	}
  	return 0;
}

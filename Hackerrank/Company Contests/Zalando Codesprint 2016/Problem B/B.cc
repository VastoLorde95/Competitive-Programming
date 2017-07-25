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

const int N = 1001000;

int n;
map<ll, int> h;

vector<pair<ll,ll> > v;

int main(){ _
	cin >> n;
	
	int t, l = 0, r = 0;
	
	ll p, tt;
	
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t == 1){
			cin >> p >> tt;
			v.pb(mp(p,tt));
			h[p]++;
		}
		else{
			cin >> tt;
			while(l < v.size()	and v[l].se + 59 < tt){
				h[v[l].fi]--;
				if(h[v[l].fi] == 0){
					h.erase(v[l].fi);	
				}
				l++;
			}	
			if(h.empty()) cout << -1 << '\n';
			else
				cout << h.rbegin()->fi << '\n';
		}
		
	}
	
	
	return 0;
}

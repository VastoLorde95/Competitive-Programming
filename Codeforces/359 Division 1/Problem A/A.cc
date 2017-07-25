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

int d1, d2;
ll cntt;
ll n, m;

int main(){
	cin >> n >> m;

	ll tn = n-1;
	ll tm = m-1;
	while(tn){
		d1++;
		tn /= 7;
	}
	while(tm){
		d2++;
		tm /= 7;
	}

	if(n == 1) d1 = 1;
	if(m == 1) d2 = 1;
	
	int l = d1+d2;
	for(int i = 0; i < 1<<7; i++){
		int cnt = 0;
		vector<int> v;
		for(int j = 0; j < 7; j++){
			if(i&(1<<j)){
				cnt++;
				v.pb(j);
			}
		}
		if(cnt != l) continue;
		
		vector<int> p;
		for(int j = 0; j < l; j++){
			p.pb(j);
		}
		
		do{
			vector<int> k = v;			
			for(int j = 0; j < k.size(); j++){
				v[j] = k[p[j]];
			}
			
			ll x = 0;
			for(int j = 0; j < d1; j++){
				x *= 7;
				x += v[j];
			}
			ll y = 0;
			for(int j = d1; j < l; j++){
				y *= 7;
				y += v[j];
			}
			if(x < n and y < m){
				cntt++;
			}
			v = k;
			
		}while (next_permutation(p.begin(), p.end()));
		
	}

	tr(cntt);		
	
	return 0;
}

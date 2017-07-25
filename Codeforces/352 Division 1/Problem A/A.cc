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
typedef pair<ll,ll> pii;

const int N = 100100;

ll ax, ay, bx, by, tx, ty;
int n;

ll sqr(ll x){
	return x*x;
}


long double dist(pii p1, pii p2){
	return (long double) sqrt(sqr(p1.fi-p2.fi) + sqr(p1.se-p2.se));
}

long double dis1[N], dis2[N], dis3[N];
long double cost;

int main(){ _
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	cin >> n;
	
	vector<pii> v;
	ll x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.pb(mp(x,y));
		
		dis1[i] = dist(v[i], mp(tx,ty));
		dis2[i] = dist(v[i], mp(ax,ay));
		dis3[i] = dist(v[i], mp(bx,by));
		
		cost += dis1[i] * 2;
	}
	
	long double inf = 2e9;	
	if(n == 1){
		long double mn = inf;
		for(int i = 0; i < n; i++){
			mn = min(mn, min(dis2[i], dis3[i]) - dis1[i]);
		}
		cost += mn;
		cout << setprecision(11) << fixed << cost << endl;
		return 0;
	}	
	else{
		long double a1 = inf;
		int id1 = -1;
		long double a2 = inf;
		int id2 = -1;
		
		for(int i = 0; i < n; i++){
			long double val = dis2[i] - dis1[i];
			if(val < a1){
				a2 = a1;
				id2 = id1;
				
				a1 = val;
				id1 = i;
			}
			else if(val <= a2){
				a2 = val;
				id2 = i;
			}
		}
		
		long double a3 = inf;
		int id3 = -1;
		long double a4 = inf;
		int id4 = -1;
		
		for(int i = 0; i < n; i++){
			long double val = dis3[i] - dis1[i];
			if(val < a3){
				a4 = a3;
				id4 = id3;
				
				a3 = val;
				id3 = i;
			}
			else if(val <= a4){
				a4 = val;
				id4 = i;
			}
		}
		
		if(id1 != id3){
			if(a1 < 0 and a3 < 0) cost += a1 + a3;
			else cost += min(a1, a3);
		}
		else{
			long double z = 0;
		 	cost += min(min(a1 + a4, a2 + a3), min(min(a3, a4), min(a1, a2)));
		}
		cout << setprecision(11) << fixed << cost << endl;
	}
	
	return 0;
}

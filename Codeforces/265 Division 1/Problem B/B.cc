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

const int N = 8;

struct point{
	ll x, y, z;
};

inline ll sqr(ll x){ return x * x; }

ll dist(point &p1, point &p2){
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y) + sqr(p1.z - p2.z);
}

bool check(vector<point> &p){
	map<ll, int> cnt;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			cnt[dist(p[i], p[j])]++;
		}
	}
	
	if(cnt.size() != 3) return false;
	
	vector<pair<ll, int> > d;
	foreach(it, cnt) d.pb(*it);
	
	if(d[0].se != 12) return false;
	if(d[1].se != 12) return false;
	if(d[2].se != 4)  return false;
	if(d[1].fi != d[0].fi*2 or d[2].fi != d[0].fi * 3) return false;
	
	return true;
}

vector<point> p(N);
vector<point> q;

void gen(int x){
	if(x == N){
		if(check(q)){
			cout << "YES\n";
			
			for(int i = 0; i < N; i++){
				cout << q[i].x << ' ' << q[i].y << ' ' << q[i].z << '\n';
			}
			
			exit(0);
		}
		return;
	}
	
	vector<int> f;
	for(int i = 0; i < 3; i++) f.pb(i);
	
	vector<ll> c = {p[x].x, p[x].y, p[x].z};
	
	do{
		point pt;
		pt.x = c[f[0]];
		pt.y = c[f[1]];
		pt.z = c[f[2]];
		
		q.pb(pt);
		gen(x+1);
		q.pop_back();
		
	} while(next_permutation(f.begin(), f.end()));
}

int main(){ _
	for(int i = 0; i < N; i++){
		cin >> p[i].x >> p[i].y >> p[i].z;
	}
	
	q.pb(p[0]);
	gen(1);
	
	puts("NO");
	
	return 0;
}

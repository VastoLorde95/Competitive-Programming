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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

typedef pair<int,int> pii;
typedef long double ld;

const int N = 100100, M = 10010;

int n, m, inf = 1e9;
vector<pair<pii,pii> > t;
vector<pii> mush;
ld p[M];
int zero[M];

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		int a, h, l, r;
		sd2(a,h); sd2(l,r);
		t.pb(mp(mp(a,h),mp(l,r)));
	}
	
	for(int i = 0; i < m; i++){
		int b, z; sd2(b,z);
		mush.pb(mp(b,z));
		p[i] = 1;
	}
	
	sort(t.begin(), t.end());
	sort(mush.begin(), mush.end());
	
	int id1, id2;
	for(int i = 0; i < n; i++){
		int a = t[i].fi.fi, h = t[i].fi.se;
		ld l = (ld) t[i].se.fi / 100.0f, r = (ld) t[i].se.se / 100.0f;
		id1 = upper_bound(mush.begin(), mush.end(), mp(a,inf)) - mush.begin();
		id2 = upper_bound(mush.begin(), mush.end(), mp(a+h,inf)) - mush.begin();
		if(r < 1){
			p[id1] *= (-r+1.0f);
			p[id2] /= (-r+1.0f);
		}
		else{
			zero[id1] += 1;
			zero[id2] -= 1;
		}
		
		id1 = lower_bound(mush.begin(), mush.end(), mp(a,0)) - mush.begin();
		id2 = lower_bound(mush.begin(), mush.end(), mp(a-h,0)) - mush.begin();
		
		if(l < 1){
			p[id2] *= (-l+1.0f);
			p[id1] /= (-l+1.0f);
		}
		else{
			zero[id2] += 1;
			zero[id1] -= 1;
		}
	}
	
	for(int i = 1; i < m; i++){
		zero[i] += zero[i-1];
		p[i] *= p[i-1];
	}
	
	ld ans = 0;
	for(int i = 0; i < m; i++){
		if(zero[i]) continue;
		ans += p[i] * mush[i].se;
	}
	
	printf("%.7lf\n", (double) ans);
	
	return 0;
}

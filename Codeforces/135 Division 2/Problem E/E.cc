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
#define tr(x) cout<<meta<<#x<<' '<<x<<endl;
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 200100, M = 1000100;

int n, m, l[N], r[N], pos[M], inf = 1e9;
set<pair<int, pair<int, int> > > s;

pair<int,pair<int,int> > get(int x, int y){
	if(x == 0 and y == n+1) return mp(-inf, mp(x, 1));
	if(x == 0) return mp(-(y-1), mp(x, 1));
	if(y == n+1) return mp(-(n-x), mp(x, n));
	return mp(-(y-x)/2, mp(x, (x+y)/2));
}

int main(){
	sd2(n,m);
	r[0] = n+1;
	l[n+1] = 0;
	
	s.insert(mp(-inf, mp(0, 1)));
	
	int t, v;
	for(int i = 0; i < m; i++){
		sd2(t, v);
		if(t == 1){
			pair<int,int> p = s.begin()->se;
			s.erase(s.begin());
			
			int x = p.fi;
			int y = r[x];
			int mid = p.se;
			
			pos[v] = mid;
			printf("%d\n", pos[v]);
			
			r[x] = mid, r[mid] = y;
			l[mid] = x, l[y] = mid;
				
			s.insert(get(x,mid));
			s.insert(get(mid,y));
		}
		else{
			int mid = pos[v];
			int x = l[mid];
			int y = r[mid];
			
			s.erase(get(x,mid));
			s.erase(get(mid,y));
			
			r[x] = y;
			l[y] = x;
			s.insert(get(x,y));
		}
	}	
	return 0;
}

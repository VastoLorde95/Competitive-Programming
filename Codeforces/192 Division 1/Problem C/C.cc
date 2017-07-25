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

const int N = 100100;

set<pair<int,int> > s;
int n, m;
vector<int> x;
int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		x.pb(i);
	}	

	int u, v;
	for(int i = 0; i < m; i++){
		sd2(u,v);
		s.insert(mp(u,v));
		s.insert(mp(v,u));
	}
	
	bool ok = false;
	int cnt = 0;
	for(int i = 0; i < 50; i++){
		random_shuffle(x.begin(), x.end());
		cnt = 0;
		for(int j = 1; j < n; j++){
			if(!s.count(mp(x[j], x[j-1]))) cnt++;
		}
		if(n > 2 and !s.count(mp(x[n-1],x[0]))) cnt++; 
		if(cnt >= m){
			ok = true;
			break;
		}
	}
	
	if(!ok) puts("-1");
	else{
		int j = 0;
		for(int i = 1; i < n and j < m; i++){
			if(!s.count(mp(x[i-1],x[i]))){
				printf("%d %d\n", x[i-1], x[i]);
				j++;
			}
		}
		if(j < m){
			printf("%d %d\n", x[0], x[n-1]);
		}
	}
	return 0;
}

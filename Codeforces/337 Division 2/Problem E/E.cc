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
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

const int N = 200100, M = 20010, K = 11;

typedef pair<int,int> pii;

int n, m, k, inf = 1e9;
int cnt[256][256];
char s[N];

set<pair<pii, char> > seg;
set<pair<pii, char> >::iterator it1, it2;

int main(){
	sd3(n,m,k);
	scanf("%s", s);
	
	int l = 0;
	for(int i = 1; i < n; i++){
		if(s[i] != s[i-1]){
			seg.insert(mp(mp(l,i-1), s[i-1]));
			l = i;
			cnt[s[i-1]][s[i]]++;
		}
	}
	seg.insert(mp(mp(l,n-1),s[n-1]));
	
	int type, r, res;
	char p[K], c;
	while(m--){
		sd(type);
		if(type == 1){
			scanf(" %d %d %c", &l, &r, &c);
			l--, r--;
			it2 = it1 = seg.lower_bound(mp(mp(l,0),'a'));
			it2--;
			
			vector<pair<pii, char> > v1, v2;
			v1.pb(mp(mp(l,r),c));
			
			while(it1 != seg.end()){
				if(it2->fi.se > r){
					v2.pb(*it2);
					v1.pb(mp(
				}
				
				if(it2->fi.se >= l and it2->fi.se <= r){
					if(it1->se != it2->se) cnt[it2->se][it1->se]--;
				}
				
				if(it2->fi.fi < l and it2->fi.se >= l){
					v2.pb(*it2);
					if(it2->se != c) cnt[it2->se][c]++;
					v1.pb(mp(mp(it2->fi.fi, l-1),it2->se));
				}
				else if(it2->fi.fi < l and it2->fi.se == l-1){
					if(it2->se != c) cnt[it2->se][c]++;
				}
				else if(it2->fi.fi >= l){
					v1.
				}
				
								
				
				
				it1++;
				it2++;			
			}
			
			foreach(it, v2) seg.erase(*it);
			foreach(it, v1) seg.insert(*it);
		}
		else{
			scanf("%s", p);
			res = 0;
			for(int i = 0; i < k; i++) for(int j = 0; j < i; j++) res += cnt[p[i]][p[j]];
			printf("%d\n", res);
		}
	}
	
	
	
	return 0;
}

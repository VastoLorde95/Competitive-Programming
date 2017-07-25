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

const int N = 100100;

int n, t, x, y;
pair<int,int> s[N];
vector<int> a, b;

int main(){
	sd(n);
	
	t = (n+2)/3;
	
	for(int i = 0; i < n; i++){
		sd(s[i].fi); s[i].se = i;
	}
	
	sort(s, s+n);
	
	if(n == 1){
		puts("YES");
		printf("%d\n%d\n", s[0].fi, 0);
		return 0;
	}
	
	int m1 = s[t].fi;	
	int m2 = s[2*t].fi;

	a.resize(n,0);
	b.resize(n,0);
	
	for(int i = 0; i < n; i++){
		int id = s[i].se;
		if(i < t){
			a[id] = i;
			b[id] = s[i].fi-i;
		}
		else if(i >= t and i < 2*t){
			a[id] = s[i].fi-i; 
			b[id] = i;
		}
		else{
			a[id] = s[i].fi-n+1+i;
			b[id] = n-1-i;
		}
	}
		
	
	
	puts("YES");
	foreach(it, a) printf("%d ", *it); puts("");
	foreach(it, b) printf("%d ", *it); puts("");
	
	return 0;
}

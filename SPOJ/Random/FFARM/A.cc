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

const int N = 1100;

int palin[N], next[N];

int ispalin(int x){
	int rev = 0, o = x;
	while(x > 0){
		rev = rev*10 + x%10;
		x /= 10;
	}
	return (rev == o);
}

int t, a, b, l, inf = 1e9;

int main(){
	for(int i = 1; i < N; i++) palin[i] = ispalin(i);
	next[N-1] = inf;
	for(int i = N-2; i > 0; i--) next[i] = (palin[i+1] == 1)? i+1 : next[i+1];
		
	sd(t);
	while(t--){
		sd3(a,b,l);
		int cnt = 0, mx = 0;
		int x = (palin[a] == 1)? a : next[a], y = x;
		int len = 0;
		
		if(x > b){
			puts("Barren Land.");
			continue;
		}
		
		int bx = x, by = y;
		
		while(y <= b){
		
			while(y-x+1 > l){
				x = next[x];
				cnt--;
			}
			
			cnt++;
			if(cnt > mx){
				mx = cnt;
				bx = x, by = y;
				len = by-bx+1;
			}
			else if(cnt == mx and y-x+1 < len){
				bx = x, by = y;
				len = by-bx+1;
			}
			
			y = next[y];
		}
		
		printf("%d %d\n", bx, by);
		
	}
	return 0;
}

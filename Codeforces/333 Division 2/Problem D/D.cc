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

int n, q;
int h[N], d[N];
int x[N], y[N];
stack<int> s;

int main(){
	sd2(n,q);
	for(int i = 0; i < n; i++){
		sd(h[i]);
	}
	
	for(int i = 0; i < n-1; i++){
		d[i] = abs(h[i+1]-h[i]);
	}	
	
	int l, r;
	while(q--){
		sd2(l, r);
		
		if(l == r){
			printf("0\n");
			continue;
		}
		
		l--, r -= 2;
		
		s.push(l);
		x[l] = l-1;
		for(int i = l+1; i <= r; i++){
			while(!s.empty() and d[s.top()] <= d[i]) s.pop();
			if(s.empty()){
				x[i] = l-1;
			}
			else{
				x[i] = s.top();
			}
			s.push(i);
		}
		
		while(!s.empty()) s.pop();
		
		s.push(r);		
		y[r] = r+1;
		for(int i = r-1; i >= l; i--){
			while(!s.empty() and d[s.top()] < d[i]) s.pop();
			if(s.empty()){
				y[i] = r+1;
			}
			else{
				y[i] = s.top();
			}
			s.push(i);
		}
		
		while(!s.empty()) s.pop();
		
		long long ans = 0;
		for(int i = l; i <= r; i++){
			long long t1 = i-x[i];
			long long t2 = y[i]-i;
			
//			tr6(i, x[i], y[i], d[i], t1, t2);
			
			ans += t1*t2*d[i];
		}
		
		cout << ans << '\n';
	}
	
	
	return 0;
}

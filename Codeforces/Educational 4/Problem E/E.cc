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

const int N = 1001000;

int n;
int p[N], q[N], v[N];
vector<vector<int> > cycles[N];

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
	}
	
	if(n == 1){
		puts("1");
		return 0;
	}
	
	int tot = 0;
	vector<int> c;
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			c.clear();
			int cur = i;
			while(!v[cur]){
				v[cur] = 1;
				c.pb(cur);
				cur = p[cur];
			}
			
			cycles[c.size()].pb(c);
			tot++;
		}
	}
	
	for(int k = 1; k <= n; k++){
		if(cycles[k].empty()) continue;
		if(k == 1){
			for(int j = 0; j < cycles[k].size(); j++){
				q[cycles[k][j][0]] = cycles[k][j][0];
			}
		}
		else if(k%2 == 0 and cycles[k].size()%2 == 1){
			puts("-1");
			return 0;	
		}
		else if(k%2 == 0){
			int x = 0, y = 1;
			while(y < cycles[k].size()){
				for(int j = 0; j < k; j++){
					if(j == k-1){
						q[cycles[k][x][j]] = cycles[k][y][j];
						q[cycles[k][y][j]] = cycles[k][x][0];
					}
					else{
						q[cycles[k][x][j]] = cycles[k][y][j];
						q[cycles[k][y][j]] = cycles[k][x][j+1];
					}
				}
				x += 2;
				y += 2;
			}
		}
		else{
			for(int j = 0; j < cycles[k].size(); j++){
				c = cycles[k][j];
				int jump = (k+1)/2;
				for(int i = 0; i < k; i++){
					if(i+jump < k){
						q[c[i]] = c[i+jump];
					}
					else{
						q[c[i]] = c[(i+jump)%k];
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", q[i]);
	}
	puts("");
	
	return 0;
}

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

using namespace std;

int n, p[100100], v[1001000];
vector<pair<int,int> > e;

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
	}
	
	for(int i = 1; i <= n; i++){
		if(p[i] == i){
			printf("YES\n");
			for(int j = 1; j <= n; j++){
				if(j != i){
					printf("%d %d\n", i,j);
				}
			}
			return 0;
		}
	}
	
	int x = -1, y = -1;
	
	for(int i = 1; i <= n; i++){
		if(p[p[i]] == i){
			x = i, y = p[i];
		}	
	}
	
	if(x == -1){
		printf("NO\n"); return 0;
	}
	
	v[x] = v[y] = 1;
	e.pb(mp(x,y));
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			int len = 1;
			e.pb(mp(x,i));
			v[i] = 1;
			for(int j = p[i]; j != i; j = p[j]){
				len++;
				v[j] = 1;
				if(len%2)
					e.pb(mp(x,j));
				else
					e.pb(mp(y,j));
			}
			
			if(len&1){
				printf("NO\n"); return 0;
			}
		}
	}
	
	
	printf("YES\n");
	foreach(edge, e){
		printf("%d %d\n", edge->fi, edge->se);
	}
	
	return 0;
}

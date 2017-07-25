#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, p[3001], v[3001], m, cnt;

void visit(int cur){
	if(v[cur]) return;
	v[cur] = 1;
	visit(p[cur]);
	return;
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
	}
	
	sd(m);
	
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			visit(i);
			cnt++;
		}
	}
	
	memset(v, 0, sizeof v);
	
	m = n - m;		
//	tr(cnt);
	printf("%d\n", abs(m-cnt));
	
	if(m < cnt){
		visit(1);
		for(int i = 2; i <= n and cnt > m; i++){
			if(!v[i]){
				visit(i);
				printf("%d %d ", 1, i);
				cnt--;
			}
		}
	}
	else if(m > cnt){
		for(int i = 1; i <= n and m > cnt; i++){
			vector<int> pos(n+1, -1); int cur = 0;
			
			for(int j = p[i]; j != i; j = p[j]) pos[j] = cur++;
			pos[i] = cur;
			
			cur = 0;
			for(int j = i+1; j <= n and m > cnt; j++){
				if(pos[j] >= cur){
					printf("%d %d ", i, j);
					m--;
					cur = pos[j]+1;
					swap(p[i], p[j]);
				}
			}
		}
	}
		
	return 0;
}

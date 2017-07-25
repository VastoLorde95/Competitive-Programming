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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, a, b, start, prev, cnt, cur, flag;
map<int, vector<int> > in, out;
set<int>::iterator it;
set<int> c;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd2(a,b);
		out[a].pb(b);
		in[b].pb(a);
		c.insert(a);
		c.insert(b);
	}
	
	for(it = c.begin(); it != c.end(); it++){
		if(in[*it].size() + out[*it].size() == 1){
			start = *it;
			break;
		}
	}
	
	cnt = 1;
	
	prev = start;
	
	if(out[start].size() > 0) cur = out[start][0];
	else cur = in[start][0];
	
	printf("%d %d ", prev, cur);
	
	while(cnt < n){
		flag = 0;
		for(int i = 0; i < out[cur].size(); i++){
			if(out[cur][i] != prev){
				prev = cur;
				cur = out[cur][i];
				flag = 1;
				break;
			}
		}
		
		if(!flag){
			for(int i = 0; i <in[cur].size(); i++){
				if(in[cur][i] != prev){
					prev = cur;
					cur = in[cur][i];
					flag = 1;
					break;
				}
			}
		}
		
		printf("%d ", cur);
		
		cnt++;
	}
	
	printf("\n");
	
	return 0;
}

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

using namespace std;

int n, x, y, cnt; 
vector<pair<int, pair<int, int> > > dist;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd2(x,y);
		dist.pb(mp(abs(x)+abs(y), mp(x,y)));
	}
	
	sort(dist.begin(), dist.end());
	
	for(int i = 0; i < n; i++){
		x = dist[i].se.fi, y = dist[i].se.se;
		if(x > 0){
			cnt++;
		}
		else if(x < 0){
			cnt++;
		}
		
		if(y > 0){
			cnt++;
		}
		else if(y < 0){
			cnt++;
		}
		
		cnt++;
		
		if(x > 0){
			cnt++;
		}
		else if(x < 0){
			cnt++;
		}
		
		if(y > 0){
			cnt++;
		}
		else if(y < 0){
			cnt++;
		}
		
		cnt++;
	}
	
	printf("%d\n", cnt);
	
	for(int i = 0; i < n; i++){
		x = dist[i].se.fi, y = dist[i].se.se;
		if(x > 0){
			printf("1 %d R\n", x);
			cnt++;
		}
		else if(x < 0){
			printf("1 %d L\n",-x);
			cnt++;
		}
		
		if(y > 0){
			printf("1 %d U\n", y);
			cnt++;
		}
		else if(y < 0){
			printf("1 %d D\n",-y);
			cnt++;
		}
		
		printf("2\n");
		cnt++;
		
		if(x > 0){
			printf("1 %d L\n", x);
			cnt++;
		}
		else if(x < 0){
			printf("1 %d R\n",-x);
			cnt++;
		}
		
		if(y > 0){
			printf("1 %d D\n", y);
			cnt++;
		}
		else if(y < 0){
			printf("1 %d U\n",-y);
			cnt++;
		}
		
		printf("3\n");
		cnt++;
	}
	
	return 0;
}

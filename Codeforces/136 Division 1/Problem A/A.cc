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

int n, x, cnt, prev[100000];
int a[100000];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(x);
		prev[i] = x;
		a[i] = x;
	}
	
	sort(a, a+n);
	
	for(int i = 0; i < n; i++){
		if(a[i] != prev[i]) cnt++;
	}
	
	if(cnt == 2 or cnt == 0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, q, p[100100], num, x, y;


int main(){
	sd2(n,q);
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		sd(num);
		if(num == 3){
			if(x > 0) y = i; else x = i;
			p[i] = p[i-1];
		}
		else{
			p[i] = (p[i-1] * (num%3))%3;
		}
	}
	
	while(q--){
		int l, r, cnt = 0;; sd2(l,r);
		if(l <= x and x <= r) cnt++;
		if(l <= y and y <= r) cnt++;
	
		if(cnt == 1){
			printf("0\n");
		}
		else{
			printf("%d\n", (p[r]*p[l-1])%3);
		}
	}
	return 0;
}

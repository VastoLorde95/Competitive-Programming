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

int n;

int main(){
	sd(n);
	if(n < 4){
		puts("NO"); return 0;
	}
	
	puts("YES");
	if(n%2 == 0){
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
		
		for(int i = 6; i <= n; i += 2){
			printf("%d - %d = 1\n", i, i-1);
		}
		int up = (n-4)/2;
		for(int i = 1; i <= up; i++){
			printf("24 * 1 = 24\n");
		}
	}
	else{
		printf("5 - 1 = 4\n");
		printf("4 - 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
		
		for(int i = 7; i <= n; i += 2){
			printf("%d - %d = 1\n", i, i-1);
		}
		int up = (n-5)/2;
		for(int i = 1; i <= up; i++){
			printf("24 * 1 = 24\n");
		}
	}
	
	return 0;
}

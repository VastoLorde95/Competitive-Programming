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

long long n, x, y;
long long a[100001], s[2000001];

int main(){ _
	cin >> n >> x >> y;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	long long cntx = 0, cnty = 0, indx = 0;
	while(cntx < x and cnty < y){
		if((cntx+1)*y > (cnty+1)*x){
			s[indx++] = 2;
			cnty++;
		}
		else if((cntx+1)*y < (cnty+1)*x){
			s[indx++] = 1;
			cntx++;
		}
		else{
			s[indx++] = 3;
			s[indx++] = 3;
			cntx++;
			cnty++;
		}
	}
	for(int i = 1; i <= n; i++){
		if(s[(a[i]-1)%(x+y)] == 1) puts("Vanya");
		else if(s[(a[i]-1)%(x+y)] == 2) puts("Vova");
		else puts("Both");
	}
	
	
	return 0;
}

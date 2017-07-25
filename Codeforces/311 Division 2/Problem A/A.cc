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

int n;
int x1, x2, x3, x4, x5, x6;

int main(){
	cin >> n;
	sd2(x1,x2);
	sd2(x3,x4);
	sd2(x5,x6);
	
	int a = x1, b = x3, c = x5;
	n -= (x1+x3+x5);
	
	if(n >= x2-x1){
		n -= x2-x1;
		a = x2;
	}
	else{
		a += n;
		n = 0;
	}
	if(n >= x4-x3){
		n -= x4-x3;
		b = x4;
	}
	else{
		b += n;
		n = 0;
	}
	if(n >= x6-x5){
		n -= x6-x5;
		c = x6;
	}
	else{
		c += n;
		n = 0;
	}
	
	tr3(a,b,c);
	
	return 0;
}

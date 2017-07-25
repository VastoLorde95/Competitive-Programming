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

string n;
int  l;
int a, b;

int main(){ _
	cin >> n; l = n.length();
	
	if(n == "0"){
		tr(4); return 0;
	}
	
	int ans = 1;
	for(int i = 0; i < l; i++){
		a *= 10;
		b *= 10;
		
		a = (a + n[i]-'0')%4;
		b = (b + n[i]-'0')%2;		
	}
	
	
	
	if(a == 0) ans += (6+1);
	if(a == 1) ans += (2+3);
	if(a == 2) ans += (4+9);
	if(a == 3) ans += (8+7);
	
	if(b == 0) ans += 6; else ans += 4;
	tr(ans%5);
	return 0;
}

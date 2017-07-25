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

long long x, y, n, MOD = 1000000007;

map<long long, long long> v;

void out(long long xx){
	cout << (xx+ MOD*5)%MOD << "\n";
}

int main(){
	cin >> x >> y >> n;
	n--;
	n %= 6;
	
	if(n == 0) out(x);
	if(n == 1) out(y);
	if(n == 2) out(y-x+MOD);
	if(n == 3) out(MOD-x);
	if(n == 4) out(MOD-y);
	if(n == 5) out(x-y+MOD); 
	
	return 0;
}

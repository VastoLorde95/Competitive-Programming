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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

string s;
int n, m, cnt[100100][3];

int main(){ _
	cin >> s >> m;
	n = s.length();
	
	for(int i = 1; i <= n; i++){
		cnt[i][0] = cnt[i-1][0] + (s[i-1] == 'x');
		cnt[i][1] = cnt[i-1][1] + (s[i-1] == 'y');
		cnt[i][2] = cnt[i-1][2] + (s[i-1] == 'z');
	}		
	
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		if(r-l+1 < 3){
			cout << "YES\n"; continue;
		}
		
		int x = cnt[r][0] - cnt[l-1][0];
		int y = cnt[r][1] - cnt[l-1][1];
		int z = cnt[r][2] - cnt[l-1][2];
		
		if(x > y) swap(x,y);
		if(y > z) swap(y,z);
		if(x > y) swap(x,y);
		
		if((x == y and y == z) or (x == y and z == x+1) or (y == x+1 and z == x+1)) cout << "YES\n";
		else cout << "NO\n";
		
		
	}
	
	
	return 0;
}

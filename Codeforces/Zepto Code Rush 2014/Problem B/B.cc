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

int n, m, k, grid[2001][2001];
string s;

bool inrange(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true;
	return false;
}

int main(){ _
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			if(s[j-1] == 'L') grid[i][j] = 1;
			else if(s[j-1] == 'R') grid[i][j] = 2;
			else if(s[j-1] == 'D') grid[i][j] = 3;
			else if(s[j-1] == 'U') grid[i][j] = 4;
		}
	}
	
	for(int i = 1; i <= m; i++){
		int cnt = 0;
		for(int j = 2; j <= n; j++){
			if(inrange(j,i+j-1) and grid[j][i+j-1] == 1) cnt++;
			if(inrange(j,i-j+1) and grid[j][i-j+1] == 2) cnt++;
			if(inrange(j+j-1,i) and grid[j+j-1][i] == 4) cnt++;
			if(inrange(j-j+1,i) and grid[j-j+1][i] == 3) cnt++;
		}
		cout << cnt << " ";
	}
	cout << "\n";
	return 0;
}

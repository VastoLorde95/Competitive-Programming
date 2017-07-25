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

int n, m;
int grid[100][100];

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == '.') grid[i][j] = 1;
			else grid[i][j] = 2;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 1){
				if(i%2){
					if(j%2){
						grid[i][j] = 3;
					}
					else{
						grid[i][j] = 4;
					}
				}
				else{
					if(j%2){
						grid[i][j] = 4;
					}
					else{
						grid[i][j] = 3;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 2) cout << "-";
			else if(grid[i][j] == 3) cout << "W";
			else cout << "B";
		}
		cout << "\n";
	}
	return 0;
}

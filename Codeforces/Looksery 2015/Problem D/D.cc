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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, a[100][100], cnt = 0;
string g[100];

int main(){ _
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> g[i];
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(g[i][j] == 'W' and a[i][j] != 1){
				cnt++;
				int d = 1-a[i][j];
				for(int x = i; x >= 0; x--){
					for(int y = j; y >= 0; y--){
						a[x][y] += d;
					}
				}
			}
			else if(g[i][j] == 'B' and a[i][j] != -1){
				cnt++;
				int d = -1-a[i][j];
				for(int x = i; x >= 0; x--){
					for(int y = j; y >= 0; y--){
						a[x][y] += d;
					}
				}
			}
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}

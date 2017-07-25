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
#include<fstream>
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

#define cin fin
#define cout fout

using namespace std;

int n, m, k, v[2000][2000], x, y, mx, INF = 1000000000;

bool inrange(int x, int y){
	if(x >= 0 and x < n and y >= 0 and y < m) return true;
	return false;
}

void bfs(int x, int y){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			v[i][j] = min(v[i][j], abs(i-x) + abs(j-y));
		}
	}
}

int main(){

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			v[i][j] = INF;
		}
	}
	
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		x--, y--;
		v[x][y] = 0;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(v[i][j] == 0){
				bfs(i,j);
			}
		}
	}
	
	mx = -1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(v[i][j] > mx){
				mx = v[i][j];
				x = i, y = j;
			}
		}
	}
	
	cout << x+1 << " " << y+1 << endl;
	
	return 0;
}

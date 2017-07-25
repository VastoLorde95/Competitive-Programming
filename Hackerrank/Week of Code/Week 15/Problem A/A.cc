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

int t;
int g[9][9];
int m[10];

bool goodrow(int ind){
	memset(m, 0, sizeof(m));
	
	for(int i = 0; i < 9; i++){
		m[g[ind][i]] = 1;
	}
	for(int i = 1; i <= 9; i++) if(!m[i]) return false;
	return true;
}

bool goodcol(int ind){
	memset(m, 0, sizeof(m));
	
	for(int i = 0; i < 9; i++){
		m[g[i][ind]] = 1;
	}
	for(int i = 1; i <= 9; i++) if(!m[i]) return false;
	return true;
}

bool goodblock(int ind){
	int y = (3*ind)%9;
	int x = (ind/3)*3;
	
	memset(m, 0, sizeof(m));
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			m[g[x+i][y+j]] = 1;
		}
	}
	for(int i = 1; i <= 9; i++) if(!m[i]) return false;
	return true;
}

bool isvalid(){
	for(int i = 0; i < 9; i++){
		if(!goodrow(i)){
			return false;
		}
		if(!goodcol(i)){
			return false;
		}
		if(!goodblock(i)){
			return false;
		}
	}
	return true;
}

int main(){
	sd(t);
	for(int T = 1; T <= t; T++){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				sd(g[i][j]);
			}
		}
		printf("Case #%d:\n",T);
		vector<pair<pair<int,int>,pair<int,int> > > res;
		if(isvalid()){
			puts("Serendipity");
			continue;
		}
		else{
			for(int i1 = 0; i1 < 9; i1++){
				for(int j1 = 0; j1 < 9; j1++){
					for(int i2 = i1; i2 < 9; i2++){
						for(int j2 = 0; j2 < 9; j2++){
							if(i1 == i2 and j2 <= j1) continue;
							swap(g[i1][j1], g[i2][j2]);
							if(isvalid()){
								res.pb(mp(mp(i1+1,j1+1),mp(i2+1,j2+1)));
							}	
							swap(g[i1][j1], g[i2][j2]);
						}
					}	
				}
			}	
		}
		foreach(it, res){
			printf("(%d,%d) <-> (%d,%d)\n",it->fi.fi, it->fi.se, it->se.fi, it->se.se);
		}
	}
	return 0;
}

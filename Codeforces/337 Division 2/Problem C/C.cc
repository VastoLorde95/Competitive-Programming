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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cerr<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cerr<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cerr<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

int k;
int res[600][600];

int main(){
	sd(k);
	
	if(k == 0){
		cout << "+" << endl;
		return 0;
	}
	
	res[0][0] = 1;
	for(int i = 1; i <= k; i++){
		int l = 1<<(i-1);
		for(int j = 0; j < l; j++){
			for(int k = 0; k < l; k++){
				res[l+j][k] = res[j][k];
			}
		}
		
		for(int j = 0; j < l; j++){
			for(int k = 0; k < l; k++){
				res[j][l+k] = 1-res[l+j][k];
			}
		}
		
		for(int j = 0; j < l; j++){
			for(int k = 0; k < l; k++){
				res[l+j][l+k] = res[j][k];				
			}
		}
	}	
	
	int l = 1<<k;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < l; j++){
			if(res[i][j]) cout << '+';
			else cout << '*';
		}
		cout << '\n';
	}
	
	return 0;
}

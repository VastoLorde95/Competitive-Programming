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

const int N = 2100;

typedef pair<int,int> pii;

int n, p[N], s[N];
int p1[N], p2[N], to[N], v[N];
int coins = 0, tot = 0;

vector<pii> moves;

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
		p1[p[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		sd(s[i]);
		p2[s[i]] = i;
	}
	
	for(int i = 1; i <= n; i++){
		to[i] = p2[p[i]];
	}
	
	while(tot < n){
		for(int i = 1; i <= n; i++){
			if(!v[i]){
				if(to[i] == i){
					v[i] = 1; ++tot;
				}
				else if(to[i] > i){
					int cur = i;
					for(int j = i+1; j <= to[i]; j++){
						if(to[j] <= cur){
							moves.pb(mp(cur, j));
							coins += abs(j-cur);
							swap(to[cur], to[j]);
							cur = j;
						}
					}
				}
				else{
					int cur = i;
					for(int j = i-1; j >= to[i]; j--){
						if(to[j] >= cur){
							moves.pb(mp(cur, j));
							coins += abs(j-cur);
							swap(to[cur], to[j]);
							cur = j;
						}
					}
				}
			}
		}
	}
	
	printf("%d\n%d\n", coins, (int)moves.size());
	foreach(it, moves){
		printf("%d %d\n", it->fi, it->se);
	}
	
	return 0;
}

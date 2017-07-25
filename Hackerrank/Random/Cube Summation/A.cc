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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int MAX_X = 101, MAX_Y = 101, MAX_Z = 101;
long long tree[MAX_X][MAX_Y][MAX_Z];

void update(int x, int y, int z, int val){
    int yy;
    while (x < MAX_X){
        yy = y;
        while(yy < MAX_Y){
			tree[x][yy][z] += val;
			yy += (yy & -yy);
		}
        x += (x & -x); 
    }
}

long long query(int x, int y, int z){
    int yy;
    long long sum = 0;
    while (x){
        yy = y;
        while(yy){
			sum += tree[x][yy][z];
			yy -= (yy & -yy);
		}
        x -= (x & -x); 
    }
    return sum;
}

int t, n, m; 
string s;

int main(){
	sd(t);
	while(t--){
		sd2(n,m);
		memset(tree, 0, sizeof tree);
		int x1, y1, z1, x2, y2, z2, w;
		while(m--){
			cin >> s;
			if(s[0] == 'U'){
				sd2(x1,y1); sd2(z1,w);
				update(y1,z1,x1,-query(y1,z1,x1)+query(y1,z1-1,x1)+query(y1-1,z1,x1)-query(y1-1,z1-1,x1));
				update(y1,z1,x1,w);
			}
			else{
				long long res = 0;
				sd3(x1,y1,z1); sd3(x2,y2,z2);
				for(int i = x1; i <= x2; i++){
					res += query(y2,z2,i) - query(y2,z1-1,i) - query(y1-1,z2,i) + query(y1-1,z1-1,i);
				}
				printf("%lld\n", res);
			}	
		}
	}
	return 0;
}

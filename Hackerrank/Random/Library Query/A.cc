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

const int MAX_X = 10001, MAX_Y = 1001;
int tree[MAX_X][MAX_Y];

void update(int x, int y, int val){
    int yy;
    while (x < MAX_X){
        yy = y;
        while(yy < MAX_Y){
			tree[x][yy] += val;
			yy += (yy & -yy);
		}
        x += (x & -x); 
    }
}

int query(int x, int y){
    int yy, sum = 0;
    while (x){
        yy = y;
        while(yy){
			sum += tree[x][yy];
			yy -= (yy & -yy);
		}
        x -= (x & -x); 
    }
    return sum;
}

int t, n, q, b[10001], type, x, y, k;

int main(){
	sd(t);
	while(t--){
		memset(tree, 0, sizeof tree);
		sd(n);
		for(int i = 1; i <= n; i++){
			sd(b[i]);
			update(i, b[i], 1);
		}
		sd(q);
		while(q--){
			sd(type);
			if(type == 1){
				sd2(x,k);
				update(x, b[x], -1);
				b[x] = k;
				update(x, b[x], 1);
			}
			else{
				sd3(x,y,k);
				int lo = 1, hi = 1001, mid;
				while(lo < hi){
					mid = (lo+hi)>>1;
					if(query(y,mid)-query(x-1,mid) >= k) hi = mid;
					else lo = mid+1;
				}
				printf("%d\n", lo);
			}
		}
	}
	return 0;
}

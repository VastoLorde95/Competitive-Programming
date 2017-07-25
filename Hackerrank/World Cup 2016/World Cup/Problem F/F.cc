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

typedef long long ll;

ll MOD = 1e9+7;

struct node{
	int a, b, p, A, B;
	node *l, *r;
	
	node(): l(NULL), r(NULL);
};

int n, q;

void update(node *cur, int x, int y, int v1, int v2, int l = 0, int r = n+1)
	if(x >= r or l >= y) return;
	if(x <= l and r <= y){
		int range = r-l;
		cur->p += ((ll)v2*cur->a)%MOD;
		if(cur->p >= MOD) cur->p -= MOD;
		cur->p += 
	}
}

int main(){
	node *root = new node();
	
	sd2(n,q);
	
	
	int t, l, r, c;
	for(int i = 0; i < q; i++){
		sd3(t,l,r);
		if(t == 1){
			sd(c);
			update1(root,l,r+1,c,0);	
		}
		else if(t == 2){
			sd(c);
		}
		else{
			
		}	
	}
	
	return 0;
}

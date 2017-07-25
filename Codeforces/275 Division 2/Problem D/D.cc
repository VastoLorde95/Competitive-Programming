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


struct node{
	int v;
	void assign(int value){
		v = value;
	}
	void combine(node &left, node &right){
		v = left.v & right.v;
	}
};

const int N = 1<<17;
node tree[2*N];

int n, m;
int bits[30][100001], a[100001], qu[100001][3];

void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
int query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return (1<<30)-1;
	if(x <= l && r <= y) return tree[id].v;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return query(x, y, left, l, mid)&query(x, y, right, mid, r);
}

int main(){
	sd2(n,m);
	for(int i = 0; i < m; i++){
		int l, r, q;
		sd3(l,r,q);
		l--, r--;
		qu[i][0] = l, qu[i][1] = r, qu[i][2] = q;
		for(int j = 0; j < 30; j++){
			if((q&(1<<j)) > 0){
				bits[j][l]++, bits[j][r+1]--;
			}
		}
	}
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; i > 0 and j < 30; j++){
			bits[j][i] += bits[j][i-1];
		}
		for(int j = 0; j < 30; j++){
			if(bits[j][i] > 0) a[i] |= (1<<j);
		}
	}
	
	build();
	
	for(int i = 0; i < m; i++){
		if(query(qu[i][0], qu[i][1]+1) != qu[i][2]){
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

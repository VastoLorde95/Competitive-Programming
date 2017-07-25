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
#define tr6(a,b,w,x,y,z) cout<<a<<" "<<b<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 1<<21;

struct node{
	int open, close, cnt;
	void assign(char c){
		if(c == '('){
			open = 1, close = 0;
		}
		else{
			close = 1, open = 0;
		}
		cnt = 0;
		return;
	}
	
	void reset(){
		open = 0;
		close = 0;
		cnt = 0;
	}
	
	void combine(node &left, node &right){
		
		int tmp = min(left.open, right.close);
		cnt = left.cnt + right.cnt + 2*tmp;
		open = left.open-tmp + right.open;
		close = left.close + right.close-tmp;
		
	}
};

int n;
string a;
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
//		tr6(id,l,r,tree[id].cnt, tree[id].open, tree[id].close);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(left, l, mid); build(right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
	
//	tr6(id,l,r,tree[id].cnt, tree[id].open, tree[id].close);
	
	return;
}



// range query -> query(x, y);
node query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y){
		node ret; ret.reset();
		return ret;
	}
	if(x <= l && r <= y){
//		tr4(x,y,l,r);
//		tr6("a","b",id,tree[id].cnt, tree[id].open, tree[id].close);
		return tree[id];
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	node res, leftnode = query(x, y, left, l, mid), rightnode = query(x, y, right, mid, r);
	res.reset();
	
	res.combine(leftnode, rightnode);
//	tr4(x,y,l,r);
//	tr6("a","b",id,res.cnt, res.open, res.close);
	
	return res;
}

int main(){ _
	cin >> a;
	n = a.length();
	build();
	
	int m;
	cin >> m;
	
//	tr(query(0,2).cnt);
	
	while(m--){
		int l, r; cin >> l >> r;
		cout << query(l-1,r).cnt << "\n";
	}
	return 0;
}

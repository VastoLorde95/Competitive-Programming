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


const int N = 1<<18;

struct node{
	int cnt;
	void assign(int value){cnt = value;}
	void update(int value){cnt = value;}
	void combine(node &left, node &right){cnt = left.cnt + right.cnt;}
};

int n, q, x, y, type, lazy[26][N], a[N], cnt[26];
node tree[26][2*N];
char s[N];

void build(int c, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[c][id].assign(a[l] == c);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	build(c, left, l, mid); build(c, right, mid, r);
	
	tree[c][id].combine(tree[c][left], tree[c][right]);
	return;
}

void upd(int c, int id,int l,int r,int x){
	lazy[c][id] = x;
	if(x == 1) tree[c][id].update((r - l) * x); else tree[c][id].update(0);
}

void shift(int c, int id,int l,int r){
	if(!lazy[c][id]) return;
	int mid = (l+r)/2;
	upd(c, id * 2, l, mid, lazy[c][id]);
	upd(c, id * 2 + 1, mid, r, lazy[c][id]);
	lazy[c][id] = 0;
}

void update(int c, int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(c, id, l, r, val);
		return;
	}
	
	shift(c, id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	update(c, x, y, val, left, l, mid);
	update(c, x, y, val, right, mid, r);
	
	tree[c][id].combine(tree[c][left], tree[c][right]);
	return;
}

int query(int c, int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[c][id].cnt;
	
	shift(c, id, l, r);
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return query(c, x, y, left, l, mid) + query(c, x, y, right, mid, r);
}


int main(){
	sd2(n,q);
	scanf("%s", s);
	
	for(int i = 0; i < n; i++) a[i] = s[i]-'a';
	
	for(int i = 0; i < 26; i++) build(i);
	
	while(q--){
		sd3(x,y,type);
		x--, y--;
		
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < 26; i++) cnt[i] = query(i, x, y+1);
		
		if(type){
			int lo = x;
			for(int i = 0; i < 26; i++){
				if(cnt[i] > 0){
					update(i, x, y+1, -1);
					update(i, lo, lo + cnt[i], 1);
					lo += cnt[i];
				}
			}
		}
		else{
			int lo = x;
			for(int i = 25; i >= 0; i--){
				if(cnt[i] > 0){
					update(i, x, y+1, -1);
					update(i, lo, lo + cnt[i], 1);
					lo += cnt[i];
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			if(query(j, i, i+1) > 0){
				printf("%c", (char)(j+'a'));
				break;
			}
		}
	}
	printf("\n");
	
	return 0;
}

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

int n, inf = 1e9;	
string s;

const int off = 200100;
const int N = 1<<20;

struct node{
	int cnt;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt = min(cnt, value);
	}
	void combine(node &left, node &right){
		cnt = min(left.cnt, right.cnt);
	}
};

node tree[2*N];

// point update -> update(index, value);
void update(int index, int val, int id = 1, int l = 0, int r = N){
	if(l+1 == r){
		tree[id].update(val);
		return;
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);
	
	tree[id].combine(tree[left], tree[right]);
}

// range query -> query(x, y);
int query(int x, int y, int id = 1, int l = 0, int r = N){
	if(x >= r or l >= y) return inf;
	if(x <= l && r <= y) return tree[id].cnt;
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	return min(query(x, y, left, l, mid), query(x, y, right, mid, r));
}


int main(){ _
	cin >> s;
	n = s.length();
	
	for(int i = 0; i < 2*N; i++){
		tree[i].cnt = inf;
	}
	
	int c = 0, v = 0;
	int len = 0, cnt = 0;
	
	update(off,-1);
	for(int i = 0; i < n; i++){
		if(s[i] <= 'Z') s[i] += 32;
		
		if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') v++;
		else c++;
		
		if(c == 0){
			update(off+c+c-v, i);	
			continue;
		}
		
		int id = query(0,off+c+c-v+1);
		if(i-id > len){
			len = i-id;
			cnt = 1;
		}
		else if(i-id == len){
			cnt++;
		}

		update(off+c+c-v, i);
		
	}
	
	if(len == 0) cout << "No solution" << endl;
	else{
		cout << len << " " << cnt << endl;
	}
	return 0;
}

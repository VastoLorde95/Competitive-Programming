#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <unordered_map>
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
typedef pair<int,int> pii;

const int N = 1<<19;

long long MOD = 1e9 + 7;

struct node{
	int p;
	unsigned long long a, b, A, B;
};

int n, q, cord, invf[400100];
//int A[2*N], B[2*N];
pair<pii,pii> quer[200100];
node tree[2*N];

//map<int, int> f;
unordered_map<int, int> f;

ll range;

int x, y;

void update(int v1, int id = 1, int l = 0, int r = n){
	if(x <= l && r <= y){
		range = invf[r]-invf[l];
	
//		tree[id].p += ((ll)v2*(tree[id].a%MOD))%MOD;
//		if(tree[id].p >= MOD) tree[id].p -= MOD;
		tree[id].p += ((ll)v1*(tree[id].b%MOD))%MOD;
		if(tree[id].p >= MOD) tree[id].p -= MOD;
//		tree[id].p += (range * (ll)(v1*v2)%MOD)%MOD;
//		if(tree[id].p >= MOD) tree[id].p -= MOD;
	
	
		tree[id].a += (range*v1);
//		if(tree[id].a >= MOD) tree[id].a -= MOD;
	
//		tree[id].b += (range*v2);
//		if(tree[id].b >= MOD) tree[id].b -= MOD;
	
		tree[id].A += v1;
//		if(tree[id].A >= MOD) tree[id].A -= MOD;
	
//		tree[id].B += v2;
//		if(tree[id].B >= MOD) tree[id].B -= MOD;
		return;
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(tree[id].A != 0 or tree[id].B != 0){
		range = invf[mid]-invf[l];
		ll v1 = tree[id].A%MOD, v2 = tree[id].B%MOD;
		
		tree[left].p += ((ll)v2*(tree[left].a%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
		tree[left].p += ((ll)v1*(tree[left].b%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
		tree[left].p += (range * (((ll)v1*v2)%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
	
	
		tree[left].a += (range*v1);
//		if(tree[left].a >= MOD) tree[left].a -= MOD;
	
		tree[left].b += (range*v2);
//		if(tree[left].b >= MOD) tree[left].b -= MOD;
	
		tree[left].A += v1;
//		if(tree[left].A >= MOD) tree[left].A -= MOD;
	
		tree[left].B += v2;
//		if(tree[left].B >= MOD) tree[left].B -= MOD;
		
		range = invf[r]-invf[mid];
		
		tree[right].p += ((ll)v2*(tree[right].a%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
		tree[right].p += ((ll)v1*(tree[right].b%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
		tree[right].p += (range * (((ll)v1*v2)%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
	
	
		tree[right].a += (range*v1);//%MOD;
//		if(tree[right].a >= MOD) tree[right].a -= MOD;
	
		tree[right].b += (range*v2);//%MOD;
//		if(tree[right].b >= MOD) tree[right].b -= MOD;
	
		tree[right].A += v1;
//		if(tree[right].A >= MOD) tree[right].A -= MOD;
	
		tree[right].B += v2;
//		if(tree[right].B >= MOD) tree[right].B -= MOD;
		
		tree[id].A = tree[id].B = 0;
	}
	
	if(x < mid)
		update(v1, left, l, mid);
	if(y > mid)
		update(v1, right, mid, r);
	
	tree[id].a = tree[left].a + tree[right].a;
//	if(tree[id].a >= MOD) tree[id].a -= MOD;
	tree[id].b = tree[left].b + tree[right].b;
//	if(tree[id].b >= MOD) tree[id].b -= MOD;
	tree[id].p = tree[left].p + tree[right].p;
	if(tree[id].p >= MOD) tree[id].p -= MOD;
	
	return;
}


void update2(int v2, int id = 1, int l = 0, int r = n){
	if(x <= l && r <= y){
		range = invf[r]-invf[l];
	
		tree[id].p += ((ll)v2*(tree[id].a%MOD))%MOD;
		if(tree[id].p >= MOD) tree[id].p -= MOD;
//		tree[id].p += ((ll)v1*(tree[id].b%MOD))%MOD;
//		if(tree[id].p >= MOD) tree[id].p -= MOD;
//		tree[id].p += (range * (ll)(v1*v2)%MOD)%MOD;
//		if(tree[id].p >= MOD) tree[id].p -= MOD;
	
	
//		tree[id].a += (range*v1);
//		if(tree[id].a >= MOD) tree[id].a -= MOD;
	
		tree[id].b += (range*v2);
//		if(tree[id].b >= MOD) tree[id].b -= MOD;
	
//		tree[id].A += v1;
//		if(tree[id].A >= MOD) tree[id].A -= MOD;
	
		tree[id].B += v2;
//		if(tree[id].B >= MOD) tree[id].B -= MOD;
		return;
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(tree[id].A != 0 or tree[id].B != 0){
		range = invf[mid]-invf[l];
		ll v1 = tree[id].A%MOD, v2 = tree[id].B%MOD;
		
		tree[left].p += ((ll)v2*(tree[left].a%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
		tree[left].p += ((ll)v1*(tree[left].b%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
		tree[left].p += (range * (((ll)v1*v2)%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
	
	
		tree[left].a += (range*v1);
//		if(tree[left].a >= MOD) tree[left].a -= MOD;
	
		tree[left].b += (range*v2);
//		if(tree[left].b >= MOD) tree[left].b -= MOD;
	
		tree[left].A += v1;
//		if(tree[left].A >= MOD) tree[left].A -= MOD;
	
		tree[left].B += v2;
//		if(tree[left].B >= MOD) tree[left].B -= MOD;
		
		range = invf[r]-invf[mid];
		
		tree[right].p += ((ll)v2*(tree[right].a%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
		tree[right].p += ((ll)v1*(tree[right].b%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
		tree[right].p += (range * (((ll)v1*v2)%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
	
	
		tree[right].a += (range*v1);//%MOD;
//		if(tree[right].a >= MOD) tree[right].a -= MOD;
	
		tree[right].b += (range*v2);//%MOD;
//		if(tree[right].b >= MOD) tree[right].b -= MOD;
	
		tree[right].A += v1;
//		if(tree[right].A >= MOD) tree[right].A -= MOD;
	
		tree[right].B += v2;
//		if(tree[right].B >= MOD) tree[right].B -= MOD;
		
		tree[id].A = tree[id].B = 0;
	}
	
	if(x < mid)
		update2(v2, left, l, mid);
	if(y > mid)
		update2(v2, right, mid, r);
	
	tree[id].a = tree[left].a + tree[right].a;
//	if(tree[id].a >= MOD) tree[id].a -= MOD;
	tree[id].b = tree[left].b + tree[right].b;
//	if(tree[id].b >= MOD) tree[id].b -= MOD;
	tree[id].p = tree[left].p + tree[right].p;
	if(tree[id].p >= MOD) tree[id].p -= MOD;
	
	return;
}

int query(int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y){
		return tree[id].p;
	}
	
	int left = id<<1, right = left+1, mid = (l+r)>>1;
	
	if(tree[id].A != 0 or tree[id].B != 0){
		range = invf[mid]-invf[l];
		ll v1 = tree[id].A%MOD, v2 = tree[id].B%MOD;
		
		tree[left].p += ((ll)v2*(tree[left].a%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
		tree[left].p += ((ll)v1*(tree[left].b%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
		tree[left].p += (range * (((ll)v1*v2)%MOD))%MOD;
		if(tree[left].p >= MOD) tree[left].p -= MOD;
	
	
		tree[left].a += (range*v1);//%MOD;
//		if(tree[left].a >= MOD) tree[left].a -= MOD;
	
		tree[left].b += (range*v2);//%MOD;
//		if(tree[left].b >= MOD) tree[left].b -= MOD;
	
		tree[left].A += v1;
//		if(tree[left].A >= MOD) tree[left].A -= MOD;
	
		tree[left].B += v2;
//		if(tree[left].B >= MOD) tree[left].B -= MOD;
		
		range = invf[r]-invf[mid];
		
		tree[right].p += (v2*(tree[right].a%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
		tree[right].p += (v1*(tree[right].b%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
		tree[right].p += (range * (((ll)v1*v2)%MOD))%MOD;
		if(tree[right].p >= MOD) tree[right].p -= MOD;
	
	
		tree[right].a += (range*v1);//%MOD;
//		if(tree[right].a >= MOD) tree[right].a -= MOD;
	
		tree[right].b += (range*v2);//%MOD;
//		if(tree[right].b >= MOD) tree[right].b -= MOD;
	
		tree[right].A += v1;
//		if(tree[right].A >= MOD) tree[right].A -= MOD;
	
		tree[right].B += v2;
//		if(tree[right].B >= MOD) tree[right].B -= MOD;
		
		tree[id].A = tree[id].B = 0;
	}
	
	int t1 =  (query(left, l, mid) + query(right, mid, r));
	if(t1 >= MOD) t1 -= MOD;
	return t1;
	
}

set<int> compressor;

int main(){
	sd2(n,q);
	
	int type, l, r, c = 0;
	for(int i = 0; i < q; i++){
		
		sd3(type,l,r);
		r++;
		if(type < 3) sd(c);
				
		quer[i] = mp(mp(type,c),mp(l,r));
		
		compressor.insert(l);
		compressor.insert(r);
	}
	
	foreach(it, compressor){
		f[*it] = cord;
		invf[cord] = *it;
		cord++;
	}
	
	invf[cord] = invf[cord-1]+1;
	
	n = cord;
	
	for(int i = 0; i < q; i++){
		if(quer[i].fi.fi == 3){
			x = f[quer[i].se.fi], y = f[quer[i].se.se];
			printf("%d\n", query());
		}
		else if(quer[i].fi.fi == 1){
			x = f[quer[i].se.fi], y = f[quer[i].se.se];
			update(quer[i].fi.se);
		}
		else{
			x = f[quer[i].se.fi], y = f[quer[i].se.se];
			update2(quer[i].fi.se);
		}
	}
	return 0;
}

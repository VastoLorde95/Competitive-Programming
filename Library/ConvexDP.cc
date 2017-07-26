#include <bits/stdc++.h>

using namespace std;

/*
	http://wcipeg.com/wiki/Convex_hull_trick
	Notes to use -
 dp[i] = min(dp[j] + b[j]*a[i]) + X;	j < i
 dp[i][j] = min(dp[i-1][k] + b[k]*a[j]) + X; k < j

	Assumptions
1. Lines will be inserted in DECREASING order of their slopes
2. Queries will be answered in INCREASING order of the x-coordinate
3. If queries are not sorted, then binary search to obtain the answer in O(logN)
4. For maxConvexHull, sort slopes in INCREASING order and then do the same
5. If slopes are NOT distinct, then be careful of x_intersection method.

	Asymptotics
1. Insert O(N) amortized for insertion of all N lines
2. Query O(Q) amortized for retrieval of all Q queries
*/

typedef long long ll;

const int N = 200100;

struct line{
	ll m, c;
	ll get(ll x){
		return m*x + c;
	}
};

// can be used when queries are in any order
line st[N];
struct convexHull{
	int top;
	
	bool smallerIntercept(const line &l1, const line &l2, const line &l3){
		return (l3.c - l1.c) * (l1.m - l2.m) <= (l2.c - l1.c) * (l1.m - l3.m);
	}
	
	convexHull() : top(0) {	}
	
	void insert(ll m, ll c){
		line l = {m, c};
		
		while(top > 1 and smallerIntercept(st[top-2], st[top-1], l)) --top;
		st[top++] = l;
		
		return;
	}
	
	ll query(ll x){
		int lo = 0, hi = top-1, mid;
		
		while(lo+1 <= hi){
			mid = (lo + hi) >> 1;
			if(st[mid].get(x) <= st[mid+1].get(x)) lo = mid+1; else hi = mid;
		}
		
		return st[lo].get(x);
	}
};



// can be used only when queries are in incrasing order of x co-ordinate
line st[N];
double pos[N];
int top, ptr;
struct convexHull{
	
	double x_intersection(const line &l1, const line &l2){ // Careful! if slopes are equal, then this is not defined!
		assert(l1.m != l2.m);
		return ((double)(l2.c-l1.c))/(l1.m-l2.m);
	}
	
	convexHull(){
		top = ptr = 0;
	}
	
	void insert(ll m, ll c){
		line l = {m, c};
		double x;
		
		while(top > 1){	// if there are two lines in the hull before insertion of this line, try to improve the hull 
			x = x_intersection(st[top-2], l);
			if(x > pos[top-1]) break;
			--top;
		}
		
		st[top++] = l;
		if(top > 1) // if there is more than one line in the hull after insertion of the current line
			pos[top-1] = x_intersection(st[top-1], st[top-2]);
		return;
	}
	
	ll query(ll x){
		while(ptr < top-1 and pos[ptr+1] <= x) ptr++; // find the line whose range straddles point x
		return st[ptr].get(x);
	}
};

int main(){
	return 0;
}

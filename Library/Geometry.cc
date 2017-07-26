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

typedef pair<long double, long double> point;

struct line{
	long double m, c, x, y;
	bool inf, zero;
	
	void assign(point &p1, point &p2){
		if(p1.fi == p2.fi){
			inf = true;
			x = p1.fi;
		}
		if(p1.se == p2.se){
			zero = true;
			y = p1.se;		
		}
		else{
			inf = zero = false;
			m = (p1.se-p2.se)/(p1.fi-p2.fi);
			c = p1.se - m*p1.fi;
		}
	}
};

struct side{
	point p1, p2;
	void assign(point &pt1, point &pt2){
		p1 = pt1, p2 = pt2;
		if(p1 > p2) swap(p1, p2);
	}
	bool crosses(line &l){
		if(p1.fi == p2.fi){
			if(l.inf){
				if(l.x == p1.fi) return true;
				return false;
			}
		
			long double x = p1.fi, y = (l.m * x) +l.c, y1 = p1.se, y2 = p2.se;
			if(y1 > y2) swap(y1, y2);
			if(y1 <= y and y <= y2) return true;
			return false;
		}
		else{
			if(l.zero){
				if(l.y == p1.se) return true;
				return false;
			}
			if(l.inf){
				long double x = l.x, x1 = p1.fi, x2 = p2.fi;
				if(x1 > x2) swap(x1, x2);
				if(x1 <= x and x <= x2) return true;
				return false;
			}
			long double y = p1.se, x = (y-l.c)/(l.m), x1 = p1.fi, x2 = p2.fi;
			if(x1 > x2) swap(x1, x2);
			if(x1 <= x and x <= x2) return true;
			return false;
		}
	}
};

int main(){
	return 0;
}

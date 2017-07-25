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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long n, res = 4;
long long x, y, t;

int main(){ _	
	cin >> n;
	
	if(n == 0){
		cout << 1 << endl;
		return 0;
	}
	
	t = n*n;
	
	int cnt = 0;
	
	long long x1 = 0, x2 = 0, y1 = 0, y2 = n;
	
	for(x = 1, y = n-1; x < n and y > 0;){
		if(x*x + y*y <= t){
			if(!(x1 == x2 and x2+1 == x and y1 == y2+1 and y2 == y)){
				cnt++;
			}
			x1 = x2;
			y1 = y2;
			x2 = x;
			y2 = y;
		}
		if((x+1)*(x+1) + (y*y) <= t) x++;
		else y--;
	}
	
	cout << cnt*4 + res << endl;
	
	return 0;
}

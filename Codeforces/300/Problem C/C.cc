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

using namespace std;

int n, m;
long long d, hi, mx, h1, h2, d1, d2, x;
pair<long long, long long> h[100000];	// day, height

int main(){ _
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> d >> hi;
		h[i] = mp(d, hi);
	}
	
	mx = max(h[m-1].se + (n-h[m-1].fi), h[0].se + (h[0].fi-1));
	
	for(int i = 1; i < m; i++){
		h1 = h[i].se, d2 = h[i].fi;
		h2 = h[i-1].se, d1 = h[i-1].fi;
		
		//cout << h1 << " " << h2 << " " << d1 << " " << d2 << endl;
		
		if(h1 <= h2){
			if((h1 + (d2-d1)) < h2){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			x = (h2-h1+(d2-d1-1)+1)/2;
			mx = max(mx, h1+x);
		}
		else{
			if((h1 - (d2-d1)) > h2){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			x = (h1-h2+(d2-d1-1)+1)/2;
			mx = max(mx, h2+x);
		}
	}
	
	cout << mx << endl;
	
	return 0;
}

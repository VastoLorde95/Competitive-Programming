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

long long n, m, s, mx1, mx2;

map<long long, long long> c1, c2;

int main(){ _
	cin >> n >> m >> s;
	
	for(long long i = 1; i <= min(m,s); i++){
		c1[(m-i)/s + 1]++;
	}
	
	for(long long i = 1; i <= min(n,s); i++){
		c2[(n-i)/s + 1]++;
	}
	
	for(map<long long, long long>::iterator it = c1.begin(); it != c1.end(); it++){
		mx1 = max(mx1, it->fi);
	}
	
	for(map<long long, long long>::iterator it = c2.begin(); it != c2.end(); it++){
		mx2 = max(mx2, it->fi);
	}
	
	
	cout << mx1*mx2*c1[mx1]*c2[mx2] << "\n";
	
	
	return 0;
}

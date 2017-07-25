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

int b, d, go[101], e[101];
string a, c;

int main(){ _
	cin >> b >> d;
	cin >> a >> c;
	
	int n = a.length(), m = c.length();
	
	for(int i = 0; i < m; i++){
		bool ok = false;
		for(int j = 0; j < n; j++){
			if(c[i] == a[j]) ok = true;
		}
		
		if(!ok){
			cout << 0 << endl;
			return 0;
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[j] == c[(i+go[i])%m]) go[i]++;
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < b; i++){
		cnt += go[cnt%m];
	}
	
	cout << (cnt/m)/d << "\n";	
		
	return 0;
}

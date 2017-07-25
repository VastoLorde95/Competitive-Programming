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

int n;
int v[100100];
long long s1[100100], s2[100100];

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(v[i]);
	}
	for(int i = 1; i <= n; i++){
		s1[i] = s1[i-1] + v[i];
	}
	sort(v+1,v+n+1);
	
//	for(int i = 1; i <= n; i++) cout << v[i] << " "; cout << endl;
	
	for(int i = 1; i <= n; i++){
		s2[i] = s2[i-1] + v[i];
//		tr2(i, s2[i]);
	}
	int m; sd(m);
	while(m--){
		int type, l, r; sd3(type, l, r);
		if(type == 1){
			cout << s1[r]-s1[l-1] << "\n";
		}
		else{
			cout << s2[r]-s2[l-1] << "\n";
		}
	}
	
	return 0;
}

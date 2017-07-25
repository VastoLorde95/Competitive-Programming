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
map<int, int> s;
long long ans = 0;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int l; sd(l);
		s[l]++;
	}
	
	for(map<int, int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++){
		int l = it->fi, c = it->se;
		if(c%2 == 1){
			if(s[l-1] > 0) s[l-1]++;
			s[l]--;
		}
	}
	
	
//	foreach(it, s) tr2(it->fi, it->se);
	
	int prev = -1;
	for(map<int, int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++){
		int l = it->fi, c = it->se;
		
		if(c == 0) continue;
		
		if(c >= 2 and prev != -1){
			ans += (long long) l * prev;
			c -= 2;
		}
		while(c >= 4){
			c -= 4;
			ans += (long long) l * l;
		}
		if(c == 2) prev = l; else prev = -1;
			
	}
	tr(ans);	
	
	return 0;
}

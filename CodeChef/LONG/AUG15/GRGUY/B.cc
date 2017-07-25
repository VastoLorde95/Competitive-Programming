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

int t;
string s1, s2;

int main(){ _
	cin >> t;
	while(t--){
		cin >> s1 >> s2;
		int cnt = 0, l = s1.length(), cur, ans = 1e9;
		s1 += '#'; s2 += '#';
		
		if(s1[0] == '#' and s2[0] == '#'){
			cout << "No\n";
			continue;
		}
		cur = 0;
		bool ok = true;
		
		for(int i = 0; i < l; i++){
			if(!cur){
				if(s1[i] == '#'){
					if(s2[i] == '#' and s2[i+1] == '#'){
						ok = false;
					}
					else{
						if(s2[i] == '#' and s2[i+1] == '.') i++;
						cur = 1;
						cnt++;
					}
				}
			}
			else{
				if(s2[i] == '#'){
					if(s1[i] == '#' and s1[i+1] == '#'){
						ok = false;
					}
					else{
						if(s1[i] == '#' and s1[i+1] == '.') i++;
						cur = 0;
						cnt++;
					}
				}
			}
		}
		
		if(ok)
			ans = cnt;
		
		cur = 1;
		cnt = 0;
		ok = true;
		for(int i = 0; i < l; i++){
			if(!cur){
				if(s1[i] == '#'){
					if(s2[i] == '#' and s2[i+1] == '#'){
						ok = false;
					}
					else{
						if(s2[i] == '#' and s2[i+1] == '.') i++;
						cur = 1;
						cnt++;
					}
				}
			}
			else{
				if(s2[i] == '#'){
					if(s1[i] == '#' and s1[i+1] == '#'){
						ok = false;
					}
					else{
						if(s1[i] == '#' and s1[i+1] == '.') i++;
						cur = 0;
						cnt++;
					}
				}
			}
		}
		if(ok) ans = min(ans, cnt);
		
			
		if(ans != 1e9){
			cout << "Yes\n" <<  ans << "\n";
		}
		else{
			cout << "No\n";
		}
		
	}
	return 0;
}

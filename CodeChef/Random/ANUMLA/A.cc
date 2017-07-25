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

int t, n, vals[1<<16];
vector<int> a, sums, tmp;
map<int, int> s;
map<int, int>::iterator itt;

int main(){
	sd(t);
	while(t--){
		a.clear(), sums.clear(), s.clear();
		sd(n);
		for(int i = 0; i < (1<<n); i++){
			sd(vals[i]);
			s[vals[i]]++;
		}
		
		sort(vals, vals+(1<<n));
		
		s[0]--;
		s[vals[1]]--;
		sums.pb(vals[1]);
		a.pb(vals[1]);
		
		int pos = 0;
		
		while(a.size() < n and pos < (1<<n)){
			int cur = s.begin()->fi;
			if(s[cur] == 0){
				s.erase(cur); pos++; continue;
			}
			
			while(s[cur] > 0){
//				foreach(it2, a) cout << *it2 << " "; cout << "\n";	
				pos++;
				a.pb(cur);
			
				tmp.clear();
				tmp.pb(cur);
				foreach(it2, sums){
					tmp.pb(*it2 + cur);
				}
				foreach(it2, tmp){
					s[*it2]--;
					sums.pb(*it2);
				}
			}
			s.erase(cur);
		}
		
		sort(a.begin(), a.end());
		
		foreach(it2, a) cout << *it2 << " "; cout << "\n";	
	}	
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
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


int mx = 100000;
int n, a[100100], mn;

unordered_map<int, int> m, steps;
unordered_set<int> f;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		int tmp = a[i];
		int s = 0;
		
		f.clear();
		
		while(tmp > 0){
			f.insert(tmp);
			m[tmp]++;
			steps[tmp] += s;
			s++;
			tmp /= 2;
		}
		tmp = a[i]*2, s = 1;
		while(tmp <= mx){
			f.insert(tmp);
			m[tmp]++;
			steps[tmp] += s;
			s++;
			tmp *= 2;
		}
		tmp = a[i], s = 0;
		while(tmp > 0){
			if(tmp%2 != 0 and tmp > 1){
				tmp /= 2, s++;
				if(!f.count(tmp*2)){
					int tmp2 = tmp*2;
					int s2 = s + 1;
					while(tmp2 <= mx){
						m[tmp2]++;
						steps[tmp2] += s2;
						s2++;
						tmp2 *= 2;
					}
				}
			}
			else{
				tmp /= 2;
				s++;
			}
		}
		
	}
	
	mn = 1e9;
	
	foreach(it, m){
		if(it->se == n){
			if(steps[it->fi] < mn){
				mn = steps[it->fi];
			 }
		}
	}
	
	cout << mn << endl;
	
	return 0;
}

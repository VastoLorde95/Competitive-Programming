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
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

int t, cnt[26], cost;
string a, b;

int x, y, z;

int main(){ _
	cin >> t;
	while(t--){
		cin >> b >> a;
		cin >> x >> y >> z;
		int l1 = a.length(), l2 = b.length();
		
		cost = 0;
		
		memset(cnt, 0, sizeof cnt);
		
		if(l1 == l2){
			for(int i = 0; i < l1; i++){
				cnt[a[i]-'a']++;
			}
			for(int i = 0; i < l2; i++){
				cnt[b[i]-'a']--;
			}
			
			int mn = min(x+y, z);
			
			for(int i = 0; i < 26; i++){
				if(cnt[i] > 0){
					cost += mn * abs(cnt[i]);
				}
			}
		}
		else if(l2 < l1){
			cost += y * (l1-l2);
			int diff = l1-l2;
			
			for(int i = 0; i < l1; i++){
				cnt[a[i]-'a']++;
			}
			for(int i = 0; i < l2; i++){
				cnt[b[i]-'a']--;
			}
			
			int mn = min(x+y, z);
			
			for(int i = 0; i < 26; i++){
				if(diff > 0 and cnt[i] > 0){
						int sub = min(cnt[i], diff);
						cnt[i] -= sub;
						diff -= sub;
					}	
				if(cnt[i] > 0){
					cost += mn * abs(cnt[i]);
				}
			}
			
		}
		else if(l2 > l1){
			cost += x * (l2-l1);
			
			int diff = l2-l1;
			
			for(int i = 0; i < l1; i++){
				cnt[a[i]-'a']++;
			}
			for(int i = 0; i < l2; i++){
				cnt[b[i]-'a']--;
			}
			
			int mn = min(x+y, z);
			
			for(int i = 0; i < 26; i++){
				if(diff > 0 and cnt[i] < 0){
						int sub = min(cnt[i], diff);
						cnt[i] += sub;
						diff -= sub;
					}	
				if(cnt[i] > 0){
					cost += mn * abs(cnt[i]);
				}
			}
		}
		
		cout << cost << "\n";
		
	}
	return 0;
}

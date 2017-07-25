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

string s, res;
vector<int> cnt, cnt2;

int main(){ _
	cnt.resize(26);
	cin >> s;
	
	
	reverse(s.begin(), s.end());
	int l = s.length(), n = l/2;
	for(int i = 0; i < l; i++){
		cnt[s[i]-'a']++;
	}
	
	for(int i = 0; i < 26; i++){
		cnt[i] /= 2;
		cnt2.pb(cnt[i]);
	}
		
	int cur = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			if(cnt[j] > 0){
				bool ok = true;	
				vector<int> tmp = cnt2;
				for(int k = cur; k < l; k++){
					if(s[k]-'a' == j){
						cnt[j]--;
						cur = k+1;
						break;
					}
					if(tmp[s[k]-'a'] == 0){
						ok = false;
						break;
					}
					tmp[s[k]-'a']--;
				}
			
				if(ok){
					res += char(j+'a');
					cnt2 = tmp;
//					tr2(res,cur);
					break;
				}
			}
		}
	}
	
	cout << res << "\n";
	
	return 0;
}

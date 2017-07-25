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

string s, b;
int cnt[1501], bad[26], n, k;
set<long long> ans;
long long MOD = 801258244502321LL, hash;
int main(){ _
	cin >> s;
	n = s.length();
	
	cin >> b;
	for(int i = 0; i < 26; i++){
		bad[i] = 1 - (int)(b[i]-'0');
	}
	
	cin >> k;
	
	for(int i = 0; i < n; i++){
		if(bad[s[i]-'a'] == 1) cnt[i+1] = cnt[i]+1;
		else cnt[i+1] = cnt[i];
	}
	
	for(int i = 1; i <= n; i++){
		hash = 0;
		for(int j = i; j <= n; j++){
			hash = (hash*27) + (s[j-1]-'a'+1);
			hash %= MOD;
			if(cnt[j]-cnt[i-1] <= k){
				ans.insert(hash);
			}
		}
	}
	
	tr(ans.size());
	
	return 0;
}

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

string s1, s2;
int dp[5010][5010], u1[5010], u2[5010], mn;

void compute(string &s, string &t){
	int l1 = s.length(), l2 = t.length();
	
	memset(dp, 0, sizeof dp);
	
	for(int i = l1-1; i >= 0; i--){
		for(int j = l2-1; j >= 0; j--){
			if(s[i] == t[j])
				dp[i][j] = dp[i+1][j+1] + 1;
			else 
				dp[i][j] = 0;
		}
	}
	return;
}

int main(){ _
	cin >> s1 >> s2;
	int l1 = s1.length(), l2 = s2.length();
	
	mn = 1e9;
	
	compute(s1,s1);		
	for(int i = 0; i < l1; i++){
		int tmp = 0;
		for(int j = 0; j < l1; j++){
			if(i == j) continue;
			tmp = max(tmp, dp[i][j]);
		}
		u1[i] = tmp+1;
	}
	
	compute(s2,s2);		
	for(int i = 0; i < l2; i++){
		int tmp = 0;
		for(int j = 0; j < l2; j++){
			if(i == j) continue;
			tmp = max(tmp, dp[i][j]);
		}
		u2[i] = tmp+1;
	}
	
	compute(s1,s2);
	for(int i = 0; i < l1; i++){
		for(int j = 0; j < l2; j++){
			if(dp[i][j] >= max(u1[i],u2[j])){
				mn = min(mn, max(u1[i], u2[j]));
			}
		}
	}
	if(mn == 1e9) cout << "-1\n";
	else cout << mn << "\n";
	
	return 0;
}

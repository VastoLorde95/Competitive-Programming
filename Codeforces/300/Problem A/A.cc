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

using namespace std;

string s;
string t;

int cur, cnt;

int main(){
	t = "CODEFORCES";
	int l = t.length();
	
	cin >> s;
	int n = s.length();
	
	for(int i = 0; i < n; i++){
		if(s[i] == t[cur]){
			cur++;
		}
		
		if(cur == l){
			cout << "YES\n";
			return 0;
		}
	}
	
	cout << "NO\n";
	
	return 0;
}

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

using namespace std;

string s1, s2;
int n, m, cnt = 1, tmp;

set<char> c;

vector<int> pos[26];
vector<int>::iterator it;

int main(){ _
	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();
	
	for(int i = 0; i < n; i++){
		c.insert(s1[i]);
		pos[s1[i]-'a'].pb(i);
	}
	
	for(int i = 0; i < m; i++){
		if(c.find(s2[i]) == c.end()){
			puts("-1"); return 0;
		}
	}
	
	int j = -1, k;
	
	for(int i = 0; i < m; i++){
		tmp = s2[i]-'a';
		it = upper_bound(pos[tmp].begin(), pos[tmp].end(), j);
		
		if(it != pos[tmp].end()){
			j = pos[tmp][it - pos[tmp].begin()];
		}
		else{
			cnt++;
			j = pos[tmp][0];
		}
//		tr2(s2[i], j);
	}
	
	tr(cnt);
	
	return 0;
}

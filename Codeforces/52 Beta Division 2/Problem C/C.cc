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

string s;
stack<string> st;
map<string, int> cnt;
int res;

int main(){ _
	cin >> s;
	int n = s.length();
	
	for(int i = 0; i < n; i++){
		string tmp;
		while(i < n and s[i] >= 'A' and s[i] <= 'Z'){
			tmp += s[i];
			i++;
		}
		
		if(tmp.size() > 0){
			res += cnt[tmp];
			st.push(tmp);
			cnt[tmp]++;			
		}
		
		if(s[i] == '.'){
			cnt[st.top()]--;
			st.pop();
		}
		
	}
	
	tr(res);
	
	return 0;
}

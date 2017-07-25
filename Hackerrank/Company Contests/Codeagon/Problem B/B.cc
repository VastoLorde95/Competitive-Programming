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

int l;
string s;
map<string, int> memo;

void solve(int i, stack<char> st, string res){
	if(i == s.length()){
		while(!st.empty()){
			res += st.top();
			st.pop();
		}
		memo[res] += 1;
		return;
	}
	
	stack<char> tmp = st;
	tmp.push(s[i]);
	solve(i+1, tmp, res);
	
	if(!st.empty()){
		res += st.top();
		st.pop();
		solve(i, st, res);
	}
}

int main(){
	cin >> s;
	l = s.length();
	stack<char> st;
	solve(0, st, "");
	
//	foreach(it, memo){
//		tr2(it->fi, it->se);
//	}
	
	tr2(memo[s], memo.size());
	
	return 0;
}

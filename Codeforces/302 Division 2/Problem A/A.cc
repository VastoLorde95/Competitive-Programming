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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int k;
set<char> s;
string q;

int main(){
	cin >> k >> q;
	int l = q.length();
	for(int i = 0; i < l; i++){
		s.insert(q[i]);
	}
	if(s.size() < k){
		puts("NO"); return 0;
	}
	
	puts("YES");
	s.clear();
	for(int i = 0; i < l; i++){
		if(s.count(q[i]) or s.size() == k) cout << q[i];
		else{
			if(i > 0) cout << "\n";
			cout << q[i];
			s.insert(q[i]);
		}
	}
	cout << "\n";
	return 0;
}

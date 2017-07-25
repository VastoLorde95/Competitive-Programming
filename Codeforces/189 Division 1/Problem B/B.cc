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

int n, id[100100], mx[100100], res, m;
stack<int> s;

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(id[i]);
		if(id[i] > m){
			mx[i] = 1;
			m = id[i];
		}	
	}
	
	for(int i = n; i >= 1; i--){
		if(!mx[i]){
			while(!s.empty() and s.top() < id[i]) s.pop();
			s.push(id[i]);
			
			if(s.size() > res) res = s.size();
		}
		else{
			while(!s.empty()) s.pop();
		}
	}
		
	cout << res << endl;
	
	return 0;
}

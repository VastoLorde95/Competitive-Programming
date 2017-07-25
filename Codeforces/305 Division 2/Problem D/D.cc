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

int n;
int a[200001], l[200001], r[200001];
int ans[200001];

stack<int> s;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	for(int i = 0; i < n; i++){
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(s.empty()){
			l[i] = -1;
		}
		else{
			l[i] = s.top();
		}
		s.push(i);
	}
	
	while(!s.empty()) s.pop();
	
	for(int i = n-1; i >= 0; i--){
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(s.empty()){
			r[i] = n;
		}
		else{
			r[i] = s.top();
		}
		s.push(i);
	}
	
	for(int i = 0; i < n; i++){
//		tr2(l[i], r[i]);
		ans[r[i]-l[i]-1] = max(ans[r[i]-l[i]-1], a[i]);
	}
	
	for(int i = n-1; i >= 1; i--){
		ans[i] = max(ans[i], ans[i+1]);
	}	
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}

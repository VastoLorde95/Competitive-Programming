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

int n;
string s;
vector<int> tmp, res;

void build(int i){
	if(i == n) return;
	
	if(s[i] == 'l'){
		build(i+1);
		res.pb(i+1);
	}
	else{
		res.pb(i+1);
		build(i+1);
	}
	
	return;
}

int main(){
	cin>> s;
	n = s.length();
	
	build(0);
	
	for(int i = 0; i < n; i++){
		printf("%d ", res[i]);
	}
	
	return 0;
}

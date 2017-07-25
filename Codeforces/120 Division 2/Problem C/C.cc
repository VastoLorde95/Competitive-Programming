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

int n = 0;
string s, t;

void solve(){
	if(cin>>s){
		t += s;
		if(s == "pair"){
			t += "<";
			solve();
			t += ",";
			solve();
			t += ">";
		}
		return;
	}
	else{
		n = 1;
	}	
	return;
}


int main(){
	sd(n);
	n = 0;
	solve();
	if(cin>>s or n == 1) puts("Error occurred");
	else puts(t.c_str());
	return 0;
}

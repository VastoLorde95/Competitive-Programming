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

string s;

int main(){ _
	cin >> s;
	int l = s.length();
	if(s[0] == 'f'){
		s = s.substr(0,3) + "://" + s.substr(3,l-3);
	}
	else{
		s = s.substr(0,4) + "://" + s.substr(4,l-4);
	}	
	
	l = s.length();
	for(int i = l-2; i >= 0; i--){
		if(s[i] == 'r' and s[i+1] == 'u'){
			if(i == l-2)
				s = s.substr(0,i) + ".ru";
			else
				s = s.substr(0,i) + "." + s.substr(i,2) + "/" + s.substr(i+2,l-i-1);
			break;
		}
	}
	
	cout << s << "\n";
	
	return 0;
}

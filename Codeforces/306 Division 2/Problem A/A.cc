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

string s;

int main(){ _
	cin >> s;
	int n = s.length();
	
	if(n < 4){
		puts("NO");
		return 0;
	}
	
	for(int i = 1; i < n; i++){
		if(s[i] == 'B' and s[i-1] == 'A'){
			for(int j = i+2; j < n; j++){
				if(s[j] == 'A' and s[j-1] == 'B'){
					puts("YES");
					return 0;
				}
			}
			break;
		}
	}
	
	for(int i = 1; i < n; i++){
		if(s[i] == 'A' and s[i-1] == 'B'){
			for(int j = i+2; j < n; j++){
				if(s[j] == 'B' and s[j-1] == 'A'){
					puts("YES");
					return 0;
				}
			}
			break;
		}
	}
	
	puts("NO");
	
	return 0;
}

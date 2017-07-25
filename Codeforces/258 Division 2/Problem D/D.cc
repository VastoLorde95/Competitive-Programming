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
long long ans1, ans2, a1, a2, b1, b2;

int main(){ _
	cin >> s;
	
	int n = s.length();
	
	for(int i = 0; i < n; i++){
		if(s[i] == 'a'){
			if(i%2 == 1){
				a1++;
				ans2 += a2;
				ans1 += a1;
			}
			else{
				a2++;
				ans2 += a1;
				ans1 += a2;
			}
		}
		else{
			if(i%2 == 1){
				b1++;
				ans2 += b2;
				ans1 += b1;
			}
			else{
				b2++;
				ans2 += b1;
				ans1 += b2;
			}
		}
	}
	
	tr2(ans2, ans1);
	
	return 0;
}

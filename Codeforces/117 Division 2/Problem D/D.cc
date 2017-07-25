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

string s1, s2;
int l1, l2, cnt;

int main(){ _
	cin >> s1 >> s2;
	l1 = s1.length();
	l2 = s2.length();
	
	if(l1 > l2){
		swap(l1,l2);
		swap(s1,s2);
	}
	
	for(int i = 1; i <= l1; i++){
		if(l1%i == 0 and l2%i == 0){
			string tmp = s1.substr(0,i);
			string s = tmp;
			
			while(s.length() < l1){
				s += tmp;
			}
			if(s != s1) continue;
			
			while(s.length() < l2){
				s += tmp;
			}
			if(s != s2) continue;
			
			cnt++;
		}
	}
	
	printf("%d\n",cnt);
	
	return 0;
}

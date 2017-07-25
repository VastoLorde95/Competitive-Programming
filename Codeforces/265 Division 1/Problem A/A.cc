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

int n, p;
string s, res, cur;

bool inrange(int index){
	if(index >= 0 and index < n) return true;
	return false;
}

bool isgood(string x){
	for(int i = 0; i < n; i++){
		if(inrange(i+1) and x[i] == x[i+1])
			return false;
		if(inrange(i+2) and x[i] == x[i+2])
			return false;
		if(inrange(i-1) and x[i] == x[i-1])
			return false;
		if(inrange(i-2) and x[i] == x[i-2])
			return false;
	}
	return true;
}

int main(){
	sd2(n,p);
	cin >> s;
	res = s;
	if(p <= 2 and n > 2){
		cout << "NO\n";
		return 0;
	}
	
	if(n == 1){
		if(s[0]-'a' == p-1)
			puts("NO");
		else{
			int tmp = s[0]-'a';
			s[0] = (char)(((tmp+1)%p)+'a');
			cout << s << endl;
		}
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		cur = s;
		for(int j = 0; j < p; j++){
			if(inrange(i-1) and s[i-1]-'a' == j) continue;
			if(inrange(i-2) and s[i-2]-'a' == j) continue;
			
			if(j > (cur[i]-'a')){
				cur[i] = (char)(j + 'a');
				
				for(int k = i+1; k < n; k++){
					for(int ch = 0; ch < p; ch++){
						if(inrange(k-1) and cur[k-1]-'a' == ch) continue;
						if(inrange(k-2) and cur[k-2]-'a' == ch) continue;
						
						cur[k] = (char)(ch+'a');
						break;
					}
				}
				
				if(isgood(cur)){
					res = cur;
					break;
				}
			}
		}
	}
	
	if(res == s) puts("NO");
	else cout << res << endl;
	
	return 0;
}

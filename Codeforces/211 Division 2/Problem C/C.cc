#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

string s, res;
int n, l, cur;

int main(){
	cin >> s;
	n = s.length(), cur = 1;
	
	if(n < 3){
		cout << s << endl;
		return 0;
	}
	
	res += s[0];
	res += s[1];
	for(int i = 2; i < n; i++){
		if(s[i] == res[cur] and res[cur] == res[cur-1]) continue;
		if(res.length() > 2 and s[i] == res[cur] and res[cur] != res[cur-1] and res[cur-1] == res[cur-2]) continue;
		
		res += s[i];
		cur++;
	}
	
	cout << res << endl;
	
	return 0;
}

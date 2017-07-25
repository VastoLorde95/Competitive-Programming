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
#define LET(x, b)  __typeof(b) x(b)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

using namespace std;

int cnt1[26], cnt2[26], cnt3[26], ansa, ansb;

string a,b,c;

int main(){ _
	cin >> a >> b >> c;
	
	for(int i = 0; i < a.size(); i++) cnt1[a[i]-'a']++;
	
	for(int i = 0; i < b.size(); i++) cnt2[b[i]-'a']++;
	
	for(int i = 0; i < c.size(); i++) cnt3[c[i]-'a']++;
	
	int sum = 1000000;
	
	for(int i = 0; i < 26; i++)
		if(cnt2[i]) sum = min(sum, cnt1[i]/cnt2[i]);
	
	for(int i = 0; i <= sum; i++){
		int res = 1000000;
		
		for(int j = 0;j < 26; j++)
			if(cnt3[j]) res = min(res,(cnt1[j]-cnt2[j]*i)/cnt3[j]);
		
		if(i + res > ansa + ansb)
			ansa = i, ansb = res;
	}
	
	for(int i = 0; i < ansa; i++) cout << b;
	
	for(int i = 0; i < ansb; i++) cout << c;
	
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < cnt1[i]-(cnt2[i]*ansa)-(cnt3[i]*ansb); j++)
		cout << (char)(i+'a');
	cout << "\n";
}

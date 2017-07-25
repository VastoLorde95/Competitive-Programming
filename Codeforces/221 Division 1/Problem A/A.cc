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

string a, pre, suff;
int c1, c2, c3, c4, val;

int main(){
	cin >> a;
	
	int n = a.length();
	
	for(int i = 0; i < n; i++){
		if(a[i] == '1'){
			if(c1) pre += a[i];
			else c1 = 1;
		}
		else if(a[i] == '6'){
			if(c2) pre += a[i];
			else c2 = 1;
		}
		else if(a[i] == '8'){
			if(c3) pre += a[i];
			else c3 = 1;
		}
		else if(a[i] == '9'){
			if(c4) pre += a[i];
			else c4 = 1;
		}
		else if(a[i] == '0') suff += a[i];
		else pre += a[i];
	}
	
	for(int i = 0; i < pre.size(); i++){
		(val *= 10) %= 7;
		(val += (pre[i]-'0')) %= 7;
	}
	
	(val *= 10000) %= 7;
	if(val == 0)
		cout << pre + "1869" + suff << endl;
	else if(val == 1)
		cout << pre + "1896" + suff << endl;
	else if(val == 2)
		cout << pre + "1986" + suff << endl;
	else if(val == 3)
		cout << pre + "8691" + suff << endl;
	else if(val == 4)
		cout << pre + "6891" + suff << endl;
	else if(val == 5)
		cout << pre + "9186" + suff << endl;
	else if(val == 6)
		cout << pre + "1968" + suff << endl;
	
	return 0;
}

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

int n, a[100000], s[100000], sum, cnt;

int main(){
	sd(n);	
	for(int i = 0; i < n; i++){
		sd(a[i]); sum += a[i];
	}
	
//	cout << sum << endl;
	
	s[0] = a[0];
	
	if(s[0]+s[0] == sum and n > 1) cnt++;
	
	for(int i = 1; i < n-1; i++){
		s[i] = a[i] + s[i-1];
		if(s[i]+s[i] == sum) cnt++;
	}
	
	cout << cnt <<"\n";
	
	return 0;
}

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

int n, a[100000], mx;
long long cnt, res;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	sort(a, a+n);
	
	mx = a[n-1];
	
	for(int i = 0; i < n-1; i++){
		cnt += (mx-a[i]);
	}
	
	if(cnt >= mx){
		cout << mx << endl;
		return 0;
	}
	
	int i = 0;
	
	int r = ceil((double)(mx-cnt)/(n-1));	// how many more rounds per person
	
	if(r < a[0])
		cout << mx + r << endl;
	else{
		while(i < n-1 and a[i] <= r) i++;
		i--;
		cout << mx+a[i] << endl;
	}
	
	return 0;
}

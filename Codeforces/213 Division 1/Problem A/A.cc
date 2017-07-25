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
	
long long a, n;
long long sum[4001];
map<long long, long long> cnt;
long long res;
string s;

int main(){ _
	cin >> a;
	cin >> s;
	n = s.length();
	
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + (s[i-1]-'0');
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			cnt[sum[j]-sum[i-1]]++;
		}
	}

	for(map<long long, long long>::iterator it = cnt.begin(); it != cnt.end(); it++){
		long long t1 = it->fi, t2 = it->se;	
		if(t1 == 0){
			if(a == 0) res = res + t2*((n*(n+1))/2);
		}
		else if(a%t1 == 0 and cnt.find(a/t1) != cnt.end()){
			res = res + (t2 * cnt[a/t1]); 
		}
	}
	
	cout << res << endl;
	
	return 0;
}

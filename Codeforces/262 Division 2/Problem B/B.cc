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

long long a, b, c, s;
vector<long long> res;

long long sum(long long x){
	long long ret = 0;
	while(x > 0){
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int main(){
	cin >> a >> b >> c;
	for(long long i = 1; i <= 90; i++){
		long long p = i;
		for(int j = 1; j < a; j++){
			p *= i;
		}
		long long x = b*p + c;
		if(sum(x) == i and x > 0 and x < 1e9) res.pb(x);
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	foreach(it, res) cout << *it << " ";
	cout << endl;
	return 0;
}

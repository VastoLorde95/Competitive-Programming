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

long long n, m, k, mn = -1;

int main(){ _ 
	cin >> n >> m >> k;
	if(n == 1 and m == 1){
		cout << -1 << endl; return 0;
	}
	else if((n == 1 and k > (m-1)) or (m == 1 and k > (n-1))){
		cout << -1 << endl; return 0;
	}
	else if(n != 1 and m != 1 and k > (n-1)+(m-1)){
		cout << -1 << endl; return 0;
	}
	
	for(long long i = 0; i*i <= n and i <= k; i++){
		long long tmp = n/(i+1);
		mn = max(mn, (n/(i+1)) * (m/(k-i+1)));		
		if(tmp <= k and tmp > 0 and k-(tmp-1)+1 > 0){
			mn = max(mn, (n/(tmp)) * (m/(k-(tmp-1)+1)));		
		}
	}
	
	for(long long i = 0; i*i <= m and i <= k; i++){
			long long tmp = m/(i+1);
			mn = max(mn, (m/(i+1)) * (n/(k-i+1)));		
			if(tmp <= k and tmp > 0 and k-(tmp-1)+1 > 0){
				mn = max(mn, (m/(tmp)) * (n/(k-(tmp-1)+1)));		
			}
	}
	
	tr(mn);
	
	
	return 0;
}

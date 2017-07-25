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

long long fib[60], n, k;

int main(){
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i <= 51; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
//		tr3(k,fib[n-i+1], fib[n-i]);
		if(k <= fib[n-i+1]){
			cout << i << " ";
		}
		else{
			if(i+1 <= n) cout << i+1 << " " << i << " "; else cout << i << " ";
			k -= fib[n-i+1];
			i++;
		}
	}
	cout << endl;
	
	return 0;
}

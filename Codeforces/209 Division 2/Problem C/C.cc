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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long n, x, a[100000];
long long sum, mn = 1ll<<60, MOD = 1000000007, res;

long long exp(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b%2) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	
	return ret;
}

int main(){ _
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	
	sort(a, a+n);
	
	mn = sum - a[n-1];
	res = exp(x, mn);
	
//	tr(res);
	
	int cnt = 0;
	
	for(int i = n-1; i >= 0; i--){
		if(sum-a[i] == mn) cnt++;
		else{
			if(cnt%x == 0){
				while(cnt%x == 0){
					if(sum-a[i] > mn){
						cnt /= x;
						res = (res*x)%MOD;
//						tr(res);
						mn++;
					}
					else break;
				}

				if(i >= 0 and sum-a[i] == mn) cnt++;
			}
			else break;
		}
	}
	
	while(cnt%x == 0){
		cnt /= x;
		res = (res*x)%MOD;
		mn++;
	}
	
//	tr(mn);	
			
	if(mn <= sum)
		cout << res << endl;
	else
		cout << exp(x,sum) << endl;
	
	return 0;
}

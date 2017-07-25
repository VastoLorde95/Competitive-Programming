#include <iostream>
using namespace std;
long a,b,n,i,ans,h[20]={},f[100]={};
bool dfs(long d,long x,long l) {
	if (d==0) {
		for (long i=1;i<=n;i++)
			if (h[i]>=0) return false;
		return true;
	}
	if (h[x]<0) return dfs(d,x+1,l);
	if (x==n) {
		h[n]-=b;f[d]=n-1;
		if (dfs(d-1,x,l)) return true;
		h[n]+=b;
	} else for (long i=max(x,l);i<=x+1;i++)
		if ((1<i)&&(i<n)) {
			f[d]=i;
			h[i]-=a;h[i-1]-=b;h[i+1]-=b;
			if (dfs(d-1,x,i)) return true;
			h[i]+=a;h[i-1]+=b;h[i+1]+=b;
		}
	return false;
}
int main() {
	cin >> n >> a >> b;
	for (i=1;i<=n;i++) cin >> h[i];
	for (ans=1;;ans++)
		if (dfs(ans,1,2)) {
			cout << ans << endl;
			for (i=ans;i>1;i--) cout << f[i] << ' ';
			cout << f[1] << endl;
			return 0;
		}
	return 0;
}

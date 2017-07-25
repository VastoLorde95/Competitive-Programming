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
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, z[1001001], x[1001001], c[1001001];
long long ans = 1, MOD = 1000000007;
string p;

void build_z(string s){
	int len = s.length(), l = 0, r = 0, k;
	z[0] = len;
	
	for(int i = 1; i < len; i++){
		if(r <= i){
			l = r = i;
			while(r < n and s[r-l] == s[r]) r++;
			z[i] = r-l;
		}
		else{
			k = i-l;
			if(z[i] < r-i)
				z[i] = z[k];
			else{
				l = i;
				while(r < n and s[r-l] == s[r]) r++;
				z[i] = r-l;
			}
		}
	}
	return;	
}

int main(){ _
	cin >> n >> m;
	cin >> p;
	
	build_z(p);
	
	int l = p.length();
	
	for(int i = 0; i < m; i++){
		cin >> x[i];
		c[x[i]]++;
		c[x[i]+l]--;
	}
	
	for(int i = 1; i < m; i++){
		if(x[i-1] + l - x[i] <= 0) continue;
		
		if(z[x[i]- x[i-1]] < x[i-1]+l-x[i]){
			
			cout << "0\n";
			return 0;
		}
	}

	for(int i = 1; i <= n; i++){
		c[i] += c[i-1];
		if(c[i] == 0) (ans *= 26) %= MOD;
	}
	
	
	cout << ans << "\n";
	return 0;
}

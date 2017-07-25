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

long long n, p[50], cost, cnt[5], tot;
vector<pair<long long, long long> > c;

int main(){ _
	cin >> n;
	for(long long i = 0; i < n; i++){
		cin >> p[i];
	}
	
	for(long long i = 0; i < 5; i++){
		cin >> cost;
		c.pb(mp(cost,i));
	}
	
	sort(c.begin(), c.end());
	
	for(long long i = 0; i < n; i++){
		tot += p[i];
		for(long long j = 4; j >= 0; j--){
			cnt[c[j].se] += tot/c[j].fi;
			tot %= c[j].fi;
		}
	}
	
	for(long long i = 0; i < 5; i++){
		cout << cnt[i] << " ";
	}
	cout << endl <<  tot << endl;
		
	return 0;
}

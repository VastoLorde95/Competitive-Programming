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

long long l, r, k, mn;
vector<long long> res;


int main(){
	cin >> l >> r >> k;
	mn = l; res.pb(l);
	
	if(l == r or k == 1) cout << l << "\n" << 1 << "\n" << l << "\n"; return 0;
	
	if(k >= 2){
		if(l+1 == r){
			if(l < (l^r)){
				res.clear();
				mn = l;
				res.pb(l);
			}
			else{
				res.clear();
				mn = l^r;
				res.pb(l); res.pb(r);
			}
		}
		else{
			long long v[] = {l, (l^(l+1)), (l^(l+2)), ((l+1)^(l+2))};
			sort(v, v+4);
			if(v[0] < mn){
				mn = v[0]; res.clear();
				if(v[0] == l){
					res.pb(l);
				}
				else if(v[0] == (l^(l+1))){
					res.pb(l); res.pb(l+1);
				}
				else if(v[0] == (l^(l+2))){
					res.pb(l); res.pb(l+2);
				}
				else if(v[0] == ((l+1)^(l+2))){
					res.pb(l+1); res.pb(l+2);
				}
			}
		}
	}
	
	if(k >= 3){
		long long cnt = 0, tmp = l;
		while(tmp > 1){
			cnt++;
			tmp >>= 1;
		}
		while(cnt >= 0){
			cnt--;
			tmp <<= 1;
		}
		
		bool ok = true;
		long long a = tmp, b = tmp;
		for(long long i = 40; i >= 0; i--){
			if((l&(1LL<<i)) > 0){
				if(tmp+(1LL<<i) > r){
					ok = false;
				}
				else{
					a |= (1LL<<i);
					b |= (l^(1LL<<i));
				}
				break;
			}
		}
		
		if(ok){
			cout << 0 << "\n" << 3 << "\n" << l << " " << a << " " << b << endl; return 0;
		}
	}
	
	if(k >= 4){
		while(l+3 <= r and mn > 0){
			long long tmp = (l^(l+1)^(l+2)^(l+3));
			if(tmp < mn){
				mn = tmp;
				res.clear();
				res.pb(l); res.pb(l+1); res.pb(l+2); res.pb(l+3);
			}
			l++;
		}
	}
	
	cout << mn << "\n" << res.size() << "\n";
	foreach(it, res) cout << *it << " "; cout << endl;
	
	return 0;
}

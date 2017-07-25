#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fst<<", "<<p.snd<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 200100;

int d, n, m;
vector<pii> gas;
int l[N];

int main(){
	sd3(d,n,m);
	
	for(int i = 0; i < m; i++){
		int x, y; sd2(x, y);
		gas.pb(mp(x, y));
	}
	gas.pb(mp(d, 0));
	
	sort(gas.begin(), gas.end());
	m++;

	stack<int> s;
	s.push(m - 1);
	
	for(int i = m - 2; i >= 0; i--){
		while(!s.empty() and gas[s.top()].snd > gas[i].snd) s.pop();
		
		l[i] = s.top();
		s.push(i);
	}
	
	ll cur = n - gas[0].fst, del = 0, ans = 0;
	
	m--;
	for(int i = 0; i < m; i++){
		if(cur < 0){
			printf("-1\n");
			return 0;
		}
		
		del = min(-cur + n, max(0ll, gas[l[i]].fst - gas[i].fst - cur));
		ans += del * gas[i].snd;
		cur += del;
		cur -= gas[i+1].fst - gas[i].fst;
	}
	
	if(cur < 0) printf("-1\n") else cout << ans << endl;
	
	return 0;
}

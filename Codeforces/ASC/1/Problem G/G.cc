#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("people.in","r",stdin);freopen("people.out","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100;

int n;
vector<pair<pii, int> >  p;
int ptr[N];
int inf = 1e9 + 7;

int lis(){
	int sz = p.size();
	vector<pii> d(sz+1, mp(inf,inf));
	for(int i = 0; i < sz; i++){
		int j = lower_bound(d.begin(), d.end(), mp(-p[i].fi.se, -1)) - d.begin();
		 d[j] = mp(-p[i].fi.se, p[i].se);
		 if(j > 0)
		 	ptr[p[i].se] = d[j-1].se;
		 else
		 	ptr[p[i].se] = -1;
	}
	int len =  0;
	for(int i = 0; i <= sz; i++)
		if(d[i].fi == inf){
			len = i;
			break;
		}
		
	vector<int> res;	
	int cur = d[len-1].se;
	while(cur != -1){
		res.pb(cur);
		cur = ptr[cur];
	}
	printf("%d\n", len);
	foreach(it, res){
		printf("%d ", *it);
	}
	puts("");

}

int main(){ __
	sd(n);
	for(int i = 1; i <= n; i++){
		int s, b; sd2(s,b);
		p.pb(mp(mp(s,-b),i));
	}
	sort(p.begin(), p.end());
	
	lis();
	
	return 0;
}

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<ll,ll> pii;

const int N = 100100;

unordered_set<int> s[3][N];
vector<pii> edges;



int main(){
	int n, m, u, v;
	sd(n);
	for(int j = 0; j < 3; j++){
		sd(m);
		for(int i = 1; i <= m; i++){
			sd2(u,v);
			s[j][u].insert(v);
			s[j][v].insert(u);
		}
	}
	
	int ROOT = 300;
	
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		int x = s[1][i].size();
		int y = s[2][i].size();
				
		if(x + y < ROOT){
			for(const int &p :s[1][i]){
				for(const int &q : s[2][i]){
					if(s[0][p].find(q) != s[0][p].end()) ans++;
				}
			}
		}
        else{
            for(int j = 1; j <= n; j++){
				if(s[1][i].find(j) != s[1][i].end()) continue;
                foreach(it, s[0][j]){
                	int k = *it;
                	if(s[2][i].find(k) != s[2][i].end()) ans++;
                }
            }
        }
	}
	
	cout << ans << endl;
	
	return 0;
}

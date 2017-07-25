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

const int N = 200100;
const int INF = 1e9;

int n;
vector<int> g[N];
int v[N];
int d[N];

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		int ai; sd(ai);
		if(ai == i) continue;
		g[i].pb(ai);
	}
	
	for(int i = 1; i < n; i++){
		g[i].pb(i+1);
	}
	
	for(int i = 2; i <= n; i++){
		g[i].pb(i-1);
	}
	
	for(int i = 1; i <= n; i++){
		d[i] = i-1;
	}
	
	queue<int> q;
	q.push(1);
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(v[cur]) continue;
		v[cur] = 1;
		
		foreach(it, g[cur]){
			if(v[*it]) continue;
			d[*it] = min(d[*it], d[cur]+1);
			q.push(*it);
		}
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", d[i]);
	}
	puts("");
	
	return 0;
}

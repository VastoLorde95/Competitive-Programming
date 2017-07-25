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
typedef pair<int,int> pii;

const int M = 64;
const int N = 100100;

int n;
ll m;
int p[N];

int jump[M][N];

int main(){ _
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}

	for(int i = 1; i <= n; i++){
		jump[0][i] = p[i];
	}
	
	for(int j = 1; j < M; j++){
		for(int i = 1; i <= n; i++){
			jump[j][i] = (jump[j-1][i] + 1 > n)? N : jump[j-1][jump[j-1][i] + 1];
		}
	}

	int cur = 1, nxt;
	ll cnt = m;
	for(int j = M-1; j >= 0; j--){
		if(jump[j][cur] <= n and (1 << j) <= cnt){
			nxt = jump[j][cur];
			m = m - (1ll << j) + 1 + (nxt  - cur);
			cur = nxt+1;
			cnt -= (1 << j);
			if(cur > n) break;
		}
	}
	
	cout << m << endl;
	
}

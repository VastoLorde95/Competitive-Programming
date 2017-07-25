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

const int N = 100100;
const int M = 1001000;
const int K = 20;
const int INF = 1e9;

struct seg{
	int l, r, link;
};

bool operator<(const seg &s1, const seg &s2){
	if(s1.r != s2.r)
		return s1.r < s2.r;
	return s1.l < s2.l;
}

int n, q;
int fst[M];
seg s[N];
vector<int> v[M];
int jump[K][N];

void preprocess(){
	fst[M-1] = INF;
	for(int i = M-2; i > 0; i--){
		fst[i] = fst[i+1];
		int mn = INF;
		int id = INF;
		
		if(fst[i] != INF){
			id = fst[i];
			mn = s[id].r;
		}
		
		foreach(it, v[i]){
			int j = *it;
			if(s[j].r < mn){
				mn = s[j].r;
				id = j;
			}
		}
		fst[i] = id;
	}

	for(int i = 1; i <= n; i++){
		jump[0][i] = fst[s[i].r+1];
	}

	for(int k = 1; k < K; k++){
		fill(jump[k], jump[k]+N, INF);
		for(int j = 1; j <= n; j++){
			if(jump[k-1][j] != INF)
				jump[k][j] = jump[k-1][jump[k-1][j]];			
		}
	}
}

int main(){
	sd2(n,q);
	
	for(int i = 1; i <= n; i++){
		sd2(s[i].l, s[i].r);
	}
	
	sort(s+1, s+n+1);
	
	for(int i = 1; i <= n; i++){
		v[s[i].l].pb(i);
	}
	
	preprocess();
	
	for(int i = 1; i <= q; i++){
		int l, r;
		sd2(l,r);
		
//		tr(meta, l, r);
		
		int ans = 0;
		
		while(l <= r){
//			tr(meta, i, l);
			int id = fst[l];
			if(id == INF or s[id].r > r) break;
			
			
			if(jump[0][id] == INF){
				ans++;
				break;
			}	
			
			if(s[jump[0][id]].r > r){
				ans++;
				break;
			}
			
			int j = 0;
			while(jump[j][id] != INF and s[jump[j][id]].r <= r) j++;
			
			j--;
			
			assert(j >= 0);
			
//			tr(meta, l, id, j, jump[j][id]);
			
			ans += (1 << j) + 1;
			
			l = s[jump[j][id]].r + 1;	
			
//			int pauu;
//			cin >> pauu;
			
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}

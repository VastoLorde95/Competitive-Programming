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

typedef pair<int, pair<int, int> > trip;

#define fst fi
#define snd se.fi
#define thd se.se
#define mt(x,y,z) mp(x,mp(y,z))

const int N = 101;
const int M = 5001;
const int INF = 1e9;

int least[M];
trip combination[M];

int dp[M][2];
vector<trip> best[M][2];

int id;
void preprocess(){
	for(int i = 1; i < M; i++) least[i] = INF;
	for(int i = 1; i < M; i++) dp[i][0] = dp[i][1] = INF;
	
	for(int i = 1; i < N; i++){
		for(int j = 1; i + j < N; j++){
			for(int k = 1; i + j + k < N; k++){
				if(i*j*k < M){
					int prod = i * j * k, sum = i + j + k;
					if(sum < least[prod]){
						least[prod] = sum;
						combination[prod] = mt(i,j,k); 
					}
				}
			}
		}
	}	

	for(int i = 1; i < M; i++){
		dp[i][id] = least[i];
		if(dp[i][id] != INF) best[i][id].pb(combination[i]);
	}

	id ^= 1;
	for(int i = 1; i < M; i++) dp[i][id] = dp[i][1-id], best[i][id] = best[i][1-id];
	
	for(int i = 1; i < M; i++){
		for(int j = 1; i + j < M; j++){
			if(least[i] + dp[j][1-id] < dp[i+j][id]){
				dp[i+j][id] = least[i] + dp[j][1-id];
				best[i+j][id].clear();
				best[i+j][id].pb(combination[i]);
				foreach(it, best[j][1-id])
					best[i+j][id].pb(*it);
			}
		}
	}
	
	return;
}

int p, q;

vector<pii> edges;

int get(int i){
	return (i*(i-1)*(i-2))/6;
}

void solve(){
	int cur = 1;
	while(p){
		int i = 3;
		while(get(i) <= p) i++;
		i--;
		p -= get(i);
		
		for(int j = 1; j <= i; j++){
			edges.pb(mp(cur, cur+j));
		}
		cur = cur + i + 1;
	}
	
	cout << cur-1 << " " << edges.size() << endl;
	foreach(edge, edges){
		cout << edge->fi << " " << edge->se << endl;
	}
	return;
}

int main(){ _
	preprocess();
	
	cin >> p >> q;
	
	if(q == 2){
		solve();
		return 0;
	}
	
	int cur = 0, indx = 0;
	vector<trip> v = best[p][id];
		
	while(p > 0){
		vector<int> cycle;
		int bg = cur + 1;
		int ed = cur + 3*(q-2);
		
		for(int i = bg; i <= ed; i++){
			cycle.pb(i);
			if(i == ed) edges.pb(mp(ed, bg));
			else edges.pb(mp(i,i+1));
		}
		
		cycle.insert(cycle.end(), cycle.begin(), cycle.end());
		
		int cnt = q - 2;
		int iter = 0;
		
		cur = ed;
		
		while(p > 0 and cnt > 0){
			trip trio = v[indx++];
			int x = trio.fst, y = trio.snd, z = trio.thd;
		
			for(int j = 1; j <= x; j++){
				edges.pb(mp(cycle[iter], cur + j));
			}
			
			for(int j = 1; j <= y; j++){
				edges.pb(mp(cycle[q-2 + iter], cur + x + j));
			}
			
			for(int j = 1; j <= z; j++){
				edges.pb(mp(cycle[2*(q-2) + iter], cur + x + y + j));
			}
			p -= x * y * z;
			cnt--;
			iter++;
			cur = cur +  x + y + z;
			
		}		
	}
	
	cout << cur << " " << edges.size() << endl;
	foreach(edge, edges){
		cout << edge->fi << " " << edge->se << endl;
	}
	
	return 0;
}

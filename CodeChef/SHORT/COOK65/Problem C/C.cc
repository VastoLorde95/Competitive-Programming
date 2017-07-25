#include <bits/stdc++.h>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__,__LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1010;
const int M = 26;

int n, k;
string a, b, res;

int lcs[N][N];
int nextPos[N][N];
int ways[N][N];

int id[M];
int inf = 1e9;

int cnt[M];

void computeLCS(){
	for(int i = n-1; i >= 0; i--)
		for(int j = n-1; j >= 0; j--)
			lcs[i][j] = (a[i] == b[j])? lcs[i+1][j+1] + 1 : max(lcs[i+1][j], lcs[i][j+1]);
}

void computeWays(){
	for(int i = n-1; i >= 0; i--){
		for(int j = n-1; j >= 0; j--){
			if(i == n-1 or j == n-1) ways[i][j] = 1;
			else if(a[i] == b[j]) ways[i][j] = ways[i+1][j+1];
			else{
				if(lcs[i][j+1] == lcs[i+1][j]){
					ways[i][j] = ways[i][j+1] + ways[i+1][j];
					if(lcs[i+1][j+1] == lcs[i+1][j]) ways[i][j] -= ways[i+1][j+1];
					ways[i][j] = min(inf+1, ways[i][j]);
				}
				else ways[i][j] = (lcs[i+1][j] > lcs[i][j+1])? ways[i+1][j] : ways[i][j+1];
			}
		}
	}
}

void buildString(){
	for(int i = 0; i < M; i++) id[i] = inf;
	
	for(int j = n-1; j >= 0; j--){
		id[b[j]-'a'] = j;
		for(int i = n-1; i >= 0; i--) nextPos[i][j] = id[a[i]-'a'];
	}	
	
	int min_i = 0, min_j = 0, len = lcs[0][0], cur_len = len;
	
	while(res.length() < len){
		int j = min_j;
		
		for(int i = min_i; i < n; i++){
			if(nextPos[i][j] == inf or lcs[i][nextPos[i][j]] != cur_len) continue;

			int c = a[i]-'a';
			if(cnt[c] > 0) continue;
			
			cnt[c] = ways[i][nextPos[i][j]];
		}
		
		char nextchar = 'a';
		for(int i = 0; i < M; i++){
			if(cnt[i] >= k){
				nextchar = 'a'+i, res += nextchar;
				break;
			}
			else k -= cnt[i];
			cnt[i] = 0;
		}
		
		for(int i = min_i; i < n; i++){
			if(nextPos[i][j] == inf or lcs[i][nextPos[i][j]] != cur_len) continue;
			if(a[i] == nextchar){
				min_i = i+1;
				min_j = nextPos[i][j]+1;
				break;
			}
		}
		cur_len--;
	}
}

int main(){ _
	cin >> n >> k >> a >> b;

	computeLCS();
	computeWays();
	
	if(ways[0][0] < k){
		cout << "-1\n"; return 0;
	}
	
	buildString();
	
	cout << res << '\n';
	
	return 0;
}

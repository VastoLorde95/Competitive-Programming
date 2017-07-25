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

const int N = 51;
const int M = 26;

int dp1[N][N][M];
int dp2[N][N][M];

string s1, s2;
int n;

vector<pii> rules[M];

void buildDP(int dp[][N][M], string &s){
	int l = s.length();
	
	for(int i = 0; i < l; i++) dp[i][i][s[i]-'a'] = 1;
	
	for(int i = 2; i <= l; i++){
		for(int j = 0, k = i-1; k < l; j++, k++){
			for(int c = 0; c < M; c++){
				bool found = false;
				
				for(int m = j; m < k and !found; m++){
					foreach(it, rules[c]){
						int x = it->fi, y = it->se;
						
						if(dp[j][m][x] and dp[m+1][k][y]){
							dp[j][k][c] = 1;
							found = true;
							break;
						}
					}
				}
				
			}
		}
	}
}

int dp[N][N];

int main(){ _
	cin >> s1 >> s2;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		string rule;
 		cin >> rule;
 		rules[rule[0]-'a'].pb(mp(rule[3]-'a', rule[4]-'a'));
	}

	buildDP(dp1, s1);
	buildDP(dp2, s2);
	
	int l1 = s1.length();
	int l2 = s2.length();
	
	const int INF = 1e9;
		
	for(int i = 0; i <= l1; i++)
		for(int j = 0; j <= l2; j++)
			dp[i][j] = INF;	

	dp[0][0] = 0;
	
	for(int i1 = 1; i1 <= l1; i1++){
		for(int j1 = 1; j1 <= l2; j1++){
			if(dp[i1-1][j1-1] == INF) continue;
			
			for(int i2 = i1; i2 <= l1; i2++){
				for(int j2 = j1; j2 <= l2; j2++){
					for(int c = 0; c < M; c++){
						
						if(dp1[i1-1][i2-1][c] and dp2[j1-1][j2-1][c]){
							dp[i2][j2] = min(dp[i2][j2], dp[i1-1][j1-1] + 1);
							break;
						}
						
					}
				}
			}
			
		}
	}
	
	if(dp[l1][l2] == INF) dp[l1][l2] = -1;
	cout << dp[l1][l2] << endl;
	
	return 0;
}

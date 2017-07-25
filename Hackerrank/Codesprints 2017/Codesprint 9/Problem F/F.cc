#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int LOGN = 18;
const int N = 1 << LOGN;
const int M = 41;
const int S = ((M * (M-1)) / 2) + 1;
const int INF = 1e9;

int n;
int a[N];
int sum[N];

int sp[LOGN][N], pos[LOGN][N], k[N], o[N];

void sparseTable(){
	
	for(int i = 0; i <= n; i++) sp[0][i] = sum[i], pos[0][i] = i;
	
	for(int j = 1; j < LOGN; j++){
		for(int i = 0; (i+(1<<j)-1) <= n; i++){
			if(sp[j-1][i] >= sp[j-1][i+(1<<(j-1))]){
				sp[j][i] = sp[j-1][i+(1<<(j-1))];
				pos[j][i] = pos[j-1][i+(1<<(j-1))];
			}
			else{
				sp[j][i] = sp[j-1][i];
				pos[j][i] = pos[j-1][i];
			}
		}
	}
	
	for(int i = 2; i <= n+1; i++){
		k[i] = k[i-1] + ((i&(i-1)) == 0);
		if(k[i] == k[i-1]) o[i] = o[i-1];
		else o[i] = ((o[i-1]+1)<<1)-1;
	}
	
	return;
}

pii rmq(int x, int y){
	if(y < x) return mp(INF,-1);
	int l = y-x+1;
	if(sp[k[l]][x] >= sp[k[l]][y-o[l]])
		return mp(sp[k[l]][y-o[l]], pos[k[l]][y-o[l]]);
	else
		return mp(sp[k[l]][x], pos[k[l]][x]);
}

int dp[S][M];
int best[S][M];

int main(){ _
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	
	sparseTable();
	
	int mx = 0;
	int cnt = 0;
	int len = 0;
	
	for(int i = 1; i <= n; i++){
		if(a[i] > 0){
			dp[a[i]][a[i]] = i;
			for(int j = a[i]+1; j <= (a[i] * (a[i] + 1)) / 2; j++){
				dp[j][a[i]] = best[j-a[i]][a[i]-1];
			}
			
			for(int j = a[i]; j <= (a[i] * (a[i] + 1)) / 2; j++){
				for(int k = a[i]; k < M; k++){
					best[j][k] = max(best[j][k-1], dp[j][k]);
				}
			}
			
			int pos = 0;
			for(int j = S-1; j >= 0; j--){
				if(best[j][M-1] > pos){
					pii tmp = rmq(pos, best[j][M-1]-1);
				
					int tot = sum[i] - tmp.fi - j;
					int mlen = i - tmp.se;
				
					if(tot > mx){
						mx = tot;
						len = mlen;
						cnt = 1;
					}
					else if(tot == mx){
						if(mlen < len){
							len = mlen;
							cnt = 1;
						}
						else if(mlen == len) cnt++;
					}
				
					pos = best[j][M-1];
				}
			}
		}
	}	
	
	if(mx == 0) cnt = n;
	
	cout << mx << ' ' << cnt << endl;
		
	return 0;
}

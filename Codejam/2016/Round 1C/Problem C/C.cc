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

const int N = 11;

int cnt1[N][N];
int cnt2[N][N];
int cnt3[N][N];

int used1[N][N];
int used2[N][N];
int used3[N][N];

vector<vector<int> > solve(int a, int b, int c, int K, int i1, int i2, int i3){
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);
	memset(cnt3, 0, sizeof cnt3);
	
	vector<vector<int> > res;
	
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			memset(used1, 0, sizeof used1);
			memset(used2, 0, sizeof used2);
			while(cnt1[i][j] < K){
				int mn = 1e9;
				int nxt = -1;
				for(int k = 1; k <= c; k++){
					if(used1[i][k] or used2[j][k]) continue;
					int mx = max(cnt2[i][k], cnt3[j][k]);
					if(mx < K and mx < mn){
						mn = mx;
						nxt = k;
					}
				}
				
				if(nxt == -1) break;
				int k = nxt;
				vector<int> tmp(3,0);
				tmp[i1] = i;
				tmp[i2] = j;
				tmp[i3] = k;
				cnt1[i][j]++;
				cnt2[i][k]++;
				cnt3[j][k]++;
				used1[i][k] = 1;
				used1[j][k] = 1;
				res.pb(tmp);
			}
			
//			for(int k = 1; k <= c; k++){
//				if(cnt2[i][k] < K and cnt3[j][k] < K and cnt1[i][j] < K){
//					vector<int> tmp(3,0);
//					tmp[i1] = i;
//					tmp[i2] = j;
//					tmp[i3] = k;
//					cnt1[i][j]++;
//					cnt2[i][k]++;
//					cnt3[j][k]++;
//					res.pb(tmp);
//				}
//			}
		}
	}
	return res;
}

void doit(){
	int j, p, s, k;
	sd3(j,p,s); sd(k);
	
	vector<vector<int> > res = solve(j,p,s,k,0,1,2);
	vector<vector<int> > tmp = solve(j,s,p,k,0,2,1);
	if(tmp.size() > res.size()) res = tmp;
						 tmp = solve(p,j,s,k,1,0,2);
	if(tmp.size() > res.size()) res = tmp;
						 tmp = solve(p,s,j,k,1,2,0);
	if(tmp.size() > res.size()) res = tmp;
						 tmp = solve(s,j,p,k,2,0,1);
	if(tmp.size() > res.size()) res = tmp;
						 tmp = solve(s,p,j,k,2,1,0);
	if(tmp.size() > res.size()) res = tmp;
	
	printf("%d\n", (int) res.size());
	foreach(it, res){
		printf("%d %d %d\n", (*it)[0], (*it)[1], (*it)[2]);
	}
	
}

int main(){
	int t; sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		doit();
	}	
	return 0;
}

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

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 10;

int t, n;
int s[N], l[N][N];
int m[N][N][N];
int MOD = 1e9+7;

int main(){
	sd(t);
	while(t--){
		sd(n);
		for(int i = 0; i < n; i++){
			sd(s[i]);
			for(int j = 0; j < s[i]; j++){
				sd(l[i][j]);
			}
		}
		
		
		for(int i = 0; i < s[0]; i++){
			for(int j = 0; j < s[1]; j++){
				for(int k = 0; k < s[2]; k++){
					m[i][j][k] = l[0][i]*l[1][j]*l[2][k];
				}
			}
		}
		
		long long mx = -1e9;
		long long cnt = 0;
		
		for(int i = 0; i < s[0]; i++){
			for(int j = i; j < s[0]; j++){
				for(int k = 0; k < s[1]; k++){
					for(int l = k; l < s[1]; l++){
						for(int a = 0; a < s[2]; a++){
							for(int b = a; b < s[2]; b++){
								
								long long sum = 0;
								for(int t1 = i; t1 <= j; t1++){
									for(int t2 = k; t2 <= l; t2++){
										for(int t3 = a; t3 <= b; t3++){
											sum += m[t1][t2][t3];
										}
									}
								}
								
								if(sum > mx){
									mx = sum;
									cnt = 1;
								}
								else if(sum == mx){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		
		printf("%lld %lld\n", mx, (cnt)%MOD);
		
	}
	return 0;
}

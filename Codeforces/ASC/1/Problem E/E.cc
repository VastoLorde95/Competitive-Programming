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
#define __ freopen("nice.in","r",stdin);freopen("nice.out","w",stdout);

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

const int N = 1<<5;

int m[N][N], ret[N][N], res[N][N], n;
vector<int> exponent;
int k, p;
char s[101];

void readN(){
	scanf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l; i++){
		exponent.pb(s[i]-'0');
	}
	
	reverse(exponent.begin(), exponent.end());
	
	for(int i = 0; i < exponent.size(); i++){
		if(exponent[i] > 0){
			exponent[i]--;
			break;
		}
		exponent[i] = 9;
	}
	
	if(exponent.back() == 0) exponent.pop_back();
	
}

void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

void mul(int a[][N], int b[][N]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res[i][j] = 0;			
			for(int k = 0; k < n; k++) add(res[i][j], a[i][k]*b[k][j] % p);
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = res[i][j];
	return;
}

void divideby2(){
	int carry = 0;
	for(int i = exponent.size() - 1; i >= 0; i--){
		int ncarry = (10*carry + exponent[i]) % 2;
		exponent[i] = (10*carry + exponent[i]) / 2;
		carry = ncarry;
	}
	while(!exponent.empty() and exponent.back() == 0) exponent.pop_back();
}

void fast(){
	for(int i = 0; i < n; i++) ret[i][i] = 1;
	
	while(!exponent.empty()){
		if(exponent[0]%2) mul(ret, m);
		mul(m,m);
		divideby2();
	}
	
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) m[i][j] = ret[i][j];
	return;
}

int main(){ __
	readN();
	sd2(k,p);
	
	if(exponent.size() == 1 and exponent[0] == 0){
		printf("%d\n", k);
		return 0;
	}
	
	n = 1 << k;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			bool ok = true;
			for(int l = 1; l < k; l++){
				int b1 = (i&(1<<(l-1))) > 0;
				int b2 = (i&(1<<l)) > 0;
				int b3 = (j&(1<<(l-1))) > 0;
				int b4 = (j&(1<<l)) > 0;
				if(b1 == b2 and b2 == b3 and b3 == b4){
					ok = false;
					break;
				}
			}
			m[i][j] = (ok)? 1 : 0;
		}
	}
	
	fast();
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			add(ans, m[i][j]);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

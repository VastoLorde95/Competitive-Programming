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

typedef long long ll;

const int N = 50000;

int n, k, x;
long long cnt[10];

long long m[100][100], id[100][100], tmp[100][100], MOD = 1e9 + 7;

void mul1(){
	memset(tmp, 0, sizeof tmp);
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			for(int k = 0; k < x; k++){
				tmp[i][j] += (id[i][k]*m[k][j])%MOD;
				if(tmp[i][j] >= MOD) tmp[i][j] -= MOD;
			}
		}
	}	
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			id[i][j] = tmp[i][j];
		}
	}
}

void mul2(){
	memset(tmp, 0, sizeof tmp);
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			for(int k = 0; k < x; k++){
				tmp[i][j] += (m[i][k]*m[k][j])%MOD;
				if(tmp[i][j] >= MOD) tmp[i][j] -= MOD;
			}
		}
	}	
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			m[i][j] = tmp[i][j];
		}
	}
}

void expp(ll b){
	for(int i = 0; i < x; i++){
		id[i][i] = 1;
	}
	
	while(b > 0){
		if(b%2) mul1();
		mul2();
		b >>= 1;
	}
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			m[i][j] = id[i][j];
		}
	}
}

int main(){
	int b;
	sd2(n,b);
	sd2(k,x);
	
	for(int i = 0; i < n; i++){
		int digit; sd(digit);
		cnt[digit]++;
	}
	
	for(int i = 0; i < x; i++){
		for(int j = 1; j <= 9; j++){
			int rem = (10*i + j)%x;
			m[i][rem] += cnt[j];
		}
	}
	
	expp(b);
	
	cout << m[0][k] << endl;
	
	
	return 0;
}

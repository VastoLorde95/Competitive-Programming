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

const int N = 200;
const ll INF = 1ll << 60;

struct Matrix{
	int n;
	vector<vector<ll> > m;
	Matrix(int nn = 0, bool id = false){
		n = nn;
		m.resize(n);
		for(int i = 0; i < n; i++) m[i].resize(n, -INF);
		if(id) for(int i = 0; i < n; i++) m[i][i] = 0;
	}
	
	vector<ll>& operator[](int i){return m[i];}
	int size(){return n;}
};

Matrix operator*(Matrix &A, Matrix &B){
	int n = A.size();
	Matrix C(n);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
	return C;
}

Matrix fast(Matrix &A, ll b){
	Matrix ret(N, true);
	while(b){
		if((b&1)) ret = ret * A;
		A = A * A;
		b >>= 1;
	}
	return ret;
}

int main(){
	
	return 0;
}
